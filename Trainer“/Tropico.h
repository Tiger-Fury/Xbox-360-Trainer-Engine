#include "common.h"

UINT32 g_titleID = 0x4b5907dc;



//ADD  BOOLS

///static codes values
bool SetAddr = false;
bool InfHealth = false;
bool OneHitKo = false;
bool InfAmmo = false;
bool InfGold = false;
bool InfGrenade = false;
bool ALLCheats = false;



// Cheat -----------------------------------------------------------------------------------
static DWORD addr;
static DWORD Ammo_addr;
static DWORD Charge_addr;
static DWORD uv_addr;
static DWORD Gold_addr;
static DWORD Veil_addr;
//static DWORD Seal_addr;
BYTE NOP[4] = { 0x60, 0x00, 0x00, 0x00 };
BYTE OptionB[4] = { 0x3b, 0x9a, 0xca, 0x00 };

//Code cave
static void __declspec(naked) CodeCave(void)
{
	DWORD addr;

	__asm
	{
// 			cmplwi cr6,r3,0          
// 			bne cr6,82788258       
			lwz r11,0(r21)
			stw r11,0(r29)                            
	}

	__asm
	{
		stw r11,addr
	}

	if(*(DWORD*)(addr) == 0x2710) // player
	{
		if(InfHealth == TRUE )
			*(DWORD*)(addr) = 0x3b9ac9ff;
	}
	else
	{
		if(OneHitKo == TRUE)
			*(DWORD*)(addr) = 0;
	}

	__asm
	{
		blr
	}
}

VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"~TeamXPG~ t3fury XPGamesaves.com", L"ChopLifter HD Trainer\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
}

VOID ButPress( MESSAGEBOX_RESULT g_mb_result )
{

	if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
	{
		Sleep(500);
		//this is the page that shows all available cheats  \r\n indicates create new line
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Ammo LT(x4)\r\nNo Overheat LB(x4)\r\nInf Fuel RB(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nXPGamesaves.com\r\nHome To TeamXPG and 360 Revolution", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
			SetDWORD(Ammo_addr, 0x390AFFFF);
			InfAmmo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Ammo Activated");
			SetDWORD(Ammo_addr, 0x390A0001);
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
			hNotify(L"No Overheat Deactivated");
			SetDWORD(uv_addr, 0xEDA0E82A);
			InfGrenade = FALSE;
			Vibr01();

		}else{

			hNotify(L"No Overheat Activated");
			SetDWORD(uv_addr, 0xEDA0E828);
			InfGrenade = TRUE;
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

		if( InfGold == TRUE )
		{
			hNotify(L"Inf Fuel Deactivated");
			SetDWORD(Charge_addr, 0xED8D0028);
			InfGold = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Fuel Activated");
			SetDWORD(Charge_addr, 0xED8D002A);
			InfGold = TRUE;
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
		//SetDWORD(addr, 0x913F0050);
		SetDWORD(Ammo_addr, 0x390AFFFF);
		SetDWORD(Charge_addr, 0xED8D0028);
		SetDWORD(uv_addr, 0xEDA0E82A);
		ALLCheats = FALSE;
		Vibr01();

	}else{

		hNotify(L"All Cheats Activated");
		//SetDWORD(addr, 0x60000000);
		SetDWORD(Ammo_addr, 0x390A0001);
		SetDWORD(Charge_addr, 0xED8D002A);
		SetDWORD(uv_addr, 0xEDA0E828);
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
	hNotify(L"Tropico 4");
	Sleep(25);
	hNotify(L"Applying All TU Patch");
	Sleep(25);

	//Breakpoint-4,Breakpoint
	//DWORD addr;
	DWORD buf[] = {0x917D0000, 0x81550004};
	DWORD ammo_buf[] = {0x390AFFFF, 0x910B0000}; 
	DWORD uv_buf[] = {0xEDA0E82A, 0xD1BF0744};
	DWORD Charge_buf[] = {0xED8D0028, 0xD19F07A8};//Fuel
//	DWORD grenade_buf[] = {0x7DA0FFAE, 0x38210070};

	addr = GetAddr(0x82100000, 0x83000000, buf, 2, 1);
	PatchJump(addr, (DWORD)CodeCave);

	Ammo_addr = GetAddr(0x82100000, 0x83000000, ammo_buf, 2, 1);
	uv_addr = GetAddr(0x82100000, 0x83000000, uv_buf, 2, 1);
	Charge_addr = GetAddr(0x82100000, 0x83000000, Charge_buf, 2, 1);//Fuel
	//PatchJump(addr, (DWORD)CodeCave_ammo);

//	addr = GetAddr(0x82000000, 0x83000000, grenade_buf, 2, 1) - 0x08;
	//PatchJump(addr, (DWORD)CodeCave_grenade);
	SetAddr = true;
}