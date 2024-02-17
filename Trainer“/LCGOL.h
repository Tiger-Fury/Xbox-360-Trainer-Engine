#include "common.h"

UINT32 g_titleID = 0x58410A59;


// 		822B408C 817F0004             lwz r11,4(r31) 
// 		822B4090 815E0008             lwz r10,8(r30) 
// 		822B4094 7D2B5050             subf r9,r11,r10 
// 		822B4098 913E0008             stw r9,8(r30)//breakpoint 
// 		Return address
// 		822B409C 817E0008             lwz r11,8(r30)*/


VOID __declspec(naked) LCGOLCheckHealth(VOID)
{ 


	__asm{

		lwz r11,4(r31) 
		lwz r10,8(r30) 
		subf r9,r11,r10 
		stw r9,8(r30)

			mflr r11
	}

	Saveregs();

	__asm 
	{
		mr MYPtr1,r0
		mr MYPtr2,r30
	}

	if(MYPtr1 == 0x8242A7B8 && InfHealth == TRUE)
	{
		*(DWORD*)(MYPtr2 + 0x08) = *(DWORD*)(MYPtr2 + 0x0C);

	}
	if(MYPtr1 != 0x8242A7B8  && OneHitKo == TRUE)
	{
		*(DWORD*)(MYPtr2 + 0x08) = 0;

	}
	Loadregs();



	__asm{

			mtlr r11
			lis r11,0x822B  
			ori r11,r11,0x409C
			mtctr r11
			bctr

	}
}

VOID SetHooks()
{
	Caveme(0x822B408C ,LCGOLCheckHealth,11);
	HooksSet = true;
}


VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"More at T3furyGaming.co.uk", L"Lara Croft and the Guardian of Light +3\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
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
			XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nInf Ammo LT(x4)\r\n 1 Hit Kill RB(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3furyGaming.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
			pop(L"Inf Ammo Deactivated");
			SetDWORD(0x823FB2A0, 0x917F02E8);
			SetDWORD(0x823F9F9C, 0x917F02E8);
			CheatLT = FALSE;
	        PulseController();

		}else{
			
			pop(L"Inf Ammo Activated");
			SetDWORD(0x823FB2A0, NOPThis);
			SetDWORD(0x823F9F9C, NOPThis);
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
		
		if( InfHealth == TRUE )
		{
			pop(L"Inf Health Deactivated");
			InfHealth = FALSE;
	        PulseController();

		}else{
			
			pop(L"Inf Health Activated");
			InfHealth = TRUE;
		    PulseController();

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
					pop(L"One Hit Kill Deactivated");
					OneHitKo = FALSE;
					PulseController();

				}else{

					pop(L"One Hit Kill Activated");
					OneHitKo = TRUE;
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
			SetDWORD(0x823FB2A0, 0x917F02E8);
			SetDWORD(0x823F9F9C, 0x917F02E8);
			OneHitKo = FALSE;
			InfHealth = FALSE;
			CheatDU = FALSE;
	        PulseController();

		}else{
			
			pop(L"All Cheats Activated");
			SetDWORD(0x823FB2A0, NOPThis);
			SetDWORD(0x823F9F9C, NOPThis);
			OneHitKo = TRUE;
			InfHealth = TRUE;
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
	hNotify(L"Lara Croft and the Guardian of Light");
	Sleep(25);
	Static_Menu = Null_Menu;
}