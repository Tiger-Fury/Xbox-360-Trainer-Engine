#include "common.h"

UINT32 g_titleID = 0x45410923;

DWORD CashValue = 0x0001f20c;
DWORD MYPtr1;
DWORD addr_ammo1 = 0x8236D9C4;
DWORD Ammo_On = 0x000f423f;
DWORD Ammo_off = 0x911E0000;
float fltXValue = 100.0;
DWORD XValue = 0x01000040;
float XPValue = 999999999.0;
float fltZValue = 0.0;
DWORD ZValue = 0x00000000;
DWORD addr5;
DWORD buf1[] = {0x0117ced9, 0x42c80000};


VOID __declspec(naked) CheckHealth(VOID)
{ 


	__asm{
		sth r10,0(r11) 
		lhz r10,151Eh(r31)
		lhz r9,0(r11)
		extsh r8,r10
			mflr r20
	}

	Saveregs();

	__asm {
		mr MYPtr1,r11
	}

	if(   *(DWORD*)(MYPtr1) == 0x01000040 &&  InfHealth == TRUE ) {
		__asm { 


			sth XValue,0(r11)

		}
	}else{
		if( InfHealth == FALSE )
		{
			__asm{

			}
		}


	}
	if(   *(DWORD*)(MYPtr1) != 0x01000040 &&  OneHitKo == TRUE )
	{

		__asm
		{

			sth ZValue,0(r11)

		}


	}else{
		if( OneHitKo == FALSE )
		{
			__asm{

			}
		}


	}

	
	Loadregs();



	__asm{
		extsh r7,r9 
		cmpw cr6,r7,r8 
		cmplwi r10,0 
		bge cr6,br2

			mtlr r20
			lis r20,0x8227      
			ori r20,r20,0xC880
			mtctr r20
			bctr

br2:
		mtlr r20
			lis r20,0x8227
			ori r20,r20,0xC884
			mtctr r20
			bctr

	}



}


VOID SetHooks()
{

	Caveme(0x8227C864,CheckHealth,20);
	HooksSet = true;
}


VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"~TeamXPG~ t3fury XPGamesaves.com", L"Watch Dogs + 7\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
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
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nInf Ammo RB(x4)\r\nFast XP LT(x4)\r\nCash and Skill LB(x4)\r\nInf Battery Y(x4)\r\nInf Items X(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury r\nXPGamesaves.com\r\nHome To TeamXPG and 360 Revolution", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
	if( g_mb_result.rgwPasscode[0] == RIGHT_BUMPER && g_mb_result.rgwPasscode[1] == RIGHT_BUMPER && g_mb_result.rgwPasscode[2] == RIGHT_BUMPER && g_mb_result.rgwPasscode[3] == RIGHT_BUMPER )
	{
		Sleep(500);

		if( OneHitKo == TRUE )
		{
			hNotify(L"Inf Ammo Deactivated");
			OneHitKo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Ammo Activated");

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

		if( Max_XP == TRUE )
		{
			hNotify(L"Fast XP Deactivated");
			SetDWORD(0x82E53CF4,0x7D085214);
			Max_XP = FALSE;
			Vibr01();

		}else{

			hNotify(L"Fast XP Activated");
			SetDWORD(0x82E53CF4,0x39087FFF);
			Max_XP = TRUE;
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

		if( Max_Cash == TRUE )
		{
			hNotify(L"30k Cash and Skill Points Deactivated");
			SetDWORD(0x82E5B550,0x7D7D5850);
			Max_Cash = FALSE;
			Vibr01();

		}else{

			hNotify(L"30k Cash and Skill Points Activated");
			SetDWORD(0x82E5B550,0x396B7530);
			Max_Cash = TRUE;
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

		if( InfItems == TRUE )
		{
			hNotify(L"Inf Items Deactivated");
			SetDWORD(0x82ABFBB0,0x7D7F5850);
			InfItems = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Items Activated");
			SetDWORD(0x82ABFBB0,0x396003E7);
			InfItems = TRUE;
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
			hNotify(L"Inf Battery Deactivated");
			SetDWORD(0x827BABF0,0xD0030090);
			InfItems = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Battery Activated");
			SetDWORD(0x827BABF0,NOPThis);
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
			SetDWORD(0x82ABFBB0,0x7D7F5850);
			SetDWORD(0x82ADFDD8,0x394BFFFF);
			SetDWORD(0x82E53CF4,0x7D085214);
			SetDWORD(0x82E5B550,0x7D7D5850);
			SetDWORD(0x827BABF0,0xD0030090);
			InfHealth = FALSE;
			ALLCheats = FALSE;
			Vibr01();

		}else{

			hNotify(L"All Cheats Activated");
			SetDWORD(0x82ABFBB0,0x396003E7);
			SetDWORD(0x82ADFDD8,0x394B0000);
			SetDWORD(0x82E53CF4,0x39087FFF);
			SetDWORD(0x82E5B550,0x396B7530);
			SetDWORD(0x827BABF0,NOPThis);
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
	hNotify(L"Syndicate");
	Sleep(25);
	SetAddr = true;
}