#include "common.h"

UINT32 g_titleID = 0x4D5308D6;


bool ExpMOD = false;
bool InfSeal = false;
bool MoneyMOD = false;
bool MoneyMOD1 = false;
bool RenownMOD = false;
bool item = false;



BYTE nades[] = { 0x39, 0x2a, 0x27, 0x10 };
BYTE nadesoff[] = { 0x7d, 0x3a, 0x50, 0x50 };//7D3A5050             subf r9,r26,r10 //392A2710
BYTE potion[] = { 0x35, 0x6a, 0x00, 0x00 };//356A0000
BYTE potionoff[] = { 0x35, 0x6a, 0xff, 0xff };
// Cheat -----------------------------------------------------------------------------------
static DWORD Renown_addr;
static DWORD seal_addr;
static DWORD item_addr;
static DWORD Money_addr;
static DWORD Money1_addr;
//static DWORD Seal_addr;
BYTE NOP[4] = { 0x60, 0x00, 0x00, 0x00 };

static void __declspec(naked) CodeCave(void)
{
	DWORD addr;

	__asm
	{
		lfs fr0,14h(r29)     
			mr r3,r29            
			fadds fr13,fr30,fr0  
			stfs fr13,14h(r29)             
	}

	__asm
	{
		stw r29,addr
	}

	if(*(DWORD*)(addr + 0x18) == 0x437A0000) // player
	{
		if(InfHealth == TRUE)
			*(DWORD*)(addr + 0x14) = 0x437A0000;
	}
	else
	{
		if(OneHitKo == TRUE)
		{
			if(*(int*)(addr + 0x14) > 0x43480000)
				*(DWORD*)(addr + 0x14) = 0x3F800000;
			else
				*(DWORD*)(addr + 0x14) = -1;
		}
	}

	__asm
	{
		blr
	}
}


VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"More at T3furyGaming.co.uk", L"Fable III Trainer\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
}

VOID ButPress( MESSAGEBOX_RESULT g_mb_result )
{

	if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
	{
		Sleep(500);
		//this is the page that shows all available cheats  \r\n indicates create new line
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\1 Hit Kill RB(x4)\r\nInf Seals LT(x4)\r\nInf Money LB(x4)\r\nInf PawnBroker Money Y(x4)\r\nInf Items X(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3furyGaming.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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

		if( InfSeal == TRUE )
		{
			hNotify(L"Inf Seals Deactivated");
			SetDWORD(seal_addr, 0x394A0001);
			InfSeal = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Seals Activated");
			SetDWORD(seal_addr, 0x3940270F);
			InfSeal = TRUE;
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

		if( MoneyMOD == TRUE )
		{
			hNotify(L"Inf Money Deactivated");
			SetDWORD(Money_addr, 0x907E000C);
			MoneyMOD = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Money Activated");
			SetDWORD(Money_addr, 0x913E000C);
			MoneyMOD = TRUE;
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

	if( MoneyMOD1 == TRUE )
	{
		hNotify(L"Inf PawnBroker Money Deactivated");
		DoCheat(0x82A45828, nadesoff, 4);
		MoneyMOD1 = FALSE;
		Vibr01();

	}else{

		hNotify(L"Inf PawnBroker Activated");
		DoCheat(0x82A45828, nades, 4);
		MoneyMOD1 = TRUE;
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

	if( item == TRUE )
	{
		hNotify(L"Inf Items/Potions etc Deactivated");
		DoCheat(0x8241B558, potionoff, 4);
		item = FALSE;
		Vibr01();

	}else{

		hNotify(L"Inf Items/Potions etc Activated");
		DoCheat(0x8241B558, potion, 4);
		item = TRUE;
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
		InfHealth = FALSE;
		OneHitKo = FALSE;
		InfSeal = FALSE;
		MoneyMOD = FALSE;
		MoneyMOD1 = FALSE;
		item = FALSE;
		ALLCheats = FALSE;
		Vibr01();

	}else{

		hNotify(L"All Cheats Activated");
		InfHealth = TRUE;
		OneHitKo = TRUE;
		InfSeal = TRUE;
		MoneyMOD = TRUE;
		MoneyMOD1 = TRUE;
		item = TRUE;
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
	hNotify(L"Fable III");
	Sleep(25);

	//Breakpoint-4,Breakpoint
	DWORD buf[] = {0xEDBE002A, 0xD1BD0014};
	DWORD money_buf[] = {0x7C6A5A14, 0x907E000C};
	//DWORD item_buf[] = {0x917F000C, 0x356AFFFF};
	DWORD money_buf1[] = {0x7D3A5050, 0x912B000C};
	//DWORD exp_buf[] = {0xEDA0082A, 0x7DABED2E};
	//DWORD renown_buf[] = {0x7D7DE214, 0x556A003E};
	DWORD seal_buf[] = {0x3BDE0001, 0x915F0444};
	///Search range
	addr = GetAddr(0x82000000, 0x83000000, buf, 2, 1) - 0x08;
	PatchJump(addr, (DWORD)CodeCave);
	Money_addr = GetAddr(0x82000000, 0x83000000, money_buf, 2, 1) + 0x04;
	Money1_addr = GetAddr(0x82000000, 0x83000000, money_buf1, 1, 2); //+ 0x04;
	//item_addr = GetAddr(0x82000000, 0x83000000, item_buf, 2, 1); //+ 0x04;
	seal_addr = GetAddr(0x82000000, 0x83000000, seal_buf, 2, 1);
	//Renown_addr = GetAddr(0x82000000, 0x83000000, renown_buf, 2, 1);
	Static_Menu = Null_Menu;
}