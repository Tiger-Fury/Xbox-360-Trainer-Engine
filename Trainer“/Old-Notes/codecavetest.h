#include "common.h"


bool OneHitKo = false;
bool InfAmmo = false;
bool AIAmmo = false;
bool InfBP = false;
bool HooksSet = false;
bool InfHealth = FALSE;
bool CheatXX = FALSE;
bool CheatLB = FALSE;
bool CheatYY = FALSE;
bool CheatRB = FALSE;
bool CheatRT = FALSE;
bool CheatLT = FALSE;
bool CheatDU = FALSE;
bool CheatDL = FALSE;
bool CheatDR = FALSE;

BYTE nop[] = { 0x60, 0x00, 0x00, 0x00 };
BYTE ammo[] = { 0x38, 0xa0, 0x03, 0xe7 };
BYTE ammoo[] = { 0x2b, 0x0b, 0x00, 0x00 };
BYTE ammoo2[] = { 0x41, 0x9a, 0xff, 0xd0 };
BYTE engo[] = { 0xd1, 0x1f, 0x00, 0x00 };
BYTE arrow[] = { 0x39, 0x00, 0x00, 0x63 };
BYTE arrowo[] = { 0x7d, 0x48, 0x4b, 0x78 };
BYTE nano[] = { 0x39, 0x20, 0x03, 0xe7 };
BYTE nanoo[] = { 0x7d, 0x29, 0x2a, 0x14 };



VOID __declspec(naked) CheckHP(VOID) {
	
	
 // 82ECC2C0 817F0020             lwz r11,20h(r31) 
 // 82ECC2C4 C01F032C             lfs fr0,32Ch(r31) 
 // 82ECC2C8 EDA0F828             fsubs fr13,fr0,fr31 
 // 82ECC2CC D1BF032C             stfs fr13,32Ch(r31)

	DWORD dwPtr;

 __asm {
	 mr dwPtr,r7
  lwz r11,20h(r31) 
  lfs fr0,32Ch(r31) 
  fsubs fr13,fr0,fr31 
  stfs fr13,32Ch(r31)
 }

 if (dwPtr == 0x00 && InfHealth == TRUE) {
  float fltValue = 100.0f;
  __asm { 
   stfs fltValue,32Ch(r31)
  }
 }
 // 82ECC2D0
 __asm{
  lis r11,0x82EC   
  ori r11,r11,0xC2D0
  mtctr r11
  bctr      
 }
 
}

VOID SetHooks()
{


	 DWORD IHealth[4];
	 patchInJump( (PDWORD)IHealth, (DWORD)CheckHP, FALSE );
	 
		DoCave(0x82ECC2C0, &IHealth[0], 4);
		DoCave(0x82ECC2C4, &IHealth[1], 4);
		DoCave(0x82ECC2C8, &IHealth[2], 4);
		DoCave(0x82ECC2CC, &IHealth[3], 4);

		HooksSet = true;
}

VOID ShowTrainerMain()
{
		
			Prompt = XShowMessageBoxUI(0, L"Crysis 3", L"View Codes: DPAD-DOWN(x4)\r\nCreated by xJACKASSx\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
			
				if( HooksSet == false )
				{
					SetHooks();
				}


}


VOID TrainerLoaded()
{
	
	Prompt = XShowMessageBoxUI(0, L"Game Name", L"Trainer Loaded!\r\nYou may now start your game\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

}

VOID ButPress( MESSAGEBOX_RESULT g_mb_result )
{
	
	if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
	{
		Sleep(500);
		XShowMessageBoxUI(0, L"Viewing All Codes", L"Inf Health Y(x4)\r\nEasy Kills DPAD-UP(x4)\r\nInf Ammo X(x4)\r\nInf Engery LB(x4)\r\nInf Arrows/Grenades RB(x4)\r\n999 Nano Points RT(x4)", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;

	}

	if( g_mb_result.rgwPasscode[0] == Y_BUTTON && g_mb_result.rgwPasscode[1] == Y_BUTTON && g_mb_result.rgwPasscode[2] == Y_BUTTON && g_mb_result.rgwPasscode[3] == Y_BUTTON )
	{
		Sleep(500);
		
		if( InfHealth == TRUE )
		{
			XShowMessageBoxUI(0, L"Cheat Disabled Successfully", L"Inf Health - Disabled\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);
			InfHealth = FALSE;
			PulseController();
		}else{
			XShowMessageBoxUI(0, L"Cheat Enabled Successfully", L"Inf Health - Enabled\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);
			InfHealth = TRUE;
			PulseController();
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
		
		if( OneHitKo == TRUE )
		{
			XShowMessageBoxUI(0, L"Cheat Disabled Successfully", L"Easy AI Kills - Disabled\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);
			OneHitKo = FALSE;
			PulseController();
		}else{
			XShowMessageBoxUI(0, L"Cheat Enabled Successfully", L"Easy AI Kills - Enabled\r\nDescription: **MAY BE BUGGY**.", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);
			OneHitKo = TRUE;
			PulseController();
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
		
		if( CheatXX == TRUE )
		{
			XShowMessageBoxUI(0, L"Cheat Disabled Successfully", L"Inf Ammo - Disabled\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);
			DoCheat(0x8311C3F0, ammoo, 4);
			DoCheat(0x8311C3F4, ammoo2, 4);
			CheatXX = FALSE;
	        PulseController();

		}else{
			
			XShowMessageBoxUI(0, L"Cheat Enabled Successfully", L"Inf Ammo - Enabled\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);
			DoCheat(0x8311C3F0, nop, 4);
			DoCheat(0x8311C3F4, ammo, 4);
			CheatXX = TRUE;
		    PulseController();

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
		
		if( CheatLB == TRUE )
		{
			XShowMessageBoxUI(0, L"Cheat Disabled Successfully", L"Inf Engery - Disabled\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);
			
			DoCheat(0x88888888, engo, 4);
			CheatLB = FALSE;
			PulseController();
		}else{
			XShowMessageBoxUI(0, L"Cheat Enabled Successfully", L"Inf Engery - Enabled\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);
			
			DoCheat(0x88888888, nop, 4);
			CheatLB = TRUE;
			PulseController();
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
		
		if( CheatRB == TRUE )
		{
			XShowMessageBoxUI(0, L"Cheat Disabled Successfully", L"Inf Arrows/Grenades - Disabled\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);
			DoCheat(0x88888888, arrowo, 4);
			CheatRB = FALSE;
			PulseController();

		}else{
			
			XShowMessageBoxUI(0, L"Cheat Enabled Successfully", L"Inf Arrows/Grenades - Enabled\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);
			
			DoCheat(0x88888888, arrow, 4);
			CheatRB = true;
			PulseController();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
	
	
	if( g_mb_result.rgwPasscode[0] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[1] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[2] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[3] == RIGHT_TRIGGER )
	{
		Sleep(500);
		
		if( CheatRT == TRUE )
		{
			XShowMessageBoxUI(0, L"Cheat Disabled Successfully", L"999 Nano Points - Disabled\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);
		CheatRT = FALSE;
		DoCheat(0x88888888, nanoo, 4);
		PulseController();

		}else{
			
			XShowMessageBoxUI(0, L"Cheat Enabled Successfully", L"999 Nano Points - Enabled\r\nDescription: ** After you use 1, should have 999 Nano points. Disable after you get 999 **", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);
		CheatRT = true;
		DoCheat(0x88888888, nano, 4);
		PulseController();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
	
}