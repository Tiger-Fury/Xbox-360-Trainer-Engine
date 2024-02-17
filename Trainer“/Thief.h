#include "common.h"

UINT32 g_titleID = 0x53510803;



//ADD  BOOLS

///static codes values
bool SetAddr = false;
bool InfHealth = false;
bool OneHitKo = false;
bool InfAmmo = false;
bool InfGrenade = false;
bool InfMoney = false;
bool ALLCheats = false;


BYTE nades[] = { 0x39, 0x2a, 0x27, 0x10 };
BYTE nadesoff[] = { 0x7d, 0x3a, 0x50, 0x50 };//7D3A5050             subf r9,r26,r10 //392A2710
BYTE potion[] = { 0x35, 0x6a, 0x00, 0x00 };//356A0000
BYTE potionoff[] = { 0x35, 0x6a, 0xff, 0xff };
// Cheat -----------------------------------------------------------------------------------
static DWORD addr;
static DWORD addr_ammo;
static DWORD addr_focus;
static DWORD addr_money;
static DWORD addr_Light;
//static DWORD Seal_addr;
BYTE NOP[4] = { 0x60, 0x00, 0x00, 0x00 };

// static void __declspec(naked) CodeCave_hp(void)
// {
// 	DWORD addr, addr1;
// 
// 	__asm
// 	{
// 		subf r3,r5,r4  
// 			stw r3,0(r29)  
// 			stw r3,0(r28)  
// 	}
// 
// 	__asm
// 	{
// 		stw r29,addr
// 			stw r28,addr1
// 	}
// 
// 	if(addr < 0x70000000)
// 	{
// 		if(*(DWORD*)(addr + 4) == 0x348 || *(DWORD*)(addr + 4) == 0x1FE) // player
// 		{
// 			if(InfHealth == TRUE)
// 			{
// 				*(DWORD*)addr = *(DWORD*)(addr + 4);
// 				*(DWORD*)addr1 = *(DWORD*)(addr + 4);
// 			}
// 		}
// 		else // enemy
// 		{
// 			if(OneHitKo == TRUE)
// 			{
// 				*(DWORD*)addr = 0xFFFFFFA0;
// 				*(DWORD*)addr1 = 0xFFFFFFA0;
// 			}
// 		}
// 	}
// 
// 	__asm
// 	{
// 		addi r1,r1,144  
// 			blr
// 	}
// }

// static void __declspec(naked) CodeCave_ammo(void)
// {
// 	DWORD addr1;
// 
// 	__asm
// 	{
// 		mr r11,r9
// 			lwz r9,0(r11) 
// 			stw r9,0(r29) 
// 			lwz r10,0(r11)
// 			addi r8,r10,1 
// 			stw r8,0(r11) 
// 	}
// 
// 	__asm
// 	{
// 		stw r11,addr1
// 	}
// 
// 	if(addr1 < 0x70000000)
// 	{
// 		if(*(DWORD*)(addr1 + 0x04) == 0x20 || *(DWORD*)(addr1 + 0x04) == 0x3C || *(DWORD*)(addr1 + 0x04) == 0x14)
// 		{
// 			if(InfAmmo = TRUE)
// 				*(DWORD*)addr1 = -999;
// 		}
// 	}
// 
// 	__asm
// 	{
// 		blr
// 	}
// }

// static void __declspec(naked) CodeCave_grenade(void)
// {
// 	DWORD addr;
// 
// 	__asm
// 	{
// 		lfs fr0,50h(r1)   
// 			fctiwz fr13,fr0   
// 			stfiwx fr13,r0,r31     
// 	}
// 
// 	__asm
// 	{
// 		stw r31,addr
// 	}
// 
// 	if(addr < 0x70000000)
// 	{
// 		if(*(DWORD*)(addr + 0x04) == 0x01)
// 		{
// 			if(InfGrenade = TRUE)
// 				*(DWORD*)addr = 998;
// 		}
// 	}
// 
// 	__asm
// 	{
// 		addi r1,r1,112
// 			blr
// 	}
// }

VOID TrainerLoaded()
{
	Vibr01();
	hNotify(L"t3furys XPG Exclusives\r\nTenchu Z +5 Trainer Loaded");
}

VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"~TeamXPG~ t3fury XPGamesaves.com", L"Thief Trainer\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
}

