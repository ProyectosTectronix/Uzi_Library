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
 * implementation of the Motor Class for the funtions of the robot
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
 *     default constructor, only initialize the Motor attributes with default values.
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
  	digitalWrite(standby_pin, LOW); // start in low as precaution.
}

/**
 * @function : Motor(int vel_min, int vel_max)
 *
 * @param vel_min : minimum speed of the motor. the values are between 0 to 255;
 *
 * @param vel_max : maximum speed of the motor. the values are between 0 to 255;
 *
 * @return : none
 *
 * @description :
 *     Constructor, only initialize the minimum speed and maximun speed of the robot,
 *   the others attributes remain with default values, also assigns the pin´s.
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
  	digitalWrite(standby_pin, LOW); // start in low as precaution.
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
Motor::~Motor(){
//
} /* <------------------------------Destructor: for the moment memory is not requested to the system, //
//					in case of booking memory with malloc() or new() implement the destructor pertinent.*/   //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * @function : void init()
 *
 * @param : none
 *
 * @return : none
 *
 * @description :
 *    initialize the Motor lifting up the pin standby_pin.
 */
void Motor::init(){
	digitalWrite(standby_pin,HIGH);
}

/**
 * @function : void differentialFWD(int v_ml, int v_mr)
 *
 * @param v_ml : speed of the left motor.
 *
 * @param v_mr : speed of the right motor.
 *
 * @return : none
 *
 * @description :
 *      Allow engines to operate at different speeds moving forward.
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
 * @param v_fwd : speed of the motors.
 *
 * @return : none
 *
 * @description :
 *     the robot go forward with v_fwd speed 
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
 * @param v_ml : speed of the left motor.
 *
 * @param v_mr : speed of the right motor.
 *
 * @return : none
 *
 * @description :
 *     Allow to operate the motors at different speeds in backwards.
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
 * @param v_bckwd : backwards speed
 *
 * @return : none
 *
 * @description :
 *     allow the robot go backwards at v_bckwd speed 
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
 * @param v_left : speed of turn robot .
 *
 * @param t_left : time in ms of the turn robot.
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
