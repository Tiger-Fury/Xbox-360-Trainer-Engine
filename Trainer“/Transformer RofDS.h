#include "common.h"

UINT32 g_titleID = 0x41560904;

DWORD MYPtr1;
DWORD MYPtr2;

DWORD buf[] = {0x812B003C, 0xC00A0344};
DWORD buf1[] = {0x419A0178, 0xC00B0344};
DWORD bufAmmo[] = {0x4800001C, 0x817E02AC};

VOID __declspec(naked) CheckHealth(VOID)
{ 


	__asm{
		lfs fr0,344h(r10)

			mflr r15
	}

	Saveregs();

	__asm 
	{
		mr MYPtr1,r10
	}

	if(InfHealth == TRUE)
	{
		*(DWORD*)(MYPtr1+0x344) = 0x43480000;

	}
	Loadregs();



	__asm{

		lfs fr13,348h(r10)
		fsubs fr12,fr0,fr13
		lfs fr11,54h(r9)

			mtlr r15
			lis r15,0x82d8
			ori r15,r15,0x5b6c
			mtctr r15
			bctr


	}



}

VOID __declspec(naked) CheckOneHit(VOID)
{ 


	__asm{
		lfs fr0,344h(r11)

			mflr r15
	}

	Saveregs();

	__asm 
	{
		mr MYPtr1,r11
	}

	if(*(DWORD*)(MYPtr1+0x348) == 0x43160000 && OneHitKo == TRUE)
	{
		*(DWORD*)(MYPtr1+0x344) = 0x3f800000;

	}
	Loadregs();



	__asm{

		lfs fr13,348h(r11)
		fcmpu cr6,fr0,fr13
		bge cr6,br2

			mtlr r15
			lis r15,0x82ca
			ori r15,r15,0x6b80
			mtctr r15
			bctr

br2:
		mtlr r15
			lis r15,0x82ca
			ori r15,r15,0x6ce4
			mtctr r15
			bctr

	}



}

VOID __declspec(naked) CheckAmmo(VOID)
{ 


	__asm{
		lwz r11,2ACh(r30)

			mflr r15
	}

	Saveregs();

	__asm 
	{
		mr MYPtr1,r30
	}

	if(InfAmmo == TRUE)
	{
		*(DWORD*)(MYPtr1+0x2A8) = 0x00000024;

	}
	Loadregs();



	__asm{

		extsw r10,r11
		std r10,50h(r1)
		lfd fr0,50h(r1)

			mtlr r15
			lis r15,0x82cc
			ori r15,r15,0x4410
			mtctr r15
			bctr


	}



}


VOID SetHooks()
{
	Caveme(addr1 ,CheckOneHit,15);
	Caveme(addr ,CheckHealth,15);
	Caveme(addr_ammo ,CheckAmmo,15);
	HooksSet = true;
}

VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"More at T3furyGaming.co.uk", L"Rise Of The Dark Spark + 3\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
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
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nOne Hit Kill RB(x4)\r\nInf Ammo LT(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3furyGaming.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
			hNotify(L"Inf Ammo Deactivated");
			InfAmmo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Ammo Activated");
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
		OneHitKo = FALSE;
		InfAmmo = FALSE;
		InfHealth = FALSE;
		ALLCheats = FALSE;
		Vibr01();

	}else{

		hNotify(L"All Cheats Activated");
		OneHitKo = TRUE;
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
	hNotify(L"Transformers: Rise Of The Dark Spark");
	Sleep(25);
 	addr = GetAddr(0x82000000, 0x83000000, buf, 2, 1)+ 0x04;
	addr1 = GetAddr(0x82000000, 0x83000000, buf1, 2, 1)+ 0x04;
 	addr_ammo = GetAddr(0x82A00000, 0x83000000, bufAmmo, 2, 1)+ 0x04;
	SetAddr = true;
}//