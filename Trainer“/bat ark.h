#include "common.h"

UINT32 g_titleID = 0x5D278B66;

bool MaxUps = false;
bool maxxp = false;
bool InfOHK = false;
bool HooksSet = false;
bool InfHealth = false;

DWORD ZValue = 0x00000064;
DWORD binary = 0x82A447B0;


VOID __declspec(naked) CheckHealth(VOID)
{
	__asm{
		lwz r11,294h(r26)           // recreate
	}

	Saveregs();              // save registers

	if( InfHealth == TRUE )    
	{
		__asm{

        stw ZValue,294h(r26)
		}
	}		

	Loadregs();             // load registers back


	__asm{
	cmpwi cr6,r11,0         
	ble cr6,br13   
	lhz r11,334h(r30)

	lis r14,0x828d               
	ori r14,r14,0x0d34
	mtctr r14
	bctr

 br13:

	lis r14,0x828d             
	ori r14,r14,0x0d70
	mtctr r14
	bctr
	}

}

VOID SetHooks()
{
    Caveme(0x828d0d24,CheckHealth,14);         // 1 line set health cave using 1st address out of list u get
    HooksSet = true;
}

VOID ShowTrainerMain()
{
	Prompt = XShowMessageBoxUI(0, L" TeamXPG GoldZ", L"Batman Arkham City V0.1\r\nInfinite Health LB+B\r\n", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_NOICON, &g_mb_result, &g_xol);
	if( HooksSet == false )
	{
		SetHooks();
	}
}


VOID Quicklaunch1()
{
	if( InfHealth == TRUE ) {

		InfHealth = FALSE;
		hNotify(L"Inf Health Disabled");
		Vibr01();
	} else {

		InfHealth = TRUE;
		hNotify(L"Inf Health Enabled");
		Vibr01();
	}
}