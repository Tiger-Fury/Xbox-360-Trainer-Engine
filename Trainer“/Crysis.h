#include "common.h"

UINT32 g_titleID = 0x45410968;

DWORD buf[] = {0xFC0A5FEE, 0xD01F01F4};
DWORD bufSpecial[] = {0xD3FF0030, 0x38210150};
DWORD bufAmmo[] = {0x419A000C, 0x93A30014};
DWORD bufGren[] = {0x7D484B78, 0x91030000};
DWORD bufNano[] = {0xC00A7C90, 0xD1BF0160};

VOID __declspec(naked) CheckHealth(VOID)
{ 


	__asm{
		stfs fr0,1F4h(r31)

			mflr r2
	}

	Saveregs();

	__asm 
	{
		mr MYPtr1,r8
			mr MYPtr2,r31
	}

	if(MYPtr1 == 0x7777  && InfHealth == TRUE)
	{
		*(DWORD*)(MYPtr2 + 0x1F4) = 0x43480000;

	}

	Loadregs();



	__asm{

		fsel fr13,fr31,fr8,fr13
			fcmpu cr6,fr0,fr9
			frsp fr13,fr13

			mtlr r2
			lis r2,0x82DF
			ori r2,r2,0xB04C
			mtctr r2
			bctr

	}
}

VOID SetHooks()
{
	Caveme(addr ,CheckHealth,2);
	HooksSet = true;
}

VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"More at T3furyGaming.co.uk", L"Crysis +5 Trainer\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
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
			XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nInf Ammo LT(x4)\r\nInf Nano Energy LB(x4)\r\nInf Grenades RB(x4)\r\nInf Night Vision Y(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nXPGamesaves.com\r\nHome To TeamXPG and 360 Revolution", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

        memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
        memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
        memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
        memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
        Prompt = 0x9999;

    }
	// 1st Cheat
		if( g_mb_result.rgwPasscode[0] == RIGHT_BUMPER && g_mb_result.rgwPasscode[1] == RIGHT_BUMPER && g_mb_result.rgwPasscode[2] == RIGHT_BUMPER && g_mb_result.rgwPasscode[3] == RIGHT_BUMPER )
	{
		Sleep(500);
		
		if( InfGrenade == TRUE )
		{
			pop(L"Inf Grenades Deactivated");
			SetDWORD(addr_Gren, 0x91030000);
			InfGrenade = FALSE;
			PulseController();

		}else{
			
			pop(L"Inf Grenades Activated");			
			SetDWORD(addr_Gren, NOPThis);
			InfGrenade = true;
			PulseController();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
		// 2nd cheat
    if( g_mb_result.rgwPasscode[0] == LEFT_BUMPER && g_mb_result.rgwPasscode[1] == LEFT_BUMPER && g_mb_result.rgwPasscode[2] == LEFT_BUMPER && g_mb_result.rgwPasscode[3] == LEFT_BUMPER )
	{
		Sleep(500);
		
		if( InfStamina == TRUE )
		{
			pop(L"Inf Nano Energy Deactivated");
			SetDWORD(addr_Stamina, 0xD3FF0030);
			InfStamina = FALSE;
			PulseController();
		}else{
			pop(L"Inf Nano Energy Activated");
			SetDWORD(addr_Stamina, NOPThis);
			InfStamina = TRUE;
			PulseController();
		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
	//3rd Cheat
	if( g_mb_result.rgwPasscode[0] == LEFT_TRIGGER && g_mb_result.rgwPasscode[1] == LEFT_TRIGGER && g_mb_result.rgwPasscode[2] == LEFT_TRIGGER && g_mb_result.rgwPasscode[3] == LEFT_TRIGGER )
	{
		Sleep(500);
		
		if( InfAmmo == TRUE )
		{
			pop(L"Inf Ammo Deactivated");
			SetDWORD(addr_ammo, 0x93A30014);
			InfAmmo = FALSE;
	        PulseController();

		}else{
			
			pop(L"Inf Ammo Activated");
			SetDWORD(addr_ammo, NOPThis);
			InfAmmo = TRUE;
		    PulseController();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
	//4th cheat
			if( g_mb_result.rgwPasscode[0] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[1] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[2] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[3] == RIGHT_TRIGGER )
	{
		Sleep(500);
		
		if( InfHealth == TRUE )
		{
			pop(L"Inf Health Deactivated");
	//		SetDWORD(addr, 0xD01F01F4);
			InfHealth = FALSE;
	        PulseController();

		}else{
			
			pop(L"Inf Health Activated");
	//		SetDWORD(addr, NOPThis);
			InfHealth = TRUE;
		    PulseController();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
	// 5th cheat
	if( g_mb_result.rgwPasscode[0] == Y_BUTTON && g_mb_result.rgwPasscode[1] == Y_BUTTON && g_mb_result.rgwPasscode[2] == Y_BUTTON && g_mb_result.rgwPasscode[3] == Y_BUTTON )
	{
		Sleep(500);
		
		if( InfSpecial == TRUE )
		{
			pop(L"Inf Night Vision Deactivated");
			SetDWORD(addr_Special, 0xD1BF0160);
			InfSpecial = FALSE;
	        PulseController();

		}else{
			
			pop(L"Inf Night Vision Activated");
			SetDWORD(addr_Special, NOPThis);
			InfSpecial = TRUE;
		    PulseController();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
	//6th cheat Multi Activate
	if( g_mb_result.rgwPasscode[0] == DPAD_UP && g_mb_result.rgwPasscode[1] == DPAD_UP && g_mb_result.rgwPasscode[2] == DPAD_UP && g_mb_result.rgwPasscode[3] == DPAD_UP )
	{
		Sleep(500);
		
		if( ALLCheats == TRUE )
		{
			pop(L"All Cheats Deactivated");
			SetDWORD(addr_Gren, 0x91030000); 
			SetDWORD(0x82E1B864, 0xD3FF0030);
			SetDWORD(addr_ammo, 0x93A30014);
			InfHealth = FALSE;
			SetDWORD(addr_Special, 0xD1BF0160);
			ALLCheats = FALSE;
	        PulseController();

		}else{
			
			pop(L"All Cheats Activated");
			SetDWORD(addr_Gren, NOPThis);
			SetDWORD(0x82E1B864, NOPThis);
			SetDWORD(addr_ammo, NOPThis);
			InfHealth = TRUE;
			SetDWORD(addr_Special, NOPThis);
			ALLCheats = TRUE;
		    PulseController();

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
	hNotify(L"Crysis");
	Sleep(25);
	addr = GetAddr(0x82000000, 0x83000000, buf, 2, 1)+ 0x04;
	addr_Special = GetAddr(0x82000000, 0x83000000, bufNano, 2, 1);
	addr_ammo = GetAddr(0x82A00000, 0x83000000, bufAmmo, 2, 1)+ 0x04;
	addr_Gren = GetAddr(0x82000000, 0x83000000, bufGren, 2, 1)+ 0x04;
	addr_Stamina = GetAddr(0x82A00000, 0x83000000, bufSpecial, 2, 1)+ 0x04;
	SetAddr = true;
}