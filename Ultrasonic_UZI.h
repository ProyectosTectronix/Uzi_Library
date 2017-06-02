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
 * @date : december 2016
 *
 * @description : 
 *     Definición de clase Ultrasonic_UZI para utilización del sensor ultrasónico
 *   que viene por defecto con el robot. 
 */
#ifndef _ULTRASONIC_UZI_H_
#define _ULTRASONIC_UZI_H_

#include "Arduino.h"
#include "macros.h"

class Ultrasonic_UZI{
public:
	Ultrasonic_UZI();
	Ultrasonic_UZI(int left_t, int left_e, int right_t, int right_e);
	~Ultrasonic_UZI();
	void init();
	float read(int sensor, int ignorar_medicion);
	
private:
	int trigL;
	int echoL;
	int trigR;
	int echoR;
};

#endif