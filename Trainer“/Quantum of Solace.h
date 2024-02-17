#include "common.h"

UINT32 g_titleID = 0x415607ff;

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

BYTE nades[] = { 0x39, 0x2a, 0x27, 0x10 };
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

		if (InfHealth == TRUE)
		{
			SetDWORD(0x82B5CDD4, 0x000000ff);
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
	Prompt = XShowMessageBoxUI(0, L" More at T3furyGaming.co.uk", L"Quantum of Solace +2 Trainer\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
}

VOID ButPress( MESSAGEBOX_RESULT g_mb_result )
{

	if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
	{
		Sleep(500);
		//this is the page that shows all available cheats  \r\n indicates create new line
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nInf Ammo LT(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3furyGaming.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
			SetDWORD(addr_ammo, NOPThis);
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
		hNotify(L"All SP Cheats Deactivated");
		ALLCheats = FALSE;
		Vibr01();

	}else{

		hNotify(L"All SP Cheats Activated");
		SetDWORD(addr, NOPThis);
		SetDWORD(addr_ammo, NOPThis);
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
	hNotify(L"Quantum of Solace");
	Sleep(25);

	addr = 0x82150324;

	addr1 = 0x823229D0;

	addr_ammo = 0x82165DA8;
	SetAddr = true;
}