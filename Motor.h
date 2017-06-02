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
 *   Definicion de clase Motor para funciones basicas del robot
 */
#ifndef _MOTOR_H_
#define _MOTOR_H_

#include "Arduino.h"
#include "macros.h"

class Motor{
public:
	int test;
	Motor();
	Motor(int vel_min, int vel_max);
	~Motor();
	void init();
	void differentialFWD(int v_ml, int v_mr);
	void forward(int v_fwd);
	void differentialBWD(int v_ml, int v_mr);
	void backward(int v_bckwd);
	void left(int v_left, int t_left);
	void right(int v_right, int t_right);
	void stop(int t_parado);

private:
	int velocidad_min;
	int velocidad_max;
	int standby_pin;
	int motor_A_pin; //derecha vistos desde atras
	int motor_B_pin; //izquierda
	int motor_A_PWM_pin;
	int motor_B_PWM_pin;
};

#endif