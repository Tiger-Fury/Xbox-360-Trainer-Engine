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

BYTE MXCarry0[] = { 0x39, 0x06b, 0xff, 0xff };//OFF 396BFFFF
BYTE MXCarry1[] = { 0x39, 0x60, 0x03, 0xe7 };//ON  396003E7
bool MaxCarry = false;

BYTE MXItems0[] = { 0x7D, 0x065, 0x58, 0x50 };//OFF 7D655850
BYTE MXItems1[] = { 0x39, 0x60, 0x00, 0x63 };//ON  39600063

BYTE MaxCash1[4] = { 0x05, 0xF5, 0xE0, 0xFF }; //0x70048CD8 0x05F5E0FF
bool MaxCash = false;

DWORD fltValue;
DWORD XValue;

static void Statics(){
	while (1){

		if (MaxCash == TRUE)
		{
			DoCheat(0x70048CD8, MaxCash1, 1);

		} 
		
		Sleep(10); 
	}
} 






VOID __declspec(naked) CheckHP(VOID) {
	
	/*
	    822D90AC       lfs fr13,-19F0h(r11) 
		822D90B0     fmadds fr0,fr31,fr0,fr13 
		822D90B4     fnmsubs fr0,fr0,fr30,fr12 
		822D90B8     stfs fr0,118Ch(r30)//breakpoint 
		Return address
		822D90BC     mr r3,r30*/

	DWORD dwPtr;

 __asm {
	mr dwPtr,r25
       lfs fr13,-19F0h(r11) 
	   fmadds fr0,fr31,fr0,fr13 
	   fnmsubs fr0,fr0,fr30,fr12 
       stfs fr0,118Ch(r30)//breakpoint  

 }

 if (dwPtr == 0x00 && InfHealth == TRUE) {
  float fltValue = 100.0f;
  __asm 
  { 

	stfs fltValue,118Ch(r30)
  }

 }else{

if( InfHealth == FALSE )
	 {
		 __asm
		 {

		 }
	 }

 }
 if (dwPtr == 0x01 && OneHitKo == TRUE) {
	 float XValue = -1.0f;
	 __asm 
	 { 

		 stfs XValue,118Ch(r30)
	 }

 }else{

	 if( OneHitKo == FALSE )
	 {
		 __asm
		 {

		 }
	 }

 }
 
 // 82ECC2D0
 __asm{
  lis r11,0x822D   
  ori r11,r11,0x90BC
  mtctr r11
  bctr      
 }
 
}

VOID SetHooks()
{


	 DWORD IHealth[4];
	 patchInJump( (PDWORD)IHealth, (DWORD)CheckHP, FALSE );
	 
		DoCave(0x822D90AC, &IHealth[0], 4);
		DoCave(0x822D90B0, &IHealth[1], 4);
		DoCave(0x822D90B4, &IHealth[2], 4);
		DoCave(0x822D90B8, &IHealth[3], 4);

		HooksSet = true;
}

VOID TrainerLoaded()
{
	PulseController();
	pop(L"t3furys XPG Exclusives\r\nTenchu Z +5 Trainer Loaded");
}


VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"~TeamXpg~ t3furys XPG Exclusives", L"Tenchu Z +5 \r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);

				if( HooksSet == false )
				{
					SetHooks();
				}

}

VOID ButPress( MESSAGEBOX_RESULT g_mb_result )
{

    if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
    {
		Sleep(500);
		     //this is the page that shows all available cheats  \r\n indicates create new line
			XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nMax Items LT(x4)\r\n 1 Hit Kill RB(x4)\r\nMax Gold X(x4)\r\nMax Item Carry Amount Y(x4)\r\nHope You Enjoy", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

        memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
        memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
        memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
        memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
        Prompt = 0x9999;

    }
	//3rd Cheat
	if( g_mb_result.rgwPasscode[0] == LEFT_TRIGGER && g_mb_result.rgwPasscode[1] == LEFT_TRIGGER && g_mb_result.rgwPasscode[2] == LEFT_TRIGGER && g_mb_result.rgwPasscode[3] == LEFT_TRIGGER )
	{
		Sleep(500);
		
		if( CheatLT == TRUE )
		{
			pop(L"Max Items Deactivated");
			DoCheat(0x82288720, MXItems0, 4);
			CheatLT = FALSE;
	        PulseController();

		}else{
			
			pop(L"Max Items Activated");
			DoCheat(0x82288720, MXItems1, 4);
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
		
		if( InfHealth == TRUE )
		{
			pop(L"Inf Health Deactivated");
			InfHealth = FALSE;
	        PulseController();

		}else{
			
			pop(L"Inf Health Activated");
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

				if( OneHitKo == TRUE )
				{
					pop(L"One Hit Kill Deactivated");
					OneHitKo = FALSE;
					PulseController();

				}else{

					pop(L"One Hit Kill Activated");
					OneHitKo = TRUE;
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

				if( MaxCash == TRUE )
				{
					pop(L"Max Cash Deactivated");
					MaxCash = FALSE;
					PulseController();

				}else{

					pop(L"Max Cash Activated");
					MaxCash = TRUE;
					PulseController();

				}

				memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
				memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
				memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
				memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
				Prompt = 0x9999;
			}

			if( g_mb_result.rgwPasscode[0] == Y_BUTTON && g_mb_result.rgwPasscode[1] == Y_BUTTON && g_mb_result.rgwPasscode[2] == Y_BUTTON && g_mb_result.rgwPasscode[3] == Y_BUTTON )
			{
				Sleep(500);

				if( MaxCarry == TRUE )
				{
					pop(L"Max Carry Deactivated");
					DoCheat(0x823F470C, MXCarry0, 4);
					MaxCarry = FALSE;
					PulseController();

				}else{

					pop(L"Max Carry Activated");
					DoCheat(0x823F470C, MXCarry1, 4);
					MaxCarry = TRUE;
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
			MaxCash =  FALSE;
			DoCheat(0x823F470C, MXCarry0, 4);
			DoCheat(0x82288720, MXItems0, 4);
			OneHitKo = FALSE;
			InfHealth = FALSE;
			CheatDU = FALSE;
	        PulseController();

		}else{
			
			pop(L"All Cheats Activated");
			MaxCash = TRUE;
			DoCheat(0x823F470C, MXCarry1, 4);
			DoCheat(0x82288720, MXItems1, 4);
			OneHitKo = TRUE;
			InfHealth = TRUE;
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