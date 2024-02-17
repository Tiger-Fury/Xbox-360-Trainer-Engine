#include "common.h"

UINT32 g_titleID = 0x415608C3;

HRESULT hre = 0; 
DWORD hr = 0; 
WCHAR r1[512];
union
{
	unsigned int integer;
	unsigned char byte[4];
} shiz;


//ADD  BOOLS

///static codes values
// bool SetAddr = false;
// bool InfHealthZOM = false;
// bool InfHealth = false;
// bool OneHitKo = false;
// bool InfAmmoZom = false;
// bool InfAmmo = false;
// bool killstreaks = false;
// bool InfGrenade = false;
// bool ALLCheats = false;
// bool ALLCheats1 = false;
// bool ALLCheats2 = false;
// bool NOAmmo = false;
// bool HooksSet = false;

DWORD pokehealth = 0x39600FA0;

BYTE nadesoff[] = { 0x7d, 0x3a, 0x50, 0x50 };//7D3A5050             subf r9,r26,r10 //392A2710
BYTE potion[] = { 0x35, 0x6a, 0x00, 0x00 };//356A0000
BYTE potionoff[] = { 0x35, 0x6a, 0xff, 0xff };
DWORD Weaponselect = 0x83551CAC;
DWORD AmmoPoke = 0x0000001e;
DWORD ksPoke = 0x00000001;
/*bool maxcashzm = false;*/
// Cheat -----------------------------------------------------------------------------------
DWORD pokeShealth = 0x39400FA0;

static void Statics(){
	while (1){

		if (maxcashzm == TRUE)
		{
			SetDWORD(0x83556FD8, 0x000f4240);
		}  

		if (ALLCheats2 == TRUE)
		{
			SetDWORD(0x8353F5EC, 0x01000000);

		}  
		Sleep(10); 
	}
}

VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L" More at T3furyGaming.co.uk", L"Black Ops 2 TU18 Trainer\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
}

