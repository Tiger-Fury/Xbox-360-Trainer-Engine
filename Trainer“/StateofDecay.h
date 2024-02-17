#include "common.h"

UINT32 g_titleID = 0x584111E8;

DWORD addi_r9_255 = 0x392900FF;

DWORD buf[] = {0x419A001C, 0xD03F00A4};
DWORD Stamina_buf[] = {0x4D9A0020, 0xD02B00AC};
DWORD Ammo_buf[] = {0x419A000C, 0x938B0010};
DWORD Silencer_buf[] = {0x7D6B5214, 0x9BAB0005};
DWORD Weapon_buf[] = {0x1D5E0006, 0x7FAA5B2E};
DWORD Invent_buf[] = {0x7D2B50AE, 0x7D29EA14};
DWORD Invent2_buf[] = {0x7D2A58AE, 0x7D29EA14};



VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"More at T3furyGaming.co.uk", L"State of Decay + 6\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
}


VOID ButPress( MESSAGEBOX_RESULT g_mb_result )
{

	if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
	{
		Sleep(500);
		//this is the page that shows all available cheats  \r\n indicates create new line
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nWeapons Don't Break RB(x4)\r\nInf Ammo LT(x4)\r\nInf Stamina LB(x4)\r\nInf Silencer X(x4)\r\nInf Items Y(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3furyGaming.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
			SetDWORD(addr, 0xD03F00A4);
			InfHealth = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Health Activated");
			SetDWORD(addr, NOPThis);
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
			hNotify(L"Weapons Don't Break Deactivated");
			SetDWORD(addr1, 0x7FAA5B2E);
			OneHitKo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Weapons Don't Break Activated");
			SetDWORD(addr1, NOPThis);
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
			SetDWORD(addr_ammo,0x938B0010);
			InfAmmo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Ammo Activated");
			SetDWORD(addr_ammo,0x920B0010);
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

		if( NoWeight == TRUE )
		{
			hNotify(L"Inf Stamina Deactivated");
			SetDWORD(addr_Stamina,0xD02B00AC);
			NoWeight = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Stamina Activated");
			SetDWORD(addr_Stamina,NOPThis);
			NoWeight = TRUE;
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

		if( InfItems == TRUE )
		{
			hNotify(L"Inf items Deactivated");
			SetDWORD(addr_Items,0x7D29EA14);
			SetDWORD(addr_Gren,0x7D29EA14);
			InfItems = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf items Activated");
			SetDWORD(addr_Items,Addi_r9_99);
			SetDWORD(addr_Gren,Addi_r9_99);
			InfItems = TRUE;
			Vibr01();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
	if( g_mb_result.rgwPasscode[0] == X_BUTTON && g_mb_result.rgwPasscode[1] == X_BUTTON && g_mb_result.rgwPasscode[2] == X_BUTTON && g_mb_result.rgwPasscode[3] == X_BUTTON )
	{
		Sleep(500);

		if( Max_XP == TRUE )
		{
			hNotify(L"Inf Silencer Deactivated");
			SetDWORD(addr_Silencer, 0x9BAB0005);
			Max_XP = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Silencer Activated");
			SetDWORD(addr_Silencer, NOPThis);
			Max_XP = TRUE;
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
			SetDWORD(addr, 0xD03F00A4);
			SetDWORD(addr1, 0x7FAA5B2E);
			SetDWORD(addr_ammo,0x938B0010);
			SetDWORD(addr_Silencer, 0x9BAB0005);
			SetDWORD(addr_Items,0x7D29EA14);
			SetDWORD(addr_Gren,0x7D29EA14);
			SetDWORD(addr_Stamina,0xD02B00AC);
			ALLCheats = FALSE;
			Vibr01();

		}else{

			hNotify(L"All Cheats Activated");
			SetDWORD(addr, NOPThis);
			SetDWORD(addr1, NOPThis);
			SetDWORD(addr_ammo,0x920B0010);
			SetDWORD(addr_Silencer, NOPThis);
			SetDWORD(addr_Items,Addi_r9_99);
			SetDWORD(addr_Gren,Addi_r9_99);
			SetDWORD(addr_Stamina,NOPThis);
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


VOID SearchAddr()
{
	hNotify(L"State Of Decay");
	Sleep(25);

	addr = GetAddr(0x83000000, 0x84000000, buf, 2, 1)+ 0x04;
	addr1 = GetAddr(0x83000000, 0x84000000, Weapon_buf, 2, 1)+ 0x04;
	addr_Stamina = GetAddr(0x83000000, 0x84000000, Stamina_buf, 2, 1)+ 0x04;
	addr_ammo = GetAddr(0x83000000, 0x84000000, Ammo_buf, 2, 1)+ 0x04;
	addr_Silencer = GetAddr(0x83000000, 0x84000000, Silencer_buf, 2, 1)+ 0x04;
	addr_Items = GetAddr(0x83000000, 0x84000000, Invent_buf, 2, 1)+ 0x04;
	addr_Gren = GetAddr(0x83000000, 0x84000000, Invent2_buf, 2, 1)+ 0x04;
	Static_Menu = Null_Menu;
}
