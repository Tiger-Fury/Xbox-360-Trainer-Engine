#ifndef _UTILITY_H
#define _UTILITY_H

// change whether TLB memory protections are in effect
#define SET_RETAIL_KEY	0
#define SET_DEV_KEY		1
#define SET_PROT_OFF	2
#define SET_PROT_ON		3
DWORD HvxSetState(DWORD key, DWORD mode);

// clean up a mount point link
HRESULT deleteLink(const char* szDrive, const char* sysStr);

// mount a path to a drive name
HRESULT MountPath(const char* szDrive, const char* szDevice, BOOL both);

// find the Export Address Table in a given module
// only works in threads with the ability to peek crypted memory
// only tested on "xam.xex" and "xboxkrnl.exe"
PIMAGE_EXPORT_ADDRESS_TABLE getModuleEat(char* modName);

// returns true if the file exists
BOOL fileExists(PCHAR path);
// returns true if the drive exists (path ie: "dlaunch:\\"
BOOL driveExists(PCHAR path);

// patches in a 4 instruction jump which uses R11/scratch reg and ctr to assemble
// addr = pointer to address being patched
// dest = address of the new destination
// linked = (true = ctr branch with link used) (false = ctr branch, link register unaffected)
VOID patchInJumpr0(PDWORD addr, DWORD dest, BOOL linked);
VOID patchInJumpr1(PDWORD addr, DWORD dest, BOOL linked);
VOID patchInJumpr2(PDWORD addr, DWORD dest, BOOL linked);
VOID patchInJumpr3(PDWORD addr, DWORD dest, BOOL linked);
VOID patchInJumpr4(PDWORD addr, DWORD dest, BOOL linked);
VOID patchInJumpr5(PDWORD addr, DWORD dest, BOOL linked);
VOID patchInJumpr6(PDWORD addr, DWORD dest, BOOL linked);
VOID patchInJumpr7(PDWORD addr, DWORD dest, BOOL linked);
VOID patchInJumpr8(PDWORD addr, DWORD dest, BOOL linked);
VOID patchInJumpr9(PDWORD addr, DWORD dest, BOOL linked);
VOID patchInJumpr10(PDWORD addr, DWORD dest, BOOL linked);
VOID patchInJumpr11(PDWORD addr, DWORD dest, BOOL linked);
VOID patchInJumpr12(PDWORD addr, DWORD dest, BOOL linked);
VOID patchInJumpr13(PDWORD addr, DWORD dest, BOOL linked);
VOID patchInJumpr14(PDWORD addr, DWORD dest, BOOL linked);
VOID patchInJumpr15(PDWORD addr, DWORD dest, BOOL linked);
VOID patchInJumpr16(PDWORD addr, DWORD dest, BOOL linked);
VOID patchInJumpr17(PDWORD addr, DWORD dest, BOOL linked);
VOID patchInJumpr18(PDWORD addr, DWORD dest, BOOL linked);
VOID patchInJumpr19(PDWORD addr, DWORD dest, BOOL linked);
VOID patchInJumpr20(PDWORD addr, DWORD dest, BOOL linked);
VOID patchInJumpr21(PDWORD addr, DWORD dest, BOOL linked);
VOID patchInJumpr22(PDWORD addr, DWORD dest, BOOL linked);
VOID patchInJumpr23(PDWORD addr, DWORD dest, BOOL linked);
VOID patchInJumpr24(PDWORD addr, DWORD dest, BOOL linked);
VOID patchInJumpr25(PDWORD addr, DWORD dest, BOOL linked);
VOID patchInJumpr26(PDWORD addr, DWORD dest, BOOL linked);
VOID patchInJumpr27(PDWORD addr, DWORD dest, BOOL linked);
VOID patchInJumpr28(PDWORD addr, DWORD dest, BOOL linked);
VOID patchInJumpr29(PDWORD addr, DWORD dest, BOOL linked);
VOID patchInJumpr30(PDWORD addr, DWORD dest, BOOL linked);
VOID patchInJumpr31(PDWORD addr, DWORD dest, BOOL linked);


// hook export table ordinals of a module, anything linked after this hook is redirected to dstFun
// modName = pointer to string of the module name to alter the export table, like "xam.xex" or "xboxkrnl.exe"
// ord = ordinal number
// dstFun = address to change ordinal link address to
// returns the address of the start of the hook patched into modName@ord
// ** note that this type of hook ONLY works on things that haven't been linked by the time the patch is made
DWORD hookExportOrd(char* modName, DWORD ord, DWORD dstFun);

// hook imported jumper stubs to a different function
// modname = module with the import to patch
// impmodname = module name with the function that was imported
// ord = function ordinal to patch
// patchAddr = destination where it is patched to
// returns TRUE if hooked
// ** NOTE THIS FUNCTION MAY STILL BE BROKEN FOR MODULES WITH MULTIPLE IMPORT TABLES OF THE SAME impmodname
BOOL hookImpStub(char* modname, char* impmodname, DWORD ord, DWORD patchAddr);

// hook a function start based on address, using 8 instruction saveStub to do the deed
// addr = address of the hook
// saveStub = address of the area to create jump stub for replaced instructions
// dest = where the hook at addr is pointing to
VOID hookFunctionStart(PDWORD addr, PDWORD saveStub, DWORD dest);

// hook a function start based on ordinal, using 8 instruction saveStub to do the deed
// modName = pointer to string of the module name to alter the export table, like "xam.xex" or "xboxkrnl.exe"
// ord = ordinal number of the function to hook in module modName
// saveStub = address of the area to create jump stub for replaced instructions
// dest = where the hook at addr is pointing to
// returns the address of the start of the hook patched into modName@ord
PDWORD hookFunctionStartOrd(char* modName, DWORD ord, PDWORD saveStub, DWORD dest);

// tries to get the data segment size and start address of named module
// modName = pointer to string of the module name to alter the export table, like "xam.xex" or "xboxkrnl.exe"
// size = pointer to a DWORD to take the size from base
BYTE* getModBaseSize(char* modName, PDWORD size);

// shows a pop up bubble onscreen, message must be multibyte
VOID notifyBubble(PSHORT mess, BYTE msgType);

DWORD resolveFunct(PCHAR modname, DWORD ord);

#endif // _UTILITY_H
