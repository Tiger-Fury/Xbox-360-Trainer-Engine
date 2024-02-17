#include "common.h"

UINT32 g_titleID = 0x544307DC;


DWORD MYPtr1;
DWORD MYPtr2;
DWORD buf[] = {0x419A004C, 0x817F00A0};
DWORD bufAmmo[] = {0x93410074, 0x816E00A8};



VOID __declspec(naked) FarCCheckAmmo(VOID)
{ 


	__asm{
			lwz r11,0A8h(r14)
            mflr r20
	     }

	Saveregs();

	__asm 
	{
			mr MYPtr1,r14
			
	}

	if(*(DWORD*)(MYPtr1+0x184) == 0x41600000 && InfAmmo == TRUE)
	{
		*(DWORD*)(MYPtr1+0xa8) = 0x00000063;			
	}
	if(*(DWORD*)(MYPtr1+0x184) == 0x41600000 && InfGrenade == TRUE)
	{
		*(DWORD*)(MYPtr1+0xB0) = 0x00000063;			
	}
	Loadregs();



	__asm{

		cmplw cr6,r26,r11
		ble cr6,br2
		mr r26,r11
		
			mtlr r20

// 			lis r20,0x826B 
// 			ori r20,r20,0x8818
// 			mtctr r20
// 			bctr

br2:
			lis r20,0x826B  
			ori r20,r20,0x881C
			mtctr r20
			bctr

	}



}

VOID __declspec(naked) FarCCheckHealth(VOID)
{ 


	__asm{
		stfs fr8,18h(r11)
			mflr r11
	}

	Saveregs();

	__asm 
	{
		mr MYPtr2,r11

	}

	if(*(DWORD*)(MYPtr2+0x18) == 0x447a0000 && InfHealth == TRUE)
	{
		*(DWORD*)(MYPtr2+0x18) = 0x44fa0000;			
	}
	Loadregs();



	__asm{

		fcmpu cr6,fr8,fr0 
		bge cr6,br3
		stfs fr0,18h(r11)

			mtlr r11

br3:
			lis r11,0x821A
			ori r11,r11,0xEB2C
			mtctr r11
			bctr

	}



}


VOID SetHooks()
{

	Caveme(0x821AEB1C,FarCCheckHealth,11);
    HooksSet = true;
}

VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"More at T3furyGaming.co.uk", L"FarCry Classic + 5\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
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
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nOne Hit Kill Removed\r\nInf Ammo LT(x4)\r\nInf Grenades LB(x4)\r\nInf Stamina Y(x4)\r\nInf Armor X(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3furyGaming.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;


	}
	if(  g_mb_result.rgwPasscode[0] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[1] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[2] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[3] == RIGHT_TRIGGER )
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
// 	if( g_mb_result.rgwPasscode[0] == RIGHT_BUMPER && g_mb_result.rgwPasscode[1] == RIGHT_BUMPER && g_mb_result.rgwPasscode[2] == RIGHT_BUMPER && g_mb_result.rgwPasscode[3] == RIGHT_BUMPER )
// 	{
// 		Sleep(500);
// 
// 		if( OneHitKo == TRUE )
// 		{
// 			hNotify(L"One Hit Kill Deactivated");
// 			OneHitKo = FALSE;
// 			Vibr01();
// 
// 		}else{
// 
// 			hNotify(L"One Hit Kill Activated");
// 			OneHitKo = TRUE;
// 			Vibr01();
// 
// 		}
// 		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
// 		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
// 		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
// 		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
// 		Prompt = 0x9999;
// 	}
	if( g_mb_result.rgwPasscode[0] == LEFT_TRIGGER && g_mb_result.rgwPasscode[1] == LEFT_TRIGGER && g_mb_result.rgwPasscode[2] == LEFT_TRIGGER && g_mb_result.rgwPasscode[3] == LEFT_TRIGGER )
	{
		Sleep(500);

		if( InfAmmo == TRUE )
		{
			hNotify(L"Inf Ammo Deactivated");
			InfAmmo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Ammo Activated");
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

		if( InfGrenade == TRUE )
		{
			hNotify(L"Inf Grenade Deactivated");
			InfGrenade = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Grenade Activated");
			InfGrenade = TRUE;
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

		if( InfStamina == TRUE )
		{
			hNotify(L"Inf Stamina Deactivated");
			InfStamina = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Stamina Activated");
			InfStamina = TRUE;
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

		if( InfArmor == TRUE )
		{
			hNotify(L"Inf Armor Deactivated");
			InfArmor = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Armor Activated");
			InfArmor = TRUE;
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

	if(ALLCheats == TRUE )
	{
		hNotify(L"All Cheats Deactivated");
		InfArmor = FALSE;
		InfGrenade = FALSE;
		InfStamina = FALSE;
		InfHealth = FALSE;
		InfAmmo = FALSE;
		ALLCheats = FALSE;
		Vibr01();

	}else{

		hNotify(L"All Cheats Activated");
		InfArmor = TRUE;
		InfGrenade = TRUE;
		InfStamina = TRUE;
		InfHealth = TRUE;
		InfAmmo = TRUE;
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
	hNotify(L"Quantum Theory");
	Sleep(25);
	//addr = GetAddr(0x82000000, 0x83000000, buf, 2, 1)+ 0x04;
	addr_ammo = GetAddr(0x82000000, 0x83000000, bufAmmo, 2, 1)+ 0x04;
	SetAddr = true;
}