#include "common.h"


bool OneHitKo = false;
bool InfAmmoo = false;
bool AIAmmo = false;
bool InfBP = false;
bool TU = false;
bool HooksSet = false;
bool InfHealth = FALSE;
bool InfAmmo = FALSE;
bool InfGrenades = FALSE;
bool AllCheats = FALSE;
bool InfMoney = FALSE;
bool InfTimer = FALSE;
bool CheatXX = FALSE;
bool CheatLB = FALSE;
bool CheatLBRB = FALSE;
bool CheatYY = FALSE;
bool CheatRB = FALSE;
bool CheatRT = FALSE;
bool CheatLT = FALSE;
bool CheatLTRT = FALSE;
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


BYTE nano[] = { 0x91, 0x7f, 0x6c, 0x78 };
BYTE ammo[] = { 0x91, 0x44, 0x00, 0x08 };
BYTE health1[] = { 0xb0, 0xdf, 0x12, 0xe4 };
BYTE health2[] = { 0xb1, 0x4b, 0x00, 0x04 };
BYTE nades[] = { 0x91, 0x7f, 0x6c, 0x64 };
BYTE money1[] = { 0x91, 0x63, 0x00, 0xd4 };
BYTE money2[] = { 0x81, 0x63, 0x00, 0xd4 };
BYTE mines[] = { 0x93, 0x7e, 0x00, 0x08 };
BYTE timer[] = { 0xd0, 0x1d, 0x04, 0xe8 };
BYTE mpoints1[] = { 0x0f, 0xff, 0xff, 0xff };
BYTE mpoints2[] = { 0x90, 0x68, 0x04, 0x14 };
BYTE mpoints3[] = { 0x93, 0xba, 0x04, 0x14 };
BYTE lpoints1[] = { 0x93, 0xba, 0x04, 0x14 };
BYTE lpoints2[] = { 0x93, 0xba, 0x04, 0x14 };

VOID TrainerLoaded()
{
	PulseController();
	pop(L"~TeamXPG~ t3furys XPG Exclusives\r\nSSF 4 Arcade Edition +2 Trainer Loaded");
}


VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"~TeamXPG~ t3furys XPG Exclusives", L"SSF 4 Arcade Edition +2 Trainer\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
}

VOID ButPress( MESSAGEBOX_RESULT g_mb_result )
{

    if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
    {
		Sleep(500);
		     //this is the page that shows all available cheats  \r\n indicates create new line
			XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nUltra Bar LB(x4)\r\nSuper Bar RB(x4)\r\nHope You Enjoy\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nXPGamesaves.com\r\nHome To TeamXPG and 360 Revolution", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
		
		if( InfGrenades == TRUE )
		{
			pop(L"Super Bar Deactivated");
			DoCheat(0x8218BD54, nades, 4);
			DoCheat(0x8218BD6C, nades, 4);
			CheatRB = FALSE;
			PulseController();

		}else{
			
			pop(L"Super Bar Activated");			
			DoCheat(0x8218BD54, nopnades, 4);
			DoCheat(0x8218BD6C, nopnades, 4);
			CheatRB = true;
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
		
		if( InfMoney == TRUE )
		{
			pop(L"Ultra Bar Deactivated");
			DoCheat(0x8218BFAC, nano, 4);
			DoCheat(0x8218BFC4, nano, 4);
			CheatLB = FALSE;
			PulseController();
		}else{
			pop(L"Ultra Bar Activated");
			DoCheat(0x8218BFAC, nopnano, 4);
			DoCheat(0x8218BFC4, nopnano, 4);
			CheatLB = TRUE;
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
		
		if( AllCheats == TRUE )
		{
			pop(L"All Cheats Deactivated");
			DoCheat(0x8218BD54, nades, 4);
			DoCheat(0x8218BD6C, nades, 4);
			DoCheat(0x8218BFAC, nano, 4);
			DoCheat(0x8218BFC4, nano, 4);
			CheatDU = FALSE;
			PulseController();

		}else{
			
			pop(L"All Cheats Activated");
			DoCheat(0x8218BD54, nop, 4);
			DoCheat(0x8218BD6C, nop, 4);
			DoCheat(0x8218BFAC, nop, 4);
			DoCheat(0x8218BFC4, nop, 4);
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