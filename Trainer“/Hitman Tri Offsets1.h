#include "common.h"
//that has to stay common.h
// your game ID goes here 
UINT32 g_titleID = 0x415608C3;

bool HM2AMMO = false;
bool HM2God = false;
bool InfAmmoSinglePlayer = false;
bool EnableMPZM = false;
bool KillstreaksActivated = false;
bool KillstreaksActivated1 = false;
bool KillstreaksActivated2 = false;
bool KillstreaksActivated3 = false;
bool BlingBling = false;
bool SinglePlayerInfHealth = false;
bool EnableSP = false;

VOID ShowTrainerMain()
{
	// this is the popup box that shows game title etc
	Prompt = XShowMessageBoxUI(0, L"t3furys XPG Exclusives - Input Code", L"HM2SA All Codes Dpad Down(x4)\r\nHMC All Codes Dpad Up(x4)\r\nInf Health HM2 Y(x4)-HMC RB(x4)\r\nInf Ammo HM2 X(x4)-HMC LB(x4)", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
}


VOID ButPress( MESSAGEBOX_RESULT g_mb_result )
{

   if( g_mb_result.rgwPasscode[0] == X_BUTTON && g_mb_result.rgwPasscode[1] == X_BUTTON && g_mb_result.rgwPasscode[2] == X_BUTTON && g_mb_result.rgwPasscode[3] == X_BUTTON )
    {
		Sleep(500);

            pop(L"Hitman 2 Inf Ammo Enabled");
          // put your desired value here 
		BYTE HM2AMMO[4] = { 0x60, 0x00, 0x00, 0x00 };
        // put your offset here 
		memcpy( (void*)0x82342DA4, HM2AMMO , 4);
	//	DmSetMemory( (void*)0x826BDBAC, 4 , AmmoMPZM, NULL );

		// so if your XPP cheat is this  2 0xC1234567 12345678
		// it will look like this 
		//BYTE God1[4] = { 0x12, 0x34, 0x56, 0x78 }
		//memcpy( (void*)0x1234567, God1, 4);


   }
	// this line shows what button activates the cheat below ,,here it's LB (left bumper)   that's the 4 button presses in other words
    if( g_mb_result.rgwPasscode[0] == Y_BUTTON && g_mb_result.rgwPasscode[1] == Y_BUTTON && g_mb_result.rgwPasscode[2] == Y_BUTTON && g_mb_result.rgwPasscode[3] == Y_BUTTON )
    {
        Sleep(500);

     
        {
			//this is our first cheat 
            pop(L"Hitman 2 Inf Health Enabled");
          // put your desired value here 
		BYTE HM2God[4] = { 0x60, 0x00, 0x00, 0x00 };
        // put your offset here 
		memcpy( (void*)0x8237CD28, HM2God , 4);
	//	DmSetMemory( (void*)0x826BDBAC, 4 , AmmoMPZM, NULL );


        }

        memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
        memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
        memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
        memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
        Prompt = 0x9999;
    }
	// X button activates this cheat
	if( g_mb_result.rgwPasscode[0] == RIGHT_BUMPER && g_mb_result.rgwPasscode[1] == RIGHT_BUMPER && g_mb_result.rgwPasscode[2] == RIGHT_BUMPER && g_mb_result.rgwPasscode[3] == RIGHT_BUMPER )
    {
        Sleep(500);

        {

        pop(L"Hitman Contracts Inf Health Enabled");
            

        BYTE GodMPZM[4] = { 0x60, 0x00, 0x00, 0x00  };
        memcpy( (void*)0x823F9D98, GodMPZM, 4);
	//	DmSetMemory( (void*)0x82190B48, 4 , GodMPZM, NULL );

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

        {

        pop(L"Hitman Contracts Inf Ammo Enabled");
            

        BYTE BlingBling[4] = { 0x60 , 0x00 , 0x00 , 0x00  };
        memcpy( (void*)0x822CC760, BlingBling, 4);
	//	DmSetMemory( (void*)0x8354F8D8, 4 , BlingBling, NULL );

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

        {
			
        pop(L"Hitman Contracts All Codes Enabled");
            

        BYTE BlingBling[4] = { 0x60, 0x00, 0x00, 0x00 };
		memcpy( (void*)0x822CC760, BlingBling , 4);
	//	DmSetMemory( (void*)0x826BDBAC, 4 , AmmoMPZM, NULL );
		BYTE GodMPZM[4] = { 0x60, 0x00, 0x00, 0x00  };
		memcpy( (void*)0x823F9D98, GodMPZM, 4);


        }

        memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
        memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
        memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
        memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
        Prompt = 0x9999;
    }

	//LB+LB+LB+X
	if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
	{
		Sleep(500);

		{

		pop(L"Hitman 2 All Codes Enabled");
		
		BYTE HM2God[4] = { 0x60 , 0x00 , 0x00 , 0x00  };
		memcpy( (void*)0x8237CD28, HM2God, 4);
		BYTE HM2AMMO[4] = { 0x60 , 0x00 , 0x00 , 0x00  };
		memcpy( (void*)0x82342DA4, HM2AMMO, 4);


		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	
    }

}