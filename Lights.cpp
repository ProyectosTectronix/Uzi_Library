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
 *     Implementación de clase Lights para funciones básicas de los LEDs RGB
 *   Utilizando la biblioteca de funciones de Adafruit
 */
#include "Lights.h"
#include <Adafruit_NeoPixel.h>

Lights::Lights(){
	num_pix = NUM_PIX;
	pin_RGB_front = RGB_LED_FRONT;
	pin_RGB_back = RGB_LED_BACK;
	brightness = BRIGHTNESS;
	leds_front = NULL;
	leds_back = NULL;
//	leds_RGB = NULL;
}

/*Lights::Lights(int num_pix, int pin_RGB, int brightness){
	this->num_pix = num_pix;
	this->pin_RGB = pin_RGB;
	this->brightness = brightness;
	leds_RGB = NULL;
	leds_front = NULL;
	leds_back = NULL;
}*/

Lights::~Lights(){
//	delete leds_RGB;
	delete leds_front;
	delete leds_back;
}

void Lights::init(){
	#if defined (__AVR_ATtiny85__)
  		if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
	#endif

	leds_front = new Adafruit_NeoPixel(num_pix, pin_RGB_front, NEO_GRB + NEO_KHZ800);
	leds_back = new Adafruit_NeoPixel(num_pix, pin_RGB_back, NEO_GRB + NEO_KHZ800);
	leds_front->begin();
	leds_back->begin();
	leds_front->show();
	leds_back->show();
}

void Lights::connection_standby(){
	for(int i=0; i<num_pix; i++){
		leds_front->setPixelColor(i, leds_front->Color(0, 150, 0)); // verde
		leds_back->setPixelColor(i, leds_back->Color(0, 150, 0));
		leds_front->show();
		leds_back->show();
		delay(1);
	}
}

void Lights::connected(){
	for(int i=0; i<num_pix; i++){
		leds_front->setPixelColor(i, leds_front->Color(0, 0, 150)); // Azul
		leds_back->setPixelColor(i, leds_back->Color(0, 0, 150)); // Azul
		leds_front->show();
		leds_back->show();
		delay(1);
	}
}

void Lights::disconnected(){
	for(int i=0; i<num_pix; i++){
		leds_front->setPixelColor(i, leds_front->Color(150, 0, 0)); // Azul
		leds_back->setPixelColor(i, leds_back->Color(150, 0, 0)); // Azul
		leds_front->show();
		leds_back->show();
		delay(1);
	}
}

void Lights::demo(){
	setColor(0, ROJO);     	// Enciende el LED 0 de color rojo
  	delay(250);                   // Espera 250 milisegundos
  	setColor(1, AMARILLO); 	// Enciende el LED 1 de color amarillo
  	delay(250);                   // Espera 250 milisegundos
  	setColor(2, VERDE);    	// Enciende el LED 2 de color verde
  	delay(250);                   // Espera 250 milisegundos
  	setColor(3, CIAN);     	// Enciende el LED 3 de color cian
  	delay(250);                   // Espera 250 milisegundos
  	setColor(0, AZUL);     	// Enciende el LED 0 de color azul
  	delay(250);                   // Espera 250 milisegundos
  	setColor(1, MAGENTA);  	// Enciende el LED 1 de color magenta
  	delay(250);                   // Espera 250 milisegundos
  	setColor(2, BLANCO);   	// Enciende el LED 2 de color blanco
  	delay(250);                   // Espera 250 milisegundos
  	setColor(3, NEGRO);    	// Apaga el LED 3
  	delay(250);
}

void Lights::setColor(int i, int red, int green, int blue){
	if(i < 4){
		if(i >= 2){
			//if(Serial){
				//String tmp = "";
				//Serial.println(tmp + "index rgb: \t\t" + i);
			//}
			leds_back->setPixelColor(i - 2, leds_back->Color(red, green, blue));
		}
		else{
			//if(Serial){
				//String tmp = "";
				//Serial.println(tmp + "index rgb: \t\t" + i);
			//}
			leds_front->setPixelColor(i, leds_front->Color(red, green, blue));
		}
	}
	else{
		//if(Serial){
			//String tmp = "";
			//Serial.println(tmp + "index rgb: \t\t" + i);
		//}
	}
	leds_front->show();
	leds_back->show();
	delay(1);
}

