#include "common.h"

UINT32 g_titleID = 0x4343081C;

DWORD buf[] = {0x7D1F4850, 0xB10B4FB4};
DWORD bufAmmo[] = {0xB15E0008, 0x38210080};
DWORD bufCash[] = {0x7D035850, 0x7FCAF378};
DWORD bufarrow[] = {0xB1640002, 0xA1640002};
DWORD bufGren[] = {0xB1640002, 0xA1640002};

VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"TeamXPG t3fury XPGamesaves.com", L"Resident Evil 4 + 5\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);

}


VOID ButPress( MESSAGEBOX_RESULT g_mb_result )
{

	if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
	{
		Sleep(500);
		//this is the page that shows all available cheats  \r\n indicates create new line
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nInf Arrows RB(x4)\r\nInf Ammo LT(x4)\r\nInf Grenades LB(x4)\r\nInf Cash Y(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nXPGamesaves.com\r\nHome To 360 Revolution", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;


	}
	if(  g_mb_result.rgwPasscode[0] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[1] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[2] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[3] == RIGHT_TRIGGER )
	{
		Sleep(500);

		if( InfHealth == TRUE )
		{
			hNotify(L"Inf Health Deactivated");
			SetDWORD(addr,0xB10B4FB4);
			InfHealth = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Health Activated");
			SetDWORD(addr,NOPThis);
			InfHealth = TRUE;
			Vibr01();

		}
		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
	if(  g_mb_result.rgwPasscode[0] == RIGHT_BUMPER && g_mb_result.rgwPasscode[1] == RIGHT_BUMPER && g_mb_result.rgwPasscode[2] == RIGHT_BUMPER && g_mb_result.rgwPasscode[3] == RIGHT_BUMPER )
	{
		Sleep(500);

		if( OneHitKo == TRUE )
		{
			hNotify(L"Inf Arrows Deactivated");
			SetDWORD(addr_arrows,0x396BFFFF);
			OneHitKo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Arrows Activated");
			SetDWORD(addr_arrows,0x396B0000);
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
			SetDWORD(addr_ammo,0x394BFFFF);
			InfAmmo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Ammo Activated");
			SetDWORD(addr_ammo,0x394B0000);
			InfAmmo = TRUE;
			Vibr01();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
	if( g_mb_result.rgwPasscode[0] == LEFT_BUMPER && g_mb_result.rgwPasscode[1] == LEFT_BUMPER && g_mb_result.rgwPasscode[2] == LEFT_BUMPER && g_mb_result.rgwPasscode[3] == LEFT_BUMPER)
	{
		Sleep(500);

		if( Max_XP == TRUE )
		{
			hNotify(L"Inf Grenade Deactivated");
			SetDWORD(addr_Gren,0x396BFFFF);
			Max_XP = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Grenade Activated");
			SetDWORD(addr_Gren,0x396B0000);
			Max_XP = TRUE;
			Vibr01();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
	if( g_mb_result.rgwPasscode[0] == Y_BUTTON && g_mb_result.rgwPasscode[1] == Y_BUTTON && g_mb_result.rgwPasscode[2] == Y_BUTTON && g_mb_result.rgwPasscode[3] == Y_BUTTON)
	{
		Sleep(500);

		if( Max_XP == TRUE )
		{
			hNotify(L"Inf Cash Deactivated");
			SetDWORD(addr_Cash,0x7D035850);
			Max_XP = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Cash Activated");
			SetDWORD(addr_Cash,0x3D0000A0);
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

	if(ALLCheats == TRUE )
	{
		hNotify(L"All Cheats Deactivated");
		SetDWORD(addr_ammo,0x394BFFFF);
		SetDWORD(addr_Cash,0x7D035850);
		SetDWORD(addr_Gren,0x396BFFFF);
		SetDWORD(addr_arrows,0x396BFFFF);
		SetDWORD(addr,0xB10B4FB4);
		ALLCheats = FALSE;
		Vibr01();

	}else{

		hNotify(L"All Cheats Activated");
		SetDWORD(addr_ammo,0x394B0000);
		SetDWORD(addr_Cash,0x3D0000A0);
		SetDWORD(addr_Gren,0x396B0000);
		SetDWORD(addr_arrows,0x396B0000);
		SetDWORD(addr,NOPThis);
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
	hNotify(L"Resident Evil 4");
	Sleep(25);
  	addr = GetAddr(0x82000000, 0x83000000, buf, 2, 1)+ 0x04;
 	addr_ammo = GetAddr(0x82000000, 0x83000000, bufAmmo, 2, 1)- 0x0C;
 	addr_Cash = GetAddr(0x82000000, 0x83000000, bufCash, 2, 1);
	addr_arrows = GetAddr(0x82000000, 0x83000000, bufarrow, 2, 2)-0x04;
	addr_Gren = GetAddr(0x82000000, 0x83000000, bufarrow, 2, 1)-0x04;
	SetAddr = true;
}//