VOID ButPress( MESSAGEBOX_RESULT g_mb_result )
{

	if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
	{
		Sleep(500);
		//this is the page that shows all available cheats  \r\n indicates create new line
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\Increased Stealth RB(x4)\r\nInf Arrows/Items LT(x4)\r\nInf Focus LB(x4)\r\nInf Money Y(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nXPGamesaves.com\r\nHome To TeamXPG and 360 Revolution", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;


	}
	if( g_mb_result.rgwPasscode[0] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[1] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[2] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[3] == RIGHT_TRIGGER )
	{
		Sleep(500);

		if( InfHealth == TRUE )
		{
			hNotify(L"Inf Health Deactivated");
			SetDWORD(addr, 0xD0230094);
			InfHealth = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Health Activated");
			SetDWORD(addr, 0x60000000);
			InfHealth = TRUE;
			Vibr01();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
	if( g_mb_result.rgwPasscode[0] == RIGHT_BUMPER && g_mb_result.rgwPasscode[1] == RIGHT_BUMPER && g_mb_result.rgwPasscode[2] == RIGHT_BUMPER && g_mb_result.rgwPasscode[3] == RIGHT_BUMPER )
	{
		Sleep(500);

		if( OneHitKo == TRUE )
		{
			hNotify(L"Increased Stealth Deactivated");
			SetDWORD(addr_Light, 0xD1890020);
			OneHitKo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Increased Stealth Activated");
			SetDWORD(addr_Light, 0x60000000);
			OneHitKo = TRUE;
			Vibr01();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
	if( g_mb_result.rgwPasscode[0] == LEFT_TRIGGER && g_mb_result.rgwPasscode[1] == LEFT_TRIGGER && g_mb_result.rgwPasscode[2] == LEFT_TRIGGER && g_mb_result.rgwPasscode[3] == LEFT_TRIGGER )
	{
		Sleep(500);

		if( InfAmmo == TRUE )
		{
			hNotify(L"Inf Arrows/Items Deactivated");
			SetDWORD(addr_ammo, 0x7FFF2850);
			InfAmmo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Arrows/Items Activated");
			SetDWORD(addr_ammo, 0x3BE00063);
			InfAmmo = TRUE;
			Vibr01();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
	if( g_mb_result.rgwPasscode[0] == LEFT_BUMPER && g_mb_result.rgwPasscode[1] == LEFT_BUMPER && g_mb_result.rgwPasscode[2] == LEFT_BUMPER && g_mb_result.rgwPasscode[3] == LEFT_BUMPER )
	{
		Sleep(500);

		if( InfGrenade == TRUE )
		{
			hNotify(L"Inf Focus Deactivated");
			SetDWORD(addr_focus, 0xD01F0064);
			InfGrenade = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Focus Activated");
			SetDWORD(addr_focus, 0x60000000);
			InfGrenade = TRUE;
			Vibr01();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
	if( g_mb_result.rgwPasscode[0] == Y_BUTTON && g_mb_result.rgwPasscode[1] == Y_BUTTON && g_mb_result.rgwPasscode[2] == Y_BUTTON && g_mb_result.rgwPasscode[3] == Y_BUTTON )
	{
		Sleep(500);

		if( InfMoney == TRUE )
		{
			hNotify(L"Inf Money Deactivated");
			SetDWORD(addr_money, 0x7FE5D214);
			InfMoney = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Money Activated");
			SetDWORD(addr_money, 0x3BE54E20);
			InfMoney = TRUE;
			Vibr01();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
if( g_mb_result.rgwPasscode[0] == DPAD_UP && g_mb_result.rgwPasscode[1] == DPAD_UP && g_mb_result.rgwPasscode[2] == DPAD_UP && g_mb_result.rgwPasscode[3] == DPAD_UP )
{
	Sleep(500);

	if( ALLCheats == TRUE )
	{
		hNotify(L"All Cheats Deactivated");
		SetDWORD(addr, 0xD0230094);
		SetDWORD(addr_Light, 0xD1890020);
		SetDWORD(addr_ammo, 0x7FFF2850);
		SetDWORD(addr_focus, 0xD01F0064);
		SetDWORD(addr_money, 0x7FE5D214);
		ALLCheats = FALSE;
		Vibr01();

	}else{

		hNotify(L"All Cheats Activated");
		SetDWORD(addr, 0x60000000);
		SetDWORD(addr_Light, 0x60000000);
		SetDWORD(addr_ammo, 0x3BE00063);
		SetDWORD(addr_focus, 0x60000000);
		SetDWORD(addr_money, 0x3BE54E20);
		ALLCheats = TRUE;
		Vibr01();

	}

	memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
	memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
	memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
	memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
	Prompt = 0x9999;
}
}

//Search for TU Address
VOID SearchAddr()
{
	hNotify(L"Thief");
	Sleep(25);
	hNotify(L"Applying All TU Patch");
	Sleep(25);

	//Breakpoint-4,Breakpoint
	//DWORD addr;
	DWORD buf[] = {0xD0230094, 0x7C7E1B78};
	DWORD ammo_buf[] = {0x7FFF2850, 0x93E30000}; 
	DWORD Focus_buf[] = {0xD01F0064, 0x7FC4F378};
	DWORD Light_buf[] = {0xD1890020, 0x807F00F8};
	DWORD Money_buf[] = {0x7FE5D214, 0x7F1F1800};

	addr = GetAddr(0x82000000, 0x83000000, buf, 2, 1);
	//PatchJump(addr, (DWORD)CodeCave_hp);

	addr_ammo = GetAddr(0x82000000, 0x83000000, ammo_buf, 2, 1);
	//SetDWORD(addr - 0x04, 0x7D695B78);
	//PatchJump(addr, (DWORD)CodeCave_ammo);

	addr_focus = GetAddr(0x82000000, 0x83000000, Focus_buf, 2, 1);
	//PatchJump(addr, (DWORD)CodeCave_grenade);
	addr_Light = GetAddr(0x82000000, 0x83000000, Light_buf, 2, 1);

	addr_money = GetAddr(0x82000000, 0x83000000, Money_buf, 2, 1);
	SetAddr = true;
}