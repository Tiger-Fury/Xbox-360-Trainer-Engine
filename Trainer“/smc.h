
#pragma once
#ifndef _SMC__H
#define _SMC_H

#include <string.h>


typedef enum _LEDState
{
    OFF        = 0x00,
    RED        = 0x08,
    GREEN    = 0x80,
    ORANGE    = 0x88
}LEDState;

extern "C" void __stdcall HalSendSMCMessage(void* input, void* output);

class smc
{
    public:
        void SetLEDS(LEDState sTopLeft, LEDState sTopRight, LEDState sBottomLeft, LEDState sBottomRight);
		void LedStateOff(LEDState sTopLeft, LEDState sTopRight, LEDState sBottomLeft, LEDState sBottomRight);
    private:
		unsigned char m_SMCMessage[16];
		unsigned char m_SMCReturn[16];
		void PrepareBuffers();
};

#endif

