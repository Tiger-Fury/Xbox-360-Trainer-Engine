#include <xtl.h>
#include <stdio.h>
#include "kernel.h"
#include "xbdm.h"
//#include "xamext.h"
//#include "launch.h"

/*
HANDLE resolveFunct(char* modname, DWORD ord) {
	HANDLE ptr32 = 0, ptr2 = 0;
	DWORD ret = 0;
	ret = XexGetModuleHandle(modname, &ptr32);
	if(ret == 0){
		ret = XexGetProcedureAddress(ptr32, ord, &ptr2);
		if(ptr2 != 0)
			return(ptr2);
	}
	return(0);
}*/

DWORD resolveFunct(PCHAR modname, DWORD ord)
{
	DWORD ptr2=0;
	HANDLE hand;
	if(NT_SUCCESS(XexGetModuleHandle(modname, &hand)))
		XexGetProcedureAddress(hand, ord, &ptr2);
	return ptr2; // function not found
}



#define SYS_STRING "\\System??\\%s"
#define USR_STRING "\\??\\%s"

DWORD __declspec(naked) HvxSetState(DWORD key, DWORD mode)
{ 
	__asm {
		li      r0, 0x0
			sc
			blr
	}
}

HRESULT doDeleteLink(const char* szDrive, const char* sysStr)
{
	STRING LinkName;
	CHAR szDestinationDrive[MAX_PATH];
	sprintf_s(szDestinationDrive, MAX_PATH, sysStr, szDrive);
	RtlInitAnsiString(&LinkName, szDestinationDrive);
	return ObDeleteSymbolicLink(&LinkName);
}

HRESULT deleteLink(const char* szDrive, BOOL both)
{
	HRESULT res = -1;
	if(both)
	{
		res = doDeleteLink(szDrive, SYS_STRING);
		res |= doDeleteLink(szDrive, USR_STRING);
	}
	else
	{
		if(KeGetCurrentProcessType() == SYSTEM_PROC)
			res = doDeleteLink(szDrive, SYS_STRING);
		else
			res = doDeleteLink(szDrive, USR_STRING);
	}
	return res;
}

HRESULT doMountPath(const char* szDrive, const char* szDevice, const char* sysStr)
{
	STRING DeviceName, LinkName;
	CHAR szDestinationDrive[MAX_PATH];
	sprintf_s(szDestinationDrive, MAX_PATH, sysStr, szDrive);
	RtlInitAnsiString(&DeviceName, szDevice);
	RtlInitAnsiString(&LinkName, szDestinationDrive);
	ObDeleteSymbolicLink(&LinkName);
	return (HRESULT)ObCreateSymbolicLink(&LinkName, &DeviceName);
}

HRESULT MountPath(const char* szDrive, const char* szDevice, BOOL both)
{
	HRESULT res = -1;
	if(both)
	{
		res = doMountPath(szDrive, szDevice, SYS_STRING);
		res |= doMountPath(szDrive, szDevice, USR_STRING);
	}
	else
	{
		if(KeGetCurrentProcessType() == SYSTEM_PROC)
			res = doMountPath(szDrive, szDevice, SYS_STRING);
		else
			res = doMountPath(szDrive, szDevice, USR_STRING);
	}
	return res;
}

PIMAGE_EXPORT_ADDRESS_TABLE getModuleEat(char* modName)
{
	PLDR_DATA_TABLE_ENTRY moduleHandle = (PLDR_DATA_TABLE_ENTRY)GetModuleHandle(modName);
	if(moduleHandle != NULL)
	{
		DWORD ret;
		PIMAGE_XEX_HEADER xhead = (PIMAGE_XEX_HEADER)moduleHandle->XexHeaderBase;
		ret = (DWORD)RtlImageXexHeaderField(xhead, 0xE10402);
		if(ret == 0)
		{
			return xhead->SecurityInfo->ExportTableAddress;
		}
	}
	return NULL;
}

// this is how xam does it... XamFileExists
// BOOL fileExists(PCHAR path)
// {
// OBJECT_ATTRIBUTES obAtrib;
// FILE_NETWORK_OPEN_INFORMATION netInfo;
// STRING filePath;
// RtlInitAnsiString(&filePath, path); //  = 0x10
// InitializeObjectAttributes(&obAtrib, &filePath, 0x40, NULL);
// if(path[0] != '\\')
// obAtrib.RootDirectory = (HANDLE)0xFFFFFFFD;
// if(NT_SUCCESS(NtQueryFullAttributesFile(&obAtrib, &netInfo)))
// {
//filter out directories from the result
// if((netInfo.FileAttributes & FILE_ATTRIBUTE_DIRECTORY) == 0)
// return TRUE;
// }
// return FALSE;
// }

