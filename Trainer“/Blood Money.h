#include "common.h"
//that has to stay common.h
// your game ID goes here 
UINT32 g_titleID = 0x415608C3;

bool AmmoMPZM = false;
bool GodMPZM = false;
bool InfAmmoSinglePlayer = false;
bool EnableMPZM = false;
bool MaxMoney = false;
bool MaxMoney1 = false;
bool MaxMoney2 = false;
bool MaxMoney3 = false;
bool MaxMoney4 = false;
bool Infhealth = false;
bool SinglePlayerInfHealth = false;
bool EnableSP = false;

VOID ShowTrainerMain()
{
	// this is the popup box that shows game title etc
	Prompt = XShowMessageBoxUI(0, L"t3furys XPG Exclusives HmBm+3", L"Inf Ammo Dpad Down(x4)\r\nMax Money LB(x4)\r\n Inf Health YXYX\r\nEnable All LB(x3)+Y", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
}


VOID ButPress( MESSAGEBOX_RESULT g_mb_result )
{

   if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
    {
		Sleep(500);
		     //this is the page that shows all available cheats  \r\n indicates create new line
				//this is our first cheat 
            pop(L"Inf Ammo Enabled");
          // put your desired value here 
		BYTE AmmoMPZM[4] = { 0x60, 0x00, 0x00, 0x00 };
        // put your offset here 
		memcpy( (void*)0x822C5110, AmmoMPZM , 4);
	//	DmSetMemory( (void*)0x826BDBAC, 4 , AmmoMPZM, NULL );

		// so if your XPP cheat is this  2 0xC1234567 12345678
		// it will look like this 
		//BYTE God1[4] = { 0x12, 0x34, 0x56, 0x78 }
		//memcpy( (void*)0x1234567, God1, 4);

   }
	if( g_mb_result.rgwPasscode[0] == LEFT_BUMPER && g_mb_result.rgwPasscode[1] == LEFT_BUMPER && g_mb_result.rgwPasscode[2] == LEFT_BUMPER && g_mb_result.rgwPasscode[3] == LEFT_BUMPER )
    {
        Sleep(500);

        {

        pop(L"Max Money Enabled");
            

        BYTE MaxMoney[4] = { 0x0F, 0xFF, 0xFF, 0xFF };
		memcpy( (void*)0xbb9529e4, MaxMoney, 1);
	//	DmSetMemory( (void*)0x8354A73C, 4 , KillstreaksActivated, NULL );
		BYTE MaxMoney1[4] = { 0x0F, 0xFF, 0xFF, 0xFF };
		memcpy( (void*)0xBB9540D4, MaxMoney1, 1);
	//	DmSetMemory( (void*)0x8354A741, 4 , KillstreaksActivated1, NULL );
		BYTE MaxMoney2[4] = { 0x0F, 0xFF, 0xFF, 0xFF };
		memcpy( (void*)0xBB9557C4, MaxMoney2, 1);
	//	DmSetMemory( (void*)0x8354A745, 4 , KillstreaksActivated2, NULL );
		BYTE MaxMoney3[4] = { 0x0F, 0xFF, 0xFF, 0xFF };
		memcpy( (void*)0xBB956EB4, MaxMoney3, 4);
		BYTE MaxMoney4[4] = { 0x60, 0x00, 0x00, 0x00 };
		memcpy( (void*)0x825471C8, MaxMoney4, 4);
	//	DmSetMemory( (void*)0x826BCFB0, 4 , KillstreaksActivated3, NULL );

        }

        memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
        memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
        memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
        memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
        Prompt = 0x9999;
    }
	// YXYX ACTIVATE CHEAT
	if( g_mb_result.rgwPasscode[0] == Y_BUTTON && g_mb_result.rgwPasscode[1] == X_BUTTON && g_mb_result.rgwPasscode[2] == Y_BUTTON && g_mb_result.rgwPasscode[3] == X_BUTTON )
    {
        Sleep(500);

        {

        pop(L"Inf Health Enabled");
            

        BYTE Infhealth[4] = { 0x00 , 0x0F , 0xFF , 0xFF  };
        memcpy( (void*)0x8243D7E0, Infhealth, 4);
	//	DmSetMemory( (void*)0x8354F8D8, 4 , BlingBling, NULL );

        }

        memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
        memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
        memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
        memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
        Prompt = 0x9999;
    }
	//LB+LB+LB+Y
	if( g_mb_result.rgwPasscode[0] == LEFT_BUMPER && g_mb_result.rgwPasscode[1] == LEFT_BUMPER && g_mb_result.rgwPasscode[2] == LEFT_BUMPER && g_mb_result.rgwPasscode[3] == Y_BUTTON )
    {
        Sleep(500);

        {
			
        pop(L"All Cheats Enabled");
            

        BYTE Infhealth[4] = { 0x60 , 0x00 , 0x00 , 0x00  };
        memcpy( (void*)0x8243D7E0, Infhealth, 4);
		BYTE AmmoMPZM[4] = { 0x60, 0x00, 0x00, 0x00 }; 
		memcpy( (void*)0x822C5110, AmmoMPZM , 4);
	//	DmSetMemory( (void*)0x82190B48, 4 , GodMPZM, NULL );
		BYTE MaxMoney[4] = { 0x0F, 0xFF, 0xFF, 0xFF };
		memcpy( (void*)0xbb9529e4, MaxMoney, 1);
	//	DmSetMemory( (void*)0x8354A73C, 4 , KillstreaksActivated, NULL );
		BYTE MaxMoney1[4] = { 0x0F, 0xFF, 0xFF, 0xFF };
		memcpy( (void*)0xBB9540D4, MaxMoney1, 1);
	//	DmSetMemory( (void*)0x8354A741, 4 , KillstreaksActivated1, NULL );
		BYTE MaxMoney2[4] = { 0x0F, 0xFF, 0xFF, 0xFF };
		memcpy( (void*)0xBB9557C4, MaxMoney2, 1);
	//	DmSetMemory( (void*)0x8354A745, 4 , KillstreaksActivated2, NULL );
		BYTE MaxMoney3[4] = { 0x0F, 0xFF, 0xFF, 0xFF };
		memcpy( (void*)0xBB956EB4, MaxMoney3, 4);
		BYTE MaxMoney4[4] = { 0x60, 0x00, 0x00, 0x00 };
		memcpy( (void*)0x825471C8, MaxMoney4, 4);

        }

        memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
        memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
        memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
        memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
        Prompt = 0x9999;
    }

}


//This is the chunk of code to add more cheats (remove // comment out commandsand insert above last } bracket) also be sure to edit button calls.
//if( g_mb_result.rgwPasscode[0] == Y_BUTTON && g_mb_result.rgwPasscode[1] == Y_BUTTON && g_mb_result.rgwPasscode[2] == Y_BUTTON && g_mb_result.rgwPasscode[3] == Y_BUTTON )
   // {
   //     Sleep(500);

     //   {

    //    XShowMessageBoxUI(0, L"Cheat Enabled Successfully", L"Cheat name\r\nDescription here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);
            

     //   BYTE Score[4] = { 0x00 , 0x00 , 0x00 , 0x00  };
      //  memcpy( (void*)0x00000000, Score, 4);
		//DmSetMemory( (void*)0x823278F0, 4 , Score, NULL );

       // }

      //  memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
     //   memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
     //   memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
     //   memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
    //    Prompt = 0x9999;
 //   }