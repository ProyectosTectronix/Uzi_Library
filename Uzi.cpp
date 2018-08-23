//////////////////////////////////////////////////////////////////////
//                            TECTRONIX								//
//                 Software Library for UZI_line_follower->				//
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

#include "Arduino.h"
#include "Button.h"
#include "Buzzer.h"
//#include "Control_BLE_v2_0.h"
#include "Lights.h"
#include "Motor.h"
#include "Qre.h"
#include "Ultrasonic_UZI.h"
#include "Uzi.h"

Uzi::Uzi():Motor(){
	button1 = new Button(1);
	button2 = new Button(2);
	button3 = new Button(3);
	button4 = new Button(4);
	button5 = new Button(5);
	buzzer = new Buzzer();
	//ble = new Control_BLE();
	leds_RGB = new Lights();
	line_follower = new Qre();
	s_sonic = new Ultrasonic_UZI();

	umbral_sonic_cercano = SONIC_MIN; // por default son 3 cm segun datasheet
	umbral_sonic_lejano = SONIC_MAX; // por default son 3 metros segun datasheet
	time_prev = 0;

	reference = 0;
	line_pos = 0;
	error_p = 0;
	error_i = 0;
	error_d = 0;
	error_prev = 0;
	left_act = 0;
	right_act = 0;
	actuation = 0;
	saturation = 0;
	follower_velocity = 0;
	qres = NULL;
}

Uzi::~Uzi(){
	delete button1;
	delete button2;
	delete button3;
	delete button4;
	delete button5;
	delete buzzer;
	//delete ble;
	delete leds_RGB;
	delete line_follower;
	delete s_sonic;
}

void Uzi::init(){
	Motor::init();
	button1->init();
	button2->init();
	button3->init();
	button4->init();
	button5->init();
	buzzer->init();
	//ble->init();
	leds_RGB->init();
	line_follower->init();
	s_sonic->init();

	distancia_ob_izq = SONIC_MAX;
	distancia_ob_der = SONIC_MAX;
	time_prev = 0;

	reference = 3000;
	line_pos = 0;
	error_p = 0;
	error_i = 0;
	error_d = 0;
	error_prev = 0;
	left_act = 0;
	right_act = 0;
	actuation = 0;
	saturation = 250;
	follower_velocity = 100;
	return;
}

bool Uzi::isPressed(int b){
	switch(b){
		case 1 : {
			return button1->isPressed();
			break;
		}
		case 2 : {
			return button2->isPressed();
			break;
		}
		case 3 : {
			return button3->isPressed();
			break;
		}
		case 4 : {
			return button4->isPressed();
			break;
		}
		case 5 : {
			return button5->isPressed();
			break;
		}
		default : {
			return false;
			break;
		}
	}
	return false;
}

bool Uzi::isReleased(int b){
	switch(b){
		case 1 : {
			return button1->isReleased();
			break;
		}
		case 2 : {
			return button2->isReleased();
			break;
		}
		case 3 : {
			return button3->isReleased();
			break;
		}
		case 4 : {
			return button4->isReleased();
			break;
		}
		case 5 : {
			return button5->isReleased();
			break;
		}
		default : {
			return false;
			break;
		}
	}
	return false;
}

bool Uzi::isClicked(int b){
	switch(b){
		case 1 : {
			return button1->isClicked();
			break;
		}
		case 2 : {
			return button2->isClicked();
			break;
		}
		case 3 : {
			return button3->isClicked();
			break;
		}
		case 4 : {
			return button4->isClicked();
			break;
		}
		case 5 : {
			return button5->isClicked();
			break;
		}
		default : {
			return false;
			break;
		}
	}
	return false;
}

void Uzi::getState(int b){
	switch(b){
		case 1 : {
			return button1->getState();
			break;
		}
		case 2 : {
			return button2->getState();
			break;
		}
		case 3 : {
			return button3->getState();
			break;
		}
		case 4 : {
			return button4->getState();
			break;
		}
		case 5 : {
			return button5->getState();
			break;
		}
		default : {
			return false;
			break;
		}
	}
	return false;
}

