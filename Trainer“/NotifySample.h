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

BYTE skillp[] = { 0x39, 0x60, 0x03, 0xe7 };
BYTE skillpo[] = { 0x7d, 0x69, 0x58, 0x50 };

BYTE clip[] = { 0x39, 0x6b, 0x00, 0xff };
BYTE clipo[] = { 0x39, 0x6b, 0xff, 0xff };

BYTE salo[] = { 0x7d, 0x75, 0x07, 0x34 };
BYTE sal[] = { 0x3b, 0xe0, 0x27, 0x0f };


VOID TrainerLoaded()
{
	PulseController();
	pop(L"GameName Trainer Loaded by JACKASS");
}


VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"Viewing All Codes - Hold in Game", L"Inf Health LB+RB+Y\r\nInf Ammo LB+RB+X\r\nNo Reload LB+RB+A\r\n9999 Max Pickup LB+RB+DPAD RIGHT\r\n999 SKill Points LB+RB+DPAD LEFT", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);
}

VOID ButPress(){

		XINPUT_STATE state; WCHAR r1[512];
		ZeroMemory( &state, sizeof(XINPUT_STATE) );
		while (1){

		if (XInputGetState(0, &state) == ERROR_SUCCESS)
		{
				/* Start Quick Codes */
				if(state.Gamepad.wButtons == (XINPUT_GAMEPAD_LEFT_SHOULDER | XINPUT_GAMEPAD_RIGHT_SHOULDER | XINPUT_GAMEPAD_B))
				{
					PulseController();					
					InfHealth = TRUE;
					DoCheat(0x88888888, ammo, 4);
					CheatXX = TRUE;
					DoCheat(0x88888888, clip, 4);
					CheatLB = TRUE;
					DoCheat(0x88888888, sal, 4);
					CheatRB = true;
					pop(L"All Cheats Activated");
				}

			    if(state.Gamepad.wButtons == (XINPUT_GAMEPAD_LEFT_SHOULDER | XINPUT_GAMEPAD_RIGHT_SHOULDER | XINPUT_GAMEPAD_Y))
				{
					if( InfHealth == TRUE ) {
					
					InfHealth = FALSE;
					pop(L"Inf Health Disabled");
					PulseController();

					} else {

					InfHealth = TRUE;
					pop(L"Inf Health Enabled");
					PulseController();

					}
				}

				if(state.Gamepad.wButtons == (XINPUT_GAMEPAD_LEFT_SHOULDER | XINPUT_GAMEPAD_RIGHT_SHOULDER | XINPUT_GAMEPAD_X))
				{
					if( CheatXX == TRUE ) {
					
					CheatXX = FALSE;
					DoCheat(0x88888888, ammoo, 4);
					pop(L"Inf Ammo Disabled");
					PulseController();

					} else {

					CheatXX = TRUE;
					DoCheat(0x88888888, ammo, 4);
					pop(L"Inf Ammo Enabled");
					PulseController();

					}
				}

				if(state.Gamepad.wButtons == (XINPUT_GAMEPAD_LEFT_SHOULDER | XINPUT_GAMEPAD_RIGHT_SHOULDER | XINPUT_GAMEPAD_A))
				{
					if( CheatLB == TRUE ) {
					
					CheatLB = FALSE;
					DoCheat(0x88888888, clipo, 4);
					pop(L"No Reload Disabled");
					PulseController();

					} else {

					CheatLB = TRUE;
					DoCheat(0x88888888, clip, 4);
					pop(L"No Reload Enabled");
					PulseController();

					}
				}

				if(state.Gamepad.wButtons == (XINPUT_GAMEPAD_LEFT_SHOULDER | XINPUT_GAMEPAD_RIGHT_SHOULDER | XINPUT_GAMEPAD_DPAD_RIGHT))
				{
					if( CheatRB == TRUE ) {
					
					CheatRB = FALSE;
					DoCheat(0x88888888, salo, 4);
					pop(L"9999 Salvage/Ammo Pickup Disabled");
					PulseController();

					} else {

					CheatRB = TRUE;
					DoCheat(0x88888888, sal, 4);
					pop(L"9999 Salvage/Ammo Pickup Enabled");
					PulseController();

					}
				}

				if(state.Gamepad.wButtons == (XINPUT_GAMEPAD_LEFT_SHOULDER | XINPUT_GAMEPAD_RIGHT_SHOULDER | XINPUT_GAMEPAD_DPAD_LEFT))
				{
					if( CheatRT == TRUE ) {
					
					CheatRT = FALSE;
					DoCheat(0x88888888, skillpo, 4);
					pop(L"999 Skill Points Disabled");
					PulseController();

					} else {
						
					CheatRT = TRUE;
					DoCheat(0x88888888, skillp, 4);
					pop(L"999 Skill Points Enabled - Disable after you gain 999");
					PulseController();

					}
				}
				/* End quick codes */

				/* Static offsets */
				if( InfHealth == TRUE ) {
					DoCheat(0x88888888, health, 4);
					DoCheat(0x88888888, health, 4);
				}
				/* End static offsets */
		
		}
		Sleep(500);
	 }
} 


VOID ProcessButtonPress( MESSAGEBOX_RESULT g_mb_result )
{

}