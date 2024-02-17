#include "common.h"
//
UINT32 g_titleID = 0x435907d5;

DWORD buf[] = {0xD01F00A4, 0xECA70372};
DWORD Ammobuf[] = {0x419A000C, 0x93830014};
DWORD stambuf[] = {0xD01F13B8, 0xED5F0028};
DWORD Grenbuf[] = {0x93A30000, 0x83FE017C};

float XValue = 100.0;
float ZValue = 0.1;
VOID __declspec(naked) CheckHealth(VOID)
{ 


	__asm{
		lfs fr13,0A4h(r3)

			mflr r26
	}

	Saveregs();

	__asm {
		mr MYPtr1,r31
	}

	if(*(DWORD*)(MYPtr1+0xAC) == 0x42C80000 && InfHealth == TRUE ) {
		__asm { 


			stfs XValue,0A4h(r31) 

		}
	}else{
		if( InfHealth == FALSE )
		{
			__asm{

				stfs fr0,0A4h(r31) 
			}
		}


	}

	Loadregs();



	__asm{
		fmuls fr5,fr7,fr13
		fcmpu cr6,fr0,fr6
		fctiw fr4,fr5 

			mtlr r26
			lis r26,0x8311  
			ori r26,r26,0xA280
			mtctr r26
			bctr



	}



}


VOID SetHooks()
{
	Caveme(addr,CheckHealth,26);
	HooksSet = true;
}
VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"More at T3furyGaming.co.uk", L"Enemy Front + 4\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
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
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nInf Stamina RB(x4)\r\nInf Ammo LT(x4)\r\nInf Grenade LB(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3furyGaming.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
			//SetDWORD(addr,0xD01F00A4);
			InfHealth = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Health Activated");
			//SetDWORD(addr,NOPThis);
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
			hNotify(L"Inf Stamina Deactivated");
			SetDWORD(addr_Stamina,0xD01F13B8);
			OneHitKo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Stamina Activated");
			SetDWORD(addr_Stamina,NOPThis);
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
			hNotify(L"Inf Ammo Deactivated");
			SetDWORD(0x83311934,0xD01F20A8);
			InfAmmo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Ammo Activated");
			SetDWORD(0x83311934,NOPThis);
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
			hNotify(L"Inf Grenades Deactivated");
			SetDWORD(addr_Gren,0x93A30000);
			InfGrenade = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Grenades Activated");
			SetDWORD(addr_Gren,NOPThis);
			InfGrenade = TRUE;
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
			//SetDWORD(addr,0xD01F00A4);
			SetDWORD(addr_Stamina,0xD01F13B8);
			SetDWORD(0x83311934,0xD01F20A8);
			SetDWORD(addr_Gren,0x93A30000);
			InfHealth = FALSE;
			ALLCheats = FALSE;
			Vibr01();

		}else{

			hNotify(L"All Cheats Activated");
			//SetDWORD(addr,NOPThis);
			SetDWORD(addr_Stamina,NOPThis);
			SetDWORD(0x83311934,NOPThis);
			SetDWORD(addr_Gren,NOPThis);
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
	hNotify(L"Enemy Front");
	//addr_ammo = GetAddr(0x8330000, 0x84000000, Ammobuf, 2, 1)+0x04;
	addr = GetAddr(0x83110000, 0x84000000, buf, 2, 1);
	addr_Stamina = GetAddr(0x83000000, 0x84000000, stambuf, 2, 1);
	addr_Gren = GetAddr(0x8249D000, 0x83000000, Grenbuf, 2, 1);
	Sleep(25);
	SetAddr = true;
}