void Uzi::r3d3(){
	buzzer->r3d3();
	return;
}

void Uzi::uzi(){
	buzzer->uzi();
	return;
}

void Uzi::happy(){
	leds_RGB->happy();
	buzzer->happy();
	return;
}

void Uzi::scary(){
	leds_RGB->scary();
	buzzer->scary();
	return;
}

void Uzi::tatan(){
	buzzer->tatan();
	return;
}

void Uzi::car(){
	buzzer->car();
	return;
}

void Uzi::barata(){
	buzzer->barata();
	return;
}

void Uzi::ranger(){
	buzzer->ranger();
	return;
}

void Uzi::march(){
	buzzer->march();
	return;
}

int Uzi::note(int nota, int octava){
	return buzzer->note(nota, octava);
}

void Uzi::sound(int nota, int octava, int delay){
	buzzer->sound(nota, octava, delay);
	return;
}

void Uzi::sound(int frecuencia, int d){
	buzzer->sound(frecuencia, d);
	return;
}

/*
void Uzi::updateStateBLEConection(bool Acknowledge){
	ble->updateStateBLEConection(Acknowledge);
	return;
}

void Uzi::updateStateMachine(){
	ble->updateStateMachine();
	return;
}

void Uzi::updateStateUZI(int data){
	ble->updateStateUZI(data);
	return;
}

void Uzi::updateStateDirection(int data){
	ble->updateStateDirection(data);
	return;
}

void Uzi::updateStateAction(int data){
	ble->updateStateAction(data);
	return;
}
*/
void Uzi::connection_standby(){
	leds_RGB->connection_standby();
	return;
}

void Uzi::connected(){
	leds_RGB->connected();
	return;
}

void Uzi::disconnected(){
	leds_RGB->disconnected();
	return;
}

void Uzi::setColor(int i, int red, int green, int blue){
	leds_RGB->setColor(i, red, green, blue);
	return;
}

void Uzi::setBrightness(int b){
	leds_RGB->setBrightness(b);
	return;
}

int Uzi::getColor(int n){
	return leds_RGB->getColor(n);
}

void Uzi::demo(){
	leds_RGB->demo();
	return;
}
/*
void Uzi::scary(){
	leds_RGB->scary();
	return;
}

void Uzi::happy(){
	leds_RGB->happy();
	return;
}
*/
void Uzi::badboy(){
	leds_RGB->badboy();
	return;
}

void Uzi::off(){
	leds_RGB->off();
	return;
}

void Uzi::rainbow(){
	leds_RGB->rainbow();
	return;
}

void Uzi::caribe(){
	leds_RGB->caribe();
	return;
}

void Uzi::power(){
	leds_RGB->power();
	return;
}

int *Uzi::read(){
	return line_follower->read();
}

void Uzi::reset(int pin){
	line_follower->reset(pin);
	return;
}

int Uzi::readLine(){
	return line_follower->readLine();
}

float Uzi::read(int sensor, int ignorar_medicion){
	return s_sonic->read(sensor, ignorar_medicion);
}

