#include "common.h"

UINT32 g_titleID = 0x5841127D;

DWORD buf[] = {0xEC20F82A, 0xD03F00C0};
DWORD buf1[] = {0xED40602A, 0xD17F0E30};
DWORD Specbuf[] = {0xEC206FBC, 0xD03F002C};
DWORD ammobuf[] = {0x91630410, 0x91230414};

VOID __declspec(naked) CheckHealth(VOID)
{ 


	__asm{
		lwz r11,0(r3)

			mflr r15
	}

	Saveregs();

	__asm 
	{
		mr MYPtr1,r3

	}

	
	if( InfHealth == TRUE)
	{
		*(DWORD*)(MYPtr1+0x1c) = 0x447A0000;

	}

	Loadregs();



	__asm{

		lwz r10,28h(r11)
		mtctr r10 
		bctrl

		mtlr r15
		lis r15,0x8236
		ori r15,r15,0x1984
		mtctr r15
		bctr
	}



}

VOID SetHooks()
{

	Caveme(0x82361974 ,CheckHealth,15);
	HooksSet = true;
}

VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"More at T3furyGaming.co.uk", L"GTA 5 All TU + 7\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
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
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nInf Special RB(x4)\r\nInf Ammo LT(x4)\r\nMax Cash LB(x4)\r\nMax Wanted Y(x4)\r\nNo Wanted X(x4)\r\nInf Armor Dpad Right(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3furyGaming.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
			SetDWORD(addr,0xD03F00C0);
			InfHealth = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Health Activated");
			SetDWORD(addr,NOPThis);
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
			hNotify(L"Inf Special Deactivated");
			//SetDWORD(addr_Special,0xD03F002C);
			OneHitKo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Special Activated");
		//	SetDWORD(addr_Special,NOPThis);
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
			hNotify(L"Inf Ammo & Grenades Deactivated");
			SetDWORD(addr_ammo,0x93DF0010);
			InfAmmo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Ammo & Grenades Activated");
			SetDWORD(addr_ammo,NOPThis);
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

		if( InfCash== TRUE )
		{
			hNotify(L"Max Cash Deactivated");
			SetDWORD(0xCB5106D0,Max_IT);
			InfCash = FALSE;
			Vibr01();

		}else{

			hNotify(L"Max Cash Activated");
			SetDWORD(0xCB5106D0,Max_IT);
			InfCash = TRUE;
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

		if( InfLight== TRUE )
		{
			hNotify(L"Max Wanted Level Activated");
			SetDWORD(0xBFB1D2D4,0x00000005);
			InfLight = FALSE;
			Vibr01();

		}else{

			hNotify(L"Max Wanted Level Activated");
			SetDWORD(0xBFB1D2D4,0x00000005);
			InfLight = TRUE;
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

		if( InfAbility== TRUE )
		{
			hNotify(L"No Wanted Level Activated");
			SetDWORD(0xBFB1D2D4,0x00000000);
			InfAbility = FALSE;
			Vibr01();

		}else{

			hNotify(L"NO Wanted Level Activated");
			SetDWORD(0xBFB1D2D4,0x00000000);
			InfAbility = TRUE;
			Vibr01();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
	if( g_mb_result.rgwPasscode[0] == DPAD_RIGHT && g_mb_result.rgwPasscode[1] == DPAD_RIGHT && g_mb_result.rgwPasscode[2] == DPAD_RIGHT && g_mb_result.rgwPasscode[3] == DPAD_RIGHT )
	{
		Sleep(500);

		if( InfArmor== TRUE )
		{
			hNotify(L"Inf Armor Activated");
			SetDWORD(addr1,0xD17F0E30);
			InfArmor = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Armor Activated");
			SetDWORD(addr1,NOPThis);
			InfArmor= TRUE;
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
			SetDWORD(0xCB5106D0,Max_IT);
			SetDWORD(addr_ammo,0x93DF0010);
			SetDWORD(addr_Special,0xD03F002C);
			SetDWORD(addr,0xD03F00C0);
			SetDWORD(addr1,0xD17F0E30);
			ALLCheats = FALSE;
			Vibr01();

		}else{

			hNotify(L"All Cheats Activated");
			SetDWORD(addr_ammo,NOPThis);
			SetDWORD(0xCB5106D0,Max_IT);
			SetDWORD(addr_Special,NOPThis);
			SetDWORD(addr,NOPThis);
			SetDWORD(addr1,NOPThis);
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
	hNotify(L"GTA V");

	Sleep(25);
//  	addr = GetAddr(0x82000000, 0x83000000, buf, 2, 1)+ 0x04;
// 	addr_Special = GetAddr(0x82000000, 0x83000000, Specbuf, 2, 1)+0x04;
//  	addr_ammo = GetAddr(0x82000000, 0x83000000, ammobuf, 2, 1)+ 0x58;
//  	addr1 = GetAddr(0x82000000, 0x83000000, buf1, 2, 1)+0x04;
// 	addr_arrows = GetAddr(0x82000000, 0x83000000, bufarrow, 2, 2)-0x04;
// 	addr_Gren = GetAddr(0x82000000, 0x83000000, bufarrow, 2, 1)-0x04;
	SetAddr = true;
}