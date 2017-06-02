#ifndef _QRE_H_
#define _QRE_H_

#include "Arduino.h"
#include "macros.h"

class Qre{
public:
	Qre();
	~Qre();
	void init();
	int *read();
	void reset(int pin);
	int readLine();
private:
	int pinQreI;
	int pinQreIC;
	int pinQreC;
	int pinQreDC;
	int pinQreD;
	int *array_qre;
	int *data_qre;
	int line;
};

#endif