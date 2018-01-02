//////////////////////////////////////////////////////////////////////
//                            TECTRONIX								//
//                 Software Library for UZI_ROBOT					//
//                             Enjoy!								//
//////////////////////////////////////////////////////////////////////
#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "RoboticElement.h"

class Button:public RoboticElement{
public:
	Button();
	Button(int sw);
	~Button();
	void init();
	bool isPressed();
	bool isReleased();
	bool isClicked();
	void getState();
private:
	int pin_button;
	bool state_button;
	int num_button;
	int threshold_high;
	int threshold_low;
};

#endif
