//////////////////////////////////////////////////////////////////////
//                            TECTRONIX								//
//                 Software Library for UZI_ROBOT					//
//                             Enjoy!								//
//////////////////////////////////////////////////////////////////////

/**
 * @filename : Control_BLE_2.0.cpp
 *
 * @version : 2.0
 *
 * @author : Diego Pandolfa
 *
 * @company : Tectronix
 *
 * @date : January 2016
 *
 * @description : 
 * implementation of the "Control BLE" class to command the robot 
 * using the cell phone application
 */
#include "Control_BLE_v2_0.h"
#include "macros.h"

Control_BLE::Control_BLE(){
	state_connection = IDLE;
	state_machine = IDLE;
	state_uzi = IDLE;
	state_direction = IDLE;
	robot = new Uzi();
	leds_RGB = new Lights();
	buzzer = new Buzzer();
}

Control_BLE::~Control_BLE(){
	delete robot;
	delete leds_RGB;
	delete buzzer;
}

void Control_BLE::init(){
	robot->init();
	leds_RGB->init();
	buzzer->init();
	state_connection = DISCONNECTED;
	state_machine = STOP;
	state_uzi = STOP;
	state_direction = STOP;
	velocity = 200;
}

void Control_BLE::updateStateBLEConection(bool Acknowledge){
	/**
	 * Posibles soluciones:
	 *
	 * Buscar la manera de que via AT Commands verificar el estado de la connexion.
	 *
	 * Algun protocolo de comunicación con Acknowledge.  <--------------- Se implemetara TTL
	 */
	switch(state_connection){
		case IDLE : 
			if(Acknowledge){
				state_connection = CONNECTED;
			}
			else{
				state_connection = IDLE;
			}
			break;
		case CONNECTED :
			if(Acknowledge){
				state_connection = CONNECTED;
			}
			else{
				state_connection = DISCONNECTED;
			}
			break;
		case DISCONNECTED :
			if(Acknowledge){
				state_connection = CONNECTED;
			}
			else{
				state_connection = DISCONNECTED;
			}
			break;
		default:
			state_connection = IDLE;
			break;
	}
}

void Control_BLE::updateStateMachine(void){
	switch(state_machine){
		case IDLE :
			if(state_connection == CONNECTED){
				state_machine = STOP;
			}
			else if(state_connection == DISCONNECTED){
				state_machine = STOP;
			}
			else{
				state_machine = IDLE;
			}
			break;
		case STOP :
			if(state_connection == CONNECTED){
				state_machine = RUN;
			}
			else if(state_connection == DISCONNECTED){
				state_machine = STOP;
			}
			else{
				state_machine = IDLE;
			}
			break;
		case RUN :
			if(state_connection == CONNECTED){
				state_machine = RUN;
			}
			else if(state_connection == DISCONNECTED){
				state_machine = STOP;
			}
			else{
				state_machine = IDLE;
			}
			break;
		default:
			state_machine = IDLE;
			break;
	}
}

void Control_BLE::updateStateUZI(int data){
	switch(state_uzi){
		case IDLE :
			if(state_machine == IDLE){
				state_uzi = IDLE;
			}
			else if(state_machine == STOP){
				state_uzi = STOP;
			}
			else if(state_machine == RUN){
				state_uzi = STOP;
			}
			else{
				state_uzi = IDLE;
			}
			break;
		case STOP :
			if(state_machine == IDLE){
				state_uzi = IDLE;
			}
			else if(state_machine == STOP){
				state_uzi = STOP;
			}
			else if(state_machine == RUN){
				state_uzi = MANUAL;
			}
			else{
				state_uzi = IDLE;
			}
			break;
		case MANUAL :
			if(state_machine == IDLE){
				state_uzi = IDLE;
			}
			else if(state_machine == STOP){
				state_uzi = STOP;
			}
			else if(state_machine == RUN){
				if( (data == AUTO_ON) || (data == 83)){
					state_uzi = AUTO;
				}
				else{
					state_uzi = MANUAL;
				}
			}
			else{
				state_uzi = IDLE;
			}
			break;
		case AUTO :
			if(state_machine == IDLE){
				state_uzi = IDLE;
			}
			else if(state_machine == STOP){
				state_uzi = STOP;
			}
			else if(state_machine == RUN){
				if(data == AUTO_OFF){
					state_uzi = MANUAL;
				}
				else{
					state_uzi = AUTO;
				}
			}
			else{
				state_uzi = IDLE;
			}
			break;
		default :
			state_uzi = IDLE;
			break;
	}
}

