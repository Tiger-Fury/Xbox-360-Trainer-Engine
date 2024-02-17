#include "common.h"

UINT32 g_titleID = 0x4343081E;
////////////////Dmc//////////////////////
DWORD buf[] = {0xB14310A6, 0x2F0A0000};
DWORD devilbuf[] = {0xB15F1446, 0x419A001C};
DWORD moneybuf[] = {0x7D6B5214, 0x917C2284};
////////////////Dmc2/////////////////////
DWORD buf1[] = {0x7D280734, 0xB15F0102};
DWORD moneybuf1[] = {0x7D082214, 0x910A0078};
DWORD devilbuf1[] = {0x7CE60734, 0xB0DF042E};
////////////////DmC3/////////////////////
DWORD buf2[] = {0xED2AF828, 0xD12B0008};
DWORD moneybuf2[] = {0x7D085214, 0x912B001C};
DWORD devilbuf2[] = {0xEDA00828, 0xD1A32CF8};

VOID __declspec(naked) CheckHealthDmC2(VOID)
{ 


	__asm{
	
		sth r10,102h(r31) 
		sth r8,100h(r31)
		mflr r15
	}

	Saveregs();

	__asm 
	{
		mr MYPtr1,r31
		mr MYPtr2,r27

	}

	if(MYPtr2 == 0x00 && InfHealth == TRUE)
	{
		 *(WORD*)(MYPtr1 + 0x100)= *(WORD*)(MYPtr1 + 0x104);

	}
	else if(MYPtr1 < 0x82000000 && OneHitKo == TRUE)
	{
		if(OneHitKo == TRUE)
		*(WORD*)(MYPtr1 + 0x100) = 0;
		
	}


	Loadregs();


	__asm{

		cmpwi cr6,r8,0 
		bgt cr6,br2 

br2:
		mtlr r15
		lis r15,0x820C
		ori r15,r15,0x5A78 
		mtctr r15
		bctr
 	}
}


VOID __declspec(naked) CheckHealthDmC3(VOID)
{ 


	__asm{
		fsubs fr9,fr10,fr31
		stfs fr9,8(r11)
		mflr r15
	}

	Saveregs();

	__asm 
	{
		mr MYPtr1,r11
		mr MYPtr2,r29
	}

	if(MYPtr2 < 0x82000000 && InfHealth == TRUE)
	{
		*(DWORD*)(MYPtr1 + 0x08) = 0x461C4000;

	}
	else if(MYPtr2 > 0x82000000 && OneHitKo == TRUE)
	{
		*(DWORD*)(MYPtr1 + 0x08) = 0;

	}
	Loadregs();


	__asm{

		lbz r11,10h(r9)
		cmplwi cr6,r11,0 

		mtlr r15
			lis r15,0x8216
			ori r15,r15,0x9548
			mtctr r15
			bctr
	}
}

VOID SetHooks()
{
	if (Gamexex == 2)
	{
		Caveme(addr ,CheckHealthDmC2,15);
		HooksSet = true;
	}
	else if (Gamexex == 3)
	{
		Caveme(addr ,CheckHealthDmC3,15);
		HooksSet = true;
	}

}

