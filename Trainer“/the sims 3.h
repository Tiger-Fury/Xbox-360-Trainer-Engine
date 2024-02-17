#include "common.h"

UINT32 g_titleID = 0x58410B52;


DWORD MYPtr1;
DWORD addr_ammo1 = 0x82270AD0;
DWORD Ammo_On = 0x396003E7;
DWORD Ammo_off = 0x7D6A5850;
float XValue = 1740.0;
float ZValue = 0.0;
DWORD TValue = 0x44a28000;


VOID __declspec(naked) CheckHealth(VOID)
{ 


	__asm{
			   lfs fr0,30h(r30)
			   fsubs fr13,fr0,fr1
			   stfs fr13,30h(r30)
                    mflr r11
	     }

	Saveregs();
	__asm {
			mr MYPtr1,r24
	}

	//if( MYPtr1 == 0x10 || MYPtr1 == 0x0A || MYPtr1 == 0x39 || MYPtr1 == 0x11 || MYPtr1 == 0x13 || MYPtr1 == 0x3B || MYPtr1 == 0x1a || MYPtr1 == 0x28  || MYPtr1 == 0x3e || MYPtr1 == 0x3d && InfHealth == TRUE)
	if( MYPtr1 != 0x15 || MYPtr1 != 0x05 || MYPtr1 != 0x16  || MYPtr1 != 0x22|| MYPtr1 != 0x24 || MYPtr1 != 0x00 || MYPtr1 != 0x03|| MYPtr1 != 0x14 || MYPtr1 != 0x1f || MYPtr1 != 0x20 || MYPtr1 != 0x17 || MYPtr1 != 0x0b || MYPtr1 != 0x1d || MYPtr1 != 0x1e || MYPtr1 != 0x06 || MYPtr1 != 0x31 || MYPtr1 != 0x49 || MYPtr1 != 0x1b || MYPtr1 != 0x1c && InfHealth == TRUE )
	{
		
		__asm
		{
 
			stfs XValue,30h(r30)
            
		}
	}else{
		if( InfHealth == FALSE )
		{
			__asm{

			}
		}


	}

	//if( MYPtr1 != 0x10 || MYPtr1 != 0x0A || MYPtr1 != 0x39 || MYPtr1 != 0x11 || MYPtr1 != 0x13 || MYPtr1 != 0x3B || MYPtr1 != 0x1a || MYPtr1 != 0x28  || MYPtr1 != 0x3e || MYPtr1 != 0x3d && OneHitKo == TRUE )
		if( MYPtr1 == 0x15 || MYPtr1 == 0x05 || MYPtr1 == 0x16  || MYPtr1 == 0x22|| MYPtr1 == 0x24 || MYPtr1 == 0x00 || MYPtr1 == 0x03|| MYPtr1 == 0x14 || MYPtr1 == 0x1f || MYPtr1 == 0x20 || MYPtr1 == 0x17 || MYPtr1 == 0x0b || MYPtr1 == 0x1d || MYPtr1 == 0x1e || MYPtr1 == 0x06 || MYPtr1 == 0x31 || MYPtr1 == 0x49 || MYPtr1 == 0x1b || MYPtr1 == 0x1c && OneHitKo == TRUE )
		{

			__asm
			{

				stfs ZValue,30h(r30)

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
			
			fcmpu cr6,fr13,fr31
				bgt cr6,br2

			mtlr r11
			lis r11,0x8227       
			ori r11,r11,0x45CC
			mtctr r11
			bctr

br2:
			mtlr r11
				lis r11,0x8227
				ori r11,r11,0x45D0
				mtctr r11
				bctr

	}



}


VOID SetHooks()
{
    Caveme(0x822745B8,CheckHealth,11);//0x822745B8
    HooksSet = true;
}

VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"~TeamXPG~ t3fury XPGamesaves.com", L"Warhammer 40K Kill Team \r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
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
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\n1 Hit Kill RB(x4)\r\nInf Special LT(x4)\r\nMax Score/Unlock All LB(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury & Goldz r\nXPGamesaves.com\r\nHome To TeamXPG and 360 Revolution", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
			hNotify(L"Inf Special Deactivated");
			SetDWORD(0x82273614,0xD3CB00F8);
			InfAmmo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Special Activated");
			SetDWORD(0x82273614, NOPThis);
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

		if( Max_Cash == TRUE )
		{
			hNotify(L"Max Score/Unlock All Deactivated");
			SetDWORD(0x8220FBB0,0x912300CC);
			Max_Cash = FALSE;
			Vibr01();

		}else{

			hNotify(L"Max Score/Unlock All Activated");
			SetDWORD(0x8220FBB0, 0x91C300CC);
			Max_Cash = TRUE;
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
			SetDWORD(0x82273614,0xD3CB00F8);
			SetDWORD(0x8220FBB0,0x912300CC);
			InfHealth = FALSE;
			OneHitKo = FALSE;
			ALLCheats = FALSE;
			Vibr01();

		}else{

			hNotify(L"All Cheats Activated");
			SetDWORD(0x82273614,NOPThis);
			SetDWORD(0x8220FBB0,0x91C300CC);
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
	hNotify(L"Warhammer 40K Kill Team");
	Sleep(25);

	SetAddr = true;
}