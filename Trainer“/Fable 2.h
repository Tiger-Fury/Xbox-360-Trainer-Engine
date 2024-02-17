#include "common.h"

UINT32 g_titleID = 0x4d5307f1;

DWORD buf[] = {0xFCC74AEE, 0xD0DB0014};
DWORD money_buf[] = {0x5549003E, 0x915A000C};
DWORD exp_buf[] = {0xEDA0082A, 0x7DABED2E};
DWORD renown_buf[] = {0x7D7DE214, 0x556A003E};

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
static DWORD Exp_addr;

static void __declspec(naked) CodeCave(void)
{
	DWORD addr;

	__asm
	{
		or r11,r4,r3          
			lfsx fr7,r7,r11       
			fsel fr6,fr7,fr11,fr9 
			stfs fr6,14h(r27)                            
	}

	__asm
	{
		stw r27,addr
	}

	if(*(DWORD*)(addr + 0x18) == 0x42C80000) // player
	{
		if(InfHealth == TRUE )
			*(DWORD*)(addr + 0x14) = 0x442F0000;
	}
	else if(*(DWORD*)(addr + 0x14) > 0x40A00000)
	{
		if(OneHitKo == TRUE)
			*(DWORD*)(addr + 0x14) = 0;
	}

	__asm
	{
		blr
	}
}


VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"More at T3furyGaming.co.uk", L"Fable II Trainer\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
}

VOID ButPress( MESSAGEBOX_RESULT g_mb_result )
{

	if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
	{
		Sleep(500);
		//this is the page that shows all available cheats  \r\n indicates create new line
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\1 Hit Kill RB(x4)\r\nInf XP LT(x4)\r\nInf Money LB(x4)\r\nInf Renown Y(x4)\r\nInf Items X(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3furyGaming.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
			hNotify(L"Inf XP Deactivated");
			SetDWORD(Exp_addr, 0xEDA0082A);
			SetDWORD(Exp_addr +4 , 0x7DABED2E);
			InfSeal = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf XP Activated");
			SetDWORD(Exp_addr, 0x3D404A00);
			SetDWORD(Exp_addr + 4, 0x7D4BE92E);
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
			SetDWORD(Money_addr, 0x915A000C);
			MoneyMOD = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Money Activated");
			SetDWORD(Money_addr, 0x911A000C);
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
		hNotify(L"Inf Renown Deactivated");
		SetDWORD(Renown_addr, 0x7D7DE214);
		MoneyMOD1 = FALSE;
		Vibr01();

	}else{

		hNotify(L"Inf Renown Activated");
		SetDWORD(Renown_addr, 0x397D7530);
		MoneyMOD1 = TRUE;
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
		SetDWORD(Exp_addr, 0xEDA0082A);
		SetDWORD(Exp_addr +4 , 0x7DABED2E);
		SetDWORD(Renown_addr, 0x7D7DE214);
		SetDWORD(Money_addr, 0x915A000C);
		ALLCheats = FALSE;
		Vibr01();

	}else{

		hNotify(L"All Cheats Activated");
		InfHealth = TRUE;
		OneHitKo = TRUE;
		SetDWORD(Exp_addr, 0x3D404A00);
		SetDWORD(Exp_addr + 4, 0x7D4BE92E);
		SetDWORD(Renown_addr, 0x397D7530);
		SetDWORD(Money_addr, 0x911A000C);
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
	hNotify(L"Fable II");
	Sleep(25);

	///Search range
	addr = GetAddr(0x82000000, 0x83000000, buf, 2, 1) - 0x08;
	PatchJump(addr, (DWORD)CodeCave);
	Money_addr = GetAddr(0x82000000, 0x83000000, money_buf, 2, 1) + 0x04;
	Exp_addr = GetAddr(0x82000000, 0x83000000, exp_buf, 2, 1);
	Renown_addr = GetAddr(0x82000000, 0x83000000, renown_buf, 2, 1);
	Static_Menu = Null_Menu;
}