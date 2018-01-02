#ifndef __ROBOTIC__ELEMENT__H__
#define __ROBOTIC__ELEMENT__H__

#include "macros.h"
#include "Arduino.h"

class RoboticElement{

public:
	virtual void getState() = 0; // debe printear su estado en el Serial
//	virtual void setState() = 0; // debe recibir un parámetro por Serial y setear su estado
};

#endif