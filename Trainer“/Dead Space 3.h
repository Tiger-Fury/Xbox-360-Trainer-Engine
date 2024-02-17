#include "common.h"

UINT32 g_titleID = 0x4541099D;

bool OneHitKo = false;
bool HooksSet = false;
bool InfHealth = false;
bool InfAmmo = false;
bool infitem = false;
bool inffres = false;
bool infstasis = false;
bool infair = false;
bool FastSpeed = false;
bool EnemySpeed = false;
bool NoSpread = false;
bool Rapid = false;
DWORD MyPtr;
DWORD MySpeed;
DWORD MySpeed2;  
DWORD MyTemp;
bool SpeedOn = false;
DWORD SPv = 0x41200000;
DWORD EPv = 0x3E4CCCCD;
DWORD SPvv = 0x3f800000;
DWORD AMv = 0x0000000F;
DWORD Coilv = 0x00000000;
DWORD Rapidv = 0x42c80000;

DWORD MyHPptr;
DWORD MyHPptr2;
DWORD XValue = 0x43FA0000;
DWORD YValue = 0x3F800000;
DWORD ZValue = 0x00000000;
bool Savestate;
bool loadstate;
DWORD State1;
DWORD State2;
DWORD State3;
DWORD cords1;
DWORD cords2;
DWORD cords3;



VOID __declspec(naked) MyPointer(VOID)
{



	__asm{
		    lis r10,-30701
			lfs fr13,0F8h(r9)
			lfs fr0,2524h(r10)
            //fcmpu cr6,fr13,fr0

			stw r10,-10h(r1) 
			//stw r11,-8h(r1)     

			mr MyPtr,r9

			}

	MyTemp = MyPtr+0x10; 
	MySpeed = *(DWORD*)(MyTemp); 
	MySpeed2 = MySpeed+0x84;

	MyHPptr = MyPtr+0x104;
	MyHPptr2 = *(DWORD*)(MyHPptr);
	
	
	if(   *(DWORD*)(MyPtr+0x104) != 0x00000000 &&  InfHealth == TRUE )  
	{
		
		__asm
		{

				stw XValue,0F8h(r9)
				stw YValue,0FCh(r9)

		}
	}

	if ( MyHPptr2 == 0x00000000 )
		goto skipmee;



	State1 = MyPtr+0x960;
	State2 = MyPtr+0x964;
	State3 = MyPtr+0x968;

	
	if (Savestate == true ){
		cords1 = *(DWORD*)(State1);
		cords2 = *(DWORD*)(State2);
		cords3 = *(DWORD*)(State3);
		Savestate = false;
	}

	if (loadstate == true){
		__asm{
			mr r10,State1
			stw cords1,0h(r10)
			mr r10,State2
			stw cords2,0h(r10)
			mr r10,State3
			stw cords3,0h(r10)
		}

		loadstate = false;
	}


	if ( FastSpeed == true && SpeedOn == false)
	{
		
		__asm{
		mr r10,MySpeed2
		stw SPv,0h(r10)
		}
		SpeedOn = true;
	}

	if ( FastSpeed == false && SpeedOn == true)
	{

		__asm{
			mr r10,MySpeed2
				stw SPvv,0h(r10)
		}
		SpeedOn = false;
	}
	
skipmee:
	if ( MyHPptr2 != 0x00000000 )
		goto skipmee2;

	if ( EnemySpeed == true)
	{

		__asm{
			mr r10,MySpeed2
				stw EPv,0h(r10)
		}

	}

	if ( EnemySpeed == false)
	{

		__asm{
			mr r10,MySpeed2
				stw SPvv,0h(r10)
		}

	}
	 




skipmee2:
	__asm{
		    lwz r10,-10h(r1) 
            //lwz r11,-8h(r1) 

			
            fcmpu cr6,fr13,fr0

		    lis r11,0x8832       
			ori r11,r11,0xC4D4
			mtctr r11
			bctr      
	}
}


