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

BYTE SOR2Timer[] = { 0x7d, 0x2a, 0x59, 0xae };

BYTE skillp[] = { 0x39, 0x60, 0x03, 0xe7 };
BYTE skillpo[] = { 0x7d, 0x69, 0x58, 0x50 };

BYTE clip[] = { 0x39, 0x6b, 0x00, 0xff };
BYTE clipo[] = { 0x39, 0x6b, 0xff, 0xff };

BYTE salo[] = { 0x7d, 0x75, 0x07, 0x34 };
BYTE sal[] = { 0x3b, 0xe0, 0x27, 0x0f };


VOID TrainerLoaded()
{
	PulseController();
	pop(L"Streets Of Rage Collection Trainer+3 Loaded");
}


VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"Viewing All Codes", L"SoR 1 Freeze Time/inf Lives Left Thumb Stick\r\n~~~~~~~~~~~~~~\r\n Please Note Needs To Be Disabled At The End Of Each Level\r\n~~~~~~~~~~~~~~\r\nSoR 2 Freeze Timer Right Thumb Stick", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);
}

VOID ButPress(){

		XINPUT_STATE state; WCHAR r1[512];
		ZeroMemory( &state, sizeof(XINPUT_STATE) );
		while (1){

		if (XInputGetState(0, &state) == ERROR_SUCCESS)
		{
				/* Start Quick Codes */
				//if(state.Gamepad.wButtons == (XINPUT_GAMEPAD_RIGHT_SHOULDER))
				//{
				//	PulseController();					
				//	InfHealth = TRUE;
				//	DoCheat(0x4113C860, health3, 2);
				//	CheatXX = TRUE;
				//	DoCheat(0x82364D34, nop, 4);
				//	pop(L"Streets of Rage 2 Cheats Activated");
			//	}

			//    if(state.Gamepad.wButtons == (XINPUT_GAMEPAD_LEFT_THUMB))
			//	{
			//		if( InfHealth == TRUE ) {
					
			//		InfHealth = FALSE;
			//		pop(L"SoR2 Inf Health Disabled");
			//		DoCheat(0x4113C860, healthd, 2);
			//		PulseController();

			//		} else {

			//		InfHealth = TRUE;
			//		pop(L"SoR2 Inf Health Enabled");
			//		DoCheat(0x4113C860, health3, 2);
			//		PulseController();

			//		}
			//	}

				if(state.Gamepad.wButtons == (XINPUT_GAMEPAD_RIGHT_THUMB))
				{
					if( CheatXX == TRUE ) {
					
					CheatXX = FALSE;
					DoCheat(0x82364D34, SOR2Timer, 4);
					pop(L"Freeze Timer Disabled");
					PulseController();

					} else {

					CheatXX = TRUE;
					DoCheat(0x82364D34, nop, 4);
					pop(L"Freeze Timer Enabled");
					PulseController();

					}
				}

				if(state.Gamepad.wButtons == (XINPUT_GAMEPAD_LEFT_THUMB))
				{
					if( CheatLB == TRUE ) {
					
					CheatLB = FALSE;
					DoCheat(0x8236172C, SOR2Timer, 4);
					pop(L"Streets of Rage Cheats Deactivated");
					PulseController();

					} else {

					CheatLB = TRUE;
					DoCheat(0x8236172C, nop, 4);
					pop(L"Streets of Rage Cheats Activated");
					PulseController();

					}
				}

				//if(state.Gamepad.wButtons == (XINPUT_GAMEPAD_LEFT_SHOULDER | XINPUT_GAMEPAD_RIGHT_SHOULDER | XINPUT_GAMEPAD_DPAD_RIGHT))
			//	{
				//	if( CheatRB == TRUE ) {
					
				//	CheatRB = FALSE;
				//	DoCheat(0x88888888, salo, 4);
				//	pop(L"9999 Salvage/Ammo Pickup Disabled");
				//	PulseController();

				//	} else {

			//		CheatRB = TRUE;
			//		DoCheat(0x88888888, sal, 4);
			//		pop(L"9999 Salvage/Ammo Pickup Enabled");
			//		PulseController();

			//		}
			//	}

				//if(state.Gamepad.wButtons == (XINPUT_GAMEPAD_LEFT_SHOULDER | XINPUT_GAMEPAD_RIGHT_SHOULDER | XINPUT_GAMEPAD_DPAD_LEFT))
			//	{
				//	if( CheatRT == TRUE ) {
					
				//	CheatRT = FALSE;
				//	DoCheat(0x88888888, skillpo, 4);
				//	pop(L"999 Skill Points Disabled");
				//	PulseController();

				//	} else {
						
				//	CheatRT = TRUE;
				//	DoCheat(0x88888888, skillp, 4);
				//	pop(L"999 Skill Points Enabled - Disable after you gain 999");
				//	PulseController();

			//		}
			//	}
				/* End quick codes */

				/* Static offsets */
			//	if( InfHealth == TRUE ) {
			//		DoCheat(0x88888888, health, 4);
			//		DoCheat(0x88888888, health, 4);
			//	}
				/* End static offsets */
		
		}
		Sleep(500);
	 }
} 


VOID ProcessButtonPress( MESSAGEBOX_RESULT g_mb_result )
{

}