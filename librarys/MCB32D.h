/*-----------------------------------
* Library:  MCB32D.h				*
* Autor:    Severin Sprenger		*
* Date:     08.04.2021				*
* Dep:      b4 microcontrollers		*
* uC:       STM32F107VC				*
------------------------------------*/

//The "TouchP0P1.h" is required

/*--------------Define--------------*/
#ifndef MCB32D_H
#define MCB32D_H


int ReadPin(int);						//Prototype for ReadPin function
int EdgeDet(int*, int*, int);			//Prototype for edge detection function
void ReadPort(int*);					//Prototype for ReadPort function
int BlinkLED(int, int, int*);			//Prototype for BlinkLED function
void SendPort(int*);					//Prototype for SendPort function
void ClearArray(int*);					//Prototype for ClearPort function
#endif
