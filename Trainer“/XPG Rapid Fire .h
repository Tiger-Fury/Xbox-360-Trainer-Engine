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

BYTE nano[] = { 0xd1, 0xbf, 0x00, 0x18 };

BYTE ammo[] = { 0x91, 0x7b, 0x00, 0x20 };

BYTE health[] = { 0xd1, 0x3d, 0x00, 0x08 };

BYTE nades[] = { 0x91, 0x7f, 0x00, 0x08 };

BYTE nv[] = { 0xd1, 0xbf, 0x01, 0x60 };

VOID TrainerLoaded()
{
	PulseController();
	pop(L"t3furys XPG Exclusives\r\nJurassic The Hunted +4 Trainer Loaded");
}


VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"~TeamXPG~ t3furys XPG Exclusives", L"Jurassic The Hunted +4 Trainer\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
}

VOID ButPress( MESSAGEBOX_RESULT g_mb_result )
{

    if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
    {
		Sleep(500);
		     //this is the page that shows all available cheats  \r\n indicates create new line
			XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nInf Ammo LT(x4)\r\nInf Nano Energy LB(x4)\r\nInf Grenades RB(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nXPGamesaves.com\r\nHome To TeamXPG and 360 Revolution", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

	InputValue();

    }
	// 1st Cheat
		if( g_mb_result.rgwPasscode[0] == RIGHT_BUMPER && g_mb_result.rgwPasscode[1] == RIGHT_BUMPER && g_mb_result.rgwPasscode[2] == RIGHT_BUMPER && g_mb_result.rgwPasscode[3] == RIGHT_BUMPER )
	{
		Sleep(500);
		
		if( CheatRB == TRUE )
		{
			pop(L"Inf Grenades Deactivated");
			DoCheat(0x821321D0, nades, 4);
			CheatRB = FALSE;
			PulseController();

		}else{
			
			pop(L"Inf Grenades Activated");			
			DoCheat(0x821321D0, nopnades, 4);
			CheatRB = true;
			PulseController();

		}

		InputValue();
	}
		// 2nd cheat
    if( g_mb_result.rgwPasscode[0] == LEFT_BUMPER && g_mb_result.rgwPasscode[1] == LEFT_BUMPER && g_mb_result.rgwPasscode[2] == LEFT_BUMPER && g_mb_result.rgwPasscode[3] == LEFT_BUMPER )
	{
		Sleep(500);
		
		if( CheatLB == TRUE )
		{
			pop(L"Inf Adrenaline Deactivated");
			DoCheat(0x823B6814, nano, 4);
			CheatLB = FALSE;
			PulseController();
		}else{
			pop(L"Inf Adrenaline Activated");
			DoCheat(0x823B6814, nopnano, 4);
			CheatLB = TRUE;
			PulseController();
		}

		InputValue();
	}
	//3rd Cheat
	if( g_mb_result.rgwPasscode[0] == LEFT_TRIGGER && g_mb_result.rgwPasscode[1] == LEFT_TRIGGER && g_mb_result.rgwPasscode[2] == LEFT_TRIGGER && g_mb_result.rgwPasscode[3] == LEFT_TRIGGER )
	{
		Sleep(500);
		
		if( CheatLT == TRUE )
		{
			pop(L"Inf Ammo Deactivated");
			DoCheat(0x82235824, ammo, 4);
			CheatLT = FALSE;
	        PulseController();

		}else{
			
			pop(L"Inf Ammo Activated");
			DoCheat(0x82235824, nopammo, 4);
			CheatLT = TRUE;
		    PulseController();

		}

		InputValue();
	}
	//4th cheat
			if( g_mb_result.rgwPasscode[0] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[1] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[2] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[3] == RIGHT_TRIGGER )
	{
		Sleep(500);
		
		if( CheatRT == TRUE )
		{
			pop(L"Inf Health Deactivated");
			DoCheat(0x823693E8, health, 4);
			CheatRT = FALSE;
	        PulseController();

		}else{
			
			pop(L"Inf Health Activated");
			DoCheat(0x823693E8, nophealth, 4);
			CheatRT = TRUE;
		    PulseController();

		}

		InputValue();
	}
	//6th cheat Multi Activate
	if( g_mb_result.rgwPasscode[0] == DPAD_UP && g_mb_result.rgwPasscode[1] == DPAD_UP && g_mb_result.rgwPasscode[2] == DPAD_UP && g_mb_result.rgwPasscode[3] == DPAD_UP )
	{
		Sleep(500);
		
		if( CheatDU == TRUE )
		{
			pop(L"All Cheats Deactivated");
			DoCheat(0x823693E8, health, 4);
			DoCheat(0x82235824, ammo, 4);
			DoCheat(0x823B6814, nano, 4);
			DoCheat(0x821321D0, nades, 4);
			CheatDU = FALSE;
	        PulseController();

		}else{
			
			pop(L"All Cheats Activated");
			DoCheat(0x823693E8, nophealth, 4);
			DoCheat(0x82235824, nopammo, 4);
			DoCheat(0x823B6814, nopnano, 4);
			DoCheat(0x821321D0, nopnades, 4);
			CheatDU = TRUE;
		    PulseController();

		}

		InputValue();
	}
				
		}
 


VOID ProcessButtonPress( MESSAGEBOX_RESULT g_mb_result )
{

}