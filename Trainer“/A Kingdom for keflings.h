#include "common.h"

UINT32 g_titleID = 0x584108DB;

bool AIAmmo = false;
bool InfBP = false;
bool TU = false;



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

BYTE nano[] = { 0x7d, 0x6b, 0x52, 0x14 }; // 7D6B5214

BYTE XpMode[] = { 0x39, 0x60, 0x7f, 0xff }; // 39607FFF

BYTE ammo[] = { 0x91, 0x7f, 0x05, 0x84 }; // 917F0584

BYTE health[] = { 0x91, 0x5f, 0x00, 0x10 }; // 915F0010
BYTE healthact[] = { 0x39, 0x60, 0x27, 0x10 }; // on 39602710

BYTE nades[] = { 0x90, 0x88, 0x00, 0x64 }; // 90880064

BYTE nv[] = { 0xd1, 0xbf, 0x01, 0x60 };



VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"More At T3furyGaming.co.uk", L"A Kingdom For Keflings +1 Trainer\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
}

VOID ButPress( MESSAGEBOX_RESULT g_mb_result )
{

    if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
    {
		Sleep(500);
		     //this is the page that shows all available cheats  \r\n indicates create new line
			XShowMessageBoxUI(0, L"Viewing All Available Codes", L"Item Don't Decrease RT(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3furyGaming.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

        memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
        memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
        memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
        memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
        Prompt = 0x9999;

    }
	// 1st Cheat
			if( g_mb_result.rgwPasscode[0] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[1] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[2] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[3] == RIGHT_TRIGGER )
	{
		Sleep(500);
		
		if( CheatRT == TRUE )
		{
			pop(L"Item Don't Decrease  Deactivated");
			DoCheat(0x82164B60, health, 4);
			CheatRT = FALSE;
	     

		}else{
			
			pop(L"Item Don't Decrease Activated");
			DoCheat(0x82164B60, nophealth, 4);
			CheatRT = TRUE;
		   

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
	hNotify(L"A Kingdom For Keflings");
	Sleep(25);
	SetAddr = true;
}