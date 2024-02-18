#include "common.h"


UINT32 g_titleID = 0x5345080C;
//ADD  BOOLS

///static codes values
bool SetAddr = false;
bool InfHealth = false;
bool InfAmmo = false;
bool XPMod = false;
// Cheat ------
static DWORD InfAmmo_addr;
static DWORD XPMod_addr;

    

static void __declspec(naked) CodeCave(void)
{
    BYTE Ptr;

     __asm
    {
        li r10,0
			stw r10,8(r11)
			stfs fr1,370h(r31)
			lwz r11,0C4h(r31)
			mr r2,r11
			            
    }

    __asm
    {
        stw r5,Ptr
        
    }

    
	if(Ptr == 0x04 || Ptr == 0x74 && InfHealth == TRUE )
	{
		float XValue = 500.0f;
		__asm
		{ 
        stfs XValue,370h(r31)
		}

	}

    __asm
    {
		 mr r11,r2
		 li r2,0
         blr
    }
}




//Search for TU Address
VOID SearchAddr()
{
	hNotify(L"Applying All TU Patch");
	Sleep(25);
	hNotify(L"Aliens Colonial Marines");
	//Breakpoint-4,Breakpoint
    DWORD addr;
    DWORD buf[] = {0x39400000, 0x914b0008};
	addr = GetAddr(0x82000000, 0x83000000, buf, 2, 1);
    PatchJump(addr, (DWORD)CodeCave);

	///Search range  
	DWORD InfAmmo_buf[] = {0x911e0000, 0x911d0000}; 
	DWORD XPMod_buf[] = {0x7d6b5214, 0x917e0000};

    InfAmmo_addr = GetAddr(0x82000000, 0x83000000, InfAmmo_buf, 2, 1); 
    XPMod_addr = GetAddr(0x82000000, 0x83000000, XPMod_buf, 2, 1);
	SetAddr = true;
}



VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"TeamXPG ", L"~Aliens Colonial Marines All TU +3~\r\nQuickLaunch Codes: \r\nLB + ↑ Infinite Health\r\nLB + → Infinite Ammo & Grenades\r\nLB + ← Score & XP Mod\r\nLB+RB+A to Activate All\r\nTrainer By:Sensi420 & XPGObyto ", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);
	
}
//Quicklaunch LB+RB+A
VOID LbRbA()
{
	
      hNotify(L"Super Mode");
	  XShowMessageBoxUI(0, L"TeamXPG ", L"SuperMode Enabled\r\nInfinite Health \r\nInfinite Ammo & Grenades\r\nScore & XP Mod", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);
 	  InfHealth = TRUE;
	  InfAmmo = TRUE;
	  SetDWORD(InfAmmo_addr, 0x60000000);
	  XPMod = TRUE;
	  SetDWORD(XPMod_addr, 0x396b0002);
}
//Quicklaunch LB+Dpad Up
VOID LbDpadUp()
{

                  if( InfHealth == TRUE ) {
					InfHealth = FALSE;
					 
					 hNotify(L"Infinite Health Disabled");
					} else {				
					InfHealth = TRUE;
					 
					 hNotify(L"Infinite Health Enabled");
					}
}

VOID LbDpadRght()
{

      if( InfAmmo == TRUE ) {
					InfAmmo = FALSE;
					SetDWORD(InfAmmo_addr, 0x911e0000);
					hNotify(L"Infinite Ammo Disabled");
					} else {				
					InfAmmo = TRUE;
					SetDWORD(InfAmmo_addr, 0x60000000);
					hNotify(L"Infinite Ammo Enabled");
					}
}


VOID LbDpadLft()
{

      if( XPMod == TRUE ) {
					XPMod = FALSE;
					 SetDWORD(XPMod_addr, 0x7d6b5214);
					 hNotify(L"Score & Rank Mod Disabled");
					} else {				
					XPMod = TRUE;
					 SetDWORD(XPMod_addr, 0x396b0002);
					 hNotify(L"Score & Rank Mod Enabled");
					}
}



