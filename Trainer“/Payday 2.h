#include "common.h"


UINT32 g_titleID = 0x4d5307f1;
//ADD  BOOLS
bool SetAddr = false;
bool InfHealth = false;
bool HitKO = false;
bool ExpMOD = false;
bool MoneyMOD = false;
bool RenownMOD = false;
// Add Mod Address name for get search 
static DWORD Money_addr;
static DWORD Renown_addr;
static DWORD Exp_addr;





//Code cave
static void __declspec(naked) CodeCave(void)
{
    DWORD addr;

    __asm
    {
        cmplwi cr6,r31,0          
        bne cr6,826367D4        
        lwz r11,0(r24)
        stw r11,0(r5)                            
    }

    __asm
    {
        stw r11,addr
    }

    if(*(DWORD*)(addr) == 0x41A00000 || *(DWORD*)(addr) == 0x41880000) // player
    {
        if(InfHealth == TRUE )
            *(DWORD*)(addr) = 0x41A00000;
    }
    
    __asm
    {
        blr
    }
}




//Search for TU Address
VOID SearchAddr()
{
	hNotify(L"Applying All TU Patch");
	Sleep(25);
	
	//Breakpoint-4,Breakpoint
	//DWORD modname_buf[] = {0xBreakpoint-4, 0xBreakpoint};
	//Example
	//83310124 817D0060  ←           lwz r11,60h(r29)//Breakpoint-8 
    //83310128 7D635A14  ←           add r11,r3,r11 //Breakpoint-4
    //8331012C 917D0060  ←           stw r11,60h(r29)//Breakpoint
	//DWORD modname_buf[] = {0x7D635A14, 0x917D0060};

    DWORD addr;
    DWORD buf[] = {0x91650000, 0x81580004};
    DWORD money_buf[] = {0x5549003E, 0x915A000C};
    DWORD exp_buf[] = {0xEDA0082A, 0x7DABED2E};
    DWORD renown_buf[] = {0x7D7DE214, 0x556A003E};
	///Search range
	//Edit to match your Breakpoint offset
	//Example if Breakpoint = 83AAAAAA set range to 0x83000000-0x84000000
	//Example if Breakpoint = 82AAAAAA set range to 0x82000000-0x83000000
	//Modname_addr = GetAddr(0x82000000, 0x83000000, modname_buf, 2, 1)
    addr = GetAddr(0x82000000, 0x83000000, buf, 2, 1);
    PatchJump(addr, (DWORD)CodeCave);
    Money_addr = GetAddr(0x82000000, 0x83000000, money_buf, 2, 1) + 0x04;
    Exp_addr = GetAddr(0x82000000, 0x83000000, exp_buf, 2, 1);
	Renown_addr = GetAddr(0x82000000, 0x83000000, renown_buf, 2, 1);
	SetAddr = true;
	//////////////////


}



VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L"TeamXPG ", L"~Fable 2 GOTY All TU +5~\r\nQuickLaunch Codes: \r\nLB + ↑ Inf Health\r\nLB + → Experience MOD\r\nLB + ↓ 1 Hit Kill\r\nLB + ← Money MOD\r\nRB + ↓ Renown MOD\r\nLB+RB+A to Activate All\r\nTrainer By:Sensi420 ", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);
	if( SetAddr == false )
	{
		SearchAddr();
	}
}
//Quicklaunch MENU LB+RB+A
VOID LbRbA()
{
	if( SetAddr == false )
	{
		SearchAddr();
	}
      hNotify(L"Super Mode");
	  XShowMessageBoxUI(0, L"TeamXPG ", L"SuperMode Enabled\r\nGodmode Enabled\r\nExperience MOD Enabled\r\nMoney MOD Enabled\r\n 1 Hit Kill", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);
 	  InfHealth = TRUE;
	  HitKO = TRUE;
	  ExpMOD = TRUE;
      SetDWORD(Exp_addr, 0x3D404A00);
      SetDWORD(Exp_addr + 4, 0x7D4BE92E);
	  MoneyMOD = TRUE;
	  SetDWORD(Money_addr, 0x911A000C);
	  RenownMOD = TRUE;
	  SetDWORD(Renown_addr, 0x397D7530);


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

      if( ExpMOD == TRUE ) {
					ExpMOD = FALSE;
					SetDWORD(Exp_addr, 0xEDA0082A);//Off Original Data
                    SetDWORD(Exp_addr +4 , 0x7DABED2E);//Off Original Data
					hNotify(L"Experience MOD Disabled");
					} else {				
					ExpMOD = TRUE;
					SetDWORD(Exp_addr, 0x3D404A00);//On Modified Data
                    SetDWORD(Exp_addr + 4, 0x7D4BE92E);//On Modified Data
					hNotify(L"Experience MOD Enabled");
					}
}

VOID LbDpadDwn()
{

      if( HitKO == TRUE ) {
					HitKO = FALSE;
					hNotify(L"1 Hit Kill Disabled");
					} else {				
					HitKO = TRUE;
					hNotify(L"1 Hit Kill Enabled");
					}
}
VOID LbDpadLft()
{

      if( MoneyMOD == TRUE ) {
					MoneyMOD = FALSE;
					 SetDWORD(Money_addr, 0x915A000C);//Off Original Data
					 hNotify(L"Money MOD Disabled");
					} else {				
					MoneyMOD = TRUE;
					 SetDWORD(Money_addr, 0x911A000C);//On Modified Data
					 hNotify(L"Money MOD Enabled");
					}
}

VOID RbDpadLft()
{

      if( RenownMOD == TRUE ) {
					RenownMOD = FALSE;
					 SetDWORD(Renown_addr, 0x7D7DE214);
					 hNotify(L"Renown MOD Disabled");
					} else {				
					RenownMOD = TRUE;
					 SetDWORD(Renown_addr, 0x397D7530);
					 hNotify(L"Renown MOD Enabled");
					}
}




