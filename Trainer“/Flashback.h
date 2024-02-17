#include "common.h"

UINT32 g_titleID = 0x584113fe;

DWORD buf[] = {0x809D0000, 0x7C652050};
// DWORD buf1[] = {0xED40602A, 0xD17F0E30};
// DWORD Specbuf[] = {0xEC206FBC, 0xD03F002C};
DWORD ammobuf[] = {0x817E0000, 0x7D6B5214};

VOID __declspec(naked) CheckHealth(VOID)
{ 


	__asm{
		subf r3,r5,r4 
		stw r3,0(r29)
			mflr r27
	}

	Saveregs();

	__asm 
	{
		mr MYPtr2,r29

	}

	//if(MYPtr1 == 0x1B || MYPtr1 == 0x0f || MYPtr1 == 0x23 || MYPtr1 == 0x11 || MYPtr1 == 0x0c || MYPtr1 == 0x10 || MYPtr1 == 0x0d || MYPtr1 == 0x00 || MYPtr1 == 0x0E || MYPtr1 == 0x13 || MYPtr1 == 0x12 || MYPtr1 == 0x32 || MYPtr1 == 0x01 || MYPtr1 == 0x29 || MYPtr1 == 0x85 || MYPtr1 == 0x14 || MYPtr1 == 0x07 || MYPtr1 == 0x03 || MYPtr1 == 0x04 || MYPtr1 == 0x06 || MYPtr1 == 0x08 || MYPtr1 == 0x02 || MYPtr1 == 0x05 || MYPtr1 == 0x16 || MYPtr1 == 0x41 || MYPtr1 == 0x3a || MYPtr1 == 0x72 || MYPtr1 == 0x38 || MYPtr1 == 0x3e || MYPtr1 == 0x31 || MYPtr1 == 0x30 || MYPtr1 == 0x35  || MYPtr1 == 0x33 || MYPtr1 == 0x2e || MYPtr1 == 0x88 || MYPtr1 == 0x94 || MYPtr1 == 0x53 || MYPtr1 == 0x3c || MYPtr1 == 0x2f && InfHealth == TRUE)
	if(*(DWORD*)(MYPtr2+0x04) > 0x00000100  && *(DWORD*)(MYPtr2+0x04) < 0x00ff0070 && InfHealth == TRUE)
	{
		*(DWORD*)(MYPtr2) = *(DWORD*)(MYPtr2+0x04);

	}

	Loadregs();



	__asm{

		stw r3,0(r28)
		addi r1,r1,144

		mtlr r27
		lis r27,0x8229
		ori r27,r27,0x3ED4 
		mtctr r27
		bctr
	}



}

VOID SetHooks()
{

	Caveme(addr ,CheckHealth,27);
	HooksSet = true;
}

VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"More at T3furyGaming.co.uk", L"Flashback + 2\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
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
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nInf XP/Item/Score/Skill LT(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3furyGaming.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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

	if( g_mb_result.rgwPasscode[0] == LEFT_TRIGGER && g_mb_result.rgwPasscode[1] == LEFT_TRIGGER && g_mb_result.rgwPasscode[2] == LEFT_TRIGGER && g_mb_result.rgwPasscode[3] == LEFT_TRIGGER )
	{
		Sleep(500);

		if( InfAmmo == TRUE )
		{
			hNotify(L"Inf XP, Skill Points & Items Deactivated");
			SetDWORD(addr_ammo,0x7D6B5214);
			InfAmmo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf XP, Skill Points & Items Activated");
			SetDWORD(addr_ammo,0x396A2710);
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
			SetDWORD(addr_ammo,0x7D6B5214);
			InfHealth = FALSE;
			ALLCheats = FALSE;
			Vibr01();

		}else{

			hNotify(L"All Cheats Activated");
			SetDWORD(addr_ammo,0x396A2710);
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
	hNotify(L"FlashBack");

	Sleep(25);
  	addr = GetAddr(0x82000000, 0x83000000, buf, 2, 1)+ 0x04;
  	addr_ammo = GetAddr(0x82000000, 0x83000000, ammobuf, 2, 1)+ 0x04;

	SetAddr = true;
}