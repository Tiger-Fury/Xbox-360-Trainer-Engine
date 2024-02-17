#include "common.h"

UINT32 g_titleID = 0x425307D5;

DWORD CashValue = 0x3b9ac9ff;
DWORD addr_ammo1 = 0x8236D9C4;
DWORD Ammo_On = 0x000f423f;
DWORD Ammo_off = 0x911E0000;
float XValue = 2000.0;
float XPValue = 999999999.0;
float ZValue = 0.0;


VOID __declspec(naked) CheckXP(VOID)
{ 


	__asm{
		stfsx fr1,r29,r31  

			mflr r28
	}

	Saveregs();


	if( Max_XP == TRUE ) {
		__asm { 


			stfsx XPValue,r29,r31 

		}
	}else{
		if( Max_XP == FALSE )
		{
			__asm{

			}
		}


	}

	Loadregs();



	__asm{
		mr r3,r30


			mtlr r28
			lis r28,0x8266 
			ori r28,r28,0xCEE8
			mtctr r28
			bctr

	}



}

VOID __declspec(naked) CheckCaps(VOID)
{ 


	__asm{
		stw r11,4(r27)  
		lwz r11,0(r27)
			mflr r17
	}

	Saveregs();


	if( Max_Cash == TRUE ) {
		__asm { 


			stw CashValue,4(r27) 

		}
	}else{
		if( Max_Cash == FALSE )
		{
			__asm{

			}
		}


	}

	Loadregs();



	__asm{
		cmplwi cr6,r11,0
		beq cr6,br2

			mtlr r17
			lis r17,0x8231
			ori r17,r17,0xDA00
			mtctr r17
			bctr

br2:
		mtlr r17
			lis r17,0x8231
			ori r17,r17,0xDA5C
			mtctr r17
			bctr

	}



}
VOID SetHooks()
{
	Caveme(0x8266CED8,CheckXP,28);
	Caveme(0x8231D9F0,CheckCaps,17);
	HooksSet = true;
}

static void Statics(){
	while (1){

		if (InfHealth == TRUE)
		{
			SetDWORD(0x83138EE9, 0x01000000);
		}  

		Sleep(10); 
	}
}

VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L" More at T3furyGaming.co.uk", L"Fallout 3 + 6\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
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
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nInf Items/Ammo RB(x4)\r\Max Level LT(x4)\r\Max Caps LB(x4)\r\no weight Y(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3furyGaming.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
			hNotify(L"Inf Ammo And Items Deactivated");
			SetDWORD(0x82316FB4,0x91560004);
			OneHitKo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Ammo And Items Activated");
			SetDWORD(0x82316FB4,NOPThis);
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
			hNotify(L"Max Level Deactivated");
			Max_XP = FALSE;
			Vibr01();

		}else{

			hNotify(L"Max Level Activated");
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
			hNotify(L"Inf Caps Deactivated");
			Max_Cash = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Caps Activated");
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

		if( NoWeight == TRUE )
		{
			hNotify(L"No Weight Deactivated");
			SetDWORD(0x82311548,0xD3FC0008);
			NoWeight = FALSE;
			Vibr01();

		}else{

			hNotify(L"No Weight Activated");
			SetDWORD(0x82311548,NOPThis);
			NoWeight = TRUE;
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
			SetDWORD(0x82311548,0xD3FC0008);
			Max_Cash = FALSE;
			Max_XP = FALSE;
			SetDWORD(0x82316FB4,0x91560004);
			InfHealth = FALSE;
			ALLCheats = FALSE;
			Vibr01();

		}else{

			hNotify(L"All Cheats Activated");
			SetDWORD(0x82311548,NOPThis);
			Max_Cash = TRUE;
			Max_XP = TRUE;
			SetDWORD(0x82316FB4,NOPThis);
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
	hNotify(L"Fallout 3 TU3");
	Sleep(25);
	SetAddr = true;
}