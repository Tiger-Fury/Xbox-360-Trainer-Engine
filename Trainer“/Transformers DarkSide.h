#include "common.h"


bool OneHitKo = false;
bool InfAmmo = false;
bool AIAmmo = false;
bool InfBP = false;
bool TU = false;
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


bool CheckGame = FALSE;
bool CheckGame2 = FALSE;
bool GameReady = false;

BYTE gcheck[] = { 0x00 };
BYTE gcheck2[] = { 0x00 };

BYTE gchecktu[] = { 0x00 };
BYTE gchecktu2[] = { 0x00 };

BYTE nop[] = { 0x60, 0x00, 0x00, 0x00 };
BYTE nopnano[] = { 0x60, 0x00, 0x00, 0x00 };
BYTE nopnades[] = { 0x60, 0x00, 0x00, 0x00 };
BYTE nopammo[] = { 0x60, 0x00, 0x00, 0x00 };
BYTE nophealth[] = { 0x60, 0x00, 0x00, 0x00 };
BYTE nopnv[] = { 0x60, 0x00, 0x00, 0x00 };

BYTE nano[] = { 0xd3, 0xff, 0x00, 0x30 };

BYTE ammo[] = { 0x91, 0x7f, 0x02, 0x98 };

BYTE health[] = { 0xd0, 0x1f, 0x01, 0xf4 };

BYTE nades[] = { 0x90, 0xbf, 0x03, 0x2c };

BYTE nv[] = { 0xd1, 0xbf, 0x01, 0x60 };


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

VOID TrainerLoaded()
{
	PulseController();
	pop(L"t3furys XPG Exclusives\r\nTransFormers DSOTM +3 Trainer Loaded");
}


VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"~TeamXpg~ t3furys XPG Exclusives", L"TransFormers DSOTM +3 Trainer\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);

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
			XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nInf Ammo LT(x4)\r\nInf Grenades RB(x4)\r\nHope You Enjoy", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
		
		if( CheatRB == TRUE )
		{
			pop(L"Inf Grenades Deactivated");
			DoCheat(0x827FD0F0, nades, 4);
			CheatRB = FALSE;
			PulseController();

		}else{
			
			pop(L"Inf Grenades Activated");			
			DoCheat(0x827FD0F0, nopnades, 4);
			CheatRB = true;
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
		
		if( CheatLT == TRUE )
		{
			pop(L"Inf Ammo Deactivated");
			DoCheat(0x827FD0C4, ammo, 4);
			CheatLT = FALSE;
	        PulseController();

		}else{
			
			pop(L"Inf Ammo Activated");
			DoCheat(0x827FD0C4, nopammo, 4);
			CheatLT = TRUE;
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
			InfHealth = FALSE;
	        PulseController();

		}else{
			
			pop(L"Inf Health Activated");
			InfHealth = TRUE;
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
		
		if( CheatDU == TRUE )
		{
			pop(L"All Cheats Deactivated");
			DoCheat(0x827FD0F0, nades, 4);
			DoCheat(0x827FD0C4, ammo, 4);;
			InfHealth = FALSE;
			CheatDU = FALSE;
	        PulseController();

		}else{
			
			pop(L"All Cheats Activated");
			DoCheat(0x827FD0F0, nopnades, 4);
			DoCheat(0x827FD0C4, nopammo, 4);
			InfHealth = TRUE;
			CheatDU = TRUE;
		    PulseController();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
				
		}



VOID ProcessButtonPress( MESSAGEBOX_RESULT g_mb_result )
{

}