void Uzi::evasor(int evadir, int ignorar){
	int izq_medido = 0;
	int der_medido = 0;
	if( !((evadir < SONIC_MIN) || (evadir > ignorar) || (ignorar > SONIC_MAX)) ){ // llamado valido de la funcion
		der_medido = s_sonic->read(1, ignorar); // distancia al sensor de la izquierda
		delay(25);
		izq_medido = s_sonic->read(0, ignorar);

		izq_medido = (izq_medido == 0)?(ignorar):(izq_medido);
		der_medido = (der_medido == 0)?(ignorar):(der_medido);

		distancia_ob_izq = izq_medido*0.250 + distancia_ob_izq*0.750;
		distancia_ob_der = der_medido*0.250 + distancia_ob_der*0.750;

		if((distancia_ob_der == 0) || (distancia_ob_izq == 0)){
			Motor::forward(100);
		}
		else{
			if( (distancia_ob_izq <= evadir) && (distancia_ob_der > evadir) ) // objeto por la izquierda
				Motor::right(50,300);
			else if( (distancia_ob_izq > evadir) && (distancia_ob_der <= evadir) ) // objeto por la derecha
				Motor::left(50,300);
			else if( (distancia_ob_izq <= evadir) && (distancia_ob_der <= evadir) ) // objeto al frente
				Motor::left(50,600);
			else
				Motor::forward(100);
		}
	}
	else{
		Motor::stop(0);
	}
}

void Uzi::evasor_debug(int evadir, int ignorar){
	float izq_medido = 0;
	float der_medido = 0;
	String tmp = "";
	unsigned long time = millis();
	unsigned long interval = 200;
	if( !((evadir < SONIC_MIN) || (evadir > ignorar) || (ignorar > SONIC_MAX)) ){ // llamado valido de la funcion
		der_medido = s_sonic->read(1, ignorar);
		delay(25); // para evitar interferencia de pulsos emitidos y recibidos
		izq_medido = s_sonic->read(0, ignorar); // distancia al sensor de la izquierda

		izq_medido = (izq_medido == 0)?(ignorar):(izq_medido);
		der_medido = (der_medido == 0)?(ignorar):(der_medido);

		distancia_ob_izq = izq_medido*0.8 + distancia_ob_izq*0.2;
		distancia_ob_der = der_medido*0.8 + distancia_ob_der*0.2;

		if(time - time_prev >= interval){
			tmp = "";
			tmp += SONIC;
			tmp += " ";
			tmp += (int )distancia_ob_izq;
			tmp += " ";
			tmp += (int )distancia_ob_der;

			if((distancia_ob_izq < 10) && (distancia_ob_der < 10)){
				Serial.print(tmp + "/////////");
			}
			else if((distancia_ob_izq < 10) || (distancia_ob_der < 10)){
				Serial.print(tmp + "////////");
			}
			else{
				Serial.print(tmp + "///////");
			}
		}

		if((distancia_ob_der == 0) || (distancia_ob_izq == 0)){
			if(time - time_prev >= interval){
				tmp = "";
				tmp += MOTOR;
				tmp += " ";
				tmp += 100;
				tmp += " ";
				tmp += 100;

				Serial.print(tmp + "///////////");
				time_prev = time;
			}
			Motor::forward(100);
		}
		else{
			if( (distancia_ob_izq <= evadir) && (distancia_ob_der > evadir) ){ // objeto por la izquierda
				if(time - time_prev >= interval){
					tmp = "";
					tmp += MOTOR;
					tmp += " ";
					tmp += 100;
					tmp += " ";
					tmp += "-";
					tmp += 100;
				
					Serial.print(tmp + "////////////");
					time_prev = time;
				}
				Motor::right(100,300);
			}
			else if( (distancia_ob_izq > evadir) && (distancia_ob_der <= evadir) ){ // objeto por la derecha
				if(time - time_prev >= interval){
					tmp = "";
					tmp += MOTOR;
					tmp += " ";
					tmp += "-";
					tmp += 100;
					tmp += " ";
					tmp += 100;
				
					Serial.print(tmp + "////////////");
					time_prev = time;
				}
				Motor::left(100,300);
			}
			else if( (distancia_ob_izq <= evadir) && (distancia_ob_der <= evadir) ){ // objeto al frente
				if(time - time_prev >= interval){
					tmp = "";
					tmp += MOTOR;
					tmp += " ";
					tmp += 100;
					tmp += " ";
					tmp += "-";
					tmp += 100;
				
					Serial.print(tmp + "////////////");
					time_prev = time;
				}
				Motor::right(100,600);
			}
			else{
				if(time - time_prev >= interval){
					tmp = "";
					tmp += MOTOR;
					tmp += " ";
					tmp += 100;
					tmp += " ";
					tmp += 100;

					Serial.print(tmp + "///////////");
					time_prev = time;
				}
				Motor::forward(100);
			}
		}
		
	}
	else{
		if(time - time_prev >= interval){
			tmp = "";
			tmp += MOTOR;
			tmp += " ";
			tmp += 0;
			tmp += " ";
			tmp += 0;

			Serial.print(tmp + "///////////////");
			time_prev = time;
		}
		Motor::stop(0);
	}
}