// this one was fixed to allow busy files to be detected as existing
BOOL fileExists(PCHAR path)
{
	HANDLE file = CreateFile(path, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if(file == INVALID_HANDLE_VALUE)
	{
		if(GetLastError() != 5) // inaccessible means it exists but is probably open somewhere else
			return FALSE;
	}
	CloseHandle(file);
	return TRUE;
}

// will check if a mounted drive is present via path = "link:\\", trailing \ needed for it to work
BOOL driveExists(PCHAR path)
{
	DWORD attr = GetFileAttributes(path);
	if(attr == NEG_ONE_AS_DWORD)
		return FALSE;
	else
		return TRUE;
}

VOID patchInJumpr0(PDWORD addr, DWORD dest, BOOL linked)
{
	if(dest & 0x8000) // If bit 16 is 1
		addr[0] = 0x3C000000 + (((dest >> 16) & 0xFFFF) + 1); // lis %r0, dest>>16 + 1
	else
		addr[0] = 0x3C000000 + ((dest >> 16) & 0xFFFF); // lis %r0, dest>>16

	addr[1] = 0x38000000 + (dest & 0xFFFF); // addi %r0, %r0, dest&0xFFFF
	addr[2] = 0x7C0903A6; // mtctr %r0        

	if(linked)
		addr[3] = 0x4E800421; // bctrl
	else
		addr[3] = 0x4E800420; // bctr
	__dcbst(0, addr);
	__sync();
	__isync();
}

VOID patchInJumpr1(PDWORD addr, DWORD dest, BOOL linked)
{
	if(dest & 0x8000) // If bit 16 is 1
		addr[0] = 0x3C200000 + (((dest >> 16) & 0xFFFF) + 1); // lis %r1, dest>>16 + 1
	else
		addr[0] = 0x3C200000 + ((dest >> 16) & 0xFFFF); // lis %r1, dest>>16

	addr[1] = 0x38210000 + (dest & 0xFFFF); // addi %r1, %r1, dest&0xFFFF
	addr[2] = 0x7C2903A6; // mtctr %r1        

	if(linked)
		addr[3] = 0x4E800421; // bctrl
	else
		addr[3] = 0x4E800420; // bctr
	__dcbst(0, addr);
	__sync();
	__isync();
}

VOID patchInJumpr2(PDWORD addr, DWORD dest, BOOL linked)
{
	if(dest & 0x8000) // If bit 16 is 1
		addr[0] = 0x3C400000 + (((dest >> 16) & 0xFFFF) + 1); // lis %r2, dest>>16 + 1
	else
		addr[0] = 0x3C400000 + ((dest >> 16) & 0xFFFF); // lis %r2, dest>>16

	addr[1] = 0x38420000 + (dest & 0xFFFF); // addi %r2, %r2, dest&0xFFFF
	addr[2] = 0x7C4903A6; // mtctr %r2        

	if(linked)
		addr[3] = 0x4E800421; // bctrl
	else
		addr[3] = 0x4E800420; // bctr
	__dcbst(0, addr);
	__sync();
	__isync();
}


VOID patchInJumpr3(PDWORD addr, DWORD dest, BOOL linked)
{
	if(dest & 0x8000) // If bit 16 is 1
		addr[0] = 0x3C600000 + (((dest >> 16) & 0xFFFF) + 1); // lis %r3, dest>>16 + 1
	else
		addr[0] = 0x3C600000 + ((dest >> 16) & 0xFFFF); // lis %r3, dest>>16

	addr[1] = 0x38630000 + (dest & 0xFFFF); // addi %r3, %r3, dest&0xFFFF
	addr[2] = 0x7C6903A6; // mtctr %r3        

	if(linked)
		addr[3] = 0x4E800421; // bctrl
	else
		addr[3] = 0x4E800420; // bctr
	__dcbst(0, addr);
	__sync();
	__isync();
}

VOID patchInJumpr4(PDWORD addr, DWORD dest, BOOL linked)
{
	if(dest & 0x8000) // If bit 16 is 1
		addr[0] = 0x3C800000 + (((dest >> 16) & 0xFFFF) + 1); // lis %r4, dest>>16 + 1
	else
		addr[0] = 0x3C800000 + ((dest >> 16) & 0xFFFF); // lis %r4, dest>>16

	addr[1] = 0x38840000 + (dest & 0xFFFF); // addi %r4, %r4, dest&0xFFFF
	addr[2] = 0x7C8903A6; // mtctr %r4        

	if(linked)
		addr[3] = 0x4E800421; // bctrl
	else
		addr[3] = 0x4E800420; // bctr
	__dcbst(0, addr);
	__sync();
	__isync();
}

VOID patchInJumpr5(PDWORD addr, DWORD dest, BOOL linked)
{
	if(dest & 0x8000) // If bit 16 is 1
		addr[0] = 0x3CA00000 + (((dest >> 16) & 0xFFFF) + 1); // lis %r5, dest>>16 + 1
	else
		addr[0] = 0x3CA00000 + ((dest >> 16) & 0xFFFF); // lis %r5, dest>>16

	addr[1] = 0x38A50000 + (dest & 0xFFFF); // addi %r5, %r5, dest&0xFFFF
	addr[2] = 0x7CA903A6; // mtctr %r5        

	if(linked)
		addr[3] = 0x4E800421; // bctrl
	else
		addr[3] = 0x4E800420; // bctr
	__dcbst(0, addr);
	__sync();
	__isync();
}

VOID patchInJumpr6(PDWORD addr, DWORD dest, BOOL linked)
{
	if(dest & 0x8000) // If bit 16 is 1
		addr[0] = 0x3CC00000 + (((dest >> 16) & 0xFFFF) + 1); // lis %r6, dest>>16 + 1
	else
		addr[0] = 0x3CC00000 + ((dest >> 16) & 0xFFFF); // lis %r6, dest>>16

	addr[1] = 0x38C60000 + (dest & 0xFFFF); // addi %r6, %r6, dest&0xFFFF
	addr[2] = 0x7CC903A6; // mtctr %r6        

	if(linked)
		addr[3] = 0x4E800421; // bctrl
	else
		addr[3] = 0x4E800420; // bctr
	__dcbst(0, addr);
	__sync();
	__isync();
}

VOID patchInJumpr7(PDWORD addr, DWORD dest, BOOL linked)
{
	if(dest & 0x8000) // If bit 16 is 1
		addr[0] = 0x3CE00000 + (((dest >> 16) & 0xFFFF) + 1); // lis %r7, dest>>16 + 1
	else
		addr[0] = 0x3CE00000 + ((dest >> 16) & 0xFFFF); // lis %r7, dest>>16

	addr[1] = 0x38E70000 + (dest & 0xFFFF); // addi %r7, %r7, dest&0xFFFF
	addr[2] = 0x7CE903A6; // mtctr %r7        

	if(linked)
		addr[3] = 0x4E800421; // bctrl
	else
		addr[3] = 0x4E800420; // bctr
	__dcbst(0, addr);
	__sync();
	__isync();
}

VOID patchInJumpr8(PDWORD addr, DWORD dest, BOOL linked)
{
	if(dest & 0x8000) // If bit 16 is 1
		addr[0] = 0x3D000000 + (((dest >> 16) & 0xFFFF) + 1); // lis %r8, dest>>16 + 1
	else
		addr[0] = 0x3D000000 + ((dest >> 16) & 0xFFFF); // lis %r8, dest>>16

	addr[1] = 0x39080000 + (dest & 0xFFFF); // addi %r8, %r8, dest&0xFFFF
	addr[2] = 0x7D0903A6; // mtctr %r8        

	if(linked)
		addr[3] = 0x4E800421; // bctrl
	else
		addr[3] = 0x4E800420; // bctr
	__dcbst(0, addr);
	__sync();
	__isync();
}

VOID patchInJumpr9(PDWORD addr, DWORD dest, BOOL linked)
{
	if(dest & 0x8000) // If bit 16 is 1
		addr[0] = 0x3D200000 + (((dest >> 16) & 0xFFFF) + 1); // lis %r9, dest>>16 + 1
	else
		addr[0] = 0x3D200000 + ((dest >> 16) & 0xFFFF); // lis %r9, dest>>16

	addr[1] = 0x39290000 + (dest & 0xFFFF); // addi %r9, %r9, dest&0xFFFF
	addr[2] = 0x7D2903A6; // mtctr %r9        

	if(linked)
		addr[3] = 0x4E800421; // bctrl
	else
		addr[3] = 0x4E800420; // bctr
	__dcbst(0, addr);
	__sync();
	__isync();
}

VOID patchInJumpr10(PDWORD addr, DWORD dest, BOOL linked)
{
	if(dest & 0x8000) // If bit 16 is 1
		addr[0] = 0x3D400000 + (((dest >> 16) & 0xFFFF) + 1); // lis %r10, dest>>16 + 1
	else
		addr[0] = 0x3D400000 + ((dest >> 16) & 0xFFFF); // lis %r10, dest>>16

	addr[1] = 0x394A0000 + (dest & 0xFFFF); // addi %r10, %r10, dest&0xFFFF
	addr[2] = 0x7D4903A6; // mtctr %r10        

	if(linked)
		addr[3] = 0x4E800421; // bctrl
	else
		addr[3] = 0x4E800420; // bctr
	__dcbst(0, addr);
	__sync();
	__isync();
}

VOID patchInJumpr11(PDWORD addr, DWORD dest, BOOL linked)
{
	if(dest & 0x8000) // If bit 16 is 1
		addr[0] = 0x3D600000 + (((dest >> 16) & 0xFFFF) + 1); // lis %r11, dest>>16 + 1
	else
		addr[0] = 0x3D600000 + ((dest >> 16) & 0xFFFF); // lis %r11, dest>>16

	addr[1] = 0x396B0000 + (dest & 0xFFFF); // addi %r11, %r11, dest&0xFFFF
	addr[2] = 0x7D6903A6; // mtctr %r11        

	if(linked)
		addr[3] = 0x4E800421; // bctrl
	else
		addr[3] = 0x4E800420; // bctr
	__dcbst(0, addr);
	__sync();
	__isync();
}

VOID patchInJumpr12(PDWORD addr, DWORD dest, BOOL linked)
{
	if(dest & 0x8000) // If bit 16 is 1
		addr[0] = 0x3D800000 + (((dest >> 16) & 0xFFFF) + 1); // lis %r12, dest>>16 + 1
	else
		addr[0] = 0x3D800000 + ((dest >> 16) & 0xFFFF); // lis %r12, dest>>16

	addr[1] = 0x398C0000 + (dest & 0xFFFF); // addi %r12, %r12, dest&0xFFFF
	addr[2] = 0x7D8903A6; // mtctr %r12        

	if(linked)
		addr[3] = 0x4E800421; // bctrl
	else
		addr[3] = 0x4E800420; // bctr
	__dcbst(0, addr);
	__sync();
	__isync();
}

VOID patchInJumpr13(PDWORD addr, DWORD dest, BOOL linked)
{
	if(dest & 0x8000) // If bit 16 is 1
		addr[0] = 0x3DA00000 + (((dest >> 16) & 0xFFFF) + 1); // lis %r13, dest>>16 + 1
	else
		addr[0] = 0x3DA00000 + ((dest >> 16) & 0xFFFF); // lis %r13, dest>>16

	addr[1] = 0x39AD0000 + (dest & 0xFFFF); // addi %r13, %r13, dest&0xFFFF
	addr[2] = 0x7DA903A6; // mtctr %r13        

	if(linked)
		addr[3] = 0x4E800421; // bctrl
	else
		addr[3] = 0x4E800420; // bctr
	__dcbst(0, addr);
	__sync();
	__isync();
}

VOID patchInJumpr14(PDWORD addr, DWORD dest, BOOL linked)
{
	if(dest & 0x8000) // If bit 16 is 1
		addr[0] = 0x3DC00000 + (((dest >> 16) & 0xFFFF) + 1); // lis %r14, dest>>16 + 1
	else
		addr[0] = 0x3DC00000 + ((dest >> 16) & 0xFFFF); // lis %r14, dest>>16

	addr[1] = 0x39CE0000 + (dest & 0xFFFF); // addi %r14, %r14, dest&0xFFFF
	addr[2] = 0x7DC903A6; // mtctr %r14        

	if(linked)
		addr[3] = 0x4E800421; // bctrl
	else
		addr[3] = 0x4E800420; // bctr
	__dcbst(0, addr);
	__sync();
	__isync();
}

VOID patchInJumpr15(PDWORD addr, DWORD dest, BOOL linked)
{
	if(dest & 0x8000) // If bit 16 is 1
		addr[0] = 0x3DE00000 + (((dest >> 16) & 0xFFFF) + 1); // lis %r15, dest>>16 + 1
	else
		addr[0] = 0x3DE00000 + ((dest >> 16) & 0xFFFF); // lis %r15, dest>>16

	addr[1] = 0x39EF0000 + (dest & 0xFFFF); // addi %r15, %r15, dest&0xFFFF
	addr[2] = 0x7DE903A6; // mtctr %r15        

	if(linked)
		addr[3] = 0x4E800421; // bctrl
	else
		addr[3] = 0x4E800420; // bctr
	__dcbst(0, addr);
	__sync();
	__isync();
}

VOID patchInJumpr16(PDWORD addr, DWORD dest, BOOL linked)
{
	if(dest & 0x8000) // If bit 16 is 1
		addr[0] = 0x3E000000 + (((dest >> 16) & 0xFFFF) + 1); // lis %r16, dest>>16 + 1
	else
		addr[0] = 0x3E000000 + ((dest >> 16) & 0xFFFF); // lis %r16, dest>>16

	addr[1] = 0x3A100000 + (dest & 0xFFFF); // addi %r16, %r16, dest&0xFFFF
	addr[2] = 0x7E0903A6; // mtctr %r16        

	if(linked)
		addr[3] = 0x4E800421; // bctrl
	else
		addr[3] = 0x4E800420; // bctr
	__dcbst(0, addr);
	__sync();
	__isync();
}

VOID patchInJumpr17(PDWORD addr, DWORD dest, BOOL linked)
{
	if(dest & 0x8000) // If bit 16 is 1
		addr[0] = 0x3E200000 + (((dest >> 16) & 0xFFFF) + 1); // lis %r17, dest>>16 + 1
	else
		addr[0] = 0x3E200000 + ((dest >> 16) & 0xFFFF); // lis %r17, dest>>16

	addr[1] = 0x3A310000 + (dest & 0xFFFF); // addi %r17, %r17, dest&0xFFFF
	addr[2] = 0x7E2903A6; // mtctr %r17        

	if(linked)
		addr[3] = 0x4E800421; // bctrl
	else
		addr[3] = 0x4E800420; // bctr
	__dcbst(0, addr);
	__sync();
	__isync();
}

VOID patchInJumpr18(PDWORD addr, DWORD dest, BOOL linked)
{
	if(dest & 0x8000) // If bit 16 is 1
		addr[0] = 0x3E400000 + (((dest >> 16) & 0xFFFF) + 1); // lis %r18, dest>>16 + 1
	else
		addr[0] = 0x3E400000 + ((dest >> 16) & 0xFFFF); // lis %r18, dest>>16

	addr[1] = 0x3A520000 + (dest & 0xFFFF); // addi %r18, %r18, dest&0xFFFF
	addr[2] = 0x7E4903A6; // mtctr %r18        

	if(linked)
		addr[3] = 0x4E800421; // bctrl
	else
		addr[3] = 0x4E800420; // bctr
	__dcbst(0, addr);
	__sync();
	__isync();
}

VOID patchInJumpr19(PDWORD addr, DWORD dest, BOOL linked)
{
	if(dest & 0x8000) // If bit 16 is 1
		addr[0] = 0x3E600000 + (((dest >> 16) & 0xFFFF) + 1); // lis %r19, dest>>16 + 1
	else
		addr[0] = 0x3E600000 + ((dest >> 16) & 0xFFFF); // lis %r19, dest>>16

	addr[1] = 0x3A730000 + (dest & 0xFFFF); // addi %r19, %r19, dest&0xFFFF
	addr[2] = 0x7E6903A6; // mtctr %r19        

	if(linked)
		addr[3] = 0x4E800421; // bctrl
	else
		addr[3] = 0x4E800420; // bctr
	__dcbst(0, addr);
	__sync();
	__isync();
}

VOID patchInJumpr20(PDWORD addr, DWORD dest, BOOL linked)
{
	if(dest & 0x8000) // If bit 16 is 1
		addr[0] = 0x3E800000 + (((dest >> 16) & 0xFFFF) + 1); // lis %r20, dest>>16 + 1
	else
		addr[0] = 0x3E800000 + ((dest >> 16) & 0xFFFF); // lis %r20, dest>>16

	addr[1] = 0x3A940000 + (dest & 0xFFFF); // addi %r20, %r20, dest&0xFFFF
	addr[2] = 0x7E8903A6; // mtctr %r20        

	if(linked)
		addr[3] = 0x4E800421; // bctrl
	else
		addr[3] = 0x4E800420; // bctr
	__dcbst(0, addr);
	__sync();
	__isync();
}

VOID patchInJumpr21(PDWORD addr, DWORD dest, BOOL linked)
{
	if(dest & 0x8000) // If bit 16 is 1
		addr[0] = 0x3EA00000 + (((dest >> 16) & 0xFFFF) + 1); // lis %r21, dest>>16 + 1
	else
		addr[0] = 0x3EA00000 + ((dest >> 16) & 0xFFFF); // lis %r21, dest>>16

	addr[1] = 0x3AB50000 + (dest & 0xFFFF); // addi %r21, %r21, dest&0xFFFF
	addr[2] = 0x7EA903A6; // mtctr %r21        

	if(linked)
		addr[3] = 0x4E800421; // bctrl
	else
		addr[3] = 0x4E800420; // bctr
	__dcbst(0, addr);
	__sync();
	__isync();
}

VOID patchInJumpr22(PDWORD addr, DWORD dest, BOOL linked)
{
	if(dest & 0x8000) // If bit 16 is 1
		addr[0] = 0x3EC00000 + (((dest >> 16) & 0xFFFF) + 1); // lis %r22, dest>>16 + 1
	else
		addr[0] = 0x3EC00000 + ((dest >> 16) & 0xFFFF); // lis %r22, dest>>16

	addr[1] = 0x3AD60000 + (dest & 0xFFFF); // addi %r22, %r22, dest&0xFFFF
	addr[2] = 0x7EC903A6; // mtctr %r22        

	if(linked)
		addr[3] = 0x4E800421; // bctrl
	else
		addr[3] = 0x4E800420; // bctr
	__dcbst(0, addr);
	__sync();
	__isync();
}

VOID patchInJumpr23(PDWORD addr, DWORD dest, BOOL linked)
{
	if(dest & 0x8000) // If bit 16 is 1
		addr[0] = 0x3EE00000 + (((dest >> 16) & 0xFFFF) + 1); // lis %r23, dest>>16 + 1
	else
		addr[0] = 0x3EE00000 + ((dest >> 16) & 0xFFFF); // lis %r23, dest>>16

	addr[1] = 0x3AF70000 + (dest & 0xFFFF); // addi %r23, %r23, dest&0xFFFF
	addr[2] = 0x7EE903A6; // mtctr %r23        

	if(linked)
		addr[3] = 0x4E800421; // bctrl
	else
		addr[3] = 0x4E800420; // bctr
	__dcbst(0, addr);
	__sync();
	__isync();
}

VOID patchInJumpr24(PDWORD addr, DWORD dest, BOOL linked)
{
	if(dest & 0x8000) // If bit 16 is 1
		addr[0] = 0x3F000000 + (((dest >> 16) & 0xFFFF) + 1); // lis %r24, dest>>16 + 1
	else
		addr[0] = 0x3F000000 + ((dest >> 16) & 0xFFFF); // lis %r24, dest>>16

	addr[1] = 0x3B180000 + (dest & 0xFFFF); // addi %r24, %r24, dest&0xFFFF
	addr[2] = 0x7F0903A6; // mtctr %r24        

	if(linked)
		addr[3] = 0x4E800421; // bctrl
	else
		addr[3] = 0x4E800420; // bctr
	__dcbst(0, addr);
	__sync();
	__isync();
}

VOID patchInJumpr25(PDWORD addr, DWORD dest, BOOL linked)
{
	if(dest & 0x8000) // If bit 16 is 1
		addr[0] = 0x3F200000 + (((dest >> 16) & 0xFFFF) + 1); // lis %r25, dest>>16 + 1
	else
		addr[0] = 0x3F200000 + ((dest >> 16) & 0xFFFF); // lis %r25, dest>>16

	addr[1] = 0x3B390000 + (dest & 0xFFFF); // addi %r25, %r25, dest&0xFFFF
	addr[2] = 0x7F2903A6; // mtctr %r24        

	if(linked)
		addr[3] = 0x4E800421; // bctrl
	else
		addr[3] = 0x4E800420; // bctr
	__dcbst(0, addr);
	__sync();
	__isync();
}

VOID patchInJumpr26(PDWORD addr, DWORD dest, BOOL linked)
{
	if(dest & 0x8000) // If bit 16 is 1
		addr[0] = 0x3F400000 + (((dest >> 16) & 0xFFFF) + 1); // lis %r26, dest>>16 + 1
	else
		addr[0] = 0x3F400000 + ((dest >> 16) & 0xFFFF); // lis %r26, dest>>16

	addr[1] = 0x3B5A0000 + (dest & 0xFFFF); // addi %r26, %r26, dest&0xFFFF
	addr[2] = 0x7F4903A6; // mtctr %r26        

	if(linked)
		addr[3] = 0x4E800421; // bctrl
	else
		addr[3] = 0x4E800420; // bctr
	__dcbst(0, addr);
	__sync();
	__isync();
}

VOID patchInJumpr27(PDWORD addr, DWORD dest, BOOL linked)
{
	if(dest & 0x8000) // If bit 16 is 1
		addr[0] = 0x3F600000 + (((dest >> 16) & 0xFFFF) + 1); // lis %r27, dest>>16 + 1
	else
		addr[0] = 0x3F600000 + ((dest >> 16) & 0xFFFF); // lis %r27, dest>>16

	addr[1] = 0x3B7B0000 + (dest & 0xFFFF); // addi %r27, %r27, dest&0xFFFF
	addr[2] = 0x7F6903A6; // mtctr %r27        

	if(linked)
		addr[3] = 0x4E800421; // bctrl
	else
		addr[3] = 0x4E800420; // bctr
	__dcbst(0, addr);
	__sync();
	__isync();
}

VOID patchInJumpr28(PDWORD addr, DWORD dest, BOOL linked)
{
	if(dest & 0x8000) // If bit 16 is 1
		addr[0] = 0x3F800000 + (((dest >> 16) & 0xFFFF) + 1); // lis %r28, dest>>16 + 1
	else
		addr[0] = 0x3F800000 + ((dest >> 16) & 0xFFFF); // lis %r28, dest>>16

	addr[1] = 0x3B9C0000 + (dest & 0xFFFF); // addi %r28, %r28, dest&0xFFFF
	addr[2] = 0x7F8903A6; // mtctr %r28        

	if(linked)
		addr[3] = 0x4E800421; // bctrl
	else
		addr[3] = 0x4E800420; // bctr
	__dcbst(0, addr);
	__sync();
	__isync();
}

VOID patchInJumpr29(PDWORD addr, DWORD dest, BOOL linked)
{
	if(dest & 0x8000) // If bit 16 is 1
		addr[0] = 0x3FA00000 + (((dest >> 16) & 0xFFFF) + 1); // lis %r29, dest>>16 + 1
	else
		addr[0] = 0x3FA00000 + ((dest >> 16) & 0xFFFF); // lis %r29, dest>>16

	addr[1] = 0x3BBD0000 + (dest & 0xFFFF); // addi %r29, %r29, dest&0xFFFF
	addr[2] = 0x7FA903A6; // mtctr %r29        

	if(linked)
		addr[3] = 0x4E800421; // bctrl
	else
		addr[3] = 0x4E800420; // bctr
	__dcbst(0, addr);
	__sync();
	__isync();
}

VOID patchInJumpr30(PDWORD addr, DWORD dest, BOOL linked)
{
	if(dest & 0x8000) // If bit 16 is 1
		addr[0] = 0x3FC00000 + (((dest >> 16) & 0xFFFF) + 1); // lis %r30, dest>>16 + 1
	else
		addr[0] = 0x3FC00000 + ((dest >> 16) & 0xFFFF); // lis %r30, dest>>16

	addr[1] = 0x3BDE0000 + (dest & 0xFFFF); // addi %r30, %r30, dest&0xFFFF
	addr[2] = 0x7FC903A6; // mtctr %r30        

	if(linked)
		addr[3] = 0x4E800421; // bctrl
	else
		addr[3] = 0x4E800420; // bctr
	__dcbst(0, addr);
	__sync();
	__isync();
}

VOID patchInJumpr31(PDWORD addr, DWORD dest, BOOL linked)
{
	if(dest & 0x8000) // If bit 16 is 1
		addr[0] = 0x3FE00000 + (((dest >> 16) & 0xFFFF) + 1); // lis %r31, dest>>16 + 1
	else
		addr[0] = 0x3FE00000 + ((dest >> 16) & 0xFFFF); // lis %r31, dest>>16

	addr[1] = 0x3BFF0000 + (dest & 0xFFFF); // addi %r31, %r31, dest&0xFFFF
	addr[2] = 0x7FE903A6; // mtctr %r31        

	if(linked)
		addr[3] = 0x4E800421; // bctrl
	else
		addr[3] = 0x4E800420; // bctr
	__dcbst(0, addr);
	__sync();
	__isync();
}

DWORD hookExportOrd(char* modName, DWORD ord, DWORD dstFun)
{
	PIMAGE_EXPORT_ADDRESS_TABLE expbase = getModuleEat(modName);
	if(expbase != NULL)
	{
		DbgPrint("setting up the hook\r\n");
		//if(expbase->ordOffset[ord-1] != 0){}
		DWORD modOffset = (expbase->ImageBaseAddress)<<16;
		DWORD origOffset = (expbase->ordOffset[ord-1])+modOffset;
		//expbase->ordOffset[ord-1] = dstFun-modOffset;

		DWORD nData = dstFun-modOffset;

		DmSetMemory( &expbase->ordOffset[ord-1], 0x04, &nData, NULL );
		__dcbst(0, &expbase->ordOffset[ord-1]);
		__sync();
		__isync();
		return origOffset;
	}
	return 0;
}

BOOL hookImpStub(char* modname, char* impmodname, DWORD ord, DWORD patchAddr)
{
	DWORD orgAddr;
	PLDR_DATA_TABLE_ENTRY ldat;
	int i, j;
	BOOL ret = FALSE;
	// get the address of the actual function that is jumped to
	orgAddr = resolveFunct(impmodname, ord);
	if(orgAddr != 0)
	{
		// find where kmod info is stowed
		ldat = (PLDR_DATA_TABLE_ENTRY)GetModuleHandle(modname);
		if(ldat != NULL)
		{
			// use kmod info to find xex header in memory
			PXEX_IMPORT_DESCRIPTOR imps = (PXEX_IMPORT_DESCRIPTOR)RtlImageXexHeaderField(ldat->XexHeaderBase, 0x000103FF);
			if(imps != NULL)
			{
				char* impName = (char*)(imps+1);
				PXEX_IMPORT_TABLE impTbl = (PXEX_IMPORT_TABLE)(impName + imps->NameTableSize);
				for(i = 0; i < (int)(imps->ModuleCount); i++)
				{
					// use import descriptor strings to refine table
					for(j = 0; j < impTbl->ImportCount; j++)
					{
						PDWORD add = (PDWORD)impTbl->ImportStubAddr[j];
						if(add[0] == orgAddr)
						{
							//DbgPrint("%s %s tbl %d has ord %x at tstub %d location %08x\n", modname, impName, i, ord, j, impTbl->ImportStubAddr[j+1]);
							patchInJumpr0((PDWORD)(impTbl->ImportStubAddr[j+1]), patchAddr, FALSE);
							patchInJumpr1((PDWORD)(impTbl->ImportStubAddr[j+1]), patchAddr, FALSE);
							patchInJumpr2((PDWORD)(impTbl->ImportStubAddr[j+1]), patchAddr, FALSE);
							patchInJumpr3((PDWORD)(impTbl->ImportStubAddr[j+1]), patchAddr, FALSE);
							patchInJumpr4((PDWORD)(impTbl->ImportStubAddr[j+1]), patchAddr, FALSE);
							patchInJumpr5((PDWORD)(impTbl->ImportStubAddr[j+1]), patchAddr, FALSE);
							patchInJumpr6((PDWORD)(impTbl->ImportStubAddr[j+1]), patchAddr, FALSE);
							patchInJumpr7((PDWORD)(impTbl->ImportStubAddr[j+1]), patchAddr, FALSE);
							patchInJumpr8((PDWORD)(impTbl->ImportStubAddr[j+1]), patchAddr, FALSE);
							patchInJumpr9((PDWORD)(impTbl->ImportStubAddr[j+1]), patchAddr, FALSE);
							patchInJumpr10((PDWORD)(impTbl->ImportStubAddr[j+1]), patchAddr, FALSE);
							patchInJumpr11((PDWORD)(impTbl->ImportStubAddr[j+1]), patchAddr, FALSE);
							patchInJumpr12((PDWORD)(impTbl->ImportStubAddr[j+1]), patchAddr, FALSE);
							patchInJumpr13((PDWORD)(impTbl->ImportStubAddr[j+1]), patchAddr, FALSE);
							patchInJumpr14((PDWORD)(impTbl->ImportStubAddr[j+1]), patchAddr, FALSE);
							patchInJumpr15((PDWORD)(impTbl->ImportStubAddr[j+1]), patchAddr, FALSE);
							patchInJumpr16((PDWORD)(impTbl->ImportStubAddr[j+1]), patchAddr, FALSE);
							patchInJumpr17((PDWORD)(impTbl->ImportStubAddr[j+1]), patchAddr, FALSE);
							patchInJumpr18((PDWORD)(impTbl->ImportStubAddr[j+1]), patchAddr, FALSE);
							patchInJumpr19((PDWORD)(impTbl->ImportStubAddr[j+1]), patchAddr, FALSE);
							patchInJumpr20((PDWORD)(impTbl->ImportStubAddr[j+1]), patchAddr, FALSE);
							patchInJumpr21((PDWORD)(impTbl->ImportStubAddr[j+1]), patchAddr, FALSE);
							patchInJumpr22((PDWORD)(impTbl->ImportStubAddr[j+1]), patchAddr, FALSE);
							patchInJumpr23((PDWORD)(impTbl->ImportStubAddr[j+1]), patchAddr, FALSE);
							patchInJumpr24((PDWORD)(impTbl->ImportStubAddr[j+1]), patchAddr, FALSE);
							patchInJumpr25((PDWORD)(impTbl->ImportStubAddr[j+1]), patchAddr, FALSE);
							patchInJumpr26((PDWORD)(impTbl->ImportStubAddr[j+1]), patchAddr, FALSE);
							patchInJumpr27((PDWORD)(impTbl->ImportStubAddr[j+1]), patchAddr, FALSE);
							patchInJumpr28((PDWORD)(impTbl->ImportStubAddr[j+1]), patchAddr, FALSE);
							patchInJumpr29((PDWORD)(impTbl->ImportStubAddr[j+1]), patchAddr, FALSE);
							patchInJumpr30((PDWORD)(impTbl->ImportStubAddr[j+1]), patchAddr, FALSE);
							patchInJumpr31((PDWORD)(impTbl->ImportStubAddr[j+1]), patchAddr, FALSE);
							j = impTbl->ImportCount;
							ret = TRUE;
						}
					}
					impTbl = (PXEX_IMPORT_TABLE)((BYTE*)impTbl+impTbl->TableSize);
					impName = impName+strlen(impName);
					while((impName[0]&0xFF) == 0x0)
						impName++;
				}
			}		
			//else DbgPrint("could not find import descriptor for mod %s\n", modname);
		}
		//else DbgPrint("could not find data table for mod %s\n", modname);
	}
	//else DbgPrint("could not find ordinal %d in mod %s\n", ord, impmodname);

	return ret;
}

BYTE* getModBaseSize(char* modName, PDWORD size)
{
	PLDR_DATA_TABLE_ENTRY ldat;
	ldat = (PLDR_DATA_TABLE_ENTRY)GetModuleHandle(modName);
	if(ldat != NULL)
	{
		if(ldat->EntryPoint > ldat->ImageBase)
			size[0] = ((DWORD)ldat->EntryPoint-(DWORD)ldat->ImageBase);
		else
			size[0] = ldat->SizeOfFullImage;
		return (BYTE*)ldat->ImageBase;
	}
	return NULL;
}

VOID __declspec(naked) GLPR_FUN(VOID)
{
	__asm{
		std     r14, -0x98(sp)
			std     r15, -0x90(sp)
			std     r16, -0x88(sp)
			std     r17, -0x80(sp)
			std     r18, -0x78(sp)
			std     r19, -0x70(sp)
			std     r20, -0x68(sp)
			std     r21, -0x60(sp)
			std     r22, -0x58(sp)
			std     r23, -0x50(sp)
			std     r24, -0x48(sp)
			std     r25, -0x40(sp)
			std     r26, -0x38(sp)
			std     r27, -0x30(sp)
			std     r28, -0x28(sp)
			std     r29, -0x20(sp)
			std     r30, -0x18(sp)
			std     r31, -0x10(sp)
			stw     r12, -0x8(sp)
			blr
	}
}

DWORD relinkGPLR(int offset, PDWORD saveStubAddr, PDWORD orgAddr)
{
	DWORD inst = 0, repl;
	int i;
	PDWORD saver = (PDWORD)GLPR_FUN;
	// if the msb is set in the instruction, set the rest of the bits to make the int negative
	if(offset&0x2000000)
		offset = offset|0xFC000000;
	//DbgPrint("frame save offset: %08x\n", offset);
	repl = orgAddr[offset/4];
	//DbgPrint("replacing %08x\n", repl);
	for(i = 0; i < 20; i++)
	{
		if(repl == saver[i])
		{
			int newOffset = (int)&saver[i]-(int)saveStubAddr;
			inst = 0x48000001|(newOffset&0x3FFFFFC);
			//DbgPrint("saver addr: %08x savestubaddr: %08x\n", &saver[i], saveStubAddr);
		}
	}
	//DbgPrint("new instruction: %08x\n", inst);
	return inst;
}

VOID hookFunctionStart(PDWORD addr, PDWORD saveStub, DWORD dest)
{
	if((saveStub != NULL)&&(addr != NULL))
	{
		int i;
		DWORD addrReloc = (DWORD)(&addr[4]);// replacing 4 instructions with a jump, this is the stub return address
		//DbgPrint("hooking addr: %08x savestub: %08x dest: %08x addreloc: %08x\n", addr, saveStub, dest, addrReloc);
		// build the stub
		// make a jump to go to the original function start+4 instructions
		if(addrReloc & 0x8000) // If bit 16 is 1
			saveStub[0] = 0x3D600000 + (((addrReloc >> 16) & 0xFFFF) + 1); // lis %r11, dest>>16 + 1
		else
			saveStub[0] = 0x3D600000 + ((addrReloc >> 16) & 0xFFFF); // lis %r11, dest>>16

		saveStub[1] = 0x396B0000 + (addrReloc & 0xFFFF); // addi %r11, %r11, dest&0xFFFF
		saveStub[2] = 0x7D6903A6; // mtctr %r11
		// instructions [3] through [6] are replaced with the original instructions from the function hook
		// copy original instructions over, relink stack frame saves to local ones
		for(i = 0; i<4; i++)
		{
			if((addr[i]&0x48000003) == 0x48000001) // branch with link
			{
				//DbgPrint("relink %08x\n", addr[i]);
				saveStub[i+3] = relinkGPLR((addr[i]&~0x48000003), &saveStub[i+3], &addr[i]);
			}
			else
			{
				//DbgPrint("copy %08x\n", addr[i]);
				saveStub[i+3] = addr[i];
			}
		}
		saveStub[7] = 0x4E800420; // bctr
		__dcbst(0, saveStub);
		__sync();
		__isync();

		//DbgPrint("savestub:\n");
		//for(i = 0; i < 8; i++)
		//{
		//	DbgPrint("PatchDword(0x%08x, 0x%08x);\n", &saveStub[i], saveStub[i]);
		//}
		// patch the actual function to jump to our replaced one
		patchInJumpr11(addr, dest, FALSE);
	}
}

PDWORD hookFunctionStartOrd(char* modName, DWORD ord, PDWORD saveStub, DWORD dest)
{
	PDWORD addr = (PDWORD)resolveFunct(modName, ord);
	if(addr != NULL)
		hookFunctionStart(addr, saveStub, dest);
	return addr;
}