VOID ShowTrainerMain()
{
	if (Gamexex == 0)
	{
		Prompt = XShowMessageBoxUI(0, L"Please Enjoy DmC HD", L"Thanks for downloading Dmc HD collection Trainer\r\nPlease Visit T3furyGaming.co.uk Today for all the latest and greatest trainers\r\nEnjoy t3 ;)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3furyGaming.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);
	}
	if (Gamexex == 1)
	{
		Prompt = XShowMessageBoxUI(0, L"More at T3furyGaming.co.uk", L"Devil May Cry + 4\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
	}
	if (Gamexex == 2)
	{
		Prompt = XShowMessageBoxUI(0, L"More at T3furyGaming.co.uk", L"Devil May Cry 2 + 4\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
	}
	if (Gamexex == 3)
	{
		Prompt = XShowMessageBoxUI(0, L"More at T3furyGaming.co.uk", L"Devil May Cry 3 + 4\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
	}
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
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nOne Hit Kill RB(x4)\r\nInf Red Orbs LT(x4)\r\nInf Devil Trigger LB(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3furyGaming.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
			Vibr01();
			if(Gamexex == 1)
			{
			SetDWORD(addr,0xB14310A6);
			InfHealth = FALSE;
			}
			else if(Gamexex >= 2)
			{
				InfHealth = FALSE;
			}
		}else{
			
			hNotify(L"Inf Health Activated");
			Vibr01();
			if(Gamexex == 1)
			{
			SetDWORD(addr,NOPThis);
			InfHealth = TRUE;
			}
			else if(Gamexex >= 2)
			{
				InfHealth = TRUE;
			}
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
			Vibr01();
			if(Gamexex == 1)
			{
			SetDWORD(addr+0x30,0x4098000C);
			OneHitKo = FALSE;
			}
			else if(Gamexex >= 2)
			{
				OneHitKo = FALSE;
			}

		}else{
		
			hNotify(L"One Hit Kill Activated");
			Vibr01();
			if(Gamexex == 1)
			{
			SetDWORD(addr+0x30,NOPThis);
			OneHitKo = TRUE;
			}
			else if(Gamexex >= 2)
			{
				OneHitKo = TRUE;
			}
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
			Vibr01();
			if(Gamexex == 1)
			{
				SetDWORD(addr_Cash, 0x917C2284);
				InfScore = FALSE;
			}
			if(Gamexex == 2)
			{
				SetDWORD(addr_Cash, 0x910A0078);
				InfScore = FALSE;
			}
			if(Gamexex == 3)
			{
				SetDWORD(addr_Cash, 0x912B001C);
				InfScore = FALSE;
			}
		}else{

			hNotify(L"Inf Red Orbs Activated");
			Vibr01();
			if(Gamexex == 1)
			{
				SetDWORD(addr_Cash, 0x905C2284);
				InfScore = TRUE;
			}
			if(Gamexex == 2)
			{
				SetDWORD(addr_Cash, 0x916A0078);
				InfScore = TRUE;
			}
			if(Gamexex == 3)
			{
				SetDWORD(addr_Cash, 0x916B001C);
				InfScore = TRUE;
			}
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
			Vibr01();
			if(Gamexex == 1)
			{
				SetDWORD(addr_Special, 0xB15F1446);
				InfStamina = FALSE;
			}
			if(Gamexex == 2)
			{
				SetDWORD(addr_Special, 0xB0DF042E);
				InfStamina = FALSE;
			}
			if(Gamexex == 3)
			{
				SetDWORD(addr_Special, 0xD1A32CF8);
				InfStamina = FALSE;
			}
		}else{

			hNotify(L"Inf Devil Trigger Activated");
			Vibr01();
			if(Gamexex >= 1)
			{
				SetDWORD(addr_Special, NOPThis);
				InfStamina = TRUE;
			}
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
		
			Vibr01();
			if(Gamexex == 1)
			{
				hNotify(L"All DmC Cheats Deactivated");
				SetDWORD(addr_Cash, 0x917C2284);
				SetDWORD(addr_Special, 0xB15F1446);
				SetDWORD(addr+0x30, 0x4098000C);
				SetDWORD(addr, 0xB14310A6);
				ALLCheats = FALSE;
			}
			if(Gamexex == 2)
			{	hNotify(L"All DmC 2 Cheats Deactivated");
				SetDWORD(addr_Cash, 0x910A0078);
				SetDWORD(addr_Special, 0xB0DF042E);
				InfHealth = FALSE;
				OneHitKo = FALSE;
				ALLCheats = FALSE;
			}
			if(Gamexex == 3)
			{	hNotify(L"All DmC 3 Cheats Deactivated");
				SetDWORD(addr_Cash, 0x912B001C);
				SetDWORD(addr_Special, 0xD1A32CF8);
				InfHealth = FALSE;
				OneHitKo = FALSE;
				ALLCheats = FALSE;
			}


		}else{


			Vibr01();
			if(Gamexex == 1)

			{	hNotify(L"All Cheats DmC Activated");
				SetDWORD(addr_Cash, 0x905C2284);
				SetDWORD(addr_Special, NOPThis);
				SetDWORD(addr+0x30,NOPThis);
				SetDWORD(addr,NOPThis);
				ALLCheats = TRUE;
			}
			if(Gamexex == 2)
			{
				hNotify(L"All Cheats DmC 2 Activated");
				SetDWORD(addr_Cash, 0x916A0078);
				SetDWORD(addr_Special, NOPThis);
				InfHealth = TRUE;
				OneHitKo = TRUE;
				ALLCheats = TRUE;
			}
			if(Gamexex == 3)
			{
				hNotify(L"All Cheats DmC 3 Activated");
				SetDWORD(addr_Cash, 0x916B001C);
				SetDWORD(addr_Special, NOPThis);
				InfHealth = TRUE;
				OneHitKo = TRUE;
				ALLCheats = TRUE;
			}

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
	if (GetDWORD(0x82294B04) == 0x4200FFFC)
	{
		hNotify(L"Devil May Cry HD Collection");
		Gamexex = 0;
		Sleep(25);
	}
	else if (GetDWORD(0x82294B04) == 0x4BE8215D)
	{
		hNotify(L"Devil May Cry");
		Gamexex = 1;
		Sleep(25);
		addr = GetAddr(0x82000000, 0x83000000, buf, 2, 1);
		addr_Cash = GetAddr(0x82000000, 0x83000000, moneybuf, 2, 1)+0x04;
		addr_Special = GetAddr(0x82000000, 0x83000000, devilbuf, 2, 1);
		SetAddr = true;
	}
	else if (GetDWORD(0x82294B04) == 0x38210060)
	{
		hNotify(L"Devil May Cry 2");
		Gamexex = 2;
		Sleep(25);
		addr = GetAddr(0x82000000, 0x83000000, buf1, 2, 1)+0x04;
		addr_Cash = GetAddr(0x82000000, 0x83000000, moneybuf1, 2, 1)+0x04;
		addr_Special = GetAddr(0x82000000, 0x83000000, devilbuf1, 2, 1)+0x04;
		SetAddr = true;
	}
	else if (GetDWORD(0x82294B04) == 0x7FC3F378)
	{
		hNotify(L"Devil May Cry 3");
		Gamexex = 3;
		Sleep(25);
		addr = GetAddr(0x82000000, 0x83000000, buf2, 2, 1);
		addr_Cash = GetAddr(0x82000000, 0x83000000, moneybuf2, 2, 1)+0x04;
		addr_Special = GetAddr(0x82000000, 0x83000000, devilbuf2, 2, 1)+0x04;
	}

}