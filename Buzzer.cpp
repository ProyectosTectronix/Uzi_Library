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
 *     Implementation of the Buzzer Class, in this class 
 *   the robot get emotions whith diferents sounds
 *   for diferent cases.
 */
#include "Arduino.h"
#include "macros.h"
#include "Buzzer.h"

/**
 * @function : Buzzer()
 *
 * @param : none
 *
 * @return : none
 *
 * @description : 
 * Is it assigned the pin where is connect the buzzer
 */
Buzzer::Buzzer(){
  pin_buzzer = PIN_BUZZER;
}

/**
 * @function : ~Buzzer()
 *
 * @param : none
 *
 * @return : none 
 * 
 * @description :
 *Destructor. In this moment dont needed memory whence is not necessary 
 *release it
 */
Buzzer::~Buzzer(){

}

/**
 * @function : void init()
 *
 * @param : none
 *
 * @return : none
 *
 * @description :
 * Play a pure sound of 440 Hz for test the buzzer. 
 */
void Buzzer::init(){
  tone(pin_buzzer,440,500);
  delay(500);
}

/**
 * @function : void r3d3()
 *
 * @param : none
 *
 * @return : none
 *
 * @description :
 * play a sound like 2d2d of the movie star wars.
 */
void Buzzer::r3d3(){
  	int f = 0;
  	for(int i=0; i<30; i++){
      	f = 100*exp(i/6.67);
      	tone(pin_buzzer,f,10);
      	delay(10);
  	}
  	f = 9000;
  	tone(pin_buzzer,f,200);
  	delay(200);
 	 for(int i=0; i<40; i++){
     	f = 9000*exp(-1*i/8.89);
      	tone(pin_buzzer,f,10);
     	delay(10);
 	}
  	tone(pin_buzzer,40000,50);
  	delay(50);
  	for(int i=0; i<100; i++){
      	f = ((1+cos((2*3.14/12)*i))/2)*(1000 + 20*i);
      	tone(pin_buzzer,f,1);
      	delay(1);
  	}
  	tone(pin_buzzer,40000,20);
  	delay(20);
  	for(int i=0; i<80; i++){
      	f = ((1+cos((2*3.14/12)*i))/2)*(3000 + 18.75*i);
      	tone(pin_buzzer,f,1);
      	delay(1);
  	}
  	tone(pin_buzzer,40000,30);
  	delay(30);
  	for(int i=0; i<80; i++){
      	f = ((1+cos((2*3.14/12)*i))/2)*(8000);
      	tone(pin_buzzer,f,1);
      	delay(1);
  	}
  	tone(pin_buzzer,40000,20);
  	delay(20);
  	for(int i=0; i<200; i++){
      	f = ((1+cos((2*3.14/12)*i))/2)*(8000);
      	tone(pin_buzzer,f,1);
      	delay(1);
  	}
  	tone(pin_buzzer,40000,80);
  	delay(80);
  	for(int i=0; i<80; i++){
      	f = ((1+cos((2*3.14/16)*i))/2)*(4700);
      	tone(pin_buzzer,f,1);
      	delay(1);
  	}
  	tone(pin_buzzer,40000,20);
  	delay(20);

  	tone(pin_buzzer,1500,110);
  	delay(110);
  
  	tone(pin_buzzer,2500,30);
  	delay(30);

  	tone(pin_buzzer,2000,110);
  	delay(110);

  	tone(pin_buzzer,40000,40);
  	delay(40);

  	tone(pin_buzzer,3000,110);
  	delay(110);

  	tone(pin_buzzer,1500,110);
  	delay(110);
}

/**
 * @function : void uzi()
 *
 * @param : none
 *
 * @return : none
 *
 * @description :
 *  tried to play the word "UZI", but the results doesnt the expected.  
 *  this will be fixed soon.
 */
void Buzzer::uzi(){
	int f = 0;
	for(int i=0; i<100; i++){
    	f = (1+0.2*sin(2*3.141592*i/8))*4000;
    	tone(pin_buzzer,f,1);
    	delay(1);
  	}
}

/**
 * @function : void happy()
 *
 * @param : none
 *
 * @return : none
 *
 * @description :
 *  Play a happy sound.
 */
void Buzzer::happy(){
	for(int i=0; i<500; i++){
    	tone(pin_buzzer,440 + 8*i,4);
    	delay(1);
  	}
  	for(int i=0; i<500; i++){
    	tone(pin_buzzer,4440 - 8*i,4);
    	delay(1);
  	}
  	tone(pin_buzzer,2220,100);
  	delay(200);
  	tone(pin_buzzer,4440,100);
  	delay(200);
  	tone(pin_buzzer,6660,100);
  	delay(100);
}

/**
 * @function : void scary()
 *
 * @param : none
 *
 * @return : none
 *play a scary sound.
 * @
 */
void Buzzer::scary(){
	double x = 0;
	int f = 0;
	for(int i=0; i<1000; i++){
    	x = i - 500;
    	f = 10000*exp(-x*x/10000);
    	tone(pin_buzzer,f,2);
    	delay(1);
  	}
}

/**
 * @function : void tatan()
 *
 * @param : none
 *
 * @return : none
 *
 * @description :
 *  Play a "successfull" sound. 
 */
void Buzzer::tatan(){
	tone(pin_buzzer,440,100);
  	delay(200);
  	tone(pin_buzzer,440,700);
  	delay(700);
}

/**
 * @function : void car()
 *
 * @param : none
 *
 * @return : none
 *
 * @description :
 * Play a "car beginning" sound.  
 */
void Buzzer::car(){
	int f = 0;
	for(int i=0; i<1000; i++){
    	f = (1+sin(2*3.141592*i/(20-0.012*i)))*250*(1 + 0.003*i);
    	tone(pin_buzzer,f,1);
    	delay(1);
  	}
  	for(int i=0; i<100; i++){
    	f = (1+sin(2*3.141592*i/(12)))*250*(1 + 3);
    	tone(pin_buzzer,f,1);
   		delay(1);
  	}
  	for(int i=0; i<500; i++){
    	f = (1+sin(2*3.141592*i/(12+0.016*i)))*250*(4 - 0.006*i);
    	tone(pin_buzzer,f,1);
    	delay(1);
  	}
  	for(int i=0; i<2000; i++){
    	f = (1+sin(2*3.141592*i/(20)))*250*(1+0.1*sin(2*3.141592*i/100));
    	tone(pin_buzzer,f,1);
    	delay(1);
  	}
}

int Buzzer::note(int nota, int octava){
  return 440.0*exp(((octava-4.0)+(nota-10.0)/12.0)*log(2.0)/log(2.7172));
}

void Buzzer::sound(int nota, int octava, int d){
  int frec = note(nota, octava);
  tone(pin_buzzer, frec, d);
  delay(d);
}

void Buzzer::sound(int frecuencia, int d){
	tone(pin_buzzer, frecuencia, d);
	delay(d);
}
