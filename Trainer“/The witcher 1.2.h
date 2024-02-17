#include "common.h"


UINT32 g_titleID = 0x4E4D0855;
//ADD  BOOLS



bool power = FALSE;
BOOL XPmod = FALSE;
//BOOL InfTime = FALSE;
BOOL InfSalt = FALSE;
BOOL InfLock = FALSE;

///static codes values
BYTE OptionA[4] = { 0x00, 0x00, 0x00, 0x5a }; 
bool Option1 = false;
BYTE OptionB[4] = { 0x00, 0x0f, 0x42, 0x3f }; 
bool Option2 = false;
BYTE OptionC[4] = { 0x00, 0x0f, 0x42, 0x3f };
bool Option3 = false;

BOOL Static1    = FALSE;
BOOL Static2    = FALSE;
BOOL Static3    = FALSE;
BOOL Static4    = FALSE;
BOOL Static5    = FALSE;
BOOL Static6    = FALSE;
BOOL Static7    = FALSE;
BOOL Static8    = FALSE;
BOOL Static9    = FALSE;
BOOL Static10   = FALSE;
BOOL Static11   = FALSE;
BOOL Static12   = FALSE;
BOOL Static13   = FALSE;
BOOL Static14   = FALSE;
BOOL Static15   = FALSE;
BOOL Quicklaunch = FALSE;
BYTE Mana[]      = { 0x7d, 0x63, 0x5a, 0x14 };
BYTE Mana1[]      = { 0x39, 0x6b, 0x27, 0x10 };
BYTE nop[]      = { 0x60, 0x00, 0x00, 0x00 };

VOID __declspec(naked) CheckHealth(VOID)
{

	WORD HPtr1;
	__asm
	{
//82F9C54C C0010050             lfs fr0,50h(r1) 
//82F9C550 C1A10054             lfs fr13,54h(r1) 
//82F9C554 ED806828             fsubs fr12,fr0,fr13 
//82F9C558 D19F0000             stfs fr12,0(r31) 
//82F9C55C 38210080             addi r1,r1,128	


	lfs fr0,50h(r1)
    lfs fr13,54h(r1)
    fsubs fr12,fr0,fr13 
    stfs fr12,0(r31)

	 stw r10,-10h(r1) 
     stw r11,-8h(r1) 
     mr HPtr1,r4


	}

	if( HPtr1 != 0xA700489B4  && InfHealth == TRUE )
	{
		float XValue = 6.0f;
		
		__asm
		{ 
			stfs XValue,0(r31) 
		    
		}

	}else{

		if( InfHealth == FALSE )
		{
			__asm{

			}
		}
	

	}

	//if( HPtr1 == 0x01 && OneHitKo == TRUE )
	//{
	//	float ZValue = 00.0f;
	//	__asm
	//	{

	//		stfs ZValue,0D0h(r30)

	//	}

	//}else{

	//	if( OneHitKo == FALSE )
	//	{
	//		__asm{

	//		}
	//	}


	//}
    //82B115DC
	__asm{ 

		    lwz r10,-10h(r1) 
			lwz r11,-8h(r1) 

			lis r14,0x82F9    
			ori r14,r14,0xC560
			mtctr r14
			bctr    
	}
}

VOID SetHooks()
{

	 Caveme(0x82F9C54C,CheckHealth,14);
	 HooksSet = true;


}

