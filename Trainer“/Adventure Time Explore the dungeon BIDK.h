#include "common.h"

UINT32 g_titleID = 0x44500807;

bool AIAmmo = false;
bool InfBP = false;
bool TU = false;
bool InfGrenades = FALSE;
bool AllCheats = FALSE;
bool InfMoney = FALSE;


BYTE nop[] = { 0x60, 0x00, 0x00, 0x00 };
BYTE nopnano[] = { 0xD1, 0xAA, 0x13, 0x8C };//D1AA138C
BYTE nopnano1[] = { 0xD3, 0xff, 0x13, 0x8C };//D3FF138C
BYTE nopnades[] = { 0x39, 0x20, 0x03, 0xe7 }; //392003E7
BYTE nopnades1[] = { 0x39, 0xe0, 0x03, 0xe7 };//38E003E7
BYTE nopnades2[] = { 0x60, 0x00, 0x00, 0x00 };
BYTE nopammo[] = { 0x39, 0x6b, 0x00, 0x00 };//396B0000
BYTE nophealth[] = { 0x60, 0x00, 0x00, 0x00 };
BYTE nophealth2[] = { 0x38, 0xe9, 0x00, 0x63 };//38E90063
BYTE nophealth1[] = { 0x38, 0x89, 0x00, 0x63 };// 38890063
BYTE nopnv[] = { 0x60, 0x00, 0x00, 0x00 };


BYTE ammo[] = { 0x39, 0x6b, 0xff, 0xff };// 396BFFFF
BYTE health1[] = { 0xec, 0x00, 0xf8, 0x28 }; //EC00F828
BYTE health2[] = { 0xb1, 0x4b, 0x00, 0x04 };
BYTE nades[] = { 0x91, 0x63, 0x00, 0x04 };
BYTE money1[] = { 0xd0, 0x0A, 0x13, 0x8c }; //D00A138C
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


VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"More At T3furyGaming.co.uk", L"Adventure Time E.T.D BIDK +5\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
}

VOID ButPress( MESSAGEBOX_RESULT g_mb_result )
{

    if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
    {
		Sleep(500);
		     //this is the page that shows all available cheats  \r\n indicates create new line
			XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nInf Ammo LT(x4)\r\nInf Special LB(x4)\r\nInf Keys RB(x4)\r\nInf Treasure X(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3furyGaming.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

        memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
        memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
        memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
        memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
        Prompt = 0x9999;

    }
	// 1st Cheat

		if( g_mb_result.rgwPasscode[0] == X_BUTTON && g_mb_result.rgwPasscode[1] == X_BUTTON && g_mb_result.rgwPasscode[2] == X_BUTTON && g_mb_result.rgwPasscode[3] == X_BUTTON )
		{
			Sleep(500);

			if( CheatRB == TRUE )
			{
				pop(L"Inf Treasure Deactivated");
				DoCheat(0x82615638, mines, 4);
				DoCheat(0x82636C44, mines1, 4);
				DoCheat(0x826157F0, mines2, 4);
				CheatRB = FALSE;
				PulseController();

			}else{

				pop(L"Inf Treasure Activated");			
				DoCheat(0x82615638, nopnades, 4);
				DoCheat(0x82636C44, nopnades1, 4);
				DoCheat(0x826157F0, nopnades2, 4);
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
			pop(L"Inf Special Deactivated");
			DoCheat(0x82611F84, money1, 4);
			DoCheat(0x8261431C, money2, 4);
			InfMoney = FALSE;
			PulseController();
		}else{
			pop(L"Inf Special Activated");
			DoCheat(0x82611F84, nopnano, 4);
			DoCheat(0x8261431C, nopnano1, 4);
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
			DoCheat(0x8263A4E0, ammo, 4);
			InfAmmo = FALSE;
	        PulseController();

		}else{
			
			pop(L"Inf Ammo Activated");
			DoCheat(0x8263A4E0, nopammo, 4);
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
			DoCheat(0x82619610, health1, 4);
			InfHealth = FALSE;
	        PulseController();

		}else{
			
			pop(L"Inf Health Activated");
			DoCheat(0x82619610, nophealth, 4);
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

				if( InfTimer == TRUE )
				{
					pop(L"Inf keys Deactivated");
					DoCheat(0x82615BAC, timer, 4);
					DoCheat(0x82583028, timer1, 4);
					DoCheat(0x825CDCFC, timer2, 4);
					InfTimer = FALSE;
					PulseController();

				}else{

					pop(L"Inf keys Activated");
					DoCheat(0x82615BAC, nophealth, 4);
					DoCheat(0x82583028, nophealth1, 4);
					DoCheat(0x825CDCFC, nophealth2, 4);
					InfTimer = TRUE;
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
			DoCheat(0x82615BAC, timer, 4);
			DoCheat(0x82583028, timer1, 4);
			DoCheat(0x825CDCFC, timer2, 4);
			DoCheat(0x82619610, health1, 4);
			DoCheat(0x8263A4E0, ammo, 4);
			DoCheat(0x82615638, mines, 4);
			DoCheat(0x82636C44, mines1, 4);
			DoCheat(0x826157F0, mines2, 4);
			DoCheat(0x82611F84, money1, 4);
			DoCheat(0x8261431C, money2, 4);
			AllCheats = FALSE;
	        PulseController();

		}else{
			
			pop(L"All Cheats Activated");
			DoCheat(0x82615BAC, nophealth, 4);
			DoCheat(0x82583028, nophealth1, 4);
			DoCheat(0x825CDCFC, nophealth2, 4);
			DoCheat(0x82619610, nophealth, 4);
			DoCheat(0x8263A4E0, nopammo, 4);
			DoCheat(0x82615638, nopnades, 4);
			DoCheat(0x82636C44, nopnades1, 4);
			DoCheat(0x826157F0, nopnades2, 4);
			DoCheat(0x82611F84, nopnano, 4);
			DoCheat(0x8261431C, nopnano1, 4);
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

VOID SearchAddr()
{
	hNotify(L"Adventure Time Explore The Dungeon BIDK");
	Sleep(25);
	SetAddr = true;
}