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
 *   Implementación de clase Motor para funciones basicas del robot
 */
#include "Arduino.h"
#include "macros.h"
#include "Motor.h"

/**
 * @function : Motor()
 *
 * @param : none
 *
 * @return : none
 *
 * @description :
 *     Constructor por defecto, sólo inicializa con valores por defecto los atributos del Motor
 */
Motor::Motor(){
	velocidad_min = 0;
	velocidad_max = 250;
	standby_pin = STAND_BY_MOTOR;
	motor_A_pin = MOTOR_A;
	motor_B_pin = MOTOR_B;
	motor_A_PWM_pin = PWM_MOTOR_A;
	motor_B_PWM_pin = PWM_MOTOR_B;
	pinMode(standby_pin, OUTPUT);
  	pinMode(motor_A_pin, OUTPUT);
  	pinMode(motor_B_pin, OUTPUT);
  	pinMode(motor_A_PWM_pin, OUTPUT);
  	pinMode(motor_B_PWM_pin, OUTPUT);
  	digitalWrite(standby_pin, LOW); // se inicializa en LOW por seguridad
}

/**
 * @function : Motor(int vel_min, int vel_max)
 *
 * @param vel_min : velocidad minima del motor. Los valores van desde 0 a 255;
 *
 * @param vel_max : velocidad máxima del motor. Los valores van desde 0 a 255;
 *
 * @return : none
 *
 * @description :
 *     Constructor, sólo inicializa las velocidades minimas y maximas del robot,
 *   los demas atributos quedan con valores por defecto, además asigna los pines.
 */