void Lights::setBrightness(int b){
	brightness = b;
	leds_front->setBrightness(brightness);
	leds_back->setBrightness(brightness);
}

int Lights::getColor(int n){
	uint32_t color = 	(n < 2)?(leds_front->getPixelColor(n)):
		   				(n < 4)?(leds_back->getPixelColor(n)):
		   				(0x0000);

	int tmp = 0;
	switch(color){
		case 0x0000 :
			tmp = BLACK;
			break;
		case 0x000F	:
			tmp = BLUE;
			break;
		case 0x00F0 :
			tmp = GREEN;
			break;
		case 0x00FF :
			tmp = CYAN;
			break;
		case 0x0F00 :
			tmp = RED;
			break;
		case 0x0F0F :
			tmp = MAGENTA_;
			break;
		case 0x0FF0 :
			tmp = YELLOW;
			break;
		case 0x0FFF :
			tmp = WHITE;
			break;
		default :
			tmp = BLACK;
			break;
	}
	return tmp;
}

void Lights::rainbow(){
	for(int i=0; i<256; i++){
    	setColor(3,255,i,0);
    	setColor(2,255,0,255-i);
    	setColor(0,i,0,255);
    	setColor(1,0,255-i,255);
    	delay(1);
  	}
  	for(int i=255; i>=0; i--){
    	setColor(3,i,255,0);
    	setColor(2,255,255-i,0);
    	setColor(0,255,0,i);
    	setColor(1,255-i,0,255);
    	delay(1);
  	}
  	for(int i=0; i<256; i++){
    	setColor(3,0,255,i);
    	setColor(2,255-i,255,0);
    	setColor(0,255,i,0);
    	setColor(1,255,0,255-i);
    	delay(1);
  	}
  	for(int i=255; i>=0; i--){
    	setColor(3,0,i,255);
    	setColor(2,0,255,255-i);
    	setColor(0,i,255,0);
    	setColor(1,255,255-i,0);
    	delay(1);
  	}
  	for(int i=0; i<256; i++){
    	setColor(3,i,0,255);
    	setColor(2,0,255-i,255);
    	setColor(0,0,255,i);
    	setColor(1,255-i,255,0);
    	delay(1);
  	}
  	for(int i=255; i>=0; i--){
    	setColor(3,255,0,i);
    	setColor(2,255-i,0,255);
    	setColor(0,0,i,255);
    	setColor(1,0,255,255-i);
    	delay(1);
  	}
}

void Lights::scary(){
	for(int i=0; i<num_pix; i++){
		leds_front->setPixelColor(i, leds_front->Color(50, 50, 50)); // gris
		leds_back->setPixelColor(i, leds_back->Color(50, 50, 50)); // gris
		leds_front->show();
		leds_back->show();
		delay(1);
	}
}

void Lights::happy(){
	for(int i=0; i<num_pix; i++){
		leds_front->setPixelColor(i, leds_front->Color(0, 150, 0)); // verde
		leds_back->setPixelColor(i, leds_back->Color(0, 150, 0)); // verde
		leds_front->show();
		leds_back->show();
		delay(1);
	}
}

void Lights::badboy(){
	for(int i=0; i<num_pix; i++){
		leds_front->setPixelColor(i, leds_front->Color(150, 0, 0)); // verde
		leds_back->setPixelColor(i, leds_back->Color(150, 0, 0)); // verde
		leds_front->show();
		leds_back->show();
		delay(1);
	}
}

void Lights::off(){
	for(int i=0; i<num_pix; i++){
		leds_front->setPixelColor(i, leds_front->Color(0, 0, 0)); // verde
		leds_back->setPixelColor(i, leds_back->Color(0, 0, 0)); // verde
		leds_front->show();
		leds_back->show();
		delay(1);
	}
}