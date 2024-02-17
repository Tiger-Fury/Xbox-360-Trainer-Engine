#include "common.h"

UINT32 g_titleID = 0x4E4D07E4;


DWORD RoFaddr;
DWORD Itembuf1[] = {0x7D6628AE, 0x7D6B5214};
DWORD Itembuf2[] = {0x40990018, 0x7D6A4850};
DWORD Goldbuf[] = {0x7D6628AE, 0x7D6B5214};
DWORD HVbuf[] = {0x2C0B0000, 0x80e80008};
DWORD Timerbuf[] = {0x7D6607B4, 0x7D695A14};
float ZValue = 0.0;


VOID __declspec(naked) CheckHealth(VOID)
{ 


	__asm{
			lwz r10,-38h(r22)

            mflr r24
	     }

	Saveregs();

	__asm 
	{
			mr MYPtr1,r22
	}

	if(InfHealth == TRUE)
	{
		
			*(DWORD*)(MYPtr1-0x38) = 0x000F423F;
			*(DWORD*)(MYPtr1-0x34) = 0x000F423F;
			
	}
	Loadregs();



	__asm{

		clrlwi r26,r25,24
		divw r9,r25,r9
		li r30,0
		
			mtlr r24
			lis r24,0x8214 
			ori r24,r24,0xa8c4
			mtctr r24
			bctr

	}



}

VOID __declspec(naked) CheckGold(VOID)
{ 


	__asm{
		lwz r7,8(r8)

			mflr r25
	}

	Saveregs();

	__asm 
	{
		mr MYPtr2,r8
	}

	if(InfGold == TRUE)
	{

		*(DWORD*)(MYPtr2+0x08) = 0x3B9AC9FF;

	}
	Loadregs();



	__asm{

		ble br5
		mr r9,r11
		addis r11,r31,7

			mtlr r25
			lis r25,0x8214  
			ori r25,r25,0xb350 
			mtctr r25
			bctr

br5:
			mtlr r25
			lis r25,0x8214
			ori r25,r25,0xb374
			mtctr r25
			bctr

	}



}

VOID SetHooks()
{
    Caveme(0x8214a8b4,CheckHealth,24);
	Caveme(0x8214b340,CheckGold,25);
    HooksSet = true;
}

VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"More at T3furyGaming.co.uk", L"Eternal Sonata + 4\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
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
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nNo Timer RB(x4)\r\nInf Items LT(x4)\r\nInf Gold LB(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3furyGaming.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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

		if( InfItems == TRUE )
		{
			hNotify(L"Inf Items Deactivated");
			SetDWORD(addr_Items,0x7D6B5214);
			SetDWORD(addr_Items1,0x7D6A4850);
			InfItems = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Items Activated");
			SetDWORD(addr_Items,Li_r11_99);
			SetDWORD(addr_Items1,Li_r11_99);
			InfItems = TRUE;
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

		if( InfGold == TRUE )
		{
			hNotify(L"Inf Gold Deactivated");
			InfGold = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Gold Activated");
			InfGold = TRUE;
			Vibr01();
			//
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

		if( InfTimer == TRUE )
		{
			hNotify(L"No Timer Deactivated");
			SetDWORD(addr_Timer, 0x7D695A14);
			InfTimer = FALSE;
			Vibr01();

		}else{

			hNotify(L"No Timer Activated");
			SetDWORD(addr_Timer, Li_r11_Nil);
			InfTimer = TRUE;
			Vibr01();
			//
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

		if( ALLCheats == TRUE )
		{
			hNotify(L"All Cheats Deactivated");
			SetDWORD(addr_Items,0x7D6B5214);
			SetDWORD(addr_Items1,0x7D6A4850);
			InfGold = FALSE;
			InfHealth = FALSE;
			SetDWORD(addr_Timer, 0x7D695A14);
			ALLCheats = FALSE;
			Vibr01();

		}else{

			hNotify(L"All Cheats Activated");
			SetDWORD(addr_Items,Li_r11_99);
			SetDWORD(addr_Items1,Li_r11_99);
			InfGold = TRUE;
			InfHealth = TRUE;
			SetDWORD(addr_Timer, Li_r11_Nil);
			ALLCheats = TRUE;
			Vibr01();
			//
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
	hNotify(L"Eternal Sonata");
	Sleep(25);
	addr_Items = GetAddr(0x82000000, 0x83000000, Itembuf1, 2, 1)+ 0x04;
	addr_Items1 = GetAddr(0x82000000, 0x83000000, Itembuf2, 2, 1)+ 0x04;
	addr_Cash = GetAddr(0x82000000, 0x83000000, Goldbuf, 2, 1)+ 0x04;
	addr_Timer = GetAddr(0x82000000, 0x83000000, Timerbuf, 2, 1)+ 0x04;
	SetAddr = true;
}