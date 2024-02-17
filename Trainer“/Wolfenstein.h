#include "common.h"

UINT32 g_titleID = 0x415607DE;



//ADD  BOOLS

///static codes values
bool SetAddr = false;
bool InfHealth = false;
bool OneHitKo = false;
bool InfAmmo = false;
bool InfGrenade = false;
bool ALLCheats = false;



// Cheat -----------------------------------------------------------------------------------
static DWORD addr;
static DWORD Ammo_addr;
static DWORD Gold_addr;
static DWORD Veil_addr;
//static DWORD Seal_addr;
BYTE NOP[4] = { 0x60, 0x00, 0x00, 0x00 };


VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"~TeamXPG~ t3fury XPGamesaves.com", L"Perfect Dark Trainer\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
}

VOID ButPress( MESSAGEBOX_RESULT g_mb_result )
{

	if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
	{
		Sleep(500);
		//this is the page that shows all available cheats  \r\n indicates create new line
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nInf Ammo LT(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nXPGamesaves.com\r\nHome To TeamXPG and 360 Revolution", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
			SetDWORD(addr, 0xD01F00D8);
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

		if( InfHealth == TRUE )
		{
			hNotify(L"Inf Veil Deactivated");
			SetDWORD(Veil_addr, 0xEC000828);
			InfHealth = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Veil Activated");
			SetDWORD(Veil_addr, 0xEC00082A);
			InfHealth = TRUE;
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
			hNotify(L"Inf Ammo Deactivated");
			SetDWORD(Ammo_addr, 0xD0030038);
			InfAmmo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Ammo Activated");
			SetDWORD(Ammo_addr, 0x60000000);
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

		if( InfAmmo == TRUE )
		{
			hNotify(L"Inf Gold Deactivated");
			SetDWORD(Gold_addr, 0x7D6BE214);
			InfAmmo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Gold Activated");
			SetDWORD(Gold_addr, 0x7D6B5A14);
			InfAmmo = TRUE;
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
		SetDWORD(Ammo_addr, 0xD0030038);
		SetDWORD(addr, 0xD18B00E4);
		SetDWORD(Gold_addr, 0x7D6BE214);
		SetDWORD(Veil_addr, 0xEC000828);
		ALLCheats = FALSE;
		Vibr01();

	}else{

		hNotify(L"All Cheats Activated");
		SetDWORD(Ammo_addr, 0x60000000);
		SetDWORD(addr, 0x60000000);
		SetDWORD(Gold_addr, 0x7D6B5A14);
		SetDWORD(Veil_addr, 0xEC00082A);
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
	hNotify(L"Wolfenstein");
	Sleep(25);
	hNotify(L"Applying All TU Patch");
	Sleep(25);

	//Breakpoint-4,Breakpoint
	//DWORD addr;
	DWORD buf[] = {0xD01F00D8, 0x3D0082CC};
	DWORD ammo_buf[] = {0xD0030038, 0x2F04001E}; 
	DWORD Gold_buf[] = {0x7D6BE214, 0x614A6493};
	DWORD Veil_buf[] = {0xEC000828, 0xD0030008};
//	DWORD grenade_buf[] = {0x7DA0FFAE, 0x38210070};

	addr = GetAddr(0x82100000, 0x83000000, buf, 2, 1);
	//PatchJump(addr, (DWORD)CodeCave_hp);

	Ammo_addr = GetAddr(0x82000000, 0x83000000, ammo_buf, 2, 1);
	Gold_addr = GetAddr(0x82000000, 0x83000000, Gold_buf, 2, 1);
	Veil_addr = GetAddr(0x82000000, 0x83000000, Veil_buf, 2, 1);
	//PatchJump(addr, (DWORD)CodeCave_ammo);

//	addr = GetAddr(0x82000000, 0x83000000, grenade_buf, 2, 1) - 0x08;
	//PatchJump(addr, (DWORD)CodeCave_grenade);
	SetAddr = true;
}