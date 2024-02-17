#include "common.h"


bool OneHitKo = false;//Determines if One Hit Kill is on or off
bool InfAmmo = false;//Determines if Inf Ammo is on or off
bool HooksSet = false;//Determines if Hook Set is on or off
bool InfHealth = FALSE;//Determines if Inf Health is on or off
bool AllOn = FALSE;//Determines if Inf All Cheats is on or off

//Values
BYTE nop[] = { 0x60, 0x00, 0x00, 0x00 };// on value // A nop (NO Operation) is a common value to use to stop a value from changing effectively stopping the operation on the breakpoint
BYTE ammo[] = { 0x91, 0x7f, 0x02, 0x90 };// original value


VOID __declspec(naked) CheckHP(VOID) { 
	
// The four lines beneath (in green) are not needed there just there as a quick reference, if your new to creating trainers doing this will help

//  82A90A48 915F0020             stw r10,20h(r31) 
//	82A90A4C ED806828             fsubs fr12,fr0,fr13 
//	82A90A50 FD6C036E             fsel fr11,fr12,fr13,fr0 
//	82A90A54 D17F034C             stfs fr11,34Ch(r31) //breakpoint

	DWORD myPtr;// declaring your pointer name which can be called anything not just myPtr, myPtr = My Pointer

 __asm {
	mr myPtr,r3 // mr myptr,r3 (move register My Pointer = r3) your register will likely be different depending on the game your doing
	stw r10,20h(r31) // 1st line in the cave, you can start your anywhere as long as it contains the line your modding in this case line 4 marked below
	fsubs fr12,fr0,fr13 
	fsel fr11,fr12,fr13,fr0 
	stfs fr11,34Ch(r31)// line 4, the line your cave will be modding

 }

 if (myPtr == 0x01 && InfHealth == TRUE) {// if My Pointer (r3) equals 0x01 and inf health bool equals true then give the player inf health. remember to use == and not just = otherwise My pointer will always equal 0x01 and will likely crash the game, == means if equals value, = means equal this value. 0x01 is a common pointer to use i'd say maybe 5-10% of games use it, but check all registers and find a pointer that only appears when YOUR player gets hit
  float fltValue = 10000.0f;// fltvalue equals 10000 float, again fltvalue can be named anything
  __asm 
  { 

	stfs fltValue,34Ch(r31)//here you change stfs fr11,34Ch(r31) to stfs fltValue,34Ch(r31) so when you get hit which will be when my pointer equals 0x01, fr11 will equal 10000 in float
  }
 
 }
 else if (myPtr == 0x063C && OneHitKo == TRUE) {// same as health just with the enemy pointer been 0x63C, also in some games instead of trying to find a enemy pointer you may be able to use the player pointer but instead of using == we would use != which means if not equal to (or other then) which would be written, if (myPtr != 0x01 && OneHitKo == TRUE) then kill enemy in one hit
	 float XfltValue = -100.0f;//same as health but with a minus, if minus crashes your game try 0 or even 1 depending on the scale of health
	 __asm 
	 { 
  
		stfs XfltValue,8(r31)
	 }

 }
 
 // 82A90A58 Return to Game Address, this is where you will give control back to the game so everything else can function as normal and not crash, this is usually the next address after the 4 line cave
 __asm{
  lis r11,0x82A9   //1st half of return address
  ori r11,r11,0x0A58//2nd half of return address
  mtctr r11
  bctr      
 }
 
}
/*Fake cave Example
VOID __declspec(naked) CheckBananas(VOID) {
	)
}*/

VOID SetHooks()// important, this is the cave activation function
{
	 DWORD IHealth[4];//cave patch
	 patchInJump( (PDWORD)IHealth, (DWORD)CheckHP, FALSE );// when the function is activated this will set the cave
	 
		DoCave(0x82A90A48, &IHealth[0], 4);// start address of the cave which is above so in this case 82A90A48 915F0020             stw r10,20h(r31) 
		DoCave(0x82A90A4C, &IHealth[1], 4);
		DoCave(0x82A90A50, &IHealth[2], 4);
		DoCave(0x82A90A54, &IHealth[3], 4);//last line in cave before return address

		/*fake cave set example*/
// 		DWORD somepatch[4];
// 		patchInJump( (PDWORD)somepatch, (DWORD)CheckBananas, FALSE );
// 
// 		DoCave(0x82000000, &somepatch[0], 4); 
// 		DoCave(0x82000004, &somepatch[1], 4);
// 		DoCave(0x82000008, &somepatch[2], 4);
// 		DoCave(0x8200000C, &somepatch[3], 4);

		HooksSet = true;
}

VOID TrainerLoaded()
{
	PulseController();
	pop(L"t3furys XPG Exclusives\r\nTransFormers WFC +2 Trainer Loaded");
}


VOID ShowTrainerMain()// when you press the activate buttons like Start + dpad up
{
	Prompt = XShowMessageBoxUI(0, L"~TeamXpg~ t3furys XPG Exclusives", L"TransFormers WFC +2 Trainer\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
	if( HooksSet == false )//When you press the activate buttons (Start + dpad up) it will automatically set your cave by setting hooksSet to true which will activate the sethooks function above 
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
			XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nInf Ammo LT(x4)\r\nInf Grenades RB(x4)\r\nHope You Enjoy", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

        memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
        memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
        memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
        memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
        Prompt = 0x9999;

    }
	//1st Cheat
	if( g_mb_result.rgwPasscode[0] == LEFT_TRIGGER && g_mb_result.rgwPasscode[1] == LEFT_TRIGGER && g_mb_result.rgwPasscode[2] == LEFT_TRIGGER && g_mb_result.rgwPasscode[3] == LEFT_TRIGGER )
	{
		Sleep(500);
		
		if( InfAmmo == TRUE )
		{
			pop(L"Inf Ammo Deactivated");
			DoCheat(0x830DBBA4, ammo, 4);
			InfAmmo = FALSE;
	        PulseController();

		}else{
			
			pop(L"Inf Ammo Activated");
			DoCheat(0x830DBBA4, nop, 4);
			InfAmmo = TRUE;
		    PulseController();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
	//2nd cheat
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
	//3rd cheat Multi Activate
	if( g_mb_result.rgwPasscode[0] == DPAD_UP && g_mb_result.rgwPasscode[1] == DPAD_UP && g_mb_result.rgwPasscode[2] == DPAD_UP && g_mb_result.rgwPasscode[3] == DPAD_UP )
	{
		Sleep(500);
		
		if( CheatDU == TRUE )
		{
			pop(L"All Cheats Deactivated");
			DoCheat(0x830DBBA4, ammo, 4);
			OneHitKo = FALSE;
			InfHealth = FALSE;
			CheatDU = FALSE;
	        PulseController();

		}else{
			
			pop(L"All Cheats Activated");
			DoCheat(0x830DBBA4, nop, 4);
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
