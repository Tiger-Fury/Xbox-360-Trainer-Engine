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


BYTE ammo[] = { 0x91, 0x44, 0x00, 0x08 };
BYTE health1[] = { 0xb0, 0xdf, 0x12, 0xe4 };
BYTE health2[] = { 0xb1, 0x4b, 0x00, 0x04 };
BYTE nades[] = { 0x93, 0xb8, 0x00, 0x08 };
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
	pop(L"~TeamXPG~ t3furys XPG Exclusives\r\nResident Evil 5 +8 Trainer Loaded");
}


VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"~TeamXPG~ t3furys XPG Exclusives", L"Resident Evil 5 +8 Trainer\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
}

VOID ButPress( MESSAGEBOX_RESULT g_mb_result )
{

    if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
    {
		Sleep(500);
		     //this is the page that shows all available cheats  \r\n indicates create new line
			XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Merc Points Y(x4)\r\nInf Health RT(x4)\r\nInf Ammo LT(x4)\r\nInf Money LB(x4)\r\nInf Grenades RB(x4)\r\nInf Mines X(x4)\r\nInf Timer LT,RT,LT,RT\r\nSpencer Estate Points LB,RB,LB,RB\r\nHope You Enjoy\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nXPGamesaves.com\r\nHome To TeamXPG and 360 Revolution", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
			pop(L"Inf Grenades Deactivated");
			DoCheat(0x823096B4, nades, 4);
			InfGrenades = FALSE;
			PulseController();

		}else{
			
			pop(L"Inf Grenades Activated");			
			DoCheat(0x823096B4, nopnades, 4);
			InfGrenades = true;
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

			if( CheatRB == TRUE )
			{
				pop(L"Inf Mines Deactivated");
				DoCheat(0x82308F44, mines, 4);
				CheatRB = FALSE;
				PulseController();

			}else{

				pop(L"Inf Mines Activated");			
				DoCheat(0x82308F44, nopnades, 4);
				CheatRB = true;
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
		
		if( InfMoney == TRUE )
		{
			pop(L"Inf Money Deactivated");
			DoCheat(0x828007A0, money1, 4);
			DoCheat(0x828007B0, money2, 4);
			InfMoney = FALSE;
			PulseController();
		}else{
			pop(L"Inf Money Activated");
			DoCheat(0x828007A0, nopnano, 4);
			DoCheat(0x828007B0, nop, 4);
			InfMoney = TRUE;
			PulseController();
		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
	if( g_mb_result.rgwPasscode[0] == LEFT_BUMPER && g_mb_result.rgwPasscode[1] == RIGHT_BUMPER && g_mb_result.rgwPasscode[2] == LEFT_BUMPER && g_mb_result.rgwPasscode[3] == RIGHT_BUMPER )
	{
		Sleep(500);

		if( InfMoney == TRUE )
		{
			pop(L"Lost In & Desperate ESC Points Deactivated");
			DoCheat(0x826919E4, lpoints1, 4);
			DoCheat(0x8230B264, lpoints2, 4);
			InfMoney = FALSE;
			PulseController();
		}else{
			pop(L"Lost In & Desperate ESC Points Activated");
			DoCheat(0x826919E4, nopnano, 4);
			DoCheat(0x8230B264, nop, 4);
			InfMoney = TRUE;
			PulseController();
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
			pop(L"Inf Ammo Deactivated");
			DoCheat(0x82766954, ammo, 4);
			InfAmmo = FALSE;
	        PulseController();

		}else{
			
			pop(L"Inf Ammo Activated");
			DoCheat(0x82766954, nopammo, 4);
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
			DoCheat(0x8269A8CC, health1, 4);
			DoCheat(0x8269A8DC, health2, 4);
			InfHealth = FALSE;
	        PulseController();

		}else{
			
			pop(L"Inf Health Activated");
			DoCheat(0x8269A8CC, nophealth, 4);
			DoCheat(0x8269A8DC, nophealth, 4);
			InfHealth = TRUE;
		    PulseController();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
			if( g_mb_result.rgwPasscode[0] == LEFT_TRIGGER && g_mb_result.rgwPasscode[1] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[2] == LEFT_TRIGGER && g_mb_result.rgwPasscode[3] == RIGHT_TRIGGER )
			{
				Sleep(500);

				if( InfTimer == TRUE )
				{
					pop(L"Stop The Clock Deactivated");
					DoCheat(0x82239A14, timer, 4);
					InfTimer = FALSE;
					PulseController();

				}else{

					pop(L"Stop The Clock Activated");
					DoCheat(0x82239A14, nophealth, 4);
					InfTimer = TRUE;
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
		
		if( CheatYY == TRUE )
		{
			pop(L"Inf/Max Merc Points Deactivated");
			DoCheat(0x07473F14, mpoints1, 4);
			DoCheat(0x8224125C, mpoints2, 4);
			DoCheat(0x822394A8, mpoints3, 4);
			CheatYY = FALSE;
	        PulseController();

		}else{
			
			pop(L"Inf/Max Merc Points Activated");
			DoCheat(0x07473F14, nopnv, 4);
			DoCheat(0x8224125C, nopnv, 4);
			DoCheat(0x822394A8, nopnv, 4);
			CheatYY = TRUE;
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
		
		if( AllCheats == TRUE )
		{
			pop(L"All Cheats Deactivated");
			DoCheat(0x823096B4, nades, 4);
			DoCheat(0x82766954, ammo, 4);
			DoCheat(0x8269A8CC, health1, 4);
			DoCheat(0x8269A8DC, health2, 4);
			DoCheat(0x828007A0, money1, 4);
			DoCheat(0x828007B0, money2, 4);
			DoCheat(0x07473F14, mpoints1, 4);
			DoCheat(0x8224125C, mpoints2, 4);
			DoCheat(0x822394A8, mpoints3, 4);
			DoCheat(0x82308F44, mines, 4);
			DoCheat(0x826919E4, lpoints1, 4);
			DoCheat(0x8230B264, lpoints2, 4);
			AllCheats = FALSE;
	        PulseController();

		}else{
			
			pop(L"All Cheats Activated");
			DoCheat(0x823096B4, nopnades, 4);
			DoCheat(0x82766954, nopammo, 4);
			DoCheat(0x8269A8CC, nophealth, 4);
			DoCheat(0x8269A8DC, nophealth, 4);
			DoCheat(0x828007A0, nop, 4);
			DoCheat(0x828007B0, nop, 4);
			DoCheat(0x07473F14, mpoints1, 4);
			DoCheat(0x8224125C, nop, 4);
			DoCheat(0x822394A8, nop, 4);
			DoCheat(0x82308F44, nop, 4);
			DoCheat(0x826919E4, nop, 4);
			DoCheat(0x8230B264, nop, 4);
			AllCheats = TRUE;
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