void Control_BLE::updateStateDirection(int data){
	String tmp = "0";
	int vel = 0; // variable auxiliar
	if(data == SET_VEL){
		tmp = "";
		if(Serial.available()>0)
			data = Serial.read();
		while(data != BREAK){
			if(Serial.available()>0){
				if(data < 48) break;
				if(data > 57) break;
				tmp += (data - 48);
				data = Serial.read();
			}
		}

		vel = atoi(tmp.c_str());
		velocity = 	(( (vel)*20+20) < 40 )?(velocity):
					(( (vel)*20+20) > 250 )?(velocity):
					( vel*20+20 );
	}

	switch(state_direction){
		case IDLE :
			if(state_uzi == MANUAL){
				state_direction = STOP;
			}
			else{
				state_direction = IDLE;
			}
			break;
		case STOP :
			if(state_uzi == MANUAL){
				switch(data){
					case U : // UP
						state_direction = UP;
						break;
					case UR :
						state_direction = URIGHT;
						break;
					case R : // RIGHT
						state_direction = RIGHT;
						break;
					case DR :
						state_direction = DRIGHT;
						break;
					case D : // DOWN
						state_direction = DOWN;
						break;
					case DL :
						state_direction = DLEFT;
						break;
					case L : // LEFT
						state_direction = LEFT;
						break;
					case UL :
						state_direction = ULEFT;
						break;
					default :
						state_direction = state_direction;
						break;
				}
			}
			else{
				state_direction = IDLE;
			}
			break;
		case UP :
			if(state_uzi == MANUAL){
				switch(data){
					case K :
						state_direction = STOP;
						break;
					case U :
						state_direction = UP;
						break;
					case UR :
						state_direction = URIGHT;
						break;
					case UL :
						state_direction = ULEFT;
						break;
					default :
						state_direction = state_direction;
						break;
				}
			}
			else{
				state_direction = IDLE;
			}
			break;
		case URIGHT :
			if(state_uzi == MANUAL){
				switch(data){
					case K :
						state_direction = STOP;
						break;
					case R :
						state_direction = RIGHT;
						break;
					case U :
						state_direction = UP;
						break;
					default :
						state_direction = state_direction;
						break;
				}
			}
			else{
				state_direction = IDLE;
			}
			break;
		case RIGHT :
			if(state_uzi == MANUAL){
				switch(data){
					case K :
						state_direction = STOP;
						break;
					case R :
						state_direction = RIGHT;
						break;
					case UR :
						state_direction = URIGHT;
						break;
					case DR :
						state_direction = DRIGHT;
						break;
					default :
						state_direction = state_direction;
						break;
				}
			}
			else{
				state_direction = IDLE;
			}
			break;
		case DRIGHT :
			if(state_uzi == MANUAL){
				switch(data){
					case K :
						state_direction = STOP;
						break;
					case R :
						state_direction = RIGHT;
						break;
					case D :
						state_direction = DOWN;
						break;
					default :
						state_direction = state_direction;
						break;
				}
			}
			else{
				state_direction = IDLE;
			}
			break;
		case DOWN :
			if(state_uzi == MANUAL){
				switch(data){
					case K :
						state_direction = STOP;
						break;
					case D :
						state_direction = DOWN;
						break;
					case DR :
						state_direction = DRIGHT;
						break;
					case DL :
						state_direction = DLEFT;
						break;
					default :
						state_direction = state_direction;
						break;
				}
			}
			else{
				state_direction = IDLE;
			}
			break;
		case DLEFT :
			if(state_uzi == MANUAL){
				switch(data){
					case K :
						state_direction = STOP;
						break;
					case D :
						state_direction = DOWN;
						break;
					case L :
						state_direction = LEFT;
						break;
					default :
						state_direction = state_direction;
						break;
				}
			}
			else{
				state_direction = IDLE;
			}
			break;
		case LEFT :
			if(state_uzi == MANUAL){
				switch(data){
					case K :
						state_direction = STOP;
						break;
					case L :
						state_direction = LEFT;
						break;
					case DL :
						state_direction = DLEFT;
						break;
					case UL :
						state_direction = ULEFT;
						break;
					default :
						state_direction = state_direction;
						break;
				}
			}
			else{
				state_direction = IDLE;
			}
			break;
		case ULEFT :
			if(state_uzi == MANUAL){
				switch(data){
					case K :
						state_direction = STOP;
						break;
					case L :
						state_direction = LEFT;
						break;
					case U :
						state_direction = UP;
						break;
					default :
						state_direction = state_direction;
						break;
				}
			}
			else{
				state_direction = IDLE;
			}
			break;
		default :
			state_direction = IDLE;
	}
}


void Control_BLE::updateStateAction(int data){
	/**
	 * the data is used for the ligts routines and the buzzer routine.
	 */
	switch(state_uzi){
		case IDLE :
			robot->stop(0);
			break;
		case STOP :
			robot->stop(0);
			break;
		case MANUAL :
			switch(state_direction){
				case IDLE :
					robot->stop(0);
					break;
				case STOP :
					robot->stop(0);
					break;
				case UP :
					robot->forward(velocity);
					break;
				case URIGHT :
					robot->differentialFWD(velocity, velocity/2);
					break;
				case RIGHT :
					robot->right(velocity,0);
					break;
				case DRIGHT :
					robot->differentialBWD(velocity, velocity/2);
					break;
				case DOWN :
					robot->backward(velocity);
					break;
				case DLEFT :
					robot->differentialBWD( velocity/2,velocity);
					break;
				case LEFT :
					robot->left(velocity,0);
					break;
				case ULEFT :
					robot->differentialFWD( velocity/2,velocity);
					break;
				default :
					robot->stop(0);
					break;
			}
			break;
		case AUTO :
			if(data == 69)
				robot->evasor_debug(15,30);
			else if(data == 83)
				robot->seguidor();
			break;
		default :
			robot->stop(0);
			break;
	}
}
