#include "common.h"

UINT32 g_titleID = 0x434307DF;

DWORD buf[] = {0xEC0C6828, 0xD01F0018};
DWORD buf1[] = {0x817F25C8, 0xC01F1484};
DWORD goldbuf[] = {0x9163000C, 0x38210070};
DWORD devilbuf[] = {0xC01F1E54, 0xEC1E002A};
DWORD moneybuf[] = {0x7F0B5000, 0x917F0114};
DWORD Skillbuf[] = {0x48000038, 0x817F0180};
DWORD Skillbuf1[] = {0x817F00EC, 0x7D6BEA15};
DWORD Timerbuf[] = {0xEC006828, 0xD0030244};

VOID __declspec(naked) CheckHealth(VOID)
{ 


	__asm{
	
		stfs fr13,2Ch(r31)
		fsubs fr0,fr12,fr13
		stfs fr0,18h(r31) 
		mflr r15
	}

	Saveregs();

	__asm 
	{
		mr MYPtr1,r31
		mr MYPtr2,r8

	}

	if(MYPtr2 == 0x00 && InfHealth == TRUE)
	{
		*(DWORD*)(MYPtr1 + 0x18) = *(DWORD*)(MYPtr1 + 0x1C);

	}
	else if(MYPtr2 != 0x00 && OneHitKo == TRUE)
	{
		*(DWORD*)(MYPtr1 + 0x18) = 0x00000000;

	}
	else if(MYPtr2 != 0x00 && DontDie == TRUE)
	{
		*(DWORD*)(MYPtr1 + 0x18) = 0x44FA0000;

	}

	Loadregs();


	__asm{

		fcmpu cr6,fr0,fr31
		
		mtlr r15
		lis r15,0x8279
		ori r15,r15,0x4B0C 
		mtctr r15
		bctr
 	}
}


VOID __declspec(naked) CheckSkill(VOID)
{ 


	__asm{
		lwz r11,180h(r31)
			add. r11,r11,r29 
			stw r11,180h(r31)
			mflr r15
	}

	Saveregs();

	__asm 
	{
		mr MYPtr1,r31
			mr MYPtr2,r8

	}

	if(MYPtr2 == 0x9030 && InfSkill == TRUE)
	{
		*(DWORD*)(MYPtr1 + 0x180) = 0x0098967F;

	}
	Loadregs();


	__asm{

		bge br2
br2:
		mtlr r15
			lis r15,0x827F
			ori r15,r15,0x4350
			mtctr r15
			bctr
	}
}

VOID SetHooks()
{

	Caveme(addr ,CheckHealth,15);
	Caveme(addr_Skill ,CheckSkill,15);
	HooksSet = true;
}

VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"More at T3furyGaming.co.uk", L"Devil May Cry 4 + 7\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
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
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nOne Hit Kill RB(x4)\r\nNo Kill RB(x3)+LB\r\nInf Red Orbs LT(x4)\r\nInf Devil Trigger LB(x4)\r\nInf Skill Points Y(x4)\r\nInf Timer X(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3furyGaming.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
	if(  g_mb_result.rgwPasscode[0] == RIGHT_BUMPER && g_mb_result.rgwPasscode[1] == RIGHT_BUMPER && g_mb_result.rgwPasscode[2] == RIGHT_BUMPER && g_mb_result.rgwPasscode[3] == RIGHT_BUMPER )
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
	if(  g_mb_result.rgwPasscode[0] == RIGHT_BUMPER && g_mb_result.rgwPasscode[1] == RIGHT_BUMPER && g_mb_result.rgwPasscode[2] == RIGHT_BUMPER && g_mb_result.rgwPasscode[3] == LEFT_BUMPER )
	{
		Sleep(500);

		if( DontDie == TRUE )
		{
			hNotify(L"No Kill Deactivated");
			DontDie = FALSE;
			Vibr01();

		}else{

			hNotify(L"No Kill Activated");
			DontDie = TRUE;
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

		if( InfScore == TRUE )
		{
			hNotify(L"Inf Red Orbs Deactivated");
			SetDWORD(addr_Cash, 0x917F0114);
			InfScore = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Red Orbs Activated");
			SetDWORD(addr_Cash, 0x915F0114);
			InfScore = TRUE;
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
			hNotify(L"Inf Devil Trigger Deactivated");
			SetDWORD(addr_Special, 0xEC1E002A);
			InfStamina = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Devil Trigger Activated");
			SetDWORD(addr_Special, 0xEC00002A);
			InfStamina = TRUE;
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
			hNotify(L"Inf Skill Points Deactivated");
			SetDWORD(addr_Cash1, 0x917F00EC);
			InfSkill = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Skill Points Activated");
			SetDWORD(addr_Cash1, 0x911F00EC);
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
			SetDWORD(addr_Timer, 0xD0030244);
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
 			SetDWORD(addr_Special, 0xEC1E002A);
 			SetDWORD(addr_Cash, 0x917F0114);
			SetDWORD(addr_Cash1, 0x917F00EC);
			SetDWORD(addr_Timer, 0xD0030244);
			InfSkill = FALSE;
			InfHealth = FALSE;
			OneHitKo = FALSE;
			ALLCheats = FALSE;
			Vibr01();

		}else{

			hNotify(L"All Cheats Activated");
 			SetDWORD(addr_Special, 0xEC00002A);
			SetDWORD(addr_Cash, 0x915F0114);
			SetDWORD(addr_Cash1, 0x911F00EC);
			SetDWORD(addr_Timer, 0xD0030244);
			InfSkill = TRUE;
			InfHealth = TRUE;
			OneHitKo = TRUE;
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
	hNotify(L"Devil May Cry 4");

	Sleep(25);
   	addr = GetAddr(0x82000000, 0x83000000, buf, 2, 1)- 0x04;
	addr1 = GetAddr(0x82000000, 0x83000000, buf1, 2, 1)+ 0x04;
    addr_Cash = GetAddr(0x82000000, 0x83000000, moneybuf, 2, 1)+0x04;
	addr_Cash1 = GetAddr(0x82000000, 0x83000000, Skillbuf1, 2, 1)+0x08;
	addr_Skill = GetAddr(0x82000000, 0x83000000, Skillbuf, 2, 1)+0x04;
 	addr_Special = GetAddr(0x82000000, 0x83000000, devilbuf, 2, 1)+ 0x04;
	addr_Timer = GetAddr(0x82000000, 0x83000000, Timerbuf, 2, 1)+ 0x04;
// 	addr_Gren = GetAddr(0x82000000, 0x83000000, goldbuf, 2, 1)- 0x04;
	SetAddr = true;
}