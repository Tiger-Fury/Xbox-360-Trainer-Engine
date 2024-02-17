#include "common.h"


UINT32 g_titleID = 0x584107FE;

DWORD buf[] = {0x2B0B0000, 0x915F15F0};
DWORD Nukebuf[] = {0x556B3032, 0x913F15F8};
DWORD Skillbuf[] = {0x917E15EC, 0x38810050};
DWORD Grenbuf[] = {0x396B0D20, 0x913F15F4};


VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"More at T3furyGaming.co.uk", L"Assault Heroes + 4\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);

}

VOID ButPress( MESSAGEBOX_RESULT g_mb_result )
{

	if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
	{
		Sleep(500);
		//this is the page that shows all available cheats  \r\n indicates create new line
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Lives RT(x4)\r\nInf Grenades RB(x4)\r\n30k Score LT(x4)\r\nInf Nukes LB(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3furyGaming.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
			hNotify(L"Inf Lives Deactivated");
			SetDWORD(/*0x82121014*/addr,0x913f15f8);
			InfHealth = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Lives Activated");
			SetDWORD(/*0x82121014*/addr,NOPThis);
			InfHealth = TRUE;
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

		if( OneHitKo == TRUE )
		{
			hNotify(L"Inf Nukes Deactivated");
			SetDWORD(/*0x82121014*/addr_Special, 0x913f15f8);
			OneHitKo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Nukes Activated");
			SetDWORD(/*0x82121014*/addr_Special, NOPThis);
			OneHitKo = TRUE;
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

		if( InfAmmo == TRUE )
		{
			hNotify(L"Inf Grenades Deactivated");
			SetDWORD(/*0x8211C4F8*/addr_Gren,0x913f15f4);
			InfAmmo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Grenades Activated");
			SetDWORD(/*0x8211C4F8*/addr_Gren, NOPThis);
			InfAmmo = TRUE;
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

		if( InfGrenade == TRUE )
		{
			hNotify(L"30k Scores Deactivated");
			SetDWORD(/*0x8211E358*/addr_Skill, 0x7D6A5A14);
			InfGrenade = FALSE;
			Vibr01();

		}else{

			hNotify(L"30k Scores Activated");
			SetDWORD(/*0x8211E358*/addr_Skill, 0x396A7530);
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

	if(ALLCheats == TRUE )
	{
		hNotify(L"All Cheats Deactivated");
		SetDWORD(/*0x8211E358*/addr_Skill, 0x7D6A5A14);
		SetDWORD(/*0x8211C4F8*/addr_Gren,0x913f15f4);
		SetDWORD(/*0x82121014*/addr_Special, 0x913f15f8);
		SetDWORD(/*0x8211B554*/addr,0x913f15f8);
		ALLCheats = FALSE;
		Vibr01();

	}else{

		hNotify(L"All Cheats Activated");
		SetDWORD(/*0x8211E358*/addr_Skill, 0x396A7530);
		SetDWORD(/*0x8211C4F8*/addr_Gren, NOPThis);
		SetDWORD(/*0x82121014*/addr_Special, NOPThis);
		SetDWORD(/*0x8211B554*/addr,NOPThis);
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

	hNotify(L"Assault Heroes");
	Sleep(25);
	addr = GetAddr(0x82000000, 0x83000000, buf, 2, 1)+0x04;
	addr_Skill = GetAddr(0x82000000, 0x83000000, Skillbuf, 2, 1)-0x04;
	addr_Special = GetAddr(0x82000000, 0x83000000, Nukebuf, 2, 1)+ 0x04;
	addr_Gren = GetAddr(0x82000000, 0x83000000, Grenbuf, 2, 1)+ 0x04;
	SetAddr = true;
}