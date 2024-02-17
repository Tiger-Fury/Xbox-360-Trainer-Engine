#include "common.h"

UINT32 g_titleID = 0x454107E9;

DWORD buf[] = {0x458CA000, 0x458CA000};
DWORD bufAmmo[] = {0x807F01D4, 0x396BFFFF};
DWORD bufcash[] = {0x3D6082C6, 0x7C8AF214};
float XRValue = 4500.0;

VOID __declspec(naked) CheckHealth(VOID)
{ 


	__asm{
		lwz r3,20h(r31)
			stfs fr31,10h(r31)
			mflr r2
	}

	Saveregs();

	__asm 
	{
		mr MYPtr1,r31
	}

	if(*(DWORD*)(MYPtr1 + 0x14) == 0x458CA000 && InfHealth == TRUE)
	{
		__asm
		{
		stfs XRValue,10h(r31)
	//	*(DWORD*)(MYPtr1+0x10) = 0x458CA000;
		}
	}
	Loadregs();



	__asm{

// 		mtlr r2
// 			lis r2,0x8272
// 			ori r2,r2,0x6F4C
// 			mtctr r2
// 			bctr
//br2:
			mtlr r2
			lis r2,0x8272
			ori r2,r2,0x6F58
			mtctr r2
			bctr


	}

}

VOID SetHooks()
{
	Caveme(0x82726F50 ,CheckHealth,2);
	HooksSet = true;
}


VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"More at T3furyGaming.co.uk", L"The Godfather + 3\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
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
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nInf Ammo LT(x4)\r\nInf Cash LT(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3furyGaming.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
			
		//	SetDWORD(addr,0xD3FF10F8);
			InfHealth = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Health Activated");;
		//	SetDWORD(addr,NOPThis);
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
			SetDWORD(addr_ammo,0x396BFFFF);
			InfAmmo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Ammo Activated");
			SetDWORD(addr_ammo,0x396B0000);
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

		if( InfCash == TRUE )
		{
			hNotify(L"Inf Cash Deactivated");
			SetDWORD(addr_Cash,0x7C8AF214);
			InfCash = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Cash Activated");
			SetDWORD(addr_Cash,0x388A7530);
			InfCash = TRUE;
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
		SetDWORD(addr_Cash,0x7C8AF214);
		SetDWORD(addr_ammo,0x396BFFFF);
		SetDWORD(addr,0xD3FF10F8);
		ALLCheats = FALSE;
		Vibr01();

	}else{

		hNotify(L"All Cheats Activated");
		SetDWORD(addr_Cash,0x388A7530);
		SetDWORD(addr_ammo,0x396B0000);
		SetDWORD(addr,NOPThis);
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
	hNotify(L"The Godfather 2");
	Sleep(25);
 //	addr = GetAddr(0x82000000, 0x83000000, buf, 2, 1)- 0x04;
	addr_ammo = GetAddr(0x82000000, 0x83000000, bufAmmo, 2, 1)+ 0x04;
	addr_Cash = GetAddr(0x82000000, 0x83000000, bufcash, 2, 1)+ 0x04;
	SetAddr = true;
}//