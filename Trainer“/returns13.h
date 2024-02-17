#include "common.h"

UINT32 g_titleID = 0x5351081B;

bool OneHitKo = false;
bool HooksSet = false;
bool InfHealth = false;
bool Ammo = false;
bool Run = false;
bool Over = false;

BYTE Ptr1;
DWORD XValue = 0x01869F;
BYTE ZValue = 0x00;

///static codes values
BYTE GilA[4] = { 0x00, 0x98, 0x96, 0x7F }; 
bool Gil = false;
DWORD GilMA = 0x6E1773FC;
BYTE NpoinA[4] = { 0x00, 0x00, 0x4E, 0x20 }; 
bool Npoin = false;
DWORD NpoinMA = 0x6E177438;
BYTE AtkA[4] = { 0x00, 0x01, 0x86, 0x9F }; 
bool Atk = false;
DWORD AtkMA = 0x6E18D4C0;
BYTE MagA[4] = { 0x00, 0x01, 0x86, 0x9F }; 
DWORD MagMA = 0x6E18D4C4;
BYTE SpeA[4] = { 0x00, 0x01, 0x86, 0x9F }; 
DWORD SpeMA = 0x6E18D4E0;

BYTE OverA[] = { 0x91, 0x43, 0x07, 0x48 };
DWORD OverMA = 0x823FE8B0;
BYTE OveA[] = { 0x90, 0xA3, 0x07, 0x48 };
DWORD OveMA = 0x823F7C04;
BYTE RunA[] = { 0xD0, 0xE3, 0x00, 0x14 };
DWORD RunMA = 0x824C05F4;
BYTE AmmoA[] = { 0x93, 0xFE, 0x03, 0x2C };
DWORD AmmoMA = 0x8239F2CC;
BYTE NOP[4] = { 0x60, 0x00, 0x00, 0x00 };


VOID __declspec(naked) CheckHealth(VOID)
{

	__asm{
		    mflr r12
		    stw r12,-8(r1)
			std r31,-10h(r1)       //8222243C D0230074  
			stwu r1,-60h(r1)     //82222440 FC000890
	     }

	Saveregs();                // Save Registers

	__asm{
			mr Ptr1,r7         // get pointer r25
	     }



	if( Ptr1 == 0x01 && InfHealth == TRUE )   // compare r25 to our pointers
	{
		
		__asm
		{
 
			stw XValue,2F0h(r31)
            
		}

	}else{
		if( InfHealth == FALSE )
		{
			__asm{
          
			}
		}
	

	}

	if( Ptr1 != 0x01 && OneHitKo == TRUE )           // compare r25 to our pointers
	{
		
		__asm
		{

			stw ZValue,2F0h(r31)

		}

	}else{
		if( OneHitKo == FALSE )
		{
			__asm{

			}
		}


	}

	Loadregs();           // load register back

	__asm{
			lis r14,0x8239            // jump back using r23 as it was empty
			ori r14,r14,0xBAD8
			mtctr r14
			bctr
	}
}

VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"TeamXPG AleXPG", L"Lightning Returns FF-XIII JAP\r\nBy AleXPG +8Trainer TU-1\r\n\r\nInfinite Health LB+RB+A\r\nInfinite ATB Bar LB+RB+B\r\nInfinite Dash LB+RB+X\r\nInf OVERCLOCK LB+RB+Y\r\nMax & Inf Gils LB+RB+↑\r\nMax & Inf GP LB+RB+↓\r\nMax Stats LB+RB+ →\r\n1 Hit Kill LB+RB+ ←\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);
	if( HooksSet == false )
	{
		SetHooks();
	}
}


VOID Quicklaunch1()
{
	if( InfHealth == TRUE ) {

		InfHealth = FALSE;
		hNotify(L"Inf Health Disabled!");
		Vibr01();
	} else {

		InfHealth = TRUE;
		hNotify(L"Inf Health Enabled!");
		Vibr01();
	}
}

VOID Quicklaunch2()
{
	if( Ammo == TRUE ) {

		Ammo = FALSE;
		DoCheat(AmmoMA, AmmoA, 4);
		hNotify(L"Infinite ATB Bar Disabled!");
		Vibr01();
	} else {

		Ammo = TRUE;
		DoCheat(AmmoMA, NOP, 4);
		hNotify(L"Infinite ATB Bar Enabled!");
		Vibr01();
	}
}

VOID Quicklaunch3()
{
	if( Run == TRUE ) {

		Run = FALSE;
		DoCheat(RunMA, RunA, 4);
		hNotify(L"Infinite Dash Disabled!");
		Vibr01();
	} else {

		Run = TRUE;
		DoCheat(RunMA, NOP, 4);
		hNotify(L"Infinite Dash Enabled!");
		Vibr01();
	}
}

VOID Quicklaunch4()
{
	if( Over == TRUE ) {

		Over = FALSE;
		DoCheat(OverMA, OverA, 4);
		DoCheat(OveMA, OverA, 4);
		hNotify(L"Infinite OVERCLOCK Disabled!");
		Vibr01();
	} else {

		Over = TRUE;
		DoCheat(OverMA, NOP, 4);
		DoCheat(OveMA, NOP, 4);
		hNotify(L"Infinite OVERCLOCK Enabled!");
		Vibr01();
	}
}

static void Statics(){
	while (1){

		if (Gil == TRUE)
		      {
               DoCheat(GilMA, GilA, 4);//story
		      }   
		if (Npoin == TRUE)
		      {
               DoCheat(NpoinMA, NpoinA, 4);//story
		      }   
		if (Atk == TRUE)
		      {
               DoCheat(AtkMA, AtkA, 4);
			   DoCheat(MagMA, MagA, 4);
			   DoCheat(SpeMA, SpeA, 4);//story
		      } 
		Sleep(10); 
	}
}

VOID Quicklaunch5()
{
     if( Gil == TRUE ) {
					
	    Gil = FALSE;
	    hNotify(L"Max & Infinite Gils Disabled");
		Vibr01();					 
     } else {

	    Gil = TRUE;
	    hNotify(L"Max & Infinite Gils Enabled");
		Vibr01();
      }
}

VOID Quicklaunch6()
{
     if( Npoin == TRUE ) {
					
	    Npoin = FALSE;
	    hNotify(L"Max & Infinite GP Disabled");
		Vibr01();					 
     } else {

	    Npoin = TRUE;
	    hNotify(L"Max & Infinite GP Enabled");
		Vibr01();
      }
}

VOID Quicklaunch7()
{
     if( Atk == TRUE ) {
					
	    Atk = FALSE;
	    hNotify(L"Max Stats Disabled");
		Vibr01();					 
     } else {

	    Atk = TRUE;
	    hNotify(L"Max Stats Enabled");
		Vibr01();
      }
}

VOID Quicklaunch8()
{
     if( OneHitKo == TRUE ) {
					
	    OneHitKo = FALSE;
	    hNotify(L"1 Hit Kill Disabled");
		Vibr01();					 
     } else {

	    OneHitKo = TRUE;
	    hNotify(L"1 Hit Kill Enabled");
		Vibr01();
      }
}