VOID ButPress( MESSAGEBOX_RESULT g_mb_result )
{

	if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
	{
		Sleep(500);
		//this is the page that shows all available cheats  \r\n indicates create new line
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All SP Cheats Dpad Up(x4)\r\nAll Zombie Cheats Dpad Right(x4)\r\nZombie Blood Dpad Left(x4)\r\nInf Health RT(x4)\r\nInf Health (Zombies) RT(x3)+LT\r\nInf Ammo LT(x4)\r\nInf Ammo (Zombies) LT(x3)+RT\r\nSuper Jump LB(x4)\r\nSuper Speed LB(x3)+RB\r\nZombie Cash Y(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3furyGaming.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
			SetDWORD(0x8229D144, NOPThis);
			InfHealth = TRUE;
			Vibr01();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
	if( g_mb_result.rgwPasscode[0] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[1] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[2] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[3] == LEFT_TRIGGER )
	{
		Sleep(500);

		if( InfHealth == TRUE )
		{
			hNotify(L"Inf Health Zombie Deactivated");
			InfHealth = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Health Zombie Activated");
			SetDWORD(0x823229D0, NOPThis);
			InfHealth = TRUE;
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
			InfAmmo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Ammo Activated");
			SetDWORD(0x82150324, NOPThis);
			InfAmmo = TRUE;
			Vibr01();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
	if( g_mb_result.rgwPasscode[0] == LEFT_TRIGGER && g_mb_result.rgwPasscode[1] == LEFT_TRIGGER && g_mb_result.rgwPasscode[2] == LEFT_TRIGGER && g_mb_result.rgwPasscode[3] == RIGHT_TRIGGER )
	{
		Sleep(500);

		if( InfAmmoZom == TRUE )
		{
			hNotify(L"Inf Ammo MP/Zom Deactivated");
			SetDWORD(0x826BE71C, 0x90E30000);
			InfAmmoZom = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Ammo MP/Zom Activated");
			SetDWORD(0x826BE71C, NOPThis);
			InfAmmoZom = TRUE;
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

		if( NOAmmo == TRUE )
		{
			hNotify(L"Super Jump + No Fall Damage Deactivated");
			SetDWORD(0x82085654,0x421c0000);
			SetDWORD(0x82001650,0x43000000);
			NOAmmo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Super Jump + No Fall Damage Activated");
			SetDWORD(0x82085654,0x491c0000);
			SetDWORD(0x82001650,0x73000000);
			NOAmmo = TRUE;
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

		if( InfGrenade == TRUE )
		{
			hNotify(L"Super Speed Deactivated");
			SetDWORD(0x83556EF0,0x3f800000);
			InfGrenade = FALSE;
			Vibr01();

		}else{

			hNotify(L"Super Speed Activated");
			SetDWORD(0x83556EF0,0x3ff00000);
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

		if( maxcashzm == TRUE )
		{
			hNotify(L"Bling King Deactivated");
			maxcashzm = FALSE;
			Vibr01();

		}else{

			hNotify(L"Bling King Activated");
			maxcashzm = TRUE;
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
		hNotify(L"All SP Cheats Deactivated");
		ALLCheats = FALSE;
		Vibr01();

	}else{

		hNotify(L"All SP Cheats Activated");
		SetDWORD(0x8229D144, NOPThis);
		SetDWORD(0x82150324, NOPThis);
		ALLCheats = TRUE;
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

	if( ALLCheats1 == TRUE )
	{
		hNotify(L"All Zombie Cheats Deactivated");
		SetDWORD(0x8353F5EC, 0x00000000);
		SetDWORD(0x826BE71C, 0x90E30000);
		maxcashzm = FALSE;
		ALLCheats2 = FALSE;
		ALLCheats1 = FALSE;
		Vibr01();

	}else{

		hNotify(L"All Zombie Cheats Activated");
		SetDWORD(0x8353F5EC, 0x01000000);
		SetDWORD(0x823229D0, NOPThis);
		SetDWORD(0x826BE71C, NOPThis);
		maxcashzm = TRUE;
		ALLCheats2 = TRUE;
		ALLCheats1 = TRUE;
		Vibr01();

	}

	memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
	memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
	memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
	memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
	Prompt = 0x9999;
}
if( g_mb_result.rgwPasscode[0] == DPAD_LEFT && g_mb_result.rgwPasscode[1] == DPAD_LEFT && g_mb_result.rgwPasscode[2] == DPAD_LEFT && g_mb_result.rgwPasscode[3] == DPAD_LEFT )
{
	Sleep(500);

	if( ALLCheats2 == TRUE )
	{
		hNotify(L"Zombie Blood Deactivated");
		ALLCheats2 = FALSE;
		Vibr01();

	}else{

		hNotify(L"Zombie Blood Activated");
		ALLCheats2 = TRUE;
		Vibr01();

	}

	memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
	memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
	memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
	memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
	Prompt = 0x9999;
}
}

VOID Quicklaunch1()
	//wind
{
	SetDWORD(Weaponselect, 0x00000045);
		InfAmmoZom = TRUE;
}



VOID Quicklaunch2()
	//ice
{
	SetDWORD(Weaponselect, 0x00000048);
	InfAmmoZom = TRUE;
}

VOID Quicklaunch3()
	//fire
{
	SetDWORD(Weaponselect, 0x00000046);
	InfAmmoZom = TRUE;
}

VOID Quicklaunch4()
	//lightning
{
	SetDWORD(Weaponselect, 0x00000047);
	InfAmmoZom = TRUE;
}

VOID Quicklaunch5()
	//raygun
{
	SetDWORD(Weaponselect, 0x00000041);
	InfAmmoZom = TRUE;
}

VOID Quicklaunch6()
	//raygun mark 2
{
	SetDWORD(Weaponselect, 0x00000042);
	InfAmmoZom = TRUE;
}

VOID Quicklaunch7()
	//porters mark 2 raygun
{
	SetDWORD(Weaponselect, 0x00000043);
	InfAmmoZom = TRUE;
}

VOID Quicklaunch8()
	//porters x2 raygun
{
	SetDWORD(Weaponselect, 0x00000044);
	InfAmmoZom = TRUE;
}
//Search for TU Address
VOID SearchAddr()
{
	if (GetDWORD(0x82294B04) == 0x1D440370)
	{
		hNotify(L"Call of Duty: Black Ops 2");
		Gamexex = 0;
		Sleep(25);
		SetAddr = true;
	}
	if (GetDWORD(0x82294B04) == 0x2F030000)
	{
		hNotify(L"Call of Duty: Black Ops 2 MP/Zombie");
		Gamexex = 1;
		Sleep(25);
		SetAddr = true;
	}
// 	hNotify(L"Black Ops 2 TU18");
// 	Sleep(25);
// 	SetAddr = true;
}