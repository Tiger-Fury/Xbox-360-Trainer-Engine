#include "common.h"

UINT32 g_titleID = 0x464507DD;

DWORD addr_ammo1 = 0x8236D9C4;
DWORD Ammo_On = 0x000f423f;
DWORD Ammo_off = 0x911E0000;
float XValue = 2000.0;
float XPValue = 999999999.0;
float ZValue = 0.01;


VOID __declspec(naked) CheckHealth(VOID)
{ 


	__asm{
			lfs fr11,2500h(r10)
			fsel fr10,fr0,fr0,fr11
			lfs fr13,1F54h(r9) 
			stfs fr10,20A4h(r31)  
			
                    mflr r16
	     }

	Saveregs();

	__asm {
			mr MYPtr1,r6
	}

	if(MYPtr1 == 0xE4DD6A && InfHealth == TRUE ) {
		__asm { 


			stfs XValue,20A4h(r31)

		}
	}else{
		if( InfHealth == FALSE )
		{
			__asm{

			}
		}


	}

	if( MYPtr1 == 0xEAE26E || MYPtr1 == 0xE204 && OneHitKo == TRUE )
		{

			__asm
			{

				stfs ZValue,20A4h(r31)

			}
	

}else{
	if( OneHitKo == FALSE )
	{
		__asm{

		}
	}


}
	Loadregs();



	__asm{
		bne cr6,br2


			mtlr r16
			lis r16,0x8274   
			ori r16,r16,0xFD40
			mtctr r16
			bctr

br2:
		mtlr r16
			lis r16,0x8274
			ori r16,r16,0xFD48
			mtctr r16
			bctr

	}



}

VOID __declspec(naked) CheckWeight(VOID)
{ 


	__asm{
		fadds fr30,fr0,fr30
			cmplwi cr6,r31,0
			bne cr6,br3 
			stfs fr30,20h(r30)  

			mflr r16
	}

	Saveregs();


	if( NoWeight == TRUE ) {
		__asm { 


			stfs ZValue,20h(r30)

		}
	}else{
		if( NoWeight == FALSE )
		{
			__asm{

			}
		}


	}

	Loadregs();



	__asm{
		lwz r31,4(r30)


			mtlr r16
			lis r16,0x8278  
			ori r16,r16,0x45BC
			mtctr r16
			bctr

br3:
		mtlr r16
			lis r16,0x8278
			ori r16,r16,0x455C
			mtctr r16
			bctr

	}



}

VOID __declspec(naked) CheckItem(VOID)
{ 


	__asm{
		ble cr6,br4
			subf r11,r10,r11
			mr r10,r28 
			stw r11,28h(r31)  

			mflr r16
	}

	Saveregs();


	if( InfItems == TRUE ) {
		__asm { 


			stw Ammo_On,28h(r31)

		}
	}else{
		if( InfItems == FALSE )
		{
			__asm{

			}
		}


	}

	Loadregs();



	__asm{
		stw r28,78h(r1)


			mtlr r16
			lis r16,0x8278  
			ori r16,r16,0x5B18
			mtctr r16
			bctr

br4:
		mtlr r16
			lis r16,0x8278
			ori r16,r16,0x5B1C
			mtctr r16
			bctr

	}

	

}

VOID __declspec(naked) CheckXP(VOID)
{ 


	__asm{
		stfs fr31,20B0h(r31) 
			mr r27,r3 
			li r5,0   

			mflr r16
	}

	Saveregs();


	if( Max_XP == TRUE ) {
		__asm { 


			stfs XPValue,20B0h(r31)

		}
	}else{
		if( Max_XP == FALSE )
		{
			__asm{

			}
		}


	}

	Loadregs();



	__asm{
		fmr fr1,fr31
		mr r3,r30

			mtlr r16
			lis r16,0x8275  
			ori r16,r16,0x0CD0
			mtctr r16
			bctr

	}



}

VOID SetHooks()
{
    Caveme(0x8274FD2C,CheckHealth,16);
	Caveme(0x827845A8,CheckWeight,16);
	Caveme(0x82785B04,CheckItem,16);
	Caveme(0x82750CBC,CheckXP,16);
    HooksSet = true;
}

VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L" More at T3furyGaming.co.uk", L"Bound by Flame + 7\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
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
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\n1 Hit Kill RB(x4)\r\nInf Magic LT(x4)\r\nNo Weight LB(x4)\r\nItem/Money Y(x4)\r\nMax XP/Skill Points X(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3furyGaming.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;


	}
	if( g_mb_result.rgwPasscode[0] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[1] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[2] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[3] == RIGHT_TRIGGER )
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
	if( g_mb_result.rgwPasscode[0] == RIGHT_BUMPER && g_mb_result.rgwPasscode[1] == RIGHT_BUMPER && g_mb_result.rgwPasscode[2] == RIGHT_BUMPER && g_mb_result.rgwPasscode[3] == RIGHT_BUMPER )
	{
		Sleep(500);

		if( OneHitKo == TRUE )
		{
			hNotify(L"One Hit Kill Deactivated");
			OneHitKo = FALSE;
			Vibr01();

		}else{

			hNotify(L"One Hit Kill Activated");
			OneHitKo = TRUE;
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

		if( InfAmmo == TRUE )
		{
			hNotify(L"Inf Magic Deactivated");
			SetDWORD(0x8274F6C4,0xD01F20A8);
			InfAmmo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Magic Activated");
			SetDWORD(0x8274F6C4,NOPThis);
			InfAmmo = TRUE;
			Vibr01();

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

		if( NoWeight == TRUE )
		{
			hNotify(L"No Weight Deactivated");
			NoWeight = FALSE;
			Vibr01();

		}else{

			hNotify(L"No Weight Activated");
			NoWeight = TRUE;
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

		if( InfItems == TRUE )
		{
			hNotify(L"Inf items and Money Deactivated");
			InfItems = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf items and Money Activated");
			InfItems = TRUE;
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

		if( Max_XP == TRUE )
		{
			hNotify(L"Max XP Deactivated");
			Max_XP = FALSE;
			Vibr01();

		}else{

			hNotify(L"Max XP Activated");
			Max_XP = TRUE;
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

		if( ALLCheats == TRUE )
		{
			hNotify(L"All Cheats Deactivated");
			SetDWORD(0x8274F6C4,0xD01F20A8);
			OneHitKo = FALSE;
			NoWeight = FALSE;
			InfItems = FALSE;
			InfHealth = FALSE;
			ALLCheats = FALSE;
			Vibr01();

		}else{

			hNotify(L"All Cheats Activated");
			SetDWORD(0x8274F6C4,NOPThis);
			OneHitKo = TRUE;
			NoWeight = TRUE;
			InfItems = TRUE;
			InfHealth = TRUE;
			ALLCheats = TRUE;
			Vibr01();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
}

VOID SearchAddr()
{
	hNotify(L"Bound by Flame");
	Sleep(25);
	SetAddr = true;
}