Motor::Motor(int vel_min, int vel_max){
	velocidad_min = vel_min;
	velocidad_max = vel_max;
	standby_pin = STAND_BY_MOTOR;
	motor_A_pin = MOTOR_A;
	motor_B_pin = MOTOR_B;
	motor_A_PWM_pin = PWM_MOTOR_A;
	motor_B_PWM_pin = PWM_MOTOR_B;
	pinMode(standby_pin, OUTPUT);
  	pinMode(motor_A_pin, OUTPUT);
  	pinMode(motor_B_pin, OUTPUT);
  	pinMode(motor_A_PWM_pin, OUTPUT);
  	pinMode(motor_B_PWM_pin, OUTPUT);
  	digitalWrite(standby_pin, LOW); // se inicializa en LOW por seguridad
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Motor::~Motor(){
//
} /* <------------------------------Destructor: por el momento no se pide memoria al sistema, //
//					en caso de reservar memoria con malloc() o new() implemetar el destructor pertinente.*/   //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @function : void init()
 *
 * @param : none
 *
 * @return : none
 *
 * @description :
 *     inicializa el Motor levantanto el pin standby_pin.
 */
void Motor::init(){
	digitalWrite(standby_pin,HIGH);
}

/**
 * @function : void differentialFWD(int v_ml, int v_mr)
 *
 * @param v_ml : velocidad del motor izquierdo.
 *
 * @param v_mr : velocidad del motor derecho.
 *
 * @return : none
 *
 * @description :
 *     Permite que los motores operen a velocidades distintas avanzando hacia adelante.
 */
void Motor::differentialFWD(int v_ml, int v_mr){
	if(v_ml < velocidad_min)
		v_ml = velocidad_min;
	else if(v_ml > velocidad_max)
		v_ml = velocidad_max;
	else
		v_ml = v_ml;

	if(v_mr < velocidad_min)
		v_mr = velocidad_min;
	else if(v_mr > velocidad_max)
		v_mr = velocidad_max;
	else
		v_mr = v_mr;
	digitalWrite(motor_A_pin, LOW);
  	digitalWrite(motor_B_pin, LOW);
  	analogWrite(motor_A_PWM_pin, v_mr);
  	analogWrite(motor_B_PWM_pin, v_ml);
}

/**
 * @function : void forward(int v_fwd)
 *
 * @param v_fwd : velocidad del avance de los motores
 *
 * @return : none
 *
 * @description :
 *     El robot avanza hacia adelante con velocidad v_fwd
 */
void Motor::forward(int v_fwd){
	if(v_fwd < velocidad_min)
		v_fwd = velocidad_min;
	else if(v_fwd > velocidad_max)
		v_fwd = velocidad_max;
	else 
		v_fwd = v_fwd;

  	digitalWrite(motor_A_pin, LOW);
  	digitalWrite(motor_B_pin, LOW);
  	analogWrite(motor_A_PWM_pin, v_fwd);
  	analogWrite(motor_B_PWM_pin, v_fwd);
}

/**
 * @function : void differentialBWD(int v_ml, int v_mr)
 *
 * @param v_ml : velocidad del motor izquierdo.
 *
 * @param v_mr : velocidad del motor derecho.
 *
 * @return : none
 *
 * @description :
 *     Permite que los motores operen a velocidades distintas en reversa.
 */
void Motor::differentialBWD(int v_ml, int v_mr){
	if(v_ml < velocidad_min)
		v_ml = velocidad_min;
	else if(v_ml > velocidad_max)
		v_ml = velocidad_max;
	else
		v_ml = v_ml;

	if(v_mr < velocidad_min)
		v_mr = velocidad_min;
	else if(v_mr > velocidad_max)
		v_mr = velocidad_max;
	else
		v_mr = v_mr;
	digitalWrite(motor_A_pin, HIGH);
  	digitalWrite(motor_B_pin, HIGH);
  	analogWrite(motor_A_PWM_pin, v_mr);
  	analogWrite(motor_B_PWM_pin, v_ml);
}

/**
 * @function : void backward(int v_bckwd)
 *
 * @param v_bckwd : velocidad de retroceso
 *
 * @return : none
 *
 * @description :
 *     Permite que el robot retroceda a velocidad v_bckwd
 */
void Motor::backward(int v_bckwd){
	if(v_bckwd < velocidad_min)
		v_bckwd = velocidad_min;
	else if(v_bckwd > velocidad_max)
		v_bckwd = velocidad_max;
	else 
		v_bckwd = v_bckwd;

	digitalWrite(motor_A_pin,HIGH);
  	digitalWrite(motor_B_pin,HIGH);
  	analogWrite(motor_A_PWM_pin, v_bckwd);
  	analogWrite(motor_B_PWM_pin, v_bckwd);
}

/**
 * @function : void left(int v_left, int t_left)
 *
 * @param v_left : velocidad de giro del robot.
 *
 * @param t_left : tiempo en ms que gira el robot.
 *
 * @return : none
 *
 * @description :
 *     Permite que el robot gire a la izquierda sobre su propio eje a velocidad v_left por un tiempo t_left
 */
void Motor::left(int v_left, int t_left){
	if(t_left < 0) return;
	if(v_left < velocidad_min)
		v_left = velocidad_min;
	else if(v_left > velocidad_max)
		v_left = velocidad_max;
	else 
		v_left = v_left;

	if(t_left == 0){
		digitalWrite(motor_A_pin,LOW);
  		digitalWrite(motor_B_pin,HIGH);
  		analogWrite(motor_A_PWM_pin, v_left);
  		analogWrite(motor_B_PWM_pin, v_left);
	}
	else{
  		digitalWrite(motor_A_pin,LOW);
  		digitalWrite(motor_B_pin,HIGH);
  		analogWrite(motor_A_PWM_pin, v_left);
  		analogWrite(motor_B_PWM_pin, v_left);
  		delay(t_left);
  	}
}

/**
 * @function : void right(int v_right, int t_right)
 *
 * @param v_right : velocidad de giro del robot.
 *
 * @param t_right : tiempo en ms en que el robot gira.
 *
 * @return : none
 *
 * @description :
 *     Permite que le robot gire sobre su propio eje hacia la derecha con velocidad v_right por un tiempo t_right.
 */
void Motor::right(int v_right, int t_right){
	if(t_right < 0) return;

	if(v_right < velocidad_min)
		v_right = velocidad_min;
	else if(v_right > velocidad_max)
		v_right = velocidad_max;
	else 
		v_right = v_right;

	if(t_right == 0){
		digitalWrite(motor_A_pin,HIGH);
  		digitalWrite(motor_B_pin,LOW);
  		analogWrite(motor_A_PWM_pin, v_right);
  		analogWrite(motor_B_PWM_pin, v_right);
	}
	else{
  		digitalWrite(motor_A_pin,HIGH);
  		digitalWrite(motor_B_pin,LOW);
  		analogWrite(motor_A_PWM_pin, v_right);
  		analogWrite(motor_B_PWM_pin, v_right);
  		delay(t_right);
  	}
}

/**
 * @function : void stop(int t_parado)
 *
 * @param t_parado : tiempo en ms por el cual se detiene el robot.
 *
 * @return : none
 *
 * @description :
 *     Permite que el robot se detenga por un tiempo t_parado
 */
void Motor::stop(int t_parado){
	if(t_parado < 0) return;
	if(t_parado == 0){
		digitalWrite(standby_pin, LOW);
		analogWrite(motor_A_PWM_pin, 0);
		analogWrite(motor_B_PWM_pin, 0);
		digitalWrite(standby_pin, HIGH);
	}
	else{
		digitalWrite(standby_pin, LOW);
  		delay(t_parado);
  		digitalWrite(standby_pin, HIGH);
  	}
}