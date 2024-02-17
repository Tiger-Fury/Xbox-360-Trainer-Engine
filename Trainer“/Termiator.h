#include "common.h"

UINT32 g_titleID = 0x4d530a95;

DWORD MYPtr1;
DWORD MYPtr2;

DWORD buf[] = {0x41820370, 0xC01A0000};
DWORD bufAmmo[] = {0x812B0064, 0x3929FFFF};
DWORD bufGren[] = {0x817D0000, 0x396BFFFF};
DWORD bufAfter[] = {0x4BF13A31, 0xC01F0000};
DWORD XPValue = 0x497423F0;

VOID __declspec(naked) CheckHealth(VOID)
{ 


	__asm{
		lwz r11,0(r5)
		stw r11,0(r24) 
		  
			mflr r18
	}

	Saveregs();

	__asm {
		mr MYPtr1,r5
		mr MYPtr2,r24
	}

	if( *(DWORD*)(MYPtr1) == 0x42200000 ||  *(DWORD*)(MYPtr2) == 0x42200000 && InfHealth == TRUE ) {
		 {


			*(DWORD*)(MYPtr1) = 0x42200000;
			*(DWORD*)(MYPtr2) = 0x42200000;

		}
	}else{
		if( InfHealth == FALSE )
		{
			__asm{

			}
		}


	}
	Loadregs();



	__asm{
		lwz r10,4(r5)
		stw r10,4(r24)

			mtlr r18
			lis r18,0x826b  
			ori r18,r18,0xf0dc
			mtctr r18
			bctr


	}



}


VOID SetHooks()
{
	Caveme(0x826bf0cc,CheckHealth,18);
	HooksSet = true;
}

VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"More at T3furyGaming.co.uk", L"Air Conflicts Vietnam + 4\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
	if( HooksSet == false )
	{
		SetHooks();
	}
}


VOID ButPress( MESSAGEBOX_RESULT g_mb_result )
{

	if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
	{
		Sleep(500);
		//this is the page that shows all available cheats  \r\n indicates create new line
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nInf AfterBurner RB(x4)\r\nInf Cannon LT(x4)\r\nInf Flares LB(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3furyGaming.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
			hNotify(L"Inf AfterBurner Deactivated");
			SetDWORD(addr_After,0xEC000828);
			OneHitKo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf AfterBurner Activated");
			SetDWORD(addr_After,NOPThis);
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
			hNotify(L"Inf Cannon Deactivated");
			SetDWORD(addr_ammo,0x3929FFFF);
			InfAmmo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Cannon Activated");
			SetDWORD(addr_ammo,0x39290000);
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
			hNotify(L"Inf Flares Deactivated");
			SetDWORD(addr_Gren,0x396BFFFF);
			InfGrenade = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Flares Activated");
			SetDWORD(addr_Gren,0x396B0000);
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
		SetDWORD(addr_After,0xEC000828);
		SetDWORD(addr_ammo,0x3929FFFF);
		SetDWORD(addr_Gren,0x396BFFFF);
		InfHealth = FALSE;
		ALLCheats = FALSE;
		Vibr01();

	}else{

		hNotify(L"All Cheats Activated");
		SetDWORD(addr_After,NOPThis);
		SetDWORD(addr_ammo,0x39290000);
		SetDWORD(addr_Gren,0x396B0000);
		InfHealth = TRUE;
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
	hNotify(L"Air Conflicts Vietnam");
	Sleep(25);
	addr = GetAddr(0x82000000, 0x83000000, buf, 2, 1)+ 0x04;
	addr_ammo = GetAddr(0x82000000, 0x83000000, bufAmmo, 2, 1)+ 0x04;
	addr_Gren = GetAddr(0x821B0140, 0x83000000, bufGren, 2, 1)+ 0x04;
	addr_After = GetAddr(0x821B0B7C, 0x83000000, bufAfter, 2, 1)+ 0x08;
	SetAddr = true;
}