VOID ShowTrainerMain()
{
	Vibr01();Prompt = XShowMessageBoxUI(0, L"TEAM-XPG Trainer : Present", L"The Witcher 2 Assassins of Kings + ?? \r\nView Codes: DPAD-DOWN(x4)", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
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
		Vibr01();XShowMessageBoxUI(0, L"Viewing All Codes", L"Inf Health LB(x4)\r\nOne Hit Kill RB(x4)\r\nInf Mana/Magic Y(x4)\r\nFast Exp X(x4)\r\nLB + ↑ Customs Amors Keys\r\nLB + ↓ Customs Access Cards\r\nInf Powers Dpad →(x4)\r\nInstant Wins Pl1 Dpad ←(x4)", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);
		if( HooksSet == false )
		{
			SetHooks();
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

		if( InfHealth == TRUE ) {
					
       	InfHealth = FALSE;
		Vibr01();hNotify(L"Active Cheat(1) God Mode OFF");
        Sleep(2000);


        } else {
	    if( HooksSet == false )
		{
		  SetHooks();
		}
		InfHealth = TRUE;
		Vibr01();hNotify(L"Active Cheat(1)God Mode ON");

        Sleep(2000);
	
	    }
    }
	if( g_mb_result.rgwPasscode[0] == RIGHT_BUMPER && g_mb_result.rgwPasscode[1] == RIGHT_BUMPER && g_mb_result.rgwPasscode[2] == RIGHT_BUMPER && g_mb_result.rgwPasscode[3] == RIGHT_BUMPER )
	{
		Sleep(500);

		if( OneHitKo == TRUE ) {	

       	OneHitKo = FALSE;
		Vibr01();hNotify(L"Active Cheat(2)One Hit Ko OFF");

        Sleep(2000);

        } else {
	    if( HooksSet == false )
		{
		  SetHooks();
		}
		OneHitKo = TRUE;
		Vibr01();hNotify(L"Active Cheat(2)One Hit Ko ON");
 
        Sleep(2000);

	    }
	}

	if( g_mb_result.rgwPasscode[0] == Y_BUTTON && g_mb_result.rgwPasscode[1] == Y_BUTTON && g_mb_result.rgwPasscode[2] == Y_BUTTON && g_mb_result.rgwPasscode[3] == Y_BUTTON )
	{
		Sleep(500);

	if( InfSalt == TRUE ) {
					
	 InfSalt = FALSE;
	 DoCheat(0x83310128, Mana, 4);
	 Vibr01();hNotify(L"Inf Mana  Disabled");
 
     Sleep(2000);
		 
     } else {
	 InfSalt = TRUE;
	 DoCheat(0x83310128, Mana1, 4);
	 Vibr01();hNotify(L"Inf Mana Enabled");

     Sleep(2000);

      }
	}
	if( g_mb_result.rgwPasscode[0] == X_BUTTON && g_mb_result.rgwPasscode[1] == X_BUTTON && g_mb_result.rgwPasscode[2] == X_BUTTON && g_mb_result.rgwPasscode[3] == X_BUTTON )
	{
		Sleep(500);

		if( XPmod == TRUE )
		{
			XPmod = FALSE;
 			BYTE XPmod2[] = { 0x7d, 0x6b, 0xe2, 0x14 };
            DoCheat(0x8254C620, XPmod2, 4);
		    Vibr01();hNotify(L"Active Cheat(4)Fast XP OFF");
            Sleep(2000);
 		    }else{
			XPmod = TRUE;
			BYTE XPmod[] = { 0x39, 0x6b, 0x75, 0x30 };
            DoCheat(0x8254C620, XPmod, 4);
			Vibr01();hNotify(L"Active Cheat(4)Fast XP ON");
            Sleep(2000);
		}

	}

	 if( g_mb_result.rgwPasscode[0] == DPAD_LEFT && g_mb_result.rgwPasscode[1] == DPAD_LEFT && g_mb_result.rgwPasscode[2] == DPAD_LEFT && g_mb_result.rgwPasscode[3] == DPAD_LEFT )
	   {
		Sleep(500);

		if( power == TRUE )
		{
			 power = FALSE;
 			 BYTE items[4] = { 0x7f, 0xeb, 0x19, 0x2e };
             DoCheat(0x8254C73C, items, 4);
			
			 Vibr01();hNotify(L"Active Cheat(7)Instant Wins Pl1 OFF");
             Sleep(2000);
 		     }else{
			 power = TRUE;
             DoCheat(0x8254C73C, nop, 4);
			 Vibr01();hNotify(L"Active Cheat(7)Instant Wins Pl1 ON");
             Sleep(2000);

		  }
	   }
	if( g_mb_result.rgwPasscode[0] == DPAD_RIGHT && g_mb_result.rgwPasscode[1] == DPAD_RIGHT && g_mb_result.rgwPasscode[2] == DPAD_RIGHT && g_mb_result.rgwPasscode[3] == DPAD_RIGHT )
	{
		Sleep(500);

		if( Static3 == TRUE )
		{
			 Static3 = FALSE;
 			 Vibr01();hNotify(L"Active Cheat(7)Infinite Power OFF");
             Sleep(2000);
 		     }else{
			 Static3 = TRUE;
              Vibr01();hNotify(L"Active Cheat(7)Infinite Power ON");
             Sleep(2000);

 
		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}

}

static void Statics(){
	while (1){

		if (Option1 == TRUE)
		      {
               DoCheat(0x83F0DCC8, OptionA, 4);
		      }  
		if (Option2 == TRUE)
		      {
              DoCheat(0x83ED6A74, OptionB, 4);
		      } 
		if (Option3 == TRUE)
		      {
               DoCheat(0x83ED6A70, OptionC, 4);
		      } 
		Sleep(10); 
	}
}



VOID TrainerLoaded()
{
	Vibr01();hNotify(L"TeamXPG Trainer Engine Loaded - Debug Kernel Active - Trainer By XPGOByto & Sensi420 & Goldz");
    Sleep(2000);
	
}

VOID TrainerLoaded1()
{
	Vibr01();hNotify(L"TeamXPG Trainer Engine Loaded - Retail Kernel Active - Trainer By XPGOByto & Sensi420 & Goldz");
    Sleep(2000);
}
VOID SearchAddr()
{
	hNotify(L"The Witcher 2");
	Sleep(25);

	SetAddr = true;
}