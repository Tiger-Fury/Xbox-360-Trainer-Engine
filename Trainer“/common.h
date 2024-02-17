#pragma once
#include <xtl.h>
#include <xbdm.h>
#include <stdio.h>
#include <xui.h>
#include "kernel.h"
#include "buttons.h"
#include "util.h"
#include "Set functions.h"

DWORD BootInfo = 0;

LPCWSTR g_strButtons[1] = { L"Continue" };
LPSTR Userid;
DWORD username;
MESSAGEBOX_RESULT g_mb_result;
XOVERLAPPED g_xol;

DWORD Prompt = 0x9999;
DWORD cavedata[4];
PDWORD addy1;
PDWORD addy2;
PDWORD addy3;
PDWORD addy4;
PWORD retaddy1;
PWORD retaddy2;

void (*Static_Menu)(void);

HRESULT (*DmSetMemoryD)(LPVOID, DWORD, LPCVOID, LPDWORD);
HRESULT (*DmGetMemoryD)(LPCVOID, DWORD, LPVOID, LPDWORD);

DWORD ResolveFunct(PCHAR modname, DWORD ord)
{
	HANDLE hand;
	DWORD ret=0, Ptr2=0;
	ret = XexGetModuleHandle(modname, &hand); 
	if(ret == 0){
		ret = XexGetProcedureAddress(hand, ord, &Ptr2 );
		if(Ptr2 != 0)
			return Ptr2;
	}
	return 0;
}


VOID notwork()
{
	Prompt = XShowMessageBoxUI(0, L"TeamXPG", L"TitleID Not Compatible", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
}

DWORD KrnlType = 0;

static void DoCheat(DWORD addr, BYTE icode[], size_t length){
	if(KrnlType != 1){
		memcpy((void*)addr, (void*)icode, length);
	}else{
		DmSetMemoryD((void*)addr, length, (void*)icode, NULL);
	}

}

static void GetMem(DWORD addr, BYTE ckval[], size_t length){
	if(KrnlType != 1){
		memcpy((void*)ckval, (void*)addr, length);
	}else{
		DmGetMemoryD((void*)addr, length, (void*)ckval, NULL);

	}
}

void SetDWORD(DWORD addr, DWORD value)
{
	if(!MmIsAddressValid((DWORD*)addr))
		return;

	if(KrnlType == 0)
		*(DWORD*)addr = value;
	else
		DmSetMemoryD((void*)addr, 4, (void*)&value, NULL);
}

void SetStatic(DWORD addr, DWORD value)
{
	if(!MmIsAddressValid((DWORD*)addr))
		return;

	if(KrnlType == 0)
		*(DWORD*)addr = *(DWORD*)value;
	else
		DmSetMemoryD((void*)addr, 4, (void*)&value, NULL);
}

DWORD GetDWORD(DWORD addr)
{
	DWORD temp;

	if(!MmIsAddressValid((DWORD*)addr))
		return 0;

	if(KrnlType == 0)
		temp = *(DWORD*)addr;
	else
		DmGetMemoryD((void*)addr, 4, (void*)&temp, NULL);

	return temp;
}

void SetBYTE(DWORD addr, BYTE value)
{
	if(!MmIsAddressValid((DWORD*)addr))
		return;

	if(KrnlType == 0)
		*(BYTE*)addr = value;
	else
		DmSetMemoryD((void*)addr, 1, (void*)&value, NULL);
}

BYTE GetBYTE(DWORD addr)
{
	BYTE temp;

	if(!MmIsAddressValid((DWORD*)addr))
		return 0;

	if(KrnlType == 0)
		temp = *(BYTE*)addr;
	else
		DmGetMemoryD((void*)addr, 1, (void*)&temp, NULL);

	return temp;
}


void SetWORD(DWORD addr, WORD value)
{
	if(!MmIsAddressValid((DWORD*)addr))
		return;

	if(KrnlType == 0)
		*(WORD*)addr = value;
	else
		DmSetMemoryD((void*)addr, 2, (void*)&value, NULL);
}

WORD GetWORD(DWORD addr)
{
	WORD temp;

	if(!MmIsAddressValid((DWORD*)addr))
		return 0;

	if(KrnlType == 0)
		temp = *(WORD*)addr;
	else
		DmGetMemoryD((void*)addr, 2, (void*)&temp, NULL);

	return temp;
}

static void Vibr01(){
	XINPUT_VIBRATION vibration;
	ZeroMemory( &vibration, sizeof(XINPUT_VIBRATION) );

	vibration.wLeftMotorSpeed = 32000;
	vibration.wRightMotorSpeed = 16000; 
	XInputSetState( 0, &vibration ); 	
	Sleep(850);	
	vibration.wLeftMotorSpeed = 0;
	vibration.wRightMotorSpeed = 0; 
	XInputSetState( 0, &vibration );
}

static void PulseController(){
	XINPUT_VIBRATION vibration;
	ZeroMemory( &vibration, sizeof(XINPUT_VIBRATION) );

	vibration.wLeftMotorSpeed = 32000;
	vibration.wRightMotorSpeed = 16000; 
	XInputSetState( 0, &vibration ); 	
	Sleep(850);	
	vibration.wLeftMotorSpeed = 0;
	vibration.wRightMotorSpeed = 0; 
	XInputSetState( 0, &vibration );
}

typedef void (*XNOTIFYQUEUEUI)(DWORD ID, DWORD Index, DWORD r5, WCHAR* Text, DWORD r7);
XNOTIFYQUEUEUI XNotifyQueueUI;
void	hNotify(WCHAR*);
DWORD WINAPI commands(WCHAR*);

void hNotify(WCHAR* Str)
{
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)commands, Str, NULL, NULL);
}