VOID __declspec(naked) CheckHealth(VOID)
{


	DWORD Ptr1;

	__asm // Recreate game code!
	{
		lfs fr0,0F4h(r31)
		stfs fr31,0F8h(r31)
	}
				Saveregs();    // Save R10 ;)

	__asm{  // Get our pointers!!
		//lfs fr0,0F4h(r31)
		//stfs fr31,0F8h(r31)
		//fcmpu cr6,fr0,fr30

		//stw r10,-10h(r1)   
			mr Ptr1,r31
          
	     }



	if( *(DWORD*)(Ptr1+0x104) == 0x00000000 && OneHitKo == TRUE )              
	{
		__asm
		{


				stw ZValue,0F8h(r31)
				stw ZValue,0FCh(r31)
		}

	}
		 Loadregs();   // Load r10 back :)
	__asm{
   //lwz r10,-10h(r1)  
		 fcmpu cr6,fr0,fr30
		    lis r11,0x884B           // Jump back to game ;)
			ori r11,r11,0x56F8
			mtctr r11
			bctr      
	}
}



VOID __declspec(naked) CheckAmmo(VOID)
{


	DWORD Ptr1;

	__asm
	{

	}

	__asm{
		            stw r12,-8(r1)
                    std r30,-18h(r1)
                    std r31,-10h(r1)
                    stwu r1,-70h(r1)
		
                   // mr r16,r11
					//mr r17,r10
				    stw r10,-30h(r1) 
			        stw r11,-40h(r1) 
					mr Ptr1,r1
			
          
	     }

	if ( Ptr1 == 0x7004E880 )
	goto endme;

	if ( Ptr1 == 0x7004E7F0 )
	goto endme;

	/*
	if( InfAmmo == TRUE )              
	{
		__asm
		{


		stw AMv,290h(r31)

		}

	}*/

	if( NoSpread == TRUE )              
	{
		__asm
		{


		stw Coilv,80h(r31)
                stw Coilv,268h(r31)

		}

	}


	if( Rapid == TRUE )              
	{
		__asm
		{


		stw Rapidv,84h(r31)

		}

	}



	endme:

	__asm{
		//  mr r11,r16
		//mr r10,r17
		//li r16,0
		//li r17,0
		    lwz r10,-30h(r1) 
            lwz r11,-40h(r1) 

		lis r15,0x8839        
		ori r15,r15,0xB9DC
	        mtctr r15
	        bctr      
	}
}

VOID SetHooks()
{	Caveme(0x884B56E8,CheckHealth,11);
	Caveme(0x8832C4C4,MyPointer,11);
	Caveme(0x8832C4C4,CheckAmmo,15);
	HooksSet = true;
}


VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L" TeamXPG - GoldZ", L"Dead Space 3 +12 \r\nView Codes: DPAD-DOWN(x4)", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
	if( HooksSet == false )
	{
		SetHooks();
	}
}

VOID SavePos()
{
	hNotify(L"Teleport !!!...\nPosition Saved");
	if( Savestate == false )
	{
		Savestate = true;
	}

}

VOID LoadPos()
{

	if( loadstate == false )
	{
		loadstate = true;
	}

}


