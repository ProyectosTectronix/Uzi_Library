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
 *     Implementación de clase Ultrasonic_UZI para utilización del sensor ultrasónico
 *   que viene por defecto con el robot. 
 */
#include "Arduino.h"
#include "macros.h"
#include "Ultrasonic_UZI.h"

/**
 * @function : Ultrasonic_UZI()
 *
 * @param : none
 *
 * @return : none
 *
 * @description :
 *     Constructor por defecto. Inicializa los atributos por defecto.
 */
Ultrasonic_UZI::Ultrasonic_UZI(){
	trigL = TRG_L;
	echoL = ECHO_L;
	trigR = TRG_R;
	echoR = ECHO_R;
}

/**
 * @function : Ultrasonic_UZI(int left_t, int left_e, int right_t, int right_e)
 *
 * @param left_t : pin del arduino en que está conectado el trigger del sensor de la izquierda observado desde atrás.
 *
 * @param left_e : pin del arduino en que está conectado el echo del sensor de la izquierda observado desde atrás.
 *
 * @param right_t: pin del arduino en que está conectado el trigger del sensor de la derecha observado desde atrás.
 *
 * @param right_e: pin del arduino en que está conectado el echo del sensor de la derecha observado desde atrás.

 * @return : none
 *
 * @description :
 *     Constructor. Define los pines del sensor segun se indica.
 */
Ultrasonic_UZI::Ultrasonic_UZI(int left_t, int left_e, int right_t, int right_e){
	trigL = left_t;
	echoL = left_e;
	trigR = right_t;
	echoR = right_e;
}

Ultrasonic_UZI::~Ultrasonic_UZI(){
  
}

/**
 * @function : void init()
 *
 * @param : none
 *
 * @return : none
 *
 * @description :
 *     inicializa el Ultrasonic_UZI definiendo como I/O los pines correspondientes
 */
void Ultrasonic_UZI::init(){
  	pinMode(trigL, OUTPUT); // trigL se configura como salida del arduino hacia el sensor
  	pinMode(echoL, INPUT); // echoL se configura como entrada al arduino desde el sensor
  	pinMode(trigR, OUTPUT); // idem a trigL
  	pinMode(echoR, INPUT); // idem al echoL
}

/**
 * @function : int read(int sensor)
 *
 * @param sensor : indica el sensor que se desea leer. "0" para la izquierda y "1" para la derecha.
 *
 * @return : retorna la distancia a la que se encuentra el objeto sensado. Si no existe objeto detectado retorna 0.
 *
 * @description :
 *     Permite leer el estado del sensor indicado, los valores obtenidos estan cm en el rango de 3 a 300 cm con resolucion de 3mm
 */
float Ultrasonic_UZI::read(int sensor, int ignorar_medicion){
  long duration;
  float distance;
  if(sensor == 0){
    digitalWrite(trigL, LOW); 
    delayMicroseconds(2); 
    digitalWrite(trigL, HIGH);
    delayMicroseconds(10); 
    digitalWrite(trigL, LOW);
    duration = pulseIn(echoL, HIGH, ignorar_medicion*58.2); // sugerencia: detecta hasta 50 cm, luego las mediciones tienen mucho ruido.
    //delay(4);
    distance = duration/58.2;
    return distance;
  }
  if(sensor == 1){
    digitalWrite(trigR, LOW); 
    delayMicroseconds(2); 
    digitalWrite(trigR, HIGH);
    delayMicroseconds(10); 
    digitalWrite(trigR, LOW);
    duration = pulseIn(echoR, HIGH, ignorar_medicion*58.2);
    //delay(4);
    distance = duration/58.2;
    return distance;
  }
  else{
    return 0;
  }
}