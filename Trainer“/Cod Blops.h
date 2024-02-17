#include "common.h"

UINT32 g_titleID = 0x41560855;

DWORD buf[] = {0x7D782050, 0x917A0184};
DWORD Ammobuf[] = {0x90E30004, 0x38210070};
DWORD moneybuf[] = {0x7C9E2BD6, 0x908300A4};

bool AIAmmo = false;
bool InfBP = false;
bool TU = false;
bool CheatXX = FALSE;
bool CheatLB = FALSE;
bool CheatYY = FALSE;
bool CheatRB = FALSE;
bool CheatRT = FALSE;
bool CheatLT = FALSE;
bool CheatDU = FALSE;
bool CheatDL = FALSE;
bool CheatDR = FALSE;

VOID __declspec(naked) CheckMoneyCodBlops(VOID)
{ 


	__asm{

		li r5,10
		divw r4,r30,r5
		stw r4,0A4h(r3)
		stw r31,1B8Ch(r29)
			mflr r16
	}

	Saveregs();

	__asm 
	{
		mr MYPtr1,r25
			mr MYPtr2,r3

	}

	if(MYPtr1 == 0x12DA && CheatRB == TRUE)
	{
		*(DWORD*)(MYPtr2 + 0x0A4)= Max_IT;

	}


	Loadregs();


	__asm{
		mtlr r16

			lis r16,0x8224
			ori r16,r16,0xE978 
			mtctr r16
			bctr
	}
}


VOID SetHooks()
{	
		if (Gamexex == 1)
		{
			Caveme(addr_Cash ,CheckMoneyCodBlops,16);
			HooksSet = true;
		}
		
}


VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"More at T3furyGaming.co.uk", L"Call of Duty Blops +3/5 Trainer\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
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
			XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health SP/ZOM RT(x4)\r\nInf Ammo SP/ZOM LT(x4)\r\nInf Money (Zombie) RB(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3furyGaming.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

        memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
        memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
        memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
        memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
        Prompt = 0x9999;

    }
	// 1st Cheat
		if( g_mb_result.rgwPasscode[0] == RIGHT_BUMPER && g_mb_result.rgwPasscode[1] == RIGHT_BUMPER && g_mb_result.rgwPasscode[2] == RIGHT_BUMPER && g_mb_result.rgwPasscode[3] == RIGHT_BUMPER )
	{
		Sleep(500);
		
		if( CheatRB == TRUE )
		{
			pop(L"Inf Money Deactivated");
			CheatRB = FALSE;
			PulseController();

		}else{
			
			pop(L"Inf Money Activated");			
			CheatRB = true;
			PulseController();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
		}
	//3rd Cheat
	if( g_mb_result.rgwPasscode[0] == LEFT_TRIGGER && g_mb_result.rgwPasscode[1] == LEFT_TRIGGER && g_mb_result.rgwPasscode[2] == LEFT_TRIGGER && g_mb_result.rgwPasscode[3] == LEFT_TRIGGER )
	{
		Sleep(500);
		
		if( CheatLT == TRUE )
		{
			pop(L"Inf Ammo Campaign/Zombie Deactivated");
			SetDWORD(addr_ammo, 0x90E30004);
			CheatLT = FALSE;
	        PulseController();

		}else{
			
			pop(L"Inf Ammo Campaign/Zombie Activated");
			SetDWORD(addr_ammo, NOPThis);
			CheatLT = TRUE;
		    PulseController();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
	//4th cheat
			if( g_mb_result.rgwPasscode[0] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[1] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[2] == RIGHT_TRIGGER && g_mb_result.rgwPasscode[3] == RIGHT_TRIGGER )
	{
		Sleep(500);
		
		if( CheatRT == TRUE )
		{
			pop(L"Inf Health Campaign/Zombie Deactivated");
			SetDWORD(addr, 0x917A0184);
			CheatRT = FALSE;
	        PulseController();

		}else{
			
			pop(L"Inf Health Campaign/Zombie Activated");
			SetDWORD(addr, NOPThis);
			CheatRT = TRUE;
		    PulseController();

		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
	//6th cheat Multi Activate
	if( g_mb_result.rgwPasscode[0] == DPAD_UP && g_mb_result.rgwPasscode[1] == DPAD_UP && g_mb_result.rgwPasscode[2] == DPAD_UP && g_mb_result.rgwPasscode[3] == DPAD_UP )
	{
		Sleep(500);
		
		if( CheatDU == TRUE )
		{
			pop(L"All Cheats Deactivated");
			SetDWORD(addr, 0x917A0184);
			SetDWORD(addr_ammo, 0x90E30004);
			CheatRB = FALSE;
			CheatDU = FALSE;
	        PulseController();

		}else{
			
			pop(L"All Cheats Activated");
			SetDWORD(addr, NOPThis);
			SetDWORD(addr_ammo, NOPThis);
			CheatRB = TRUE;
			CheatDU = TRUE;
		    PulseController();

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
		if (GetDWORD(0x82294B04) == 0xFEA0F890)
		{
		hNotify(L"Call of Duty: Black Ops");
		Sleep(25);

		addr = GetAddr(0x82000000, 0x83000000, buf, 2, 1)+0x04;
		addr_ammo = GetAddr(0x82000000, 0x83000000, Ammobuf, 2, 1);
		SetAddr = true;

		}
}