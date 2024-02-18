#include "common.h"

UINT32 g_titleID = 0x5345080C;



//ADD  BOOLS

///static codes values
bool SetAddr = false;
bool InfHealth = false;
bool OneHitKo = false;
bool InfAmmo = false;
bool InfGrenade = false;
bool ALLCheats = false;


BYTE nades[] = { 0x39, 0x2a, 0x27, 0x10 };
BYTE nadesoff[] = { 0x7d, 0x3a, 0x50, 0x50 };//7D3A5050             subf r9,r26,r10 //392A2710
BYTE potion[] = { 0x35, 0x6a, 0x00, 0x00 };//356A0000
BYTE potionoff[] = { 0x35, 0x6a, 0xff, 0xff };
// Cheat -----------------------------------------------------------------------------------
static DWORD Renown_addr;
static DWORD seal_addr;
static DWORD item_addr;
static DWORD Money_addr;
static DWORD Money1_addr;
//static DWORD Seal_addr;
BYTE NOP[4] = { 0x60, 0x00, 0x00, 0x00 };

static void __declspec(naked) CodeCave_hp(void)
{
	DWORD addr, addr1;

	__asm
	{
			mr r2,r11
			li r10,0 
			stw r10,8(r11)  
			stfs fr1,370h(r31)
			lwz r11,0C4h(r31) 
	}

	__asm
	{
		stw r5,addr
	}

		if(*(DWORD*)(addr +4) == 0xF70048604 || *(DWORD*)(addr+4) == 0x970048604) // player
		{
			if(InfHealth = TRUE)
			{
				*(DWORD*)addr = *(DWORD*)(addr);
				*(DWORD*)addr1 = *(DWORD*)(addr);
			}
		}
		else // enemy
		{
			if(OneHitKo = TRUE)
			{
				*(DWORD*)addr = 0;
				*(DWORD*)addr1 = 0;
			}
		}
	

	__asm
	{  
			blr
	}
}

static void __declspec(naked) CodeCave_ammo(void)
{
	DWORD addr, addr1;

	__asm
	{
		lwz r11,0(r30) 
			addi r10,r11,1 
			stw r10,0(r30) 
	}

	__asm
	{
		stw r30,addr1
			stw r1,addr
	}

	if(addr == 0x7004D9D0 || addr == 0x70049B80)
	{
		if(InfAmmo = TRUE)
			*(DWORD*)addr1 = 0;
	}

	__asm
	{
		addi r1,r1,128 
			blr
	}
}

static void __declspec(naked) CodeCave_grenade(void)
{
	DWORD addr;

	__asm
	{
		lfs fr0,50h(r1)   
			fctiwz fr13,fr0   
			stfiwx fr13,r0,r31     
	}

	__asm
	{
		stw r31,addr
	}

	if(*(DWORD*)(addr + 0x04) == 0x01)
	{
		if(InfGrenade = TRUE)
			*(DWORD*)addr = 998;
	}

	__asm
	{
		addi r1,r1,112
			blr
	}
}

VOID TrainerLoaded()
{
	Vibr01();
	hNotify(L"t3furys XPG Exclusives\r\nTenchu Z +5 Trainer Loaded");
}

VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"~TeamXPG~ t3fury XPGamesaves.com", L"Gears of War Judgment Trainer\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
}

VOID ButPress( MESSAGEBOX_RESULT g_mb_result )
{

	if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
	{
		Sleep(500);
		//this is the page that shows all available cheats  \r\n indicates create new line
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\1 Hit Kill RB(x4)\r\nInf Ammo LT(x4)\r\nInf Grenades LB(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nXPGamesaves.com\r\nHome To TeamXPG and 360 Revolution", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
			InfHealth = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Health Activated");
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
			hNotify(L"One Hit Kill Deactivated");
			OneHitKo = FALSE;
			Vibr01();

		}else{

			hNotify(L"One Hit Kill Activated");
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
			hNotify(L"Inf Ammo Deactivated");
			InfAmmo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Ammo Activated");
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
			hNotify(L"Inf Grenade Deactivated");
			InfGrenade = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Grenade Activated");
			InfGrenade = TRUE;
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
		InfHealth = FALSE;
		OneHitKo = FALSE;
		InfAmmo = FALSE;
		InfGrenade = FALSE;
		ALLCheats = FALSE;
		Vibr01();

	}else{

		hNotify(L"All Cheats Activated");
		InfHealth = TRUE;
		OneHitKo = TRUE;
		InfAmmo = TRUE;
		InfGrenade = TRUE;
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

	hNotify(L"Gears of War 2");
	Sleep(25);
	hNotify(L"Applying All TU Patch");
	Sleep(25);

	//Breakpoint-4,Breakpoint
	DWORD addr;
	DWORD buf[] = {0xD03F0370, 0x914B0008};
	DWORD ammo_buf[] = {0x394B0001, 0x915E0000}; 
	DWORD grenade_buf[] = {0x7DA0FFAE, 0x38210070};

	addr = GetAddr(0x82000000, 0x83000000, buf, 2, 1); + 0x04;
	PatchJump(addr, (DWORD)CodeCave_hp);

	addr = GetAddr(0x82000000, 0x83000000, ammo_buf, 2, 1) - 0x04;
	PatchJump(addr, (DWORD)CodeCave_ammo);

	addr = GetAddr(0x82000000, 0x83000000, grenade_buf, 2, 1) - 0x08;
	PatchJump(addr, (DWORD)CodeCave_grenade);
	SetAddr = true;
	

}
