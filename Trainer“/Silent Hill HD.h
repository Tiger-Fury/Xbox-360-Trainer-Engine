#include "common.h"

UINT32 g_titleID = 0x4B4E0845;

DWORD buf[] = {0xEC000828, 0xD01E0154};
DWORD buf1[] = {0xEDA1682A, 0xD01E019C};
DWORD bufAmmo[] = {0x554A043F, 0x7D49432E};
DWORD bufAmmo1[] = {0x5508043F, 0x7D0B532E};

VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"More at T3furyGaming.co.uk", L"Silent Hill HD Trainer\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
}

VOID ButPress( MESSAGEBOX_RESULT g_mb_result )
{

	if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
	{
		Sleep(500);
		//this is the page that shows all available cheats  \r\n indicates create new line
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nInf Ammo LT(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3furyGaming.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
			if(Gamexex == 1)

			{
			hNotify(L"Inf Health Deactivated");
			SetDWORD(addr, 0xD01E0154);
			InfHealth = FALSE;
			Vibr01();
			}
			if(Gamexex == 2)
			{
				hNotify(L"Inf Health Deactivated");
				SetDWORD(addr, 0xD01E019C);
				InfHealth = FALSE;
				Vibr01();
			}
		}else{
			if(Gamexex >= 1)
			{
			hNotify(L"Inf Health Activated");			
			SetDWORD(addr, NOPThis);
			InfHealth = TRUE;
			Vibr01();
			}
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
			if(Gamexex == 1)
			{
			hNotify(L"Inf Ammo Deactivated");
			SetDWORD(addr_ammo, 0x7D49432E);
			InfAmmo = FALSE;
			Vibr01();
			}
			if(Gamexex == 2)
			{
				hNotify(L"Inf Ammo Deactivated");
				SetDWORD(addr_ammo, 0x7D0B532E);
				InfAmmo = FALSE;
				Vibr01();
			}
		}else{

			if(Gamexex >= 1)
			{
			hNotify(L"Inf Ammo Activated");
			SetDWORD(addr_ammo, NOPThis);
			InfAmmo = TRUE;
			Vibr01();
			}
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
		if(Gamexex == 1)
		{
		hNotify(L"All Cheats Deactivated");
		SetDWORD(addr, 0xD01E0154);
		SetDWORD(addr_ammo, 0x7D49432E);
		ALLCheats = FALSE;
		Vibr01();
		}
		if(Gamexex == 2)
		{
			hNotify(L"All Cheats Deactivated");
			SetDWORD(addr, 0xD01E019C);
			SetDWORD(addr_ammo, 0x7D0B532E);
			ALLCheats = FALSE;
			Vibr01();
		}
	}else{

		if(Gamexex >= 1)
		{
		hNotify(L"All Cheats Activated");
		SetDWORD(addr, NOPThis);
		SetDWORD(addr_ammo, NOPThis);
		ALLCheats = TRUE;
		Vibr01();
		}
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

	if (GetDWORD(0x82094B04) == 0x4801459D)
	{
		hNotify(L"Welcome to Silent Hill");
		Gamexex = 0;
		Sleep(25);
	}
	else if (GetDWORD(0x82094B04) == 0x40001503)
	{
		hNotify(L"Silent Hill 2");
		Gamexex = 1;
		Sleep(25);
		addr = GetAddr(0x82000000, 0x83000000, buf, 2, 1)+0x04;
		addr_ammo = GetAddr(0x82000000, 0x83000000, bufAmmo, 2, 1)+0x04;
		SetAddr = true;
	}
	else if (GetDWORD(0x82094B04) == 0x00000000)
	{
		hNotify(L"Silent Hill 3");
		Gamexex = 2;
		Sleep(25);
		addr = GetAddr(0x82000000, 0x83000000, buf1, 2, 1)+0x04;
		addr_ammo = GetAddr(0x82000000, 0x83000000, bufAmmo1, 2, 1)+0x04;
		SetAddr = true;
	}


}