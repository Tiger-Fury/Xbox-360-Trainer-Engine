#include "common.h"

UINT32 g_titleID = 0x584113C7;

DWORD buf[] = {0xC00AF980, 0xC1AB00E0};
DWORD bufAmmo[] = {0xC0030004, 0xEC00F82A};
DWORD bufxp[] = {0xEC00602A, 0xD01F0270};

VOID __declspec(naked) CheckHealth(VOID)
{ 


	__asm{
		lfs fr13,0E0h(r11)

			mflr r16
	}

	Saveregs();

	__asm 
	{
		mr MYPtr1,r11
	}

	if(*(DWORD*)(MYPtr1) == 0x8213b510 && InfHealth == TRUE)
	{
		*(DWORD*)(MYPtr1+0xE0) = 0x45480000;

	}else{
		if(*(DWORD*)(MYPtr1) != 0x8213b510 && OneHitKo == TRUE)
		{

			*(DWORD*)(MYPtr1+0xE0) = 0x358637BD;
		}
	}
	Loadregs();



	__asm{

		fcmpu cr6,fr13,fr0
		bgt cr6,br2
		lbz r11,0A49h(r3)

br2:
			mtlr r16
			lis r16,0x82a9
			ori r16,r16,0x7c2c
			mtctr r16
			bctr

	}


}
/////////////////////////////////


VOID SetHooks()
{
	Caveme(addr,CheckHealth,16);

	HooksSet = true;
}

VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"More at T3furyGaming.co.uk", L"Strider + 4\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
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
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nOne Hit Kill RB(x4)\r\nInf Power LT(x4)\r\nTimer Challenge Mode LB(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3furyGaming.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
	if(  g_mb_result.rgwPasscode[0] == RIGHT_BUMPER && g_mb_result.rgwPasscode[1] == RIGHT_BUMPER && g_mb_result.rgwPasscode[2] == RIGHT_BUMPER && g_mb_result.rgwPasscode[3] == RIGHT_BUMPER )
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
			hNotify(L"Inf Power Deactivated");
			SetDWORD(addr_ammo,0xEC00F82A);
			InfAmmo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Power Activated");
			SetDWORD(addr_ammo,0xEC00002A);
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
			hNotify(L"Timer Challenge Mode Deactivated");
			SetDWORD(addr_Timer,0xD01F0270);
			Max_XP = FALSE;
			Vibr01();

		}else{

			hNotify(L"Timer Challenge Mode Activated");
			SetDWORD(addr_Timer,NOPThis);
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
		SetDWORD(addr_ammo,0xEC00F82A);
		SetDWORD(addr_Timer,0xD01F0270);
		OneHitKo = FALSE;
		InfHealth = FALSE;
		ALLCheats = FALSE;
		Vibr01();

	}else{

		hNotify(L"All Cheats Activated");
		SetDWORD(addr_ammo,0xEC00002A);
		SetDWORD(addr_Timer,NOPThis);
		OneHitKo = TRUE;
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
	hNotify(L"Strider");
	Sleep(25);
  	addr = GetAddr(0x82A00000, 0x83000000, buf, 2, 1)+ 0x04;
 	addr_ammo = GetAddr(0x82A00000, 0x83000000, bufAmmo, 2, 1)+ 0x04;
 	addr_Timer = GetAddr(0x82000000, 0x83000000, bufxp, 2, 1)+0x04;

	Static_Menu = Null_Menu;
}//