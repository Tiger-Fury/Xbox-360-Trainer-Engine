#include "common.h"

UINT32 g_titleID = 0x4E4D07E5;

DWORD buf[] = {0x40820014, 0xa16400be};
DWORD Specbuf[] = {0x7F0A4000, 0xB16300B8};
DWORD Skillbuf[] = {0x90CB016C, 0x7CE83B78};
DWORD Skillbuf1[] = {0x38600000, 0x93EB0000};
DWORD Timerbuf[] = {0x356BFFFF, 0x916A0000};

VOID __declspec(naked) CheckHealth(VOID)
{ 


	__asm{
	
		lhz r11,0BEh(r4) 
		lhz r10,0B4h(r30)//

		mflr r15
	}

	Saveregs();

	__asm 
	{
		mr MYPtr1,r30
		mr MYPtr2,r10
	}

	if(*(WORD*)(MYPtr1+0x32) == 0x0F3C || *(WORD*)(MYPtr1+0x32) == 0x10CC || *(WORD*)(MYPtr1+0x32) == 0x125C || *(WORD*)(MYPtr1+0x32) == 0x157C || *(WORD*)(MYPtr1+0x32) == 0x170C || *(WORD*)(MYPtr1+0x32) == 0x189C || *(WORD*)(MYPtr1+0x32) == 0x1A2C || *(WORD*)(MYPtr1+0x32) == 0x1BBC|| *(WORD*)(MYPtr1+0x32) == 0x125C  || *(WORD*)(MYPtr1+0x32) == 0x13EC || *(WORD*)(MYPtr1+0x32) == 0x1D4C && InfHealth == TRUE)
	{
		*(WORD*)(MYPtr1 + 0xB6) = *(WORD*)(MYPtr1+0x32);

	}

	Loadregs();


	__asm{

		cmplw cr6,r11,r10
		beq cr6,br2

br2:
		mtlr r15
		lis r15,0x821C
		ori r15,r15,0xE5A4
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
	Prompt = XShowMessageBoxUI(0, L"More at T3furyGaming.co.uk", L"Dynasty Warriors Gundam + 5\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
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
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nInf/Max Special LT(x4)\r\nMax Pilot Points LB(x4)\r\nMaX Suit Points Y(x4)\r\nInf Timer X(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3furyGaming.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
	if( g_mb_result.rgwPasscode[0] == LEFT_BUMPER && g_mb_result.rgwPasscode[1] == LEFT_BUMPER && g_mb_result.rgwPasscode[2] == LEFT_BUMPER && g_mb_result.rgwPasscode[3] == LEFT_BUMPER )
	{
		Sleep(500);

		if( InfStamina == TRUE )
		{
			hNotify(L"Max Pilot XP Deactivated");
			SetDWORD(addr_Skill, 0x90CB016C);
			InfStamina = FALSE;
			Vibr01();

		}else{

			hNotify(L"Max Pilot XP Activated");
			SetDWORD(addr_Skill, 0x912B016C);
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
			SetDWORD(addr_Special, 0xB16300B8);
			InfSpecial = FALSE;
			Vibr01();

		}else{

			hNotify(L"Max/Inf Special Activated");
			SetDWORD(addr_Special, 0xB16300B8);
			InfSpecial = TRUE;
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

		if( InfSkill == TRUE )
		{
			hNotify(L"Max Suit XP Deactivated");
			SetDWORD(addr_Cash1, 0x93EB0000);
			InfSkill = FALSE;
			Vibr01();

		}else{

			hNotify(L"Max Suit XP Activated");
			SetDWORD(addr_Cash1, 0x912B0000);
			InfSkill = TRUE;
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

		if( InfTimer == TRUE )
		{
			hNotify(L"Inf Timer Deactivated");
			SetDWORD(addr_Timer, 0x916A0000);
			InfTimer = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Timer Activated");
			SetDWORD(addr_Timer, NOPThis);
			InfTimer = TRUE;
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
			SetDWORD(addr_Skill, 0x90CB016C);
			SetDWORD(addr_Cash1, 0x93EB0000);
			SetDWORD(addr_Special, 0xB16300B8);
			SetDWORD(addr_Timer, 0x916A0000);
			InfHealth = FALSE;
			ALLCheats = FALSE;
			Vibr01();

		}else{

			hNotify(L"All Cheats Activated");
 			SetDWORD(addr_Skill, 0x912B016C);
			SetDWORD(addr_Cash1, 0x912B0000);
			SetDWORD(addr_Special, 0xB10300B8);
			SetDWORD(addr_Timer, NOPThis);
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
	hNotify(L"Dynasty Warriors Gundam");

	Sleep(25);
   	addr = GetAddr(0x82000000, 0x83000000, buf, 2, 1)+ 0x04;
 	addr_Cash1 = GetAddr(0x82000000, 0x83000000, Skillbuf1, 2, 1)+0x04;
 	addr_Skill = GetAddr(0x82000000, 0x83000000, Skillbuf, 2, 1);
  	addr_Special = GetAddr(0x82000000, 0x83000000, Specbuf, 2, 1)+ 0x04;
 	addr_Timer = GetAddr(0x82000000, 0x83000000, Timerbuf, 2, 1)+ 0x04;
// 	addr_Gren = GetAddr(0x82000000, 0x83000000, goldbuf, 2, 1)- 0x04;
	SetAddr = true;
}