VOID ProcessButtonPress( MESSAGEBOX_RESULT g_mb_result )
{

	if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
	{
		Sleep(500);
		XShowMessageBoxUI(0, L"Viewing All Codes", L"Inf Ammo UP(x4)\r\nInf Health LB(x4)\r\nOne Hit Kills X(x4)\r\nInf Stasis RB(x4)\r\nInf Resource RT(x4)\r\nInf Items LT(x4)\r\nInf Air Y(x4)\r\nSuper Speed X(x2)Y(x2)\r\nSlow Motion Enemy's X(x3)Y(x1)\r\nNo Spread or Recoil LB(x2)RB(x2)\r\nRapid Fire LB(x3)RB(x1)\r\nQuick Launch Options - \r\nSave Teleport Location LB + X\r\nRestore Location LB + A", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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

		if( InfHealth == TRUE )
		{
			hNotify(L"Inf Health Deactivated");
			InfHealth = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Health Activated");
			InfHealth = TRUE;
			Vibr01();

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

		if( OneHitKo == true )
		{
			hNotify(L"One Hit Kill Deactivated");
			OneHitKo = false;
			Vibr01();

		}else{

			hNotify(L"One Hit Kill Activated");
			OneHitKo = true;
			Vibr01();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;

	}

	if( g_mb_result.rgwPasscode[0] == X_BUTTON && g_mb_result.rgwPasscode[1] == X_BUTTON && g_mb_result.rgwPasscode[2] == Y_BUTTON && g_mb_result.rgwPasscode[3] == Y_BUTTON )
	{
		Sleep(500);

		if( FastSpeed == true )
		{
			hNotify(L"Speed Deactivated");
			FastSpeed = false;
			Vibr01();

		}else{

			hNotify(L"Speed Activated");
			FastSpeed = true;
			Vibr01();
		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;

	}

	if( g_mb_result.rgwPasscode[0] == X_BUTTON && g_mb_result.rgwPasscode[1] == X_BUTTON && g_mb_result.rgwPasscode[2] == X_BUTTON && g_mb_result.rgwPasscode[3] == Y_BUTTON )
	{
		Sleep(500);

		if( EnemySpeed == true )
		{
			hNotify(L"Slow Enemy's Deactivated");
			EnemySpeed = false;
			Vibr01();

		}else{

			hNotify(L"Slow Enemy's Activated");
			EnemySpeed = true;
			Vibr01();
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

		if( InfAmmo == TRUE )
		{
			hNotify(L"Inf Ammo Deactivated");
			SetDWORD(0x8836A804, 0x939f0290);
			InfAmmo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Ammo Activated");
			SetDWORD(0x8836A804, 0x60000000);
			InfAmmo = TRUE;
			Vibr01();

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

		if( infitem == TRUE )
		{
			hNotify(L"Inf Items Deactivated");
			SetDWORD(0x882CB12C,0x917f0004);
			SetDWORD(0x882CBE74,0x915f0004);
			infitem = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Items Activated");
			SetDWORD(0x882CB12C,0x60000000);
			SetDWORD(0x882CBE74,0x60000000);
			infitem = TRUE;
			Vibr01();
		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}

	if( g_mb_result.rgwPasscode[0] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[1] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[2] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[3] == RIGHT_TRIGGER )
	{
		Sleep(500);

		if( inffres == TRUE )
		{
			hNotify(L"Inf Resource Deactivated");
			SetDWORD(0x882CC080,0x914b0000);
			SetDWORD(0x882D7C50,0x7d294214);
			inffres = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Resource Activated");
			SetDWORD(0x882CC080,0x60000000);
			SetDWORD(0x882D7C50,0x39292710);
			inffres = TRUE;
			Vibr01();
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

		if( infstasis == TRUE )
		{
			hNotify(L"Inf Stasis Deactivated");
			SetDWORD(0x884F3118,0xd0090100);
			infstasis = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Stasis Activated");
			SetDWORD(0x884F3118,0x60000000);
			infstasis = TRUE;
			Vibr01();
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

		if( infair == TRUE )
		{
			hNotify(L"Inf Air Deactivated");
			SetDWORD(0x884575E8,0xd01e0060);
			infair = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Air Activated");
			SetDWORD(0x884575E8,0x60000000);
			infair = TRUE;
			Vibr01();
		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}

		if( g_mb_result.rgwPasscode[0] == LEFT_BUMPER && g_mb_result.rgwPasscode[1] == LEFT_BUMPER && g_mb_result.rgwPasscode[2] == RIGHT_BUMPER && g_mb_result.rgwPasscode[3] == RIGHT_BUMPER )
	{
		Sleep(500);

		if( NoSpread == TRUE )
		{
			hNotify(L"No Spread / Recoil Deactivated");
			NoSpread = FALSE;
			Vibr01();

		}else{

			hNotify(L"No Spread / Recoil Activated");
			NoSpread = TRUE;
			Vibr01();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}

		if( g_mb_result.rgwPasscode[0] == LEFT_BUMPER && g_mb_result.rgwPasscode[1] == LEFT_BUMPER && g_mb_result.rgwPasscode[2] == LEFT_BUMPER && g_mb_result.rgwPasscode[3] == RIGHT_BUMPER )
	{
		Sleep(500);

		if( Rapid == TRUE )
		{
			hNotify(L"Rapid Fire Deactivated");
			Rapid = FALSE;
			Vibr01();

		}else{

			hNotify(L"Rapid Fire Activated");
			Rapid = TRUE;
			Vibr01();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}



}