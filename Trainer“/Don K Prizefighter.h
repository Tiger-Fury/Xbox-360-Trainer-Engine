#include "common.h"

UINT32 g_titleID = 0x545407DC;

DWORD Timerbuf[] = {0xD03F0028, 0x817A0014};

VOID __declspec(naked) CheckHealth(VOID)
{ 


	__asm{
		lfs fr0,29E4h(r11)

			mflr r27
	}

	Saveregs();

	__asm 
	{
		mr MYPtr1,r11
	}

	if( InfHealth == TRUE)
	{

		*(DWORD*)(MYPtr1+0x29E4) = 0x3f800000;
		//*(DWORD*)(MYPtr1+0x29D8) = 0x3f800000;
	}
	Loadregs();



	__asm{

		lis r11,-32243
		fcmpu cr6,fr0,fr31
		addi r23,r11,18664

			mtlr r27
			lis r27,0x821a
			ori r27,r27,0xa9ac
			mtctr r27
			bctr

	}



}

VOID __declspec(naked) CheckStam(VOID)
{ 


	__asm{
			lfs fr0,29E8h(r11)

            mflr r27
	     }

	Saveregs();

	__asm 
	{
			mr MYPtr1,r11
	}

	if( InfStamina == TRUE)
	{
		
			*(DWORD*)(MYPtr1+0x29E8) = 0x3f800000;
			
	}
	Loadregs();



	__asm{

		fcmpu cr6,fr0,fr31
		ble cr6,br6
		fmr fr0,fr31

br6:
			mtlr r27
			lis r27,0x821a
			ori r27,r27,0xab1c
			mtctr r27
			bctr

	}



}

VOID __declspec(naked) CheckBoost(VOID)
{ 


	__asm{
		lfs fr0,29F4h(r11)

			mflr r27
	}

	Saveregs();

	__asm 
	{
		mr MYPtr1,r11
	}

	if(InfItems == TRUE)
	{

		*(DWORD*)(MYPtr1+0x29F4) = 0x3f800000;

	}
	Loadregs();



	__asm{

		fcmpu cr6,fr0,fr31
		ble cr6,br7
		fmr fr0,fr31

br7:
			mtlr r27
			lis r27,0x821a
			ori r27,r27,0xabc8
			mtctr r27
			bctr

	}



}

VOID SetHooks()
{
	Caveme(0x821aa99c,CheckHealth,27);
    Caveme(0x821aabb4,CheckBoost,27);
	Caveme(0x821aab08,CheckStam,27);
    HooksSet = true;
}

VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"More at T3furyGaming.co.uk", L"Don King Prizefighter + 3\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
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
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nInf Stamina RB(x4)\r\nInf Adrenaline LT(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3furyGaming.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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

		if( InfStamina == TRUE )
		{
			hNotify(L"Inf Stamina Deactivated");
			InfStamina = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Stamina Activated");
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

		if( InfItems == TRUE )
		{
			hNotify(L"Inf Boost Deactivated");
			InfItems = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Boost Activated");
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
			InfStamina = FALSE;
			InfHealth = FALSE;
			InfItems = FALSE;
			ALLCheats = FALSE;
			Vibr01();

		}else{

			hNotify(L"All Cheats Activated");
			InfStamina = TRUE;
			InfHealth = TRUE;
			InfItems = TRUE;
			ALLCheats = TRUE;
			Vibr01();
			//
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
	hNotify(L"Don King PrizeFighter");
	Sleep(25);

	SetAddr = true;
}