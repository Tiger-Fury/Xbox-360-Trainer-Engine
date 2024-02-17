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

BYTE ammo[] = { 0x3b, 0xc0, 0x03, 0xe7 };
BYTE ammoo[] = { 0x7f, 0xcb, 0x07, 0x34 };

BYTE health[] = { 0x00, 0x00, 0x27, 0x0f };
BYTE health2[] = { 0x00, 0x00, 0x27, 0x0f };
BYTE health3[] = { 0x79, 0xff };
BYTE healthd[] = { 0x00, 0x70 };

BYTE SOR2Timer[] = { 0x91, 0x1f, 0x03, 0x64 };

BYTE skillp[] = { 0x39, 0x60, 0x03, 0xe7 };
BYTE skillpo[] = { 0x7d, 0x69, 0x58, 0x50 };

BYTE clip[] = { 0x39, 0x6b, 0x00, 0xff };
BYTE clipo[] = { 0x39, 0x6b, 0xff, 0xff };

BYTE salo[] = { 0x7d, 0x75, 0x07, 0x34 };
BYTE sal[] = { 0x3b, 0xe0, 0x27, 0x0f };

DWORD maxhealth = 0x821FD694;

VOID TrainerLoaded()
{
	PulseController();
	pop(L"protect Loaded");
}


VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"Viewing All Codes", L"Inf Health Right Thumb Stick", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);
}

VOID ButPress(){

		XINPUT_STATE state; WCHAR r1[512];
		ZeroMemory( &state, sizeof(XINPUT_STATE) );
		while (1){

		if (XInputGetState(0, &state) == ERROR_SUCCESS)
		{

				if(state.Gamepad.wButtons == (XINPUT_GAMEPAD_RIGHT_THUMB))
				{
					if( CheatXX == TRUE ) {
					
					CheatXX = FALSE;
					DoCheat(maxhealth, SOR2Timer, 4);
					pop(L"Inf Health Disabled");
					PulseController();

					} else {

					CheatXX = TRUE;
					DoCheat(maxhealth, nop, 4);
					pop(L"Inf Health Enabled");
					PulseController();

					}
				}

		
		}
		Sleep(500);
	 }
} 


VOID ProcessButtonPress( MESSAGEBOX_RESULT g_mb_result )
{

}