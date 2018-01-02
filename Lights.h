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
 *   	Definicion de clase Lights para funciones básicas de los LEDs RGB
 *   Utilizando la biblioteca de funciones de Adafruit
 */
#ifndef _LIGHTS_H_
#define _LIGHTS_H_

#include "Arduino.h"
#include "macros.h"
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

class Lights{
public:
	Lights();
	~Lights();
	void init();
	void connection_standby();
	void connected();
	void disconnected();
	void setColor(int i, int red, int green, int blue);
	void setBrightness(int b);
	int getColor(int n);
	void demo();
//	void stop();
	void rainbow();
private:
	int num_pix;
	int brightness;
	int pin_RGB_front;
	int pin_RGB_back;
	Adafruit_NeoPixel *leds_front;
	Adafruit_NeoPixel *leds_back;
};
#endif