#include "Button.h"

Button::Button(){
	pin_button = BUTTONS;
	state_button = false;
	num_button = 0;
	threshold_high = 1023;
	threshold_low = 0;
}

Button::Button(int sw){
	pin_button = BUTTONS;
	state_button = false;
	num_button = sw;
	threshold_high = 1023;
	threshold_low = 0;
}

Button::~Button(){

}
void Button::init(){
	switch(num_button){
		case 1 :
			threshold_low = THR_LOW_S1;
			threshold_high = THR_HIGH_S1;
			break;
		case 2 :
			threshold_low = THR_LOW_S2;
			threshold_high = THR_HIGH_S2;
			break;
		case 3 :
			threshold_low = THR_LOW_S3;
			threshold_high = THR_HIGH_S3;
			break;
		case 4 :
			threshold_low = THR_LOW_S4;
			threshold_high = THR_HIGH_S4;
			break;
		case 5 :
			threshold_low = THR_LOW_S5;
			threshold_high = THR_HIGH_S5;
			break;
		default :
			threshold_low = 0;
			threshold_high = 1023;
			break;
	}
	state_button = false;
}
bool Button::isPressed(){
	int tmp = analogRead(pin_button);
	if((tmp >= threshold_low) && (tmp <= threshold_high)){
		return true;
	}
	else{
		return false;
	}
}

bool Button::isRelease(){
	int tmp = analogRead(pin_button);
	if((tmp >= threshold_low) && (tmp <= threshold_high)){
		return false;
	}
	else{
		return true;
	}
}

bool Button::isClicked(){
	if(this->isPressed()){
		while(this->isPressed());
		return true;
	}
	else {
		return false;
	}
}