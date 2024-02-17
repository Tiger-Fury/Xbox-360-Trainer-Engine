#include "common.h"

UINT32 g_titleID = 0x464f0803;


DWORD buf[] = {0x39600001, 0xc00a0044};
DWORD buf1[] = {0x916A0004, 0x897F009E};
DWORD bufAmmo[] = {0x7D2B4B78, 0x916A0004};
DWORD bufstam[] = {0x9421FF90, 0xC003000C};
DWORD bufstam1[] = {0x81610054, 0x917C68B0};
DWORD bufxp[] = {0x815E001C, 0x7D4B5214};
DWORD buffocus[] = {0x7C7F1B78, 0xEC0D002A};
DWORD bufScore[] = {0x7D2A582E, 0x7D3D4A14};
VOID __declspec(naked) CheckHealth(VOID)
{ 


	__asm{
		//lfs fr0,44h(r10)
		fsubs fr13,fr0,fr31
		stfs fr13,40h(r31)

			mflr r15
	}

	Saveregs();

	__asm 
	{
		mr MYPtr1,r31
			mr MYPtr2,r5
	}

	if(MYPtr2 == 0x01 && InfHealth == TRUE)
	{
		*(DWORD*)(MYPtr1+0x40) = *(DWORD*)(MYPtr1+0x44);

	}
	if(MYPtr2 == 0x00 && OneHitKo == TRUE)
	{
		*(DWORD*)(MYPtr1+0x40) = 0;

	}
	Loadregs();



	__asm{

		addi r8,r9,-18640
		fmr fr30,fr1

			mtlr r15
				lis r15,0x822C
				ori r15,r15,0xA20C
				mtctr r15
				bctr
		
	}

}

VOID SetHooks()
{
	Caveme(/*addr*/ 0x822CA1FC,CheckHealth,15);
	HooksSet = true;
}

VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"More at T3furyGaming.co.uk", L"Sniper Elite 3 + 7\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
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
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nOne Hit Kill RB(x4)\r\nInf Ammo & Items LT(x4)\r\nNO BPM Limit & No Increase LB(x4)\r\nMax XP Y(x4)\r\nInf Focus X(x4)\r\nFast Score YXYX\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury & Losparo \r\nXPGamesaves.com\r\nHome To 360 Revolution", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;


	}
	if(  g_mb_result.rgwPasscode[0] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[1] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[2] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[3] == RIGHT_TRIGGER )
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
	if( g_mb_result.rgwPasscode[0] == LEFT_TRIGGER && g_mb_result.rgwPasscode[1] == LEFT_TRIGGER && g_mb_result.rgwPasscode[2] == LEFT_TRIGGER && g_mb_result.rgwPasscode[3] == LEFT_TRIGGER )
	{
		Sleep(500);

		if( InfAmmo == TRUE )
		{
			hNotify(L"Inf Ammo, Grenades & Items Deactivated");
			SetDWORD(addr_ammo,0x916A0004);
			InfAmmo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Ammo, Grenades & Items Activated");
			SetDWORD(addr_ammo,NOPThis);
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

		if( InfStamina == TRUE )
		{
			hNotify(L"0 BPM Deactivated");
			SetDWORD(addr_Stamina1,0x917C68B0);
			InfStamina = FALSE;
			Vibr01();

		}else{

			hNotify(L"0 BPM Activated");
			SetDWORD(addr_Stamina1,NOPThis);
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

		if( Max_XP == TRUE )
		{
			hNotify(L"Max XP Deactivated");
			SetDWORD(addr_XP,0x7D4B5214);
			Max_XP = FALSE;
			Vibr01();

		}else{

			hNotify(L"Max XP Activated");
			SetDWORD(addr_XP,0x394B7530);
			Max_XP = TRUE;
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

		if( InfFocus == TRUE )
		{
			hNotify(L"Inf Focus Deactivated");
			SetDWORD(addr_Focus,0xEC0D002A);
			InfFocus = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Focus Activated");
			SetDWORD(addr_Focus,0xFC0D0028);
			InfFocus = TRUE;
			Vibr01();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
	if( g_mb_result.rgwPasscode[0] == Y_BUTTON && g_mb_result.rgwPasscode[1] == X_BUTTON && g_mb_result.rgwPasscode[2] == Y_BUTTON && g_mb_result.rgwPasscode[3] == X_BUTTON )
	{
		Sleep(500);

		if( InfScore == TRUE )
		{
			hNotify(L"Fast Score Deactivated");
			SetDWORD(addr_Score,0x7D3D4A14);
			InfScore = FALSE;
			Vibr01();

		}else{

			hNotify(L"Fast Score Activated");
			SetDWORD(addr_Score,0x39297530);
			InfScore = TRUE;
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
		SetDWORD(addr_ammo,0x916A0004);
		SetDWORD(addr_Stamina1,0x917C68B0);
		SetDWORD(addr_XP,0x7D4B5214);
		SetDWORD(addr_Focus,0xEC0D002A);
		SetDWORD(addr_Score,0x7D3D4A14);
		InfHealth = FALSE;
		ALLCheats = FALSE;
		Vibr01();

	}else{

		hNotify(L"All Cheats Activated");
		OneHitKo = TRUE;
		SetDWORD(addr_ammo,NOPThis);
		SetDWORD(addr_Stamina1,NOPThis);
		SetDWORD(addr_XP,0x394B7530);
		SetDWORD(addr_Focus,0xFC0D0028);
		SetDWORD(addr_Score,0x39297530);
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
	hNotify(L"Sniper Elite 3");
	Sleep(25);
 	addr = GetAddr(0x826B5000, 0x83000000, buf, 2, 1)+ 0x04;
	addr_ammo = GetAddr(0x826B0000, 0x83000000, buf1, 2, 1);
	addr_Stamina = GetAddr(0x82600000, 0x83000000, bufstam, 2, 1)+ 0x04;
	addr_Stamina1 = GetAddr(0x82600000, 0x83000000, bufstam1, 2, 1)+ 0x04;
	addr_XP = GetAddr(0x82600000, 0x83000000, bufxp, 2, 1)+ 0x04;
	addr_Focus = GetAddr(0x82600000, 0x83000000, buffocus, 2, 1)+ 0x04;
	addr_Score = GetAddr(0x82600000, 0x83000000, bufScore, 2, 1)+ 0x04;
	SetAddr = true;
}//