void Uzi::seguidor(){
	unsigned long time = millis();
	unsigned long interval = 200;
	line_pos = line_follower->readLine();

	//medicion = (1000*qres[0] + 2000*qres[1] + 3000*qres[2] + 4000*qres[3] + 5000*qres[4])/(qres[0] + qres[1] +qres[2] + qres[3] + qres[5]);

	error_p = reference - line_pos;
	error_i += error_p;
	error_d = error_p - error_prev;

	error_prev = error_p;

	actuation = error_p*KP + error_i*KI + error_d*KD;

	actuation = (follower_velocity + actuation > saturation)?(saturation - follower_velocity):
              (follower_velocity - actuation > saturation)?(saturation - follower_velocity):
              (follower_velocity + actuation < -saturation)?(follower_velocity - saturation):
              (follower_velocity - actuation < -saturation)?(follower_velocity - saturation):
              (actuation);

    left_act = (follower_velocity - actuation < 0)?(0):(follower_velocity - actuation);
  	right_act = (follower_velocity + actuation < 0)?(0):(follower_velocity + actuation);

  	left_act = (left_act > follower_velocity)?(follower_velocity):(left_act);
  	right_act = (right_act > follower_velocity)?(follower_velocity):(right_act);
	
  	error_i = 	( (left_act >= (saturation - 1)) || (right_act >= (saturation - 1)) )?(0):
  				( (left_act <= 1) || (right_act <= 1) )?(0):
  				(error_i);

//  	String tmp = "";
//  	Serial.println(tmp + "actuacion:\t\t" + left_act + "\t\t" + right_act);
	Motor::differentialFWD(left_act, right_act);

	//---------- print display --------//

	if(time - time_prev >= interval){
	if(Serial){
		String tmp = "";
		tmp += MOTOR;
		tmp += " ";
		tmp += left_act;
		tmp += " ";
		tmp += right_act;
		if(left_act > 100 && right_act > 100){
			tmp += "///////////";
		}
		else if(left_act > 100 || right_act > 100){
			tmp += "////////////";
		}
		else if(left_act > 10 && right_act > 10){
			tmp += "/////////////";
		}
		else if(left_act > 10 || right_act > 10){
			tmp += "//////////////";
		}
		else {
			tmp += "///////////////";
		}
		Serial.print(tmp);

		tmp = "";
		tmp += QRE;
		tmp += " ";
		if(line_pos < 1000){
			tmp += "0 0 0 0 0";
		}
		else if(line_pos < 1500){
			tmp += "1 0 0 0 0";
		}
		else if(line_pos < 2000){
			tmp += "1 1 0 0 0";
		}
		else if(line_pos < 2500){
			tmp += "0 1 0 0 0";
		}
		else if(line_pos < 3000){
			tmp += "0 1 1 0 0";
		}
		else if(line_pos < 3500){
			tmp += "0 0 1 0 0";
		}
		else if(line_pos < 4000){
			tmp += "0 0 1 1 0";
		}
		else if(line_pos < 4500){
			tmp += "0 0 0 1 0";
		}
		else if(line_pos < 5000){
			tmp += "0 0 0 1 1";
		}
		else if(line_pos < 5500){
			tmp += "0 0 0 0 1";
		}
		else{
			tmp += "1 1 1 1 1";
		}
		tmp += "/////////";
		Serial.print(tmp);
		time_prev = time;
	}
	}

}

