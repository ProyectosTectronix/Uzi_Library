#include "Qre.h"

Qre::Qre(){
	array_qre = new int[5];
	array_qre[0] = pinQreI = QREI;
	array_qre[1] = pinQreIC = QREIC;
	array_qre[2] = pinQreC = QREC;
	array_qre[3] = pinQreDC = QREDC;
	array_qre[4] = pinQreD = QRED;
	data_qre = new int[5];
	line = 0;
}

Qre::~Qre(){

}

void Qre::init(){
	pinMode(pinQreI, INPUT);
	pinMode(pinQreIC, INPUT);
	pinMode(pinQreC, INPUT);
	pinMode(pinQreDC, INPUT);
	pinMode(pinQreD, INPUT);
	delay(1);
}

void Qre::reset(int pin){
	pinMode(pin, OUTPUT);
	digitalWrite(pin, HIGH);
	delay(3);
	digitalWrite(pin, LOW);
	pinMode(pin, INPUT);
	//delay(5);
}

int *Qre::read(){
	for(int i=0; i<5; i++){
		reset(array_qre[i]);
		if(i == 0){
			delay(6);
		}
		else if( i == 1){
			delay(4);
		}
		else if(i == 2){
			delay(3);
		}
		else if(i == 3){
			delay(4);
		}
		else if( i == 4){
			delay(6);
		}
		else{
			delay(5);
		}
		data_qre[i] = (digitalRead(array_qre[i]) == HIGH)?(1):(0);
	}
	return data_qre;
}

int Qre::readLine(){
	int q1=0, q2=0, q3=0, q4=0, q5=0;
	int sensores = 0;
	int medicion = 0;
	String tmp = "";
	this->read();

/*	for(int i=0; i<5; i++){
    	Serial.print(tmp + "qre[" + i + "] : " + data_qre[i] + "\t\t");  
  	}
  	Serial.println();
*/
  	q1 = (int )data_qre[0];
  	q2 = (int )data_qre[1];
  	q3 = (int )data_qre[2];
  	q4 = (int )data_qre[3];
  	q5 = (int )data_qre[4];

  	tmp = "";
	sensores = (int)(q1 + q2 + q3 + q4 + q5);
//	Serial.println(tmp + "sensores:\t\t" + sensores);

	medicion = (int)(q1*1000 + q2*2000 + q3*3000 + q4*4000 + q5*5000);
//	Serial.println(tmp + "medicion:\t\t" + medicion);

	line = (int)(sensores == 0)?(0):(medicion/(sensores));
//	Serial.println(tmp + "linea:\t\t" + line);
	return line;
}
