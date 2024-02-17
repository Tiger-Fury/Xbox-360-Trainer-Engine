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


BYTE ammo[] = { 0x91, 0x63, 0x00, 0x0c };
BYTE health1[] = { 0xd1, 0xbf, 0x05, 0xb8 };
BYTE health2[] = { 0xb1, 0x4b, 0x00, 0x04 };
BYTE nades[] = { 0x91, 0x63, 0x00, 0x04 };
BYTE money1[] = { 0xd1, 0x7f, 0x14, 0xec };
BYTE money2[] = { 0x81, 0x63, 0x00, 0xd4 };
BYTE mines[] = { 0xd1, 0x6b, 0x00, 0x00 };
BYTE timer[] = { 0xd1, 0x9f, 0x14, 0xbc };
BYTE mpoints1[] = { 0x91, 0x2a, 0x00, 0x00 };
BYTE mpoints2[] = { 0x91, 0x68, 0x00, 0x04 };
BYTE mpoints3[] = { 0x93, 0xba, 0x04, 0x14 };
BYTE lpoints1[] = { 0x91, 0x7f, 0x00, 0x70 };
BYTE lpoints2[] = { 0x93, 0xba, 0x04, 0x14 };
BYTE chained[] = { 0xd1, 0x88, 0x00, 0x00 };

VOID TrainerLoaded()
{
	PulseController();
	pop(L"~TeamXPG~ t3furys XPG Exclusives\r\nHow To Survive +12 Trainer Loaded");
}


VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"~TeamXPG~ t3furys XPG Exclusives", L"How To Survive +12 Trainer\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
}

VOID ButPress( MESSAGEBOX_RESULT g_mb_result )
{

    if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
    {
		Sleep(500);
		     //this is the page that shows all available cheats  \r\n indicates create new line
			XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Medical Items Y(x4)\r\nInf Craft Items Y(x3)+X\r\nInf Health RT(x4)\r\nInf Ammo LT(x4)\r\nInf Stamina LB(x4)\r\nInf Arrows RB(x4)\r\nNo Hunger X(x4)\r\nInf Flame Stick LT,RT,LT,RT\r\nInf Skill Points LB,RB,LB,RB\r\nInf Gas LB(x3)+LT\r\nHope You Enjoy\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nXPGamesaves.com\r\nHome To TeamXPG and 360 Revolution", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
			pop(L"Inf Arrows Deactivated");
			DoCheat(0x824EE444, nades, 4);
			InfGrenades = FALSE;
			PulseController();

		}else{
			
			pop(L"Inf Arrows Activated");			
			DoCheat(0x824EE444, nopnades, 4);
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
				pop(L"No Hunger, No Thirst, No Sleep Deactivated");
				DoCheat(0x8244B280, mines, 4);
				CheatRB = FALSE;
				PulseController();

			}else{

				pop(L"No Hunger, No Thirst, No Sleep Activated");			
				DoCheat(0x8244B280, nopnades, 4);
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
			pop(L"Inf Stamina Deactivated");
			DoCheat(0x825112F8, money1, 4);
			InfMoney = FALSE;
			PulseController();
		}else{
			pop(L"Inf Stamina Activated");
			DoCheat(0x825112F8, nopnano, 4);;
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
			pop(L"Inf Skill Points Deactivated");
			DoCheat(0x824DA22C, lpoints1, 4);
			InfMoney = FALSE;
			PulseController();
		}else{
			pop(L"Inf Skill Points Activated");
			DoCheat(0x824DA22C, nopnano, 4);
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
			DoCheat(0x824EE414, ammo, 4);
			InfAmmo = FALSE;
	        PulseController();

		}else{
			
			pop(L"Inf Ammo Activated");
			DoCheat(0x824EE414, nopammo, 4);
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
			DoCheat(0x8250F154, health1, 4);
			InfHealth = FALSE;
	        PulseController();

		}else{
			
			pop(L"Inf Health Activated");
			DoCheat(0x8250F154, nophealth, 4);
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
					pop(L"Inf Flame Stick Deactivated");
					DoCheat(0x824B38F0, timer, 4);
					InfTimer = FALSE;
					PulseController();

				}else{

					pop(L"Inf Flame Stick Activated");
					DoCheat(0x824B38F0, nophealth, 4);
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
			pop(L"Inf Medical Items Deactivated");
			DoCheat(0x82426FB4, mpoints1, 4);
			CheatYY = FALSE;
	        PulseController();

		}else{
			
			pop(L"Inf Medical Items Activated");
			DoCheat(0x82426FB4, nopnv, 4);
			CheatYY = TRUE;
		    PulseController();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
	if( g_mb_result.rgwPasscode[0] == Y_BUTTON && g_mb_result.rgwPasscode[1] == Y_BUTTON && g_mb_result.rgwPasscode[2] == Y_BUTTON && g_mb_result.rgwPasscode[3] == X_BUTTON )
	{
		Sleep(500);

		if( CheatYY == TRUE )
		{
			pop(L"Inf Craft Items Deactivated");
			DoCheat(0x82423C08, mpoints2, 4);
			CheatYY = FALSE;
			PulseController();

		}else{

			pop(L"Inf Craft Items Activated");
			DoCheat(0x82423C08, nopnv, 4);
			CheatYY = TRUE;
			PulseController();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
	if( g_mb_result.rgwPasscode[0] == LEFT_BUMPER && g_mb_result.rgwPasscode[1] == LEFT_BUMPER && g_mb_result.rgwPasscode[2] == LEFT_BUMPER && g_mb_result.rgwPasscode[3] == LEFT_TRIGGER )
	{
		Sleep(500);

		if( OneHitKo == TRUE )
		{
			pop(L"Inf ChainSaw Gas Deactivated");
			DoCheat(0x824F502C, chained, 4);
			InfMoney = FALSE;
			PulseController();
		}else{
			pop(L"Inf ChainSaw Gas Activated");
			DoCheat(0x824F502C, nopnano, 4);
			InfMoney = TRUE;
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
			DoCheat(0x824EE444, nades, 4);
			DoCheat(0x8244B280, mines, 4);
			DoCheat(0x825112F8, money1, 4);
			DoCheat(0x824DA22C, lpoints1, 4);
			DoCheat(0x824EE414, ammo, 4);
			DoCheat(0x8250F154, health1, 4);
			DoCheat(0x824B38F0, timer, 4);
			DoCheat(0x82426FB4, mpoints1, 4);
			DoCheat(0x82423C08, mpoints2, 4);
			DoCheat(0x824F502C, chained, 4);
			AllCheats = FALSE;
	        PulseController();

		}else{
			
			pop(L"All Cheats Activated");
			DoCheat(0x824EE444, nopnades, 4);
			DoCheat(0x8244B280, nop, 4);
			DoCheat(0x825112F8, nop, 4);
			DoCheat(0x824DA22C, nop, 4);
			DoCheat(0x824EE414, nopammo, 4);
			DoCheat(0x8250F154, nophealth, 4);
			DoCheat(0x824B38F0, nop, 4);
			DoCheat(0x82426FB4, nop, 4);
			DoCheat(0x82423C08, nop, 4);
			DoCheat(0x824F502C, nopnano, 4);
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