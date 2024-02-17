#include "common.h"

UINT32 g_titleID = 0x565707D0;

DWORD buf[] = {0x90DF0018, 0x809D0000};
DWORD bufspec[] = {0x81610058, 0x7F0A5800};
VOID __declspec(naked) CheckHealth(VOID)
{ 


	__asm{
		stw r6,18h(r31)
			lwz r4,0(r29)
			subf r3,r5,r4
			stw r3,0(r29)

			mflr r7
	}

	Saveregs();

	__asm 
	{
		mr MYPtr1,r29
	}

	if(*(DWORD*)(MYPtr1-0x2ec) == 0x82197cd8 && InfHealth == TRUE)
	{
		*(DWORD*)(MYPtr1) = *(DWORD*)(MYPtr1+0x04);

	}
	if(*(DWORD*)(MYPtr1-0x2ec) == 0x821982f0 && OneHitKo == TRUE)
	{
		*(DWORD*)(MYPtr1) = 0x00000001;

	}
	if(*(DWORD*)(MYPtr1-0x2ec) == 0x00000078 && InfGold == TRUE)
	{
		*(DWORD*)(MYPtr1) = 0x0000270F;
		*(DWORD*)(MYPtr1+0x04) = 0x0000270F;

	}
	Loadregs();



	__asm{

		mtlr r7
			lis r7,0x8226
			ori r7,r7,0xE67C
			mtctr r7
			bctr
	}

}

VOID __declspec(naked) CheckSpark(VOID)
{ 


	__asm{
		lwz r11,58h(r1)
			cmpw cr6,r10,r11
			bge cr6,br2
			stw r10,0(r30)

			mflr r20
	}

	Saveregs();

	__asm 
	{
		mr MYPtr1,r30
	}

	if(*(DWORD*)(MYPtr1+0x04) == 0x00000023 && InfSpecial == TRUE)
	{
		*(DWORD*)(MYPtr1) = *(DWORD*)(MYPtr1+0x04);

	}
	if(*(DWORD*)(MYPtr1+0x0C) == 0x00000009 && InfItems == TRUE)
	{
		*(DWORD*)(MYPtr1+0x08) =*(DWORD*)(MYPtr1+0x0C);

	}
	Loadregs();



	__asm{

br2:
		mtlr r20
			lis r20,0x8226
			ori r20,r20,0xEC3C
			mtctr r20
			bctr
	}

}

VOID SetHooks()
{
	Caveme(addr ,CheckHealth,7);
	Caveme(addr_Special ,CheckSpark,20);
	HooksSet = true;
}


VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"More at T3furyGaming.co.uk", L"Lollipop Chainsaw + 5\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
	
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
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nInf Medals LT(x4)\r\nTwo Hit Kill RB(x4)\r\nInf Special LB(x4)\r\nInf Nick Tickets Y(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3furyGaming.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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

		if( InfGold == TRUE )
		{
			hNotify(L"Inf Medals Deactivated");
			InfGold = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Medals Activated");
			InfGold = TRUE;
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

	if( g_mb_result.rgwPasscode[0] == LEFT_BUMPER && g_mb_result.rgwPasscode[1] == LEFT_BUMPER && g_mb_result.rgwPasscode[2] == LEFT_BUMPER && g_mb_result.rgwPasscode[3] == LEFT_BUMPER )
	{
		Sleep(500);

		if( InfSpecial == TRUE )
		{
			hNotify(L"Inf Special Deactivated");
			InfSpecial = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Special Activated");
			InfSpecial = TRUE;
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

		if( InfItems == TRUE )
		{
			hNotify(L"Inf Nick Deactivated");
			InfItems = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Nick Activated");
			InfItems = TRUE;
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
		InfSpecial = FALSE;
		OneHitKo = FALSE;
		InfGold = FALSE;
		InfItems = FALSE;
		InfHealth = FALSE;
		ALLCheats = FALSE;
		Vibr01();

	}else{

		hNotify(L"All Cheats Activated");
		InfSpecial = TRUE;
		OneHitKo = TRUE;
		InfGold = TRUE;
		InfItems = TRUE;
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

	hNotify(L"Lollipop Chainsaw");
	Sleep(25);
	addr = GetAddr(0x82000000, 0x83000000, buf, 2, 1);
	addr_Special = GetAddr(0x82000000, 0x83000000, bufspec, 2, 1);
	SetAddr = true;
	
}//