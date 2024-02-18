#include "smc.h"

//Below includes///////

int LedType = 0;
LEDState sTopLeft = OFF, 
	sTopRight = OFF, 
	sBottomLeft = OFF, 
	sBottomRight = OFF;

//////////////////////////
//Add some voids for quick function calling
//////////////////////////

void SetLedState(int Format)
{
	smc MySMC;
	MySMC.SetLEDS(GREEN,GREEN,GREEN,GREEN);
}   
void LedStateOff(int Format)
{
	smc MySMC;
	MySMC.SetLEDS(OFF,OFF,OFF,OFF);
}

////////////////////////////////
//In trainer ,Call void's with
//   SetLedState(NULL);
//   LedStateOff(NULL); 
//
// I added something like this under a cheat ,,or when loading trainer etc 
//
//  SetLedState(NULL);
//  Sleep(3000);
//  LedStateOff(NULL); 
//////////////////////////////


//////////////////////////////
//The colors can be set 
//to any combination of 
//RED, GREEN, ORANGE, and OFF.
//////////////////////////////
//There are 2 ways to allow more color combos 
//ex: all GREEN for enable and all RED for disable
//////////////////////////////
//Simply c&p your void and change it's call name 
//and the color combo it instructs to set
//ex: 
//void SetLedStateGreen(int Format)
//      {
//	smc MySMC;
//	MySMC.SetLEDS(GREEN,GREEN,GREEN,GREEN);
//      }   
//////////////////////////////
//and add another line to your smc.h public section to match
//void SetLedStateGreen(LEDState sTopLeft, LEDState sTopRight, LEDState sBottomLeft, LEDState sBottomRight);
/////////////////////////////
/////////////////////////////
//or just add the contents of your void in the trainer where you want it.
//ex:       smc MySMC;   MySMC.SetLEDS(RED,RED,RED,RED);           
/////////////////////////////