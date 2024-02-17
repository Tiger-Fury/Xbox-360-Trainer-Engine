#include "common.h"

UINT32 g_titleID = 0x4B4E083C;

DWORD buf[] = {0xB3D90000, 0x38600000};
DWORD buf_check[] = {0x816900C8, 0x7F0B5040};
DWORD buf_check1[] = {0x7C7BE82A, 0x7FE4FB78};
DWORD buf_check2[] = {0x888A0000, 0xE87B0000};


static void MGSPWStatics(){
	DWORD addr;

	if(InfAmmo == TRUE)
	{

		addr = GetDWORD(0x833F2CC0) + 0xB4;
		if(GetWORD(addr + 0x02) == 0)
		{
			Sleep(3000);
			return;
		}
		SetWORD(addr, GetWORD(addr + 0x02));
		SetBYTE(addr - 0x05, 0x1E);
		SetWORD(addr + 0x10, GetWORD(addr + 0x12));
		SetBYTE(addr + 0x10 - 0x05, 0x1E);
		SetWORD(addr + 0x20, GetWORD(addr + 0x22));
	}
}

VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"More at T3furyGaming.co.uk", L"MGS Peace Walker + 3\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
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
			hNotify(L"Inf Health Deactivated");
			SetDWORD(addr_Health, 0xB3D90000);
			InfHealth = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Health Activated");
		//	SetDWORD(0x82904D20, NOPThis);
			SetDWORD(addr_Health, NOPThis);
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
	if( g_mb_result.rgwPasscode[0] == DPAD_UP && g_mb_result.rgwPasscode[1] == DPAD_UP && g_mb_result.rgwPasscode[2] == DPAD_UP && g_mb_result.rgwPasscode[3] == DPAD_UP )
	{
		Sleep(500);

		if( ALLCheats == TRUE )
		{
			hNotify(L"All Cheats Deactivated");
			SetDWORD(addr_Health, 0xB3D90000);
			InfAmmo = FALSE;
			ALLCheats = FALSE;
			Vibr01();

		}else{

			hNotify(L"All Cheats Activated");
			SetDWORD(addr_Health, NOPThis);
			InfAmmo = TRUE;
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
	hNotify(L"Metal Gear Solid Peace Walker");
	Sleep(25);
	
	Check_Remove = GetAddr(0x82000000, 0x83000000, buf_check, 2, 1)+ 0x04;
	Check_Remove1 = GetAddr(0x82000000, 0x83000000, buf_check, 2, 2)+ 0x04;
	Check_Remove2 = GetAddr(0x82000000, 0x83000000, buf_check1, 2, 1)+ 0x0C;
	Check_Remove3 = GetAddr(0x82000000, 0x83000000, buf_check2, 2, 1)+ 0x0C;

	SetDWORD(Check_Remove2, 0x7F000040);
	SetDWORD(Check_Remove3, 0x7F000040);
	SetDWORD(Check_Remove, 0x7F0A5040);
	SetDWORD(Check_Remove1, 0x7F0A5040);

	addr_Health = GetAddr(0x82000000, 0x83000000, buf, 2, 1);

	Static_Menu = MGSPWStatics;
}