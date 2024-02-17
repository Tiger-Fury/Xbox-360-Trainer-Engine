#include "common.h"

UINT32 g_titleID = 0x454109E0;

DWORD buf[] = {0xeda007f2, 0xc19c0014};
DWORD bufAmmo[] = {0x7D0A5850, 0x917F0070};
DWORD bufstam[] = {0xC003002C, 0xEDA1002A};
DWORD bufspec[] = {0xEDA1073A, 0xD1BF0020};
VOID __declspec(naked) CheckHealth(VOID)
{ 


	__asm{
		lfs fr12,14h(r28)

			mflr r7
	}

	Saveregs();

	__asm 
	{
		mr MYPtr1,r28
	}

	if(InfHealth == TRUE)
	{
		*(DWORD*)(MYPtr1+0x10) = *(DWORD*)(MYPtr1+0x14);

	}
	Loadregs();



	__asm{

		fmuls fr1,fr12,fr13
		addi r1,r1,128
		lfd fr31,-30h(r1)

		mtlr r7
			lis r7,0x8947
			ori r7,r7,0x0858
			mtctr r7
			bctr
	}



}


VOID SetHooks()
{
	Caveme(addr ,CheckHealth,7);
	HooksSet = true;
}

VOID BFHSearch()
{
	if (Gamexex == 1)
	{
		addr = GetAddr(0x89000000, 0x8A000000, buf, 2, 1)+ 0x04;
		addr_ammo = GetAddr(0x88000000, 0x89000000, bufAmmo, 2, 1)+ 0x04;
		addr_XP = GetAddr(0x88000000, 0x89000000, bufstam, 2, 1)+ 0x04;
		addr_Special = GetAddr(0x89000000, 0x8A000000, bufspec, 2, 1)+ 0x04;

		if( HooksSet == false )
		{
			SetHooks();
		}
	}
}

VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"More at T3furyGaming.co.uk", L"BattleField Hardline + 4\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
	
		Gamexex = 1;
		BFHSearch();
	
}


VOID ButPress( MESSAGEBOX_RESULT g_mb_result )
{

	if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
	{
		Sleep(500);
		//this is the page that shows all available cheats  \r\n indicates create new line
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nInf Ammo LT(x4)\r\nUnlock All RB(x4)\r\nInvisibility LB(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3furyGaming.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
			SetDWORD(addr_ammo,0x917F0070);
			SetDWORD(addr_ammo + 0x10,0x909F0070);
			InfAmmo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Ammo Activated");
			SetDWORD(addr_ammo,NOPThis);
			SetDWORD(addr_ammo + 0x10,NOPThis);
			InfAmmo = TRUE;
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

		if( InfScore == TRUE )
		{
			hNotify(L"Max XP Deactivated");
			SetDWORD(addr_XP,0xEDA1002A);
			InfScore = FALSE;
			Vibr01();

		}else{

			hNotify(L"Max XP Activated");
			SetDWORD(addr_XP,0xEDA5002A);
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

		if( InfSpecial == TRUE )
		{
			hNotify(L"Invisibility Deactivated");
			SetDWORD(addr_Special,0xD1BF0020);
			InfSpecial = FALSE;
			Vibr01();

		}else{

			hNotify(L"Invisibility Activated");
			SetDWORD(addr_Special,NOPThis);
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
		SetDWORD(addr_XP,0xEDA1002A);
		SetDWORD(addr_ammo,0x917F0070);
		SetDWORD(addr_ammo + 0x10,0x909F0070);
		SetDWORD(addr_Special,0xD1BF0020);
		InfHealth = FALSE;
		ALLCheats = FALSE;
		Vibr01();

	}else{

		hNotify(L"All Cheats Activated");
		SetDWORD(addr_XP,0xEDA5002A);
		SetDWORD(addr_ammo,NOPThis);
		SetDWORD(addr_ammo + 0x10,NOPThis);
		SetDWORD(addr_Special,NOPThis);
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

	hNotify(L"BattleField: Hardline");
	Sleep(25);

	SetAddr = true;
	
}//