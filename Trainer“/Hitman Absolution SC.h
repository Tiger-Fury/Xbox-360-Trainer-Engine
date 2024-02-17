#include "common.h"

UINT32 g_titleID = 0x53518813;


DWORD MYPtr1;
DWORD MYPtr2;
DWORD addr_ammo1 = 0x82291A7C;
DWORD HVaddr;
DWORD HVbuf[] = {0xED8CF028, 0xD19F07C4};
DWORD Grenbuf[] = {0x917D00E4, 0x817D00E4};
DWORD ammobuf[] = {0x917E0148, 0x817E00E4};



// VOID __declspec(naked) HMASCCheckScore(VOID)
// { 
// 
// 
// 	__asm{
// 			stw r31,88h(r3)
// 
//             mflr r15
// 	     }
// 
// 	Saveregs();
// 
// 	__asm 
// 	{
// 			mr MYPtr1,r3
// 			mr MYPtr2,r31
// 	}
// 
// 	if(InfHealth == TRUE)
// 	{
// 		//if(*(DWORD*)(MYPtr1+0x88) == 0xA48F9988)
// 			*(DWORD*)(MYPtr2+0x88) = 0x02faf080;
// 			
// 	}
// 	Loadregs();
// 
// 
// 
// 	__asm{
// 
// 		lis r10,-31789 
// 		mr r4,r31
// 		addi r31,r10,6560 
// 
// 			mtlr r15
// 
// 			lis r15,0x82CE  
// 			ori r15,r15,0x1724
// 			mtctr r15
// 			bctr
// 
// 	}
// 
// 
// 
// }
// 
// 
// VOID SetHooks()
// {
//     Caveme(0x82CE1714,HMASCCheckScore,15);
//     HooksSet = true;
// }

VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"More at T3furyGaming.co.uk", L"Double Clutch + 4\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_MAXBUTTONS, &g_mb_result, &g_xol);
// 	if( HooksSet == false )
// 	{
// 		SetHooks();
// 	}
}


VOID ButPress( MESSAGEBOX_RESULT g_mb_result )
{

	if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
	{
		Sleep(500);
		//this is the page that shows all available cheats  \r\n indicates create new line
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nOne Hit Kill RB(x4)\r\nInf Ammo LT(x4)\r\nInf Grenades LB(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3furyGaming.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;


	}
	if( g_strButtons[2] = L"inf health" )
	{
		Sleep(500);

		if( InfHealth == TRUE )
		{
			hNotify(L"Unlock All Deactivated");
			InfHealth = FALSE;
			Vibr01();

		}else{

			hNotify(L"Unlock All Activated");
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
			SetDWORD(addr_ammo,0x396BFFFF);
			InfAmmo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Ammo Activated");
			SetDWORD(addr_ammo, Addi_r11_nil);
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

		if( InfGrenade == TRUE )
		{
			hNotify(L"Inf Grenade Deactivated");
			SetDWORD(addr_Gren, 0x396BFFFF);
			InfGrenade = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Grenade Activated");
			SetDWORD(addr_Gren, Addi_r11_nil);
			InfGrenade = TRUE;
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
		SetDWORD(addr_Gren, 0x396BFFFF);
		SetDWORD(addr_ammo, 0x396BFFFF);
		InfHealth = FALSE;
		OneHitKo = FALSE;
		ALLCheats = FALSE;
		Vibr01();

	}else{

		hNotify(L"All Cheats Activated");
		SetDWORD(addr_Gren, Addi_r11_nil);
		SetDWORD(addr_ammo, Addi_r11_nil);
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
	hNotify(L"Double Clutch");
	HVaddr = GetAddr(0x82000000, 0x83000000, HVbuf, 2, 1)+0x04;
	addr_ammo = GetAddr(0x82000000, 0x83000000, ammobuf, 2, 1)-0x04;
	addr_Gren = GetAddr(0x82000000, 0x83000000, Grenbuf, 2, 1)-0x04;
	Sleep(25);
	SetAddr = true;
}