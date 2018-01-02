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
#ifndef _BUZZER_H_
#define _BUZZER_H_

class Buzzer{
public:
	Buzzer();
	~Buzzer();
	void init(); // sonido de encendido.
	void r3d3(); // sonido de arturi3
	void uzi(); // vocalización de la palabra UZI
	void happy(); // expresion como la de Wall-i
	void scary(); // expresion como la de Wall-i
	void tatan(); // sonido  "TATAN"!
	void car();
	int note(int nota, int octava);
	void sound(int nota, int octava, int delay);
	void sound(int frecuencia, int d);
private:
	int pin_buzzer;
};

#endif