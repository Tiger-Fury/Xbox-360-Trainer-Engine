#include "common.h"

UINT32 g_titleID = 0x445407DE;

DWORD addr_ammo1 = 0x82291A7C;
DWORD Ammo_On = 0x396003E7;
DWORD Ammo_off = 0x914B00E4;
float XValue = 10000.0;
float ZValue = 0.0;


VOID __declspec(naked) CheckHealth(VOID)
{ 


	__asm{
			stfs fr12,2Ch(r31)    // put at top with recreated
			addi r7,r8,10144 // put at top with recreated
			lfs fr0,4(r7)
                    mflr r15
	     }

	Saveregs();

	__asm {
			mr MYPtr1,r31
	}

	if(   *(DWORD*)(MYPtr1+0xFC) == 0x44656e7a || *(DWORD*)(MYPtr1 + 0xFC) == 0x45737465  &&  InfHealth == TRUE )
	{
		
		__asm
		{
 
			stfs XValue,2Ch(r31)
            
		}
	}else{
		if( InfHealth == FALSE )
		{
			__asm{

			}
		}


	}

	if(  OneHitKo == TRUE )
		{

			__asm
			{

	

			}
	

}else{
	if( OneHitKo == FALSE )
	{
		__asm{

		}
	}


}
	Loadregs();



	__asm{

		fcmpu cr6,fr12,fr0
			bgt cr6,br2 

			mtlr r15
			lis r15,0x8249       
			ori r15,r15,0xc840
			mtctr r15
			bctr

br2:
		mtlr r15
			lis r15,0x8249
			ori r15,r15,0xc884
			mtctr r15
			bctr
	}



}


VOID SetHooks()
{
    Caveme(0x8249C82C,CheckHealth,15);
    HooksSet = true;
}

VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L" More at T3furyGaming.co.uk", L"Cursed Crusade + 5\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nView Available Codes: DPAD-DOWN(x4)\r\nActivate All Codes: DPAD-UP(x4)\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_PASSCODEMODE, &g_mb_result, &g_xol);
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
		XShowMessageBoxUI(0, L"Viewing All Available Codes", L"All Cheats Dpad Up(x4)\r\nInf Health RT(x4)\r\nInf Ammo LT(x4)\r\n1 Hit Kill RB(x4)\r\nInf Skill Points LB(x4)\r\nInf Tech Points Y(x4)\r\n~~~~~~~~~~~~~~~~~~~~~~~~~\r\nCreated by t3fury \r\nT3furyGaming.co.uk\r\nThe Future of Gaming is Here", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);

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
// 	if( g_mb_result.rgwPasscode[0] == RIGHT_BUMPER && g_mb_result.rgwPasscode[1] == RIGHT_BUMPER && g_mb_result.rgwPasscode[2] == RIGHT_BUMPER && g_mb_result.rgwPasscode[3] == RIGHT_BUMPER )
// 	{
// 		Sleep(500);
// 
// 		if( OneHitKo == TRUE )
// 		{
// 			hNotify(L"One Hit Kill Deactivated");
// 			OneHitKo = FALSE;
// 			Vibr01();
// 
// 		}else{
// 
// 			hNotify(L"One Hit Kill Activated");
// 			OneHitKo = TRUE;
// 			Vibr01();
// 
// 		}
// 		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
// 		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
// 		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
// 		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
// 		Prompt = 0x9999;
// 	}
	if( g_mb_result.rgwPasscode[0] == LEFT_TRIGGER && g_mb_result.rgwPasscode[1] == LEFT_TRIGGER && g_mb_result.rgwPasscode[2] == LEFT_TRIGGER && g_mb_result.rgwPasscode[3] == LEFT_TRIGGER )
	{
		Sleep(500);

		if( InfAmmo == TRUE )
		{
			hNotify(L"Inf Ammo Deactivated");
			SetDWORD(addr_ammo1,Ammo_off);
			InfAmmo = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Ammo Activated");
			SetDWORD(addr_ammo1, NOPThis);
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
			hNotify(L"Inf Skill Points Deactivated");
			SetDWORD(uv_addr, 0x396BFFFF);
			InfGrenade = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Skill Points Activated");
			SetDWORD(uv_addr, 0x396B000F);
			InfGrenade = TRUE;
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

		if( InfGold == TRUE )
		{
			hNotify(L"Inf Tech Points Deactivated");
			SetDWORD(Charge_addr, 0x394AFFFF);
			InfGold = FALSE;
			Vibr01();

		}else{

			hNotify(L"Inf Tech Points Activated");
			SetDWORD(Charge_addr, 0x394A000F);
			InfGold = TRUE;
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

		if( ALLCheats == TRUE )
		{
			hNotify(L"All Cheats Deactivated");
			SetDWORD(addr_ammo1,Ammo_off);
			InfHealth = FALSE;
			SetDWORD(Charge_addr, 0x394AFFFF);
			SetDWORD(uv_addr, 0x396BFFFF);
			ALLCheats = FALSE;
			Vibr01();

		}else{

			hNotify(L"All Cheats Activated");
			SetDWORD(addr_ammo1, Ammo_On);
			InfHealth = TRUE;
			SetDWORD(Charge_addr, 0x394A000F);
			SetDWORD(uv_addr, 0x396B000F);
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
	hNotify(L"The Cursed Crusade");
	Sleep(25);
	DWORD uv_buf[] = {0x396BFFFF, 0x91631120};
	uv_addr = GetAddr(0x82100000, 0x83000000, uv_buf, 2, 1);
	DWORD Charge_buf[] = {0x394AFFFF, 0x914B1124};
	Charge_addr = GetAddr(0x82100000, 0x83000000, Charge_buf, 2, 1);
	SetAddr = true;
}