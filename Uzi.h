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
 */
#ifndef _UZI_H_
#define _UZI_H_

#include "Arduino.h"
#include "macros.h"
#include "Motor.h"
#include "Ultrasonic_UZI.h"
#include "Lights.h"
#include "Buzzer.h"
#include "Qre.h"

#define SONIC_MAX 300
#define SONIC_MIN 3

class Uzi : public Motor{
public:
	Uzi();
	~Uzi();
	void init();
	void evasor(int evadir, int ignorar);
	void evasor_debug(int evadir, int ignorar);
	void seguidor();
	void seguidor_debug();

private:
	//listar sensores conectados
	Ultrasonic_UZI *s_sonic; //puntero referencia a un objeto instancia de Ultrasonic_UZI
	Qre *line_follower; //puntero referencia a un objeto instacia de Qre
	int umbral_sonic_cercano; // deterina cuando un objeto está lo suficientemente cerca para esquivarlo
	int umbral_sonic_lejano; // determina cuando un objeto está lo suficientemente lejano como para ignorarlo
	float distancia_ob_izq; // distancia al objeto más cercano por la izquierda
	float distancia_ob_der; // distancia al objeto más cercano por la derecha
	Lights *leds_RGB; // puntero referencia a un objeto instancia de Lights
	Buzzer *buzzer; // puntero referencia a un objeto instancia de Buzzer;
	unsigned long time_prev;

	int reference;
	int line_pos;
	int error_p;
	int error_i;
	int error_d;
	int error_prev;
	int left_act;
	int right_act;
	int actuation;
	int saturation;
	int follower_velocity; // velocidad del seguidor de lineas
};

#endif