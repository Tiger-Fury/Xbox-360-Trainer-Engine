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
BYTE nopnano[] = { 0xD1, 0xAA, 0x13, 0x8C };//D1AA138C
BYTE nopnades[] = { 0x39, 0x20, 0x03, 0xe7 }; //392003E7
BYTE nopnades1[] = { 0x39, 0xe0, 0x03, 0xe7 };//38E003E7
BYTE nopnades2[] = { 0x60, 0x00, 0x00, 0x00 };
BYTE nopammo[] = { 0x39, 0x2a, 0x00, 0xff };//392A00ff
BYTE nophealth[] = { 0x60, 0x00, 0x00, 0x00 };
BYTE nophealth2[] = { 0x38, 0xe9, 0x00, 0x63 };//38E90063
BYTE nophealth1[] = { 0x38, 0x89, 0x00, 0x63 };// 38890063
BYTE nopnv[] = { 0x60, 0x00, 0x00, 0x00 };


BYTE ammo[] = { 0x7d, 0x2a, 0x5a, 0x14 };// 7D2A5A14
BYTE health1[] = { 0xd1, 0x9d, 0x02, 0x18 }; //D19D0218

BYTE nades[] = { 0x91, 0x63, 0x00, 0x04 };
BYTE money1[] = { 0xd0, 0xab, 0x00, 0x00 }; //D0AB0000
BYTE money2[] = { 0xd1, 0xbf, 0x13, 0x8c }; //D1BF138C
BYTE mines[] = { 0x7d, 0x24, 0x4a, 0x14 }; //7D244A14
BYTE mines1[] = { 0x7c, 0xeb, 0x40, 0x50 };//7CEB4050
BYTE mines2[] = { 0x7d, 0x26, 0x21, 0x1e };//7D26212E
BYTE timer[] = { 0x7d, 0x0b, 0x51, 0x2e }; //7D0B512E
BYTE timer1[] = { 0x38, 0x89, 0x00, 0x01 };//38890001
BYTE timer2[] = { 0x38, 0xe9, 0x00, 0x02 };//38E90002
BYTE mpoints1[] = { 0x91, 0x2a, 0x00, 0x00 };
BYTE mpoints2[] = { 0x91, 0x68, 0x00, 0x04 };
BYTE mpoints3[] = { 0x93, 0xba, 0x04, 0x14 };
BYTE lpoints1[] = { 0x91, 0x7f, 0x00, 0x70 };
BYTE lpoints2[] = { 0x93, 0xba, 0x04, 0x14 };
BYTE chained[] = { 0xd1, 0x88, 0x00, 0x00 };

VOID TrainerLoaded()
{
	PulseController();
	pop(L"~TeamXPG~ t3fury\r\nHitman Absolution +3 Trainer Loaded");
}


VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"~TeamXPG~ t3fury", L"Hitman Absolution +3\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
}

VOID ButPress( MESSAGEBOX_RESULT g_mb_result )
{

    if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
    {
		Sleep(500);
		     //this is the page that shows all available cheats  \r\n indicates create new line
			XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nInf Ammo LT(x4)\r\nInf Instinct LB(x4)\r\nHope You Enjoy\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nXPGamesaves.com\r\nHome To TeamXPG and 360 Revolution", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

        memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
        memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
        memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
        memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
        Prompt = 0x9999;

    }
	// 1st Cheat

    if( g_mb_result.rgwPasscode[0] == LEFT_BUMPER && g_mb_result.rgwPasscode[1] == LEFT_BUMPER && g_mb_result.rgwPasscode[2] == LEFT_BUMPER && g_mb_result.rgwPasscode[3] == LEFT_BUMPER )
	{
		Sleep(500);
		
		if( InfMoney == TRUE )
		{
			pop(L"Inf Instinct Deactivated");
			DoCheat(0x829DF2F0, money1, 4);
			InfMoney = FALSE;
			PulseController();
		}else{
			pop(L"Inf Instinct Activated");
			DoCheat(0x829DF2F0, nop, 4);
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
			DoCheat(0x82A15E84, ammo, 4);
			InfAmmo = FALSE;
	        PulseController();

		}else{
			
			pop(L"Inf Ammo Activated");
			DoCheat(0x82A15E84, nopammo, 4);
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
			DoCheat(0x829DE574, health1, 4);
			InfHealth = FALSE;
	        PulseController();

		}else{
			
			pop(L"Inf Health Activated");
			DoCheat(0x829DE574, nophealth, 4);
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
		
		if( AllCheats == TRUE )
		{
			pop(L"All Cheats Deactivated");
			DoCheat(0x829DF2F0, money1, 4);
			DoCheat(0x82A15E84, ammo, 4);
			DoCheat(0x829DE574, health1, 4);
			AllCheats = FALSE;
	        PulseController();

		}else{
			
			pop(L"All Cheats Activated");
			DoCheat(0x829DF2F0, nop, 4);
			DoCheat(0x82A15E84, nopammo, 4);
			DoCheat(0x829DE574, nophealth, 4);
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