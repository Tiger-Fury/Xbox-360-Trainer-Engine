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

BYTE ammo[] = { 0x91, 0x7f, 0x02, 0x90 };

BYTE health[] = { 0xd0, 0x1f, 0x01, 0xf4 };

BYTE nades[] = { 0x90, 0xbf, 0x03, 0x2c };

BYTE nv[] = { 0xd1, 0xbf, 0x01, 0x60 };


VOID __declspec(naked) CheckHP(VOID) {
	
	
	//  82BB4458  lis r11,-32255		 
	//	82BB445C  stfs fr28,2Ch(r31)  break
	//	82BB4460  lis r10,-32256		  
	//	82BB4464  stfs fr27,30h(r31)  

	DWORD dwPtr;

 __asm {
	mr dwPtr,r5
		lis r11,-32255		 
		stfs fr28,2Ch(r31)  
		lis r10,-32256		  
		stfs fr27,30h(r31) 

 }

 if (dwPtr == 0x10 && InfHealth == TRUE) {
  float fltValue = 200.0f;
  __asm 
  { 

	stfs fltValue,2Ch(r31)
  }

 }else{

if( InfHealth == FALSE )
	 {
		 __asm
		 {

		 }
	 }

 }
 
 
 // 82ECC2D0
 __asm{
  lis r11,0x82BB   
  ori r11,r11,0x4468
  mtctr r11
  bctr      
 }
 
}

VOID SetHooks()
{


	 DWORD IHealth[4];
	 patchInJump( (PDWORD)IHealth, (DWORD)CheckHP, FALSE );
	 
		DoCave(0x82BB4458, &IHealth[0], 4);
		DoCave(0x82BB445C, &IHealth[1], 4);
		DoCave(0x82BB4460, &IHealth[2], 4);
		DoCave(0x82BB4464, &IHealth[3], 4);

		HooksSet = true;
}

VOID TrainerLoaded()
{
	PulseController();
	pop(L"t3furys XPG Exclusives\r\nTransFormers FoC +2 Trainer Loaded");
}


VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"~TeamXpg~ t3furys XPG Exclusives", L"TransFormers FoC +2 Trainer\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);

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
	//3rd Cheat
	if( g_mb_result.rgwPasscode[0] == LEFT_TRIGGER && g_mb_result.rgwPasscode[1] == LEFT_TRIGGER && g_mb_result.rgwPasscode[2] == LEFT_TRIGGER && g_mb_result.rgwPasscode[3] == LEFT_TRIGGER )
	{
		Sleep(500);
		
		if( CheatLT == TRUE )
		{
			pop(L"Inf Ammo Deactivated");
			DoCheat(0x830DBBA4, ammo, 4);
			CheatLT = FALSE;
	        PulseController();

		}else{
			
			pop(L"Inf Ammo Activated");
			DoCheat(0x830DBBA4, nopammo, 4);
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
			if( g_mb_result.rgwPasscode[0] == RIGHT_BUMPER && g_mb_result.rgwPasscode[1] == RIGHT_BUMPER && g_mb_result.rgwPasscode[2] == RIGHT_BUMPER && g_mb_result.rgwPasscode[3] == RIGHT_BUMPER )
			{
				Sleep(500);

				if( InfHealth == TRUE )
				{
					pop(L"One Hit Kill Deactivated");
					OneHitKo = FALSE;
					PulseController();

				}else{

					pop(L"One Hit Kill Activated");
					OneHitKo = TRUE;
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
			DoCheat(0x830DBBA4, ammo, 4);
			OneHitKo = FALSE;
			InfHealth = FALSE;
			CheatDU = FALSE;
	        PulseController();

		}else{
			
			pop(L"All Cheats Activated");
			DoCheat(0x830DBBA4, nopammo, 4);
			OneHitKo = TRUE;
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