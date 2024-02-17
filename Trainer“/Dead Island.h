#include "common.h"

UINT32 g_titleID = 0x4b4d07df;

VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"More at T3furyGaming.co.uk", L"Dead Island +10 Trainer\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
}

VOID ButPress( MESSAGEBOX_RESULT g_mb_result )
{

	if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
	{
		Sleep(500);
		//this is the page that shows all available cheats  \r\n indicates create new line
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nOne Hit Kill RB(x4)\r\nInf Ammo LT(x4)\r\nInf Stamina LB(x4)\r\nInf Cash LB(x3)+RB\r\nMax XP Y(x4)\r\nInf Light/Weapons Don't Break X(x4)\r\nInf Items Y+X(x3)\r\nInf Rage Dpad Up+A\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3furyGaming.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
			hNotify(L"1 Hit Kill Deactivated");
			OneHitKo = FALSE;
			Vibr01();

		}else{

			hNotify(L"1 Hit Kill Activated");
			SetDWORD(addr_1HK, 0xD1FF0598);
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
			SetDWORD(addr_ammo, NOPThis);
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

		if( NOAmmo == TRUE )
		{
			hNotify(L"Inf Stamina Deactivated");
			NOAmmo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Stamina Activated");
			SetDWORD(addr_Stamina, NOPThis);
			NOAmmo = TRUE;
			Vibr01();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
	if( g_mb_result.rgwPasscode[0] == LEFT_BUMPER && g_mb_result.rgwPasscode[1] == LEFT_BUMPER && g_mb_result.rgwPasscode[2] == LEFT_BUMPER && g_mb_result.rgwPasscode[3] == RIGHT_BUMPER )
	{
		Sleep(500);

		if( Max_Cash == TRUE )
		{
			hNotify(L"Inf Money Deactivated");
			Max_Cash = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Money Activated");
			SetDWORD(addr_Cash, 0x90230714);
			Max_Cash = TRUE;
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

		if( Max_XP == TRUE )
		{
			hNotify(L"Max XP Deactivated");
			Max_XP = FALSE;
			Vibr01();

		}else{

			hNotify(L"Max XP Activated");
			SetDWORD(addr_XP, 0x9023003C);
			Max_XP = TRUE;
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

		if( InfLight == TRUE )
		{
			hNotify(L"Inf Light and Weapons Don't Break Deactivated");
			InfLight = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Light and Weapons Don't Break Activated");
			SetDWORD(addr_Light, NOPThis);
			SetDWORD(addr_Weapon, NOPThis);
			InfLight = TRUE;
			Vibr01();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
	if( g_mb_result.rgwPasscode[0] == Y_BUTTON && g_mb_result.rgwPasscode[1] == X_BUTTON && g_mb_result.rgwPasscode[2] == X_BUTTON && g_mb_result.rgwPasscode[3] == X_BUTTON )
	{
		Sleep(500);

		if( InfItems == TRUE )
		{
			hNotify(L"Inf Items Deactivated");
			InfItems = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Items Activated");
			SetDWORD(addr_Items, Li_r11_99);
			InfItems = TRUE;
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
		ALLCheats = FALSE;
		Vibr01();

	}else{

		hNotify(L"All Cheats Activated");
		SetDWORD(addr, NOPThis);
		SetDWORD(addr_1HK, 0xD1FF0598);
		SetDWORD(addr_ammo, NOPThis);
		SetDWORD(addr_Stamina, NOPThis);
		SetDWORD(addr_Cash, 0x90230714);
		SetDWORD(addr_XP, 0x9023003C);
		SetDWORD(addr_Light, NOPThis);
		SetDWORD(addr_Weapon, NOPThis);
		SetDWORD(addr_Items, Li_r11_99);
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

VOID Quicklaunch1()
	//wind
{
	if( InfRage == TRUE )
	{
	hNotify(L"Rage Off");
	SetDWORD(addr_Rage, 0xD01F1258);
	InfRage = FALSE;
	}else{
	hNotify(L"Rage On");
	SetDWORD(addr_Rage, NOPThis);
	InfRage = TRUE;
	}
}
VOID SearchAddr()
{
	hNotify(L"Dead Island");
	Sleep(25);


	DWORD buf_Health[] = {0xD3FF0854, 0x38210070};
	DWORD buf1HK[] = {0xD3FF0598, 0x38210070};
	DWORD buf_Ammo[] = {0x90E90000, 0x419A0020};
	DWORD buf_stam[] = {0xD1BF08B8, 0x3BCB2370};
	DWORD buf_Cash[] = {0x91630714, 0x7C9B2378};
	DWORD buf_XP[] = {0x9123003C, 0x419A002C};
	DWORD buf_Light[] = {0xD19F0034, 0xC00B2370};
	DWORD buf_Weapon[] = {0xD3FE0004, 0x38210070};
	DWORD buf_Rage[] = {0xD01F1258, 0xFF00F800};
	DWORD buf_Items[] = {0x396BFFFF, 0x7FA3EB78};

	addr = GetAddr(0x82600000, 0x83000000, buf_Health, 2, 1);
	addr_1HK = GetAddr(0x82B70000, 0x83000000, buf1HK, 2, 1);
	addr_ammo = GetAddr(0x82700000, 0x83000000, buf_Ammo,2,1);
	addr_Stamina = GetAddr(0x82000000, 0x83000000, buf_stam,2,1);
	addr_Cash = GetAddr(0x82000000, 0x83000000, buf_Cash,2,1);
	addr_XP = GetAddr(0x82800000, 0x83000000, buf_XP,2,1);
	addr_Light = GetAddr(0x82A93000, 0x83000000, buf_Light,2,1);
	addr_Weapon = GetAddr(0x82D10000, 0x83000000, buf_Weapon,2,1);
	addr_Rage = GetAddr(0x828EEf00, 0x83000000, buf_Rage,2,1);
	addr_Items = GetAddr(0x828DA010, 0x83000000, buf_Items,2,1);
	SetAddr = true;
}