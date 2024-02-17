#include "common.h"

UINT32 g_titleID = 0x454109C6;



//ADD  BOOLS

///static codes values
bool SetAddr = false;
bool InfHealth = false;
bool OneHitKo = false;
bool InfAmmo = false;
bool InfGrenade = false;
bool ALLCheats = false;
bool NOAmmo = false;
bool HooksSet = false;

DWORD pokehealth = 0x7D3E5A14;

BYTE nades[] = { 0x39, 0x2a, 0x27, 0x10 };
BYTE nadesoff[] = { 0x7d, 0x3a, 0x50, 0x50 };//7D3A5050             subf r9,r26,r10 //392A2710
BYTE potion[] = { 0x35, 0x6a, 0x00, 0x00 };//356A0000
BYTE potionoff[] = { 0x35, 0x6a, 0xff, 0xff };
// Cheat -----------------------------------------------------------------------------------
DWORD pokeShealth = 0x39400FA0;

// VOID __declspec(naked) CheckHP(VOID) {
// 
// 
// 	DWORD dwPtr;
// 
// 	__asm {
// 			mr dwPtr,r0
// 			lwz r9,20h(r3)     
// 			lwz r10,24h(r3)        
// 			add r11,r11,r9  
// 			stw r11,20h(r3)   
// 	}
// 
// 	if (dwPtr == 0x82B4A9A0 && InfHealth == TRUE) {
// 		DWORD fltValue = 0x00000FA0;
// 		__asm { 
// 			stw fltValue,20h(r3)
// 		}
// 
// 	}else{
// 
// 		if( InfHealth == FALSE )
// 		{
// 			__asm
// 			{
// 
// 			}
// 		}
// 
// 	}
// 
// 	if (dwPtr != 0x82B4A9A0 && OneHitKo == TRUE) {
// 		DWORD XValue = 0x00000000;
// 		__asm 
// 		{ 
// 
// 			stw XValue,20h(r3)
// 		}
// 
// 	}else{
// 
// 		if( OneHitKo == FALSE )
// 		{
// 			__asm
// 			{
// 
// 			}
// 		}
// 
// 	}
// 
// 	// 82ECC2D0
// 	__asm{
// 		lis r11,0x8251   
// 			ori r11,r11,0x7BB4
// 			mtctr r11
// 			bctr      
// 	}
// 
// }
// 
// VOID __declspec(naked) CheckAmmo(VOID) {
// 
// 
// 	DWORD dwPtr;
// 
// 	__asm {
// 			mr dwPtr,r11     
// 			li r11,0  
// 			stw r11,47Ch(r3) 
// 			blr
// 			lwz r11,5A8h(r3)
// 	}
// 
// 	if (dwPtr == 0x1C && InfAmmo == TRUE) {
// 		DWORD AValue = 63;
// 		__asm { 
// 			stw AValue,47Ch(r3)
// 		}
// 
// 	}else{
// 
// 		if( InfAmmo == FALSE )
// 		{
// 			__asm
// 			{
// 
// 			}
// 		}
// 
// 	}
// 
// 	if (dwPtr != 0x00 && NOAmmo == TRUE) {
// 		DWORD Bvalue = 0x00000000;
// 		__asm 
// 		{ 
// 
// 			stw Bvalue,47Ch(r3)
// 		}
// 
// 	}else{
// 
// 		if( NOAmmo == FALSE )
// 		{
// 			__asm
// 			{
// 
// 			}
// 		}
// 
// 	}
// 
// 	// 82ECC2D0
// 	__asm{
// 		lis r11,0x82A5   
// 			ori r11,r11,0x04C4
// 			mtctr r11
// 			bctr      
// 	}
// 
// }

// VOID SetHooks()
// {
// // 
// // 
// // 	DWORD IHealth[4];
// // 	patchInJump( (PDWORD)IHealth, (DWORD)CheckHP, FALSE );
// // 
// // 	DoCave(0x82517BA4, &IHealth[0], 4);
// // 	DoCave(0x82517BA8, &IHealth[1], 4);
// // 	DoCave(0x82517BAC, &IHealth[2], 4);
// // 	DoCave(0x82517BB0, &IHealth[3], 4);
// 
// 	DWORD IAmmo[4];
// 	patchInJump( (PDWORD)IAmmo, (DWORD)CheckAmmo, FALSE );
// 	DoCave(0x82A504B4, &IAmmo[0], 4);
// 	DoCave(0x82A504B8, &IAmmo[1], 4);
// 	DoCave(0x82A504BC, &IAmmo[2], 4);
// 	DoCave(0x82A504C0, &IAmmo[3], 4);
// 
// 	HooksSet = true;
// }

VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"~TeamXPG~ t3fury XPGamesaves.com", L"Need For Speed Rivals\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
// 	if( HooksSet == false )
// 	{
//		SetHooks();
// 	}
}

VOID ButPress( MESSAGEBOX_RESULT g_mb_result )
{

	if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
	{
		Sleep(500);
		//this is the page that shows all available cheats  \r\n indicates create new line
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf NoS RT(x4)\r\nInf SP LT(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nXPGamesaves.com\r\nHome To TeamXPG and 360 Revolution", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
			hNotify(L"Inf NOS Deactivated");
			InfHealth = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf NOS Activated");
			SetDWORD(addr, NOPThis);
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
// 			hNotify(L"Inf Grenade Deactivated");
// 			OneHitKo = FALSE;
// 			Vibr01();
// 
// 		}else{
// 
// 			hNotify(L"Inf Grenade Activated");
// 			SetDWORD(addr_Gren, NOPThis);
// 			OneHitKo = TRUE;
// 			Vibr01();
// 
// 		}
// 
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
			hNotify(L"Inf SP Deactivated");
			InfAmmo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf SP Activated");
			SetDWORD(addr_ammo, pokehealth);
			InfAmmo = TRUE;
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
		ALLCheats = FALSE;
		Vibr01();

	}else{

		hNotify(L"All Cheats Activated");
		SetDWORD(addr_ammo, pokehealth);
		SetDWORD(addr, NOPThis);
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

//Search for TU Address
VOID SearchAddr()
{
	hNotify(L"Need For Speed Rivals");
	Sleep(25);
// 	hNotify(L"Applying All TU Patch");
// 	Sleep(25);

	//Breakpoint-4,Breakpoint
	// if your reading this then your an XYZ Gimp bitch, who has no skill at all and just steals everyone elses hard work
// 	DWORD buf[] = {0xD13F0180, 0xC11F0378};
// 	DWORD buf1[] = {0x812B0020, 0x7FA3EB78};
// 	DWORD ammo_buf[] = {0x7D3E5850, 0x7D1E5050}; 
// 	DWORD grenade_buf[] = {0x91670000, 0x7C685850};
// 	DWORD Silencer_buf[] = {0x396BFFFF, 0x556A043E};

	addr = 0x88BC6B14;

	addr_ammo = 0x88B239E8;

	SetAddr = true;
}

VOID XYZ_BITCH()
{
	hNotify(L"if your reading this then your an XYZ Gimp bitch, who has no skill at all and just steals everyone elses hard work");
}