void Uzi::maze(){
  static int count___ = 0;
  qres = line_follower->read();  
  if((qres[0] == 0) && (qres[1] == 0) && (qres[2] == 0) && (qres[3] == 0) && (qres[4] == 0)){ // si estoy en lo blanco
    //count___++;
    //if(count___ <= 100) return;
    count___ = 0;
    Motor::forward(50);
    delay(250);
    Motor::stop();
    Motor::left(50,800);
    Motor::stop();
    qres = line_follower->read();
    if((qres[0] == 1) || (qres[1] == 1) || (qres[2] == 1) || (qres[3] == 1) || (qres[4] == 1)){ //si a la izquierda hay línea
      Motor::backward(50); //me posiciono en la línea.
      delay(400);
      Motor::stop();
      return;
    }
    else{
      Motor::right(50,800); // busco línea al frente
      Motor::stop();
      qres = line_follower->read();
      if((qres[0] == 1) || (qres[1] == 1) || (qres[2] == 1) || (qres[3] == 1) || (qres[4] == 1)){ // si hay línea al frente
        Motor::backward(50);
        delay(400);
        Motor::stop();
        return;
      }
      else{
        Motor::right(50,800); // busco línea a la derecha
        Motor::stop();
        qres = line_follower->read();
        if((qres[0] == 1) || (qres[1] == 1) || (qres[2] == 1) || (qres[3] == 1) || (qres[4] == 1)){ // si hay línea a la derecha
          Motor::backward(50);
          delay(400);
          Motor::stop();
          return;
        }
        else{
          Motor::right(50,800); // giro a la derecha
          Motor::stop();
          return;
        }
      }
    }
  }
  else if((qres[0] == 1) && (qres[1] == 1) && (qres[2] == 1) && (qres[3] == 1) && (qres[4] == 1)){
  	count___++;
    if(count___ >= 10){
    	Motor::stop();
    	march();
    	delay(5000);
    	return;
    }
    //count___ = 0;
  	Motor::forward(30);
  	delay(10);
  }
  else if( ((qres[0] == 1) && (qres[1] == 1) && (qres[2] == 1) && (qres[3] == 0) && (qres[4] == 0)) || ((qres[0] == 1) && (qres[1] == 1) && (qres[2] == 1) && (qres[3] == 1) && (qres[4] == 0)) ){
    count___ = 0;
    Motor::forward(50);
    delay(250);
    Motor::stop();
    Motor::left(50,800);
    Motor::stop();
    qres = line_follower->read();
    if((qres[0] == 1) || (qres[1] == 1) || (qres[2] == 1) || (qres[3] == 1) || (qres[4] == 1)){ //si a la izquierda hay línea
      Motor::backward(50); //me posiciono en la línea.
      delay(400);
      Motor::stop();
      return;
    }
    else{
      Motor::right(50,800); // giro a la derecha
      Motor::stop();
      return;
    }
  }
  else if( (qres[0] == 1) ){ // si la linea está al extremo izquierdo
  	count___ = 0;
    Motor::differentialFWD(60,80);
    return;
  }
  else if( (qres[4] == 1) ){ // si la línea está en el extremo derecho
  	count___ = 0;
    Motor::differentialFWD(80,60);
    return;
  }
  else if( (qres[1] == 1) ){
  	count___ = 0;
    Motor::differentialFWD(70,80);
    return;
  }
  else if( (qres[3] == 1) ){
  	count___ = 0;
    Motor::differentialFWD(80,70);
    return;
  }
  else if( (qres[2] == 1) ){ // si hay línea al medio, avanzo.
  	count___ = 0;
    Motor::forward(100);
    return;
  }
  else{
    count___ = 0;
  }
  delay(1);
}