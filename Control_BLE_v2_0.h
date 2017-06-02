//////////////////////////////////////////////////////////////////////
//                            TECTRONIX								//
//                 Software Library for UZI_ROBOT					//
//                             Enjoy!								//
//////////////////////////////////////////////////////////////////////

/**
 * @author : Diego Pandolfa
 *
 * @company : Tectronix
 *
 * @date : january 2017
 *
 * @version : 2.0
 *
 * @description : 
 *   Definicion de clase Control_BLE_2.0 para comandar el robot usando nuestra aplicación
 *	móvil.
 */
#ifndef _CONTROL_BLE_v2_0_
#define _CONTROL_BLE_v2_0_

#include "Arduino.h"
#include "macros.h"
#include "Motor.h"
#include "Ultrasonic_UZI.h"
#include "Uzi.h"
#include "Lights.h"
#include "Buzzer.h"

class Control_BLE{
public:
	Control_BLE();
	~Control_BLE();
	void init();
	void updateStateBLEConection(bool Acknowledge);
	void updateStateMachine();
	void updateStateUZI(int data);
	void updateStateDirection(int data);
	void updateStateAction(int data);

private:
	int state_connection;
	int state_machine;
	int state_uzi;
	int state_direction;
	int velocity;
	Uzi *robot;
	Lights *leds_RGB;
	Buzzer *buzzer;
};

#endif