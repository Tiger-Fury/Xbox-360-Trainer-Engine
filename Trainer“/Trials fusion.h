#include "common.h"

UINT32 g_titleID = 0x58411401;


DWORD MYPtr1;
DWORD Timerbuf[] = {0xD03F0028, 0x817A0014};

VOID __declspec(naked) CheckTimer(VOID)
{ 


	__asm{
			lwz r11,14h(r26)

            mflr r14
	     }

	Saveregs();

	__asm 
	{
			mr MYPtr1,r26
	}

	if(*(DWORD*)(MYPtr1+0x14) == 0x00000100 && InfHealth == TRUE)
	{
		
			*(DWORD*)(MYPtr1+0x14) = 0x00000000;
			
	}
	Loadregs();



	__asm{

		stw r11,30h(r31)
		lwz r6,10h(r30)
		cmplwi cr6,r6,0

			mtlr r14
			lis r14,0x8221
			ori r14,r14,0x4518
			mtctr r14
			bctr

	}



}


VOID SetHooks()
{
    Caveme(addr_Timer,CheckTimer,14);
    HooksSet = true;
}

VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"More at T3furyGaming.co.uk", L"Trials Fusion\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
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
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nRate of Fire LT(x4)\r\nNo Recoil LB(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3furyGaming.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
			hNotify(L"No Timer Deactivated");
			InfHealth = FALSE;
			Vibr01();

		}else{

			hNotify(L"No Timer Activated");
			InfHealth = TRUE;
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
	hNotify(L"Trials Fusion");
	Sleep(25);
	addr_Timer = GetAddr(0x82000000, 0x83000000, Timerbuf, 2, 1)+ 0x04;

	SetAddr = true;
}