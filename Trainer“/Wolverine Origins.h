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
BYTE nopskillpoints[] = { 0x60, 0x00, 0x00, 0x00 };

BYTE max[] = { 0x0f, 0xff, 0xff, 0xff };
BYTE max1[] = { 0x0f, 0xff, 0xff, 0xff };
BYTE max2[] = { 0x0f, 0xff, 0xff, 0xff };

BYTE nano[] = { 0x7d, 0x2b, 0x5a, 0x14 };

BYTE ammo[] = { 0xd3, 0xff, 0x09, 0x40 };

BYTE health[] = { 0xd0, 0x19, 0x00, 0x58 };

BYTE nades[] = { 0x91, 0x03, 0x00, 0x00 };

BYTE nv[] = { 0xd1, 0xbf, 0x01, 0x60 };

BYTE skillpoints[] = { 0x91, 0x1f, 0x00, 0x50 };

VOID TrainerLoaded()
{
	PulseController();
	pop(L"~TeamXPG~ t3furys XPG Exclusives\r\nWolverine X-men Origins +4 Trainer Loaded");
}


VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"~TeamXPG~ t3furys XPG Exclusives", L"Wolverine X-Men Origins +4 Trainer\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
}

VOID ButPress( MESSAGEBOX_RESULT g_mb_result )
{

    if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
    {
		Sleep(500);
		     //this is the page that shows all available cheats  \r\n indicates create new line
			XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nInf Rage LT(x4)\r\nInf Skills Points RB(x4)\r\nMax Level LB(x4)\r\nHope You Enjoy\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nXPGamesaves.com\r\nHome To TeamXPG and 360 Revolution", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
			pop(L"Inf Skill Points Deactivated");
			DoCheat(0x829CBA80, skillpoints, 4);
			CheatRB = FALSE;
			PulseController();

		}else{
			
			pop(L"Inf Skill Points Activated");			
			DoCheat(0x42768630, max, 4);
			DoCheat(0x42778630, max, 4);
			DoCheat(0x829CBA80, nopskillpoints, 4);
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
		
		if( CheatLB == TRUE )
		{
			pop(L"Max Level Deactivated");
			DoCheat(0x829CB9B4, nano, 4);
			CheatLB = FALSE;
			PulseController();
		}else{
			pop(L"Max Level Activated");
			DoCheat(0x829CB9B4, nop, 4);
			CheatLB = TRUE;
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
		
		if( CheatLT == TRUE )
		{
			pop(L"Inf Rage Deactivated");
			DoCheat(0x82A1B3FC, ammo, 4);
			CheatLT = FALSE;
	        PulseController();

		}else{
			
			pop(L"Inf Rage Activated");
			DoCheat(0x82A1B3FC, nopammo, 4);
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
		
		if( CheatRT == TRUE )
		{
			pop(L"Inf Health Deactivated");
			DoCheat(0x829A79C8, health, 4);
			CheatRT = FALSE;
	        PulseController();

		}else{
			
			pop(L"Inf Health Activated");
			DoCheat(0x829A79C8, nophealth, 4);
			CheatRT = TRUE;
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
			DoCheat(0x82E1B864, nano, 4);
			DoCheat(0x82A1B3FC, ammo, 4);
			DoCheat(0x829A79C8, health, 4);
			DoCheat(0x829CBA80, skillpoints, 4);
			CheatDU = FALSE;
	        PulseController();

		}else{
			
			pop(L"All Cheats Activated");
			DoCheat(0x42768630, max, 4);
			DoCheat(0x42778630, max, 4);
			DoCheat(0x82E1B864, nopnano, 4);
			DoCheat(0x82A1B3FC, nopammo, 4);
			DoCheat(0x829A79C8, nophealth, 4);
			DoCheat(0x829CBA80, nopskillpoints, 4);
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