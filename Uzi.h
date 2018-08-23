//////////////////////////////////////////////////////////////////////
//                            TECTRONIX								//
//                 Software Library for UZI_ROBOT					//
//                             Enjoy!								//
//////////////////////////////////////////////////////////////////////

/**
 * @author : Diego Pandolfa
 *
 * @company : Tectronix SpA.
 *
 * @date : december 2016
 * @edited : august 2018
 *
 * @description : 
 */
#ifndef _UZI_H_
#define _UZI_H_

#include "Arduino.h"
#include "Button.h"
#include "Buzzer.h"
//#include "Control_BLE_v2_0.h"
#include "Lights.h"
#include "Motor.h"
#include "Qre.h"
#include "Ultrasonic_UZI.h"

#define SONIC_MAX 300
#define SONIC_MIN 3

//class Control_BLE;

class Uzi : public Motor{
public:
	Uzi(); // ok
	~Uzi(); // ok
	void init(); // ok

	bool isPressed(int b); // ok
	bool isReleased(int b); // ok
	bool isClicked(int b); // ok
	void getState(int b); // ok

	void r3d3(); // sonido de arturi3 // ok
	void uzi(); // vocalización de la palabra UZI // ok
	void happy(); // expresion como la de Wall-i
	void scary(); // expresion como la de Wall-i
	void tatan(); // sonido  "TATAN"!
	void car();
	void barata();
	void ranger();
	void march();
	int note(int nota, int octava);
	void sound(int nota, int octava, int delay);
	void sound(int frecuencia, int d);
/*
	void updateStateBLEConection(bool Acknowledge);
	void updateStateMachine();
	void updateStateUZI(int data);
	void updateStateDirection(int data);
	void updateStateAction(int data);
*/
	void connection_standby();
	void connected();
	void disconnected();
	void setColor(int i, int red, int green, int blue);
	void setBrightness(int b);
	int getColor(int n);
	void demo();
	//void scary();
	//void happy();
	void badboy();
	void off();
	void rainbow();
	void caribe();
	void power();

	int *read();
	void reset(int pin);
	int readLine();

	float read(int sensor, int ignorar_medicion);

	void evasor(int evadir, int ignorar);
	void evasor_debug(int evadir, int ignorar);
	void seguidor();
	void seguidor_debug();
	void maze();

private:
	//listar sensores conectados
	Button *button1;
	Button *button2;
	Button *button3;
	Button *button4;
	Button *button5;
	Buzzer *buzzer; // puntero referencia a un objeto instancia de Buzzer
	//Control_BLE *ble;
	Lights *leds_RGB; // puntero referencia a un objeto instancia de Lights
	Qre *line_follower; //puntero referencia a un objeto instacia de Qre
	Ultrasonic_UZI *s_sonic; //puntero referencia a un objeto instancia de Ultrasonic_UZI

	int umbral_sonic_cercano; // deterina cuando un objeto está lo suficientemente cerca para esquivarlo
	int umbral_sonic_lejano; // determina cuando un objeto está lo suficientemente lejano como para ignorarlo
	float distancia_ob_izq; // distancia al objeto más cercano por la izquierda
	float distancia_ob_der; // distancia al objeto más cercano por la derecha
	
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
	int *qres; // arreglo de las lecturas del Qre
};

#endif