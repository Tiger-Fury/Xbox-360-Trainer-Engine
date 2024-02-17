#include "common.h"

UINT32 g_titleID = 0x43430824;

DWORD buf[] = {0x3D608200, 0xC1BF083C};
DWORD goldbuf[] = {0x9163000C, 0x38210070};
DWORD devilbuf[] = {0xFD6C682E, 0xD17E0000};
DWORD moneybuf[] = {0x7d075838, 0x90E3000C};

VOID __declspec(naked) CheckHealth(VOID)
{ 


	__asm{
	
		lfs fr13,83Ch(r31)
	
			mflr r14
	}

	Saveregs();

	__asm 
	{
		mr MYPtr1,r31

	}

	if(*(DWORD*)(MYPtr1+0x8E0) == 0x821A4DA4 ||*(DWORD*)(MYPtr1+0x8E0) == 0x821A5E34 && InfHealth == TRUE)
	{
		*(DWORD*)(MYPtr1+0x83C) = 0x44FA0000;

	}
	else if(*(DWORD*)(MYPtr1+0x8E0) != 0x821A4DA4 ||*(DWORD*)(MYPtr1+0x8E0) != 0x821A5E34  && OneHitKo == TRUE)
	{
		*(DWORD*)(MYPtr1+0x83C) = 0x1E3CE508;

	}
	Loadregs();


	__asm{

		lfs fr0,0BCCh(r11)
		fcmpu cr6,fr13,fr0
		bgt cr6,br2

br2:
		mtlr r14
		lis r14,0x82D1
		ori r14,r14,0x092C 
		mtctr r14
		bctr
 	}



}

VOID SetHooks()
{

	Caveme(addr ,CheckHealth,14);
	HooksSet = true;
}

VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"More at T3furyGaming.co.uk", L"Devil May Cry 5 + 5\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
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
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nOne Hit Kill RB(x4)\r\nInf Red Orbs LT(x4)\r\nInf Devil Trigger LB(x4)\r\nInf Gold Orbs Y(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3furyGaming.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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

		if( InfScore == TRUE )
		{
			hNotify(L"Inf Red Orbs Deactivated");
			SetDWORD(addr_Cash, 0x90E3000C);
			InfScore = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Red Orbs Activated");
			SetDWORD(addr_Cash, 0x93C3000C);
			InfScore = TRUE;
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

		if( InfStamina == TRUE )
		{
			hNotify(L"Inf Devil Trigger Deactivated");
			SetDWORD(addr_Special, 0xD17E0000);
			InfStamina = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Devil Trigger Activated");
			SetDWORD(addr_Special, NOPThis);
			InfStamina = TRUE;
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
			hNotify(L"Inf Gold Orbs Deactivated");
			SetDWORD(addr_Gren, 0x396BFFFF);
			InfItems = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Gold Orbs Activated");
			SetDWORD(addr_Gren, 0x396B0000);
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

		if(ALLCheats == TRUE )
		{
			hNotify(L"All Cheats Deactivated");
			SetDWORD(addr_Special, 0xD17E0000);
			SetDWORD(addr_Cash, 0x90E3000C);
			SetDWORD(addr_Gren, 0x396Bffff);
			InfHealth = FALSE;
			OneHitKo = FALSE;
			ALLCheats = FALSE;
			Vibr01();

		}else{

			hNotify(L"All Cheats Activated");
			SetDWORD(addr_Special, NOPThis);
			SetDWORD(addr_Cash, 0x93C3000C);
			SetDWORD(addr_Gren, 0x396B0000);
			InfHealth = TRUE;
			OneHitKo = TRUE;
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
	hNotify(L"Devil May Cry");

	Sleep(25);
   	addr = GetAddr(0x82000000, 0x83000000, buf, 2, 1)+ 0x04;
   	addr_Cash = GetAddr(0x82000000, 0x83000000, moneybuf, 2, 1)+ 0x04;
	addr_Special = GetAddr(0x82000000, 0x83000000, devilbuf, 2, 1)+ 0x04;
	addr_Gren = GetAddr(0x82000000, 0x83000000, goldbuf, 2, 1)- 0x04;
	SetAddr = true;
}