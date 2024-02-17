#include "common.h"

UINT32 g_titleID = 0x394F07D4;

DWORD buf[] = {0xC00B26F4, 0xFF010000};
DWORD Timerbuf[] = {0x7CC55038, 0x90BF0024};
DWORD Moneybuf[] = {0x00000000, 0xfffff17b};

VOID __declspec(naked) CheckHealth(VOID)
{ 


	__asm{
	
		lfs fr0,114h(r31)
		mflr r15
	}

	Saveregs();

	__asm 
	{
		mr MYPtr1,r31
	}

	if( InfHealth == TRUE)//health
	{
		*(DWORD*)(MYPtr1 + 0x114) = 0x447A0000;

	}


	Loadregs();


	__asm{

		fsubs fr13,fr0,fr1
		fsel fr0,fr13,fr1,fr0
		fsel fr0,fr0,fr0,fr31

		mtlr r15
		lis r15,0x8283
		ori r15,r15,0xFD24
		mtctr r15
		bctr
 	}
}

static void Statics(){
	while (1){

		if (OneHitKo == TRUE)
		{
			SetDWORD(Gold_addr, Max_IT);
		}  

		if (ALLCheats2 == TRUE)
		{
			SetDWORD(0x8353F5EC, 0x01000000);

		}  
		Sleep(10); 
	}
}

VOID SetHooks()
{

	Caveme(addr,CheckHealth,15);
//	Caveme(0x8287f704,CheckKill,4);
	HooksSet = true;
}
//
VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"More at T3furyGaming.co.uk", L"Diablo 3 + 1\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
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
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3furyGaming.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
			hNotify(L"Inf Gold Deactivated");
			OneHitKo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Gold Activated");
			Gold_addr = GetAddr(0x48000000, 0x49000000, Moneybuf, 2, 6)+0x20;
			OneHitKo = TRUE;
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
			OneHitKo = FALSE;
			InfHealth = FALSE;
			ALLCheats = FALSE;
			Vibr01();

		}else{

			hNotify(L"All Cheats Activated");
			Gold_addr = GetAddr(0x48000000, 0x49000000, Moneybuf, 2, 6)+0x20;
			OneHitKo = TRUE;
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
	hNotify(L"Diablo 3 RoS Edition");

	Sleep(25);


    addr = GetAddr(0x82000000, 0x83000000, buf, 2, 1)+0x0c;
	SetAddr = true;
}