#ifndef _BUTTON_H_
#define _BUTTON_H_

#include "macros.h"
#include "Arduino.h"

class Button{
public:
	Button();
	Button(int sw);
	~Button();
	void init();
	bool isPressed();
	bool isRelease();
	bool isClicked();
private:
	int pin_button;
	bool state_button;
	int num_button;
	int threshold_high;
	int threshold_low;
};

#endif