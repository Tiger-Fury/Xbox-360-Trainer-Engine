#include "common.h"

UINT32 g_titleID = 0x4E4D0800;

DWORD buf1[] = {0x5548103A, 0xB17F013E};
DWORD buf[] = {0x40980020, 0x81560124};
DWORD Specbuf[] = {0x41990014, 0x915F012C};
DWORD Skillbuf[] = {0x90CB016C, 0x7CE83B78};
DWORD Skillbuf1[] = {0x38600000, 0x93EB0000};
DWORD Timerbuf[] = {0x356BFFFF, 0x916A0000};


VOID __declspec(naked) CheckHealth(VOID)
{ 


	__asm{

		lwz r10,124h(r22)

			mflr r15
	}

	Saveregs();

	__asm 
	{
		mr MYPtr1,r22
			mr MYPtr2,r26
			//mr MYPtr2,r4
	}

	if( MYPtr2 == 0x04 || MYPtr2 == 0x09 || MYPtr2 == 0x0A || MYPtr2 == 0x00 || MYPtr2 == 0x03 && InfHealth == TRUE)
	{
		*(DWORD*)(MYPtr1 + 0x124) = *(DWORD*)(MYPtr1 + 0x120);

	}
	if(MYPtr2 == 0x01 && InfHealth2 == TRUE)
	{
		*(DWORD*)(MYPtr1 + 0x124) = *(DWORD*)(MYPtr1 + 0x120);

	}
	Loadregs();


	__asm{

		lwz r9,120h(r22)
		slwi r8,r10,2
		cmpw cr6,r8,r9

			mtlr r15
			lis r15,0x8218
			ori r15,r15,0x4e1c
			mtctr r15
			bctr
	}
}


VOID SetHooks()
{

	Caveme(addr ,CheckHealth,15);
	HooksSet = true;
}

VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"More at T3furyGaming.co.uk", L"Dynasty Warriors Gundam 2 + 4\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
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
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nInf Health Char RT(x3)\r\nInf Boost RB(x4)\r\nInf/Max Special LT(x4)\r\nMax Pilot Points LB(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3furyGaming.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
	if( g_mb_result.rgwPasscode[0] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[1] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[2] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[3] == LEFT_TRIGGER )
	{
		Sleep(500);

		if( InfHealth2 == TRUE )
		{
			hNotify(L"Inf Health Char Deactivated");
			InfHealth2 = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Health Char Activated");
			InfHealth2 = TRUE;
			Vibr01();

		}
		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
	if(  g_mb_result.rgwPasscode[0] == RIGHT_BUMPER && g_mb_result.rgwPasscode[1] == RIGHT_BUMPER && g_mb_result.rgwPasscode[2] == RIGHT_BUMPER && g_mb_result.rgwPasscode[3] == RIGHT_BUMPER )
	{
		Sleep(500);

		if( OneHitKo == TRUE )
		{
			hNotify(L"Inf Boost Deactivated");
			SetDWORD(addr_Gren, 0xB17F013E);
			OneHitKo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Boost Activated");
			SetDWORD(addr_Gren, NOPThis);
			OneHitKo = TRUE;
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

		if( InfStamina == TRUE )
		{
			hNotify(L"Max Pilot XP Deactivated");
			InfStamina = FALSE;
			Vibr01();

		}else{

			hNotify(L"Max Pilot XP Activated");
			SetDWORD(0x8273AD04, 0x00074c20);
			InfStamina = TRUE;
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

		if( InfSpecial == TRUE )
		{
			hNotify(L"Max/Inf Special Deactivated");
			SetDWORD(addr_Special, 0x915F012C);
			InfSpecial = FALSE;
			Vibr01();

		}else{

			hNotify(L"Max/Inf Special Activated");
			SetDWORD(addr_Special, 0x917F012C);
			InfSpecial = TRUE;
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
			SetDWORD(addr_Special, 0x915F012C);
			SetDWORD(addr_Gren, 0xB17F013E);
			InfHealth = FALSE;
			ALLCheats = FALSE;
			Vibr01();

		}else{

			hNotify(L"All Cheats Activated");
			SetDWORD(addr_Special, 0x917F012C);
			SetDWORD(addr_Gren, NOPThis);
			SetDWORD(0x8273AD04, 0x00074c20);
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
	hNotify(L"Dynasty Warriors Gundam 2");

	Sleep(25);
   	addr = GetAddr(0x82000000, 0x83000000, buf, 2, 1)+ 0x04;
   	addr_Special = GetAddr(0x82000000, 0x83000000, Specbuf, 2, 1)+ 0x04;
 	addr_Gren = GetAddr(0x82000000, 0x83000000, buf1, 2, 1)+ 0x04;
	SetAddr = true;
}