void pop(WCHAR* Str)
{
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)commands, Str, NULL, NULL);
}

void NameNotify(const WCHAR* str)
{
	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)commands, (LPVOID)str, NULL, NULL);
}

DWORD WINAPI commands(WCHAR* Str)
{
	XNotifyQueueUI = (XNOTIFYQUEUEUI)resolveFunct("xam.xex", 0x290);
	WCHAR buffer[0x256];
	swprintf(buffer, Str);
	XNotifyQueueUI(0x22, 0x0, 2, buffer, 0);

	return 0;
}

VOID DoCave(DWORD addr, PDWORD jack, size_t length){

  switch(KrnlType){
  case 0:
   memcpy( (PDWORD)addr, jack, length);
   break;

  case 1:  
   DmSetMemoryD( (PDWORD)addr, length, jack, NULL);
   break;
  }
}

VOID Fastcave1(PDWORD addr, DWORD icode[], size_t length){

	if(KrnlType != 1){
		memcpy((void*)addr, (void*)icode, length);
	}else{
		DmSetMemoryD((void*)addr, length, (void*)icode, NULL);
	}
}


void Caveme(DWORD addr, void *patch, BYTE reg)
{
	if (reg == 0) {
		patchInJumpr0( cavedata, (DWORD)patch, false );
	}
	if (reg == 1) {
		patchInJumpr1( cavedata, (DWORD)patch, false );
	}
	if (reg == 2) {
		patchInJumpr2( cavedata, (DWORD)patch, false );
	}
	if (reg == 3) {
		patchInJumpr3( cavedata, (DWORD)patch, false );
	}
	if (reg == 4) {
		patchInJumpr4( cavedata, (DWORD)patch, false );
	}
	if (reg == 5) {
		patchInJumpr5( cavedata, (DWORD)patch, false );
	}
	if (reg == 6) {
		patchInJumpr6( cavedata, (DWORD)patch, false );
	}
	if (reg == 7) {
		patchInJumpr7( cavedata, (DWORD)patch, false );
	}
	if (reg == 8) {
		patchInJumpr8( cavedata, (DWORD)patch, false );
	}
	if (reg == 9) {
		patchInJumpr9( cavedata, (DWORD)patch, false );
	}
	if (reg == 10) {
		patchInJumpr10( cavedata, (DWORD)patch, false );
	}
	if (reg == 11) {
		patchInJumpr11( cavedata, (DWORD)patch, false );
	}
	if (reg == 12) {
		patchInJumpr12( cavedata, (DWORD)patch, false );
	}
	if (reg == 13) {
		patchInJumpr13( cavedata, (DWORD)patch, false );
	}
	if (reg == 14) {
		patchInJumpr14( cavedata, (DWORD)patch, false );
	}
	if (reg == 15) {
		patchInJumpr15( cavedata, (DWORD)patch, false );
	}
	if (reg == 16) {
		patchInJumpr16( cavedata, (DWORD)patch, false );
	}
	if (reg == 17) {
		patchInJumpr17( cavedata, (DWORD)patch, false );
	}
	if (reg == 18) {
		patchInJumpr18( cavedata, (DWORD)patch, false );
	}
	if (reg == 19) {
		patchInJumpr19( cavedata, (DWORD)patch, false );
	}
	if (reg == 20) {
		patchInJumpr20( cavedata, (DWORD)patch, false );
	}
	if (reg == 21) {
		patchInJumpr21( cavedata, (DWORD)patch, false );
	}
	if (reg == 22) {
		patchInJumpr22( cavedata, (DWORD)patch, false );
	}
	if (reg == 23) {
		patchInJumpr23( cavedata, (DWORD)patch, false );
	}
	if (reg == 24) {
		patchInJumpr24( cavedata, (DWORD)patch, false );
	}
	if (reg == 25) {
		patchInJumpr25( cavedata, (DWORD)patch, false );
	}
	if (reg == 26) {
		patchInJumpr26( cavedata, (DWORD)patch, false );
	}
	if (reg == 27) {
		patchInJumpr27( cavedata, (DWORD)patch, false );
	}
	if (reg == 28) {
		patchInJumpr28( cavedata, (DWORD)patch, false );
	}
	if (reg == 29) {
		patchInJumpr29( cavedata, (DWORD)patch, false );
	}
	if (reg == 30) {
		patchInJumpr30( cavedata, (DWORD)patch, false );
	}
	if (reg == 31) {
		patchInJumpr31( cavedata, (DWORD)patch, false );
	}
	addy1 = (PDWORD)addr; 
	addy2 = (PDWORD)(addr + 0x04);
	addy3 = (PDWORD)(addr + 0x08);
	addy4 = (PDWORD)(addr + 0x0C);
	
	Fastcave1( addy1, &cavedata[0], 4 );
	Fastcave1( addy2, &cavedata[1], 4 );
	Fastcave1( addy3, &cavedata[2], 4 );
	Fastcave1( addy4, &cavedata[3], 4 );
}

