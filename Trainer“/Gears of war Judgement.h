#include "common.h"

UINT32 g_titleID = 0x4D530A26;



static void __declspec(naked) CodeCave_hp(void)
{
	DWORD addr, addr1;

	__asm
	{
		subf r3,r5,r4  
			stw r3,0(r29)  
			stw r3,0(r28)  
	}

	__asm
	{
		stw r29,addr
			stw r28,addr1
	}

	if(addr < 0x70000000)
	{
		if(*(DWORD*)(addr + 4) == 0x348 || *(DWORD*)(addr + 4) == 0x1FE) // player
		{
			if(InfHealth == TRUE)
			{
				*(DWORD*)addr = *(DWORD*)(addr + 4);
				*(DWORD*)addr1 = *(DWORD*)(addr + 4);
			}
		}
		else // enemy
		{
			if(OneHitKo == TRUE)
			{
				*(DWORD*)addr = 0xFFFFFFA0;
				*(DWORD*)addr1 = 0xFFFFFFA0;
			}
		}
	}

	__asm
	{
		addi r1,r1,144  
			blr
	}
}

static void __declspec(naked) CodeCave_ammo(void)
{
	DWORD addr1;

	__asm
	{
		mr r11,r9
			lwz r9,0(r11) 
			stw r9,0(r29) 
			lwz r10,0(r11)
			addi r8,r10,1 
			stw r8,0(r11) 
	}

	__asm
	{
		stw r11,addr1
	}

	if(addr1 < 0x70000000)
	{
		if(*(DWORD*)(addr1 + 0x04) == 0x20 || *(DWORD*)(addr1 + 0x04) == 0x3C || *(DWORD*)(addr1 + 0x04) == 0x14)
		{
			if(InfAmmo = TRUE)
				*(DWORD*)addr1 = -999;
		}
	}

	__asm
	{
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

	if(addr < 0x70000000)
	{
		if(*(DWORD*)(addr + 0x04) == 0x01)
		{
			if(InfGrenade = TRUE)
				*(DWORD*)addr = 998;
		}
	}

	__asm
	{
		addi r1,r1,112
			blr
	}
}


VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"More at T3furyGaming.co.uk", L"Gears of War Judgment + 4\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
}

VOID ButPress( MESSAGEBOX_RESULT g_mb_result )
{

	if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
	{
		Sleep(500);
		//this is the page that shows all available cheats  \r\n indicates create new line
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\1 Hit Kill RB(x4)\r\nInf Ammo LT(x4)\r\nInf Grenades LB(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3furyGaming.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
	hNotify(L"Gears of War Judgment");
	Sleep(25);

	//Breakpoint-4,Breakpoint
	DWORD addr;
	DWORD buf[] = {0x7C652050, 0x907D0000};
	DWORD ammo_buf[] = {0x390A0001, 0x910B0000}; 
	DWORD grenade_buf[] = {0x7DA0FFAE, 0x38210070};

	addr = GetAddr(0x82000000, 0x83000000, buf, 2, 1);
	PatchJump(addr, (DWORD)CodeCave_hp);

	addr = GetAddr(0x82000000, 0x83000000, ammo_buf, 2, 1) - 0x08;
	SetDWORD(addr - 0x04, 0x7D695B78);
	PatchJump(addr, (DWORD)CodeCave_ammo);

	addr = GetAddr(0x82000000, 0x83000000, grenade_buf, 2, 1) - 0x08;
	PatchJump(addr, (DWORD)CodeCave_grenade);
	SetAddr = true;
}