#include "common.h"

UINT32 g_titleID = 0x4B4D07FD;

DWORD buf[] = {0x7F9AE92E, 0x7FC4F378};
DWORD Timerbuf[] = {0x7CC55038, 0x90BF0024};

VOID __declspec(naked) CheckHealth(VOID)
{ 


	__asm{
	
		stwx r28,r26,r29
		mflr r15
	}

	Saveregs();

	__asm 
	{
		mr MYPtr1,r29
	}

	if(*(DWORD*)(MYPtr1) == 0x82035014 && InfHealth == TRUE)//health
	{
		*(DWORD*)(MYPtr1 + 0x38) = *(DWORD*)(MYPtr1 + 0x34);

	}
	if(*(DWORD*)(MYPtr1) == 0x82035014 && InfSpecial == TRUE)//attrib
	{
		*(DWORD*)(MYPtr1 + 0x14) = 0x000000ff;
		*(DWORD*)(MYPtr1 + 0x18) = 0x000000ff;
		*(DWORD*)(MYPtr1 + 0x1C) = 0x000000ff;
		*(DWORD*)(MYPtr1 + 0x20) = 0x000000ff;
		*(DWORD*)(MYPtr1 + 0x24) = 0x000000ff;
		*(DWORD*)(MYPtr1 + 0x28) = 0x000000ff;
		*(DWORD*)(MYPtr1 + 0x2c) = 0x000000ff;
		*(DWORD*)(MYPtr1 + 0x30) = 0x000000ff;
	}
	if(*(DWORD*)(MYPtr1) == 0x82035014 && InfSkill == TRUE)//glory
	{
		*(DWORD*)(MYPtr1 + 0x3c) = Max_IT;

	}
	if(*(DWORD*)(MYPtr1) == 0x82035014 && InfStamina == TRUE)//glory
	{
		*(DWORD*)(MYPtr1 + 0x40) = 0x00000064;

	}

	Loadregs();


	__asm{

		mr r4,r30
		lwz r11,0(r29)
		mr r3,r29

		mtlr r15
		lis r15,0x824f
		ori r15,r15,0x7198
		mtctr r15
		bctr
 	}
}


VOID SetHooks()
{

	Caveme(addr ,CheckHealth,15);
	HooksSet = true;
}
//
VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"More at T3furyGaming.co.uk", L"Risen 3 + 5\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
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
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nMax Attributes LT(x4)\r\nPopularity Bar LB(x4)\r\nMax Glory Y(x4)\r\nInf Items, ammo, gold X(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3furyGaming.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
	if( g_mb_result.rgwPasscode[0] == LEFT_BUMPER && g_mb_result.rgwPasscode[1] == LEFT_BUMPER && g_mb_result.rgwPasscode[2] == LEFT_BUMPER && g_mb_result.rgwPasscode[3] == LEFT_BUMPER )
	{
		Sleep(500);

		if( InfStamina == TRUE )
		{
			hNotify(L"Max Popularity Bar Deactivated");
			InfStamina = FALSE;
			Vibr01();

		}else{

			hNotify(L"Max Popularity Bar Activated");
			InfStamina = TRUE;
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

		if( InfSpecial == TRUE )
		{
			hNotify(L"Max Attributes Deactivated");
			InfSpecial = FALSE;
			Vibr01();

		}else{

			hNotify(L"Max Attributes Activated");
			InfSpecial = TRUE;
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

		if( InfSkill == TRUE )
		{
			hNotify(L"Max Glory Deactivated");
			InfSkill = FALSE;
			Vibr01();

		}else{

			hNotify(L"Max Glory Activated");
			InfSkill = TRUE;
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

		if( InfTimer == TRUE )
		{
			hNotify(L"Inf Ammo,Items, Gold Deactivated");
			SetDWORD(addr_Timer, 0x90BF0024);
			InfTimer = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Ammo,Items, Gold Activated");
			SetDWORD(addr_Timer, 0x3CA00100);
			InfTimer = TRUE;
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
			SetDWORD(addr_Timer, 0x90BF0024);
			InfStamina = FALSE;
			InfSpecial = FALSE;
			InfSkill = FALSE;
			InfHealth = FALSE;
			ALLCheats = FALSE;
			Vibr01();

		}else{

			hNotify(L"All Cheats Activated");
			SetDWORD(addr_Timer, 0x3CA00100);
			InfStamina = TRUE;
			InfSpecial = TRUE;
			InfSkill = TRUE;
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
	hNotify(L"Risen 3: Titan Lords");

	Sleep(25);
    addr = GetAddr(0x82000000, 0x83000000, buf, 2, 1);
  	addr_Timer = GetAddr(0x82000000, 0x83000000, Timerbuf, 2, 1);
	SetAddr = true;
}