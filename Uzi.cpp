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

#include "Arduino.h"
#include "macros.h"
#include "Motor.h"
#include "Ultrasonic_UZI.h"
#include "Uzi.h"

Uzi::Uzi():Motor(){
	s_sonic = new Ultrasonic_UZI();
	line_follower = new Qre();
	leds_RGB = new Lights();
	buzzer = new Buzzer();
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
}

Uzi::~Uzi(){
	delete s_sonic;
	delete line_follower;
	delete leds_RGB;
	delete buzzer;
}

void Uzi::init(){
	Motor::init();
	s_sonic->init();
	line_follower->init();
	leds_RGB->init();
	buzzer->init();
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
	follower_velocity = 50;
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

		distancia_ob_izq = izq_medido*0.2 + distancia_ob_izq*0.8;
		distancia_ob_der = der_medido*0.2 + distancia_ob_der*0.8;

		if((distancia_ob_der == 0) || (distancia_ob_izq == 0)){
			Motor::forward(100);
		}
		else{
			if( (distancia_ob_izq <= evadir) && (distancia_ob_der > evadir) ) // objeto por la izquierda
				Motor::right(50,200);
			else if( (distancia_ob_izq > evadir) && (distancia_ob_der <= evadir) ) // objeto por la derecha
				Motor::left(50,200);
			else if( (distancia_ob_izq <= evadir) && (distancia_ob_der <= evadir) ) // objeto al frente
				Motor::left(50,300);
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
	unsigned long interval = 100;
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
			tmp += distancia_ob_izq;
			tmp += " ";
			tmp += distancia_ob_der;

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
				Motor::right(100,0);
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
				Motor::left(100,0);
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
				Motor::right(100,0);
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
	
  	error_i = 	( (left_act >= (saturation - 1)) || (right_act >= (saturation - 1)) )?(0):
  				( (left_act <= 1) || (right_act <= 1) )?(0):
  				(error_i);

  	String tmp = "";
  	Serial.println(tmp + "actuacion:\t\t" + left_act + "\t\t" + right_act);
	Motor::differentialFWD(left_act, right_act);
}