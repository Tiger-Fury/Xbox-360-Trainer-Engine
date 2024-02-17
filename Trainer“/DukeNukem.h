#include "common.h"

UINT32 g_titleID = 0x5454084E;

DWORD buf[] = {0x7d4b5378, 0xc1aa0a34};
DWORD buf1[] = {0x7D6B1A14, 0xC00B0044};
DWORD bufAmmo[] = {0x419A01CC, 0xC00B0988};
DWORD bufstam[] = {0x9421FF90, 0xC003000C};
VOID __declspec(naked) CheckHealth(VOID)
{ 


	__asm{
		lfs fr13,0A34h(r10)

			mflr r17
	}

	Saveregs();

	__asm 
	{
		mr MYPtr1,r10
	}

	if(InfHealth == TRUE)
	{
		*(DWORD*)(MYPtr1+0xA34) = 0x43700000;

	}
	Loadregs();



	__asm{

		lfs fr12,0A38h(r10)
		fdivs fr11,fr13,fr12
		lfs fr10,0A38h(r10)

		mtlr r17
			lis r17,0x8295
			ori r17,r17,0x24a8
			mtctr r17
			bctr
	}



}

VOID __declspec(naked) CheckAmmo(VOID)
{ 


	__asm{
		lfs fr0,988h(r11)

			mflr r19
	}

	Saveregs();

	__asm 
	{
		mr MYPtr1,r11
	}

	if(InfAmmo == TRUE)
	{
		*(DWORD*)(MYPtr1+0x988) = 0x43700000;

	}
	Loadregs();



	__asm{

		mr r4,r22
		fctiwz fr13,fr0
		stfd fr13,0C8h(r1)

			mtlr r19
			lis r19,0x8295
			ori r19,r19,0x1314
			mtctr r19
			bctr
	}



}

VOID SetHooks()
{
	Caveme(addr ,CheckHealth,17);
	Caveme(addr_ammo ,CheckAmmo,19);
	HooksSet = true;
}

VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"More at T3furyGaming.co.uk", L"Duke Nukem Forever + 2\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
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
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nInf Ammo LT(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3furyGaming.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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

	if( g_mb_result.rgwPasscode[0] == LEFT_TRIGGER && g_mb_result.rgwPasscode[1] == LEFT_TRIGGER && g_mb_result.rgwPasscode[2] == LEFT_TRIGGER && g_mb_result.rgwPasscode[3] == LEFT_TRIGGER )
	{
		Sleep(500);

		if( InfAmmo == TRUE )
		{
			hNotify(L"Inf Ammo Deactivated");
//			SetDWORD(addr_ammo,0xD19F0000);
			InfAmmo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Ammo Activated");
//			SetDWORD(addr_ammo,NOPThis);
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

	if(ALLCheats == TRUE )
	{
		hNotify(L"All Cheats Deactivated");
		InfAmmo = FALSE;
		InfHealth = FALSE;
		ALLCheats = FALSE;
		Vibr01();

	}else{

		hNotify(L"All Cheats Activated");
		InfAmmo = TRUE;
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
	hNotify(L"Duke Nukem Forever");
	Sleep(25);
	addr = GetAddr(0x82000000, 0x83000000, buf, 2, 1)+ 0x04;
	addr_ammo = GetAddr(0x82000000, 0x83000000, bufAmmo, 2, 1)+ 0x04;
	SetAddr = true;
}//