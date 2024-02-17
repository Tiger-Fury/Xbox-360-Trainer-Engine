#include <xtl.h>
#include "kernel.h"
#include "common.h"
#include "BlackOps2test.h"


HANDLE hThread; 
DWORD hThreadId;
HANDLE hTh01 = 0; 
DWORD hThId01 = 0;


static void Main01(){
	
	/* Change to 1 to Disable */
	WORD quickcodes = 0;
	/* ----------------------*/

	HRESULT hre = 0; DWORD hr = 0; 
	XINPUT_STATE state; WCHAR r1[512];
	ZeroMemory( &state, sizeof(XINPUT_STATE) );
	while (1){

		if (XInputGetState(0, &state) == ERROR_SUCCESS)
		{
				/* Disable if no plan to use it.. */
			    if ( quickcodes == 0 )
				{ 
					ExCreateThread(&hTh01, 0, &hThId01, (VOID*)XapiThreadStartup , 
					(LPTHREAD_START_ROUTINE)ButPress, NULL, 0x2);
					quickcodes = 1;
				}
				if( (BOOL)state.Gamepad.wButtons & XINPUT_GAMEPAD_BACK  && (BOOL)state.Gamepad.wButtons & XINPUT_GAMEPAD_START )
				{
					ShowTrainerMain();
				}
			
					if( Prompt == 0x000003E5 && g_mb_result.rgwPasscode[0] != 0x00 && g_mb_result.rgwPasscode[1] != 0x00 && g_mb_result.rgwPasscode[2] != 0x00 && g_mb_result.rgwPasscode[3] != 0x00 )
					{
							ButPress( g_mb_result );

							memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
							memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
							memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
							memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
							Prompt = 0x9999;
					}
		}else{
			memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
			memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
			memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
			memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
			Prompt = 0x9999;
		}

		Sleep(500);
	}
}

BOOL APIENTRY DllMain(HANDLE hInstDLL, DWORD reason, LPVOID lpReserved){
	if(reason == DLL_PROCESS_ATTACH){
		DmSetMemoryD = (HRESULT (__cdecl *)(LPVOID, DWORD, LPCVOID, LPDWORD)) (ResolveFunct("xbdm.xex", 40));
		if (DmSetMemoryD != 0){
			KrnlType = 1; //  1 = dev kernel ; 0 = retail kernel (default)
			DmGetMemoryD = (HRESULT (__cdecl *)(LPCVOID, DWORD, LPVOID, LPDWORD)) (ResolveFunct("xbdm.xex", 10));
		}
		ExCreateThread(&hThread, 0, &hThreadId, (VOID*)XapiThreadStartup , (LPTHREAD_START_ROUTINE)Main01, NULL, 0x2);
		XSetThreadProcessor(hThread, 4); ResumeThread(hThread); CloseHandle(hThread);
	
		Sleep(200);
		XShowMessageBoxUI(0, L"Created By T3fury", L"Trainer Engine Modified Jackass Engine Furiass Engine\r\n~~~~~~~~~~~~~~\r\n Big Thanks To BegalLegal1 For Teaching Me\r\n ", ARRAYSIZE(g_strButtons), g_strButtons, 0, XMB_ALERTICON, &g_mb_result, &g_xol);
		memset( &g_mb_result.rgwPasscode[0], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[1], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[2], 0x00, 0x02 );
		memset( &g_mb_result.rgwPasscode[3], 0x00, 0x02 );
		Prompt = 0x9999; //HERE
	}

	

	return TRUE;
}