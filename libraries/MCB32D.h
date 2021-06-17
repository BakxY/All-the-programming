/*---------------------------------------
* Library:  MCB32D.h					*
* Autor:    S.Sprenger & A.Hofmann		*
* Date:     08.04.2021					*
* Revision: 17.06.2021 / AH				*
* Dep:      b4 microcontrollers			*
* uC:       STM32F107VC					*
----------------------------------------*/

/*---------------------------------------
* Revision history
-----------------------------------------
* Revision 10.06.2021 / AH
* Added variable names on functions
* Revision 17.06.2021 / AH
* Visual cleanup of functions
* Simplification of functions
* Comments -> explaining variables
* MCB32D_InitLED function
----------------------------------------*/

//The "TouchP0P1.h" is required

/*--------------DEFINE------------------*/
#ifndef MCB32D_H
#define MCB32D_H

/*--------------PROTOTYPES--------------*/
int iReadPin(int iPin);												//Prototype for ReadPin function, iPin -> selected pin of input port
int iEdgeDet(int* piStatusOld, int* piStatusNew, int iEdgeType);	//Prototype for EdgeDet function, piStatusOld -> old button state, piStatusNew -> new button state, iEdgeType -> for which edge to check 0 = NEG / 1 = POS
void vReadPort(int iStatusArray[8]);								//Prototype for ReadPort function, iStatusArray -> array in which the values are stored
int iBlinkLED(int iOn, int iOff, int* piTimer);						//Prototype for BlinkLED function, iOn -> on period, iOff -> off period, piTimer -> Timer for blinking LED
void vSendPort(int iStatusArray[8]);								//Prototype for SendPort function, iStatusArray -> array from which the values are read
void vClearArray(int iStatusArray[8]);								//Prototype for ClearPort function, iStatusArray -> array which is set to 0x00
void MCB32D_InitLED(void);											//Prototype for MCB32D_InitLED function
#endif
