#include "common.h"
#include <stdio.h>
#include "xbdm.h"

UINT32 g_titleID = 0x584109BE;

bool Cash = false;
bool HooksSet = false;

BYTE OptionA[1] = { 0x63 }; 
bool Option1 = false;
BYTE OptionB[1] = { 0x63 }; 
bool Option2 = false;
BYTE OptionC[4] = { 0x3b, 0x9a, 0xc9, 0xff };
bool Option3 = false;
BYTE OptionD[4] = { 0x00, 0x00, 0x00, 0x63 };
bool Option4 = false;
static void Statics(){
	while (1){
	
		if (Option1 == TRUE)
		{
			DoCheat(0x4000961F, OptionA, 1);
			
		} 
		if (Option2 == TRUE)
		{
			DoCheat(0x4000961B, OptionB, 1);
		} 
		if (Option3 == TRUE)
		{
			DoCheat(0x4000E930, OptionC, 4);
		} 
		if (Option4 == TRUE)
		{
			DoCheat(0x4000960C, OptionD, 4);
			DoCheat(0x40009608, OptionD, 4);
		} 
		Sleep(10); 
	}
}  
//Add Cheats here
				/*
				if( InfHealth== TRUE )
				{
					BYTE InfHealth[4] = { 0x00 , 0x00 , 0x00 , 0x63 };

					//memcpy( (void*)0x4000960C, InfHealth, 4);
					DmSetMemory( (void*)0x4000960C, 4 , InfHealth, NULL );
				}
				
				if( GodMode== TRUE )
				{
					BYTE GodMode[4] = { 0x60 , 0x00 , 0x00 , 0x00 };

					//memcpy( (void*)0x82089D6C, GodMode, 4);
					DmSetMemory( (void*)0x82089D6C, 4 , GodMode, NULL );
				}
				
				 */
//end Cheats

VOID Quicklaunch1()
{
	
	if( Option1== TRUE )
	{
		//XShowMessageBoxUI(0, L"Cheat Disabled Successfully", L"Infinite Ropes - Disabled\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_ERRORICON, &g_mb_result, &g_xol);
		hNotify(L"Infinite ropes disabled  ~TeamXPG~ ");
		Option1 = FALSE;
		Vibr01();
	}else{

		//XShowMessageBoxUI(0, L"Cheat Enabled Successfully", L"Infinite Ropes!!\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_WARNINGICON, &g_mb_result, &g_xol);
		hNotify(L"Infinite ropes enabled  ~TeamXPG~ ");
		Option1 = TRUE;
		Vibr01();

}}
VOID Quicklaunch2()
{
	if( Option2== TRUE )
	{
		//XShowMessageBoxUI(0, L"Cheat Disabled Successfully", L"Infinite Bombs - Disabled\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_ERRORICON, &g_mb_result, &g_xol);
		hNotify(L"Infinite bombs disabled  ~TeamXPG~ ");
		Option2 = FALSE;
		Vibr01();
	}else{

		//XShowMessageBoxUI(0, L"Cheat Enabled Successfully", L"Infinite Bombs!\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_WARNINGICON, &g_mb_result, &g_xol);
		hNotify(L"Infinite bombs enabled  ~TeamXPG~ ");
		Option2 = TRUE;
		Vibr01();
}}
VOID Quicklaunch3()
{
	if( Option3== TRUE )
	{
		//XShowMessageBoxUI(0, L"Cheat Disabled Successfully", L"Max Cash - Disabled\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_ERRORICON, &g_mb_result, &g_xol);
		hNotify(L"Max Cash Disabled  ~TeamXPG~ ");
		Option3 = FALSE;
		Vibr01();
	}else{

		//XShowMessageBoxUI(0, L"Cheat Enabled Successfully", L"Max Cash\r\nGive Me Monez!!\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_WARNINGICON, &g_mb_result, &g_xol);
		hNotify(L"Max Cash Enabled  ~TeamXPG~ ");
		Option3 = TRUE;	
		Vibr01();
}}	
VOID Quicklaunch4()
{
	if( Option4== TRUE )
	{
		//XShowMessageBoxUI(0, L"Cheat Disabled Successfully", L"Max Cash - Disabled\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_ERRORICON, &g_mb_result, &g_xol);
		hNotify(L"Infinite Health Disabled  ~TeamXPG~ ");
		Option4 = FALSE;
		Vibr01();
	}else{

		//XShowMessageBoxUI(0, L"Cheat Enabled Successfully", L"Max Cash\r\nGive Me Monez!!\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_WARNINGICON, &g_mb_result, &g_xol);
		hNotify(L"Infinite Health Enabled  ~TeamXPG~ ");
		Option4 = TRUE;	
		Vibr01();
	}}	
VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"XPGamesaves.com TeamXPG begallegal1", L"~Spelunky +4~\r\nView Codes: DPAD-DOWN(x4)" , ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
	hNotify(L"Spelunky +4 \n~TeamXPG~  ~XPGamesaves.com~");
	Vibr01();
}
VOID __declspec(naked) CheckDamage(VOID)
{


}
/*VOID SetHooks()
{

		
		82089D68 2F0A0002             cmpwi cr6,r10,2 
	//	82089D6C 917F0140             stw r11,140h(r31) 
		82089D70 409A001C             bne cr6,82089D8C 
		82089D74 2F180000             cmpwi cr6,r24,0 
		

		DWORD Stuff[4];
		patchInJump( (PDWORD)Stuff, (DWORD)CheckDamage, FALSE );
		DmSetMemory( (PDWORD)0x826CF764, 4, &Stuff[0], NULL );
		DmSetMemory( (PDWORD)0x826CF768, 4, &Stuff[1], NULL );
		DmSetMemory( (PDWORD)0x826CF76C, 4, &Stuff[2], NULL );
		DmSetMemory( (PDWORD)0x826CF770, 4, &Stuff[3], NULL );
		

		memcpy( (PDWORD)0x826CF764, &Stuff[0], 4 );
		memcpy( (PDWORD)0x826CF768, &Stuff[1], 4 );
		memcpy( (PDWORD)0x826CF76C, &Stuff[2], 4 );
		memcpy( (PDWORD)0x826CF770, &Stuff[3], 4 );
		HooksSet = true;
}
*/
VOID ProcessButtonPress( MESSAGEBOX_RESULT g_mb_result )
{

	if( g_mb_result.rgwPasscode[0] == DPAD_DOWN && g_mb_result.rgwPasscode[1] == DPAD_DOWN && g_mb_result.rgwPasscode[2] == DPAD_DOWN && g_mb_result.rgwPasscode[3] == DPAD_DOWN )
	{
	
		Sleep(500);
		XShowMessageBoxUI(0, L"Code List", L"Max Cash Press Y+B+A\r\nInf Bombs Press RB+RT+A\r\nInfinite Ropes Press LB+LT+A\r\nInfinite Health Press DPadUP+Back+A\r\n~~~~~~~~~~~~~~~~~~~\r\nView Trainer Credits Press DPad Up(x4)", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_ALERTICON, &g_mb_result, &g_xol);
		
		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;

	}

	if( g_mb_result.rgwPasscode[0] == DPAD_UP && g_mb_result.rgwPasscode[1] == DPAD_UP && g_mb_result.rgwPasscode[2] == DPAD_UP && g_mb_result.rgwPasscode[3] == DPAD_UP )
	{
		Sleep(500);
		XShowMessageBoxUI(0, L"~~TeamXPG~~XPGamesaves.com~~", L"Trainer Engine By PermaNulled\r\n~~~~~~~~~~~~~~\r\nTrainer Built By begallegal1", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_ALERTICON, &g_mb_result, &g_xol);

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;

	}
	
	
/*	if( g_mb_result.rgwPasscode[0] == X_BUTTON && g_mb_result.rgwPasscode[1] == X_BUTTON && g_mb_result.rgwPasscode[2] == X_BUTTON && g_mb_result.rgwPasscode[3] == X_BUTTON )
	{
		Sleep(500);

		if( Cash== TRUE )
		{
			XShowMessageBoxUI(0, L"Mega Cash Disabled Successfully", L"Mega Cash Disabled\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_ERRORICON, &g_mb_result, &g_xol);
			Cash = FALSE;
		}else{

			XShowMessageBoxUI(0, L"Mega Cash Enabled Successfully", L"Mega Cash!\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_WARNINGICON, &g_mb_result, &g_xol);
			Cash = TRUE;


		}

		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999;
	}
	
	*/

}
