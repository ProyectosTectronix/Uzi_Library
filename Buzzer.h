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
	void init(); // "Uzi ON" sound .
	void r3d3(); // r2d2 of star wars sound.
	void uzi(); // word uzi sound.
	void happy(); // happy sound.
	void scary(); // scary sound.
	void tatan(); // 
	void car(); // car sound.
	int note(int nota, int octava);
	void sound(int nota, int octava, int delay);
	void sound(int frecuencia, int d);
private:
	int pin_buzzer;
};

#endif