void PatchInJump(DWORD addr, DWORD codecave, BYTE reg, BYTE link)
{
	DWORD buf0 = 0x3C000000;
	DWORD buf1 = 0x60000000;

	buf0 |= (codecave >> 16);
	buf1 |= (codecave & 0xFFFF);

	buf0 |= (reg*0x200000);
	buf1 |= (reg*0x210000);

	SetDWORD(addr, buf0);
	SetDWORD(addr + 0x04, buf1);
	SetDWORD(addr + 0x08, 0x7D6903A6);
	if(link)
		SetDWORD(addr + 0x0C, 0x4E800421);
	else
		SetDWORD(addr + 0x0C, 0x4E800420);

}


static void Saveregs(){
	__asm{
		stw r10,-10h(r1) 
			stw r11,-8h(r1) 
	}
}
static void Loadregs(){
	__asm{
		lwz r10,-10h(r1) 
			lwz r11,-8h(r1) 
	}
}


DWORD GetAddr(DWORD addr_start, DWORD addr_end, DWORD *buf, DWORD buf_num, DWORD num)
{
	DWORD i, addr;

	addr = addr_start;

	while(addr < addr_end)
	{
		if((addr & 0xFFFF) == 0)
		{
			if(!MmIsAddressValid((DWORD*)addr))
			{
				addr += 0x10000;
				continue;
			}
		}

		for(i = 0; i< buf_num; i++)
		{
			if(*(DWORD*)(addr + i*4 ) != buf[i])
				break;
		}

		if(i == buf_num)
		{
			num--;
			if(num == 0)
				return addr;
		}

		addr += 4;
	}
	return 0;
}

LPCWSTR btnOk[1] =
{
	L"OK"
};

DWORD btodw(byte *b)
{
	return (b[3]) | (b[2] << 8) | (b[1] << 16) | (b[0] << 24);
}

