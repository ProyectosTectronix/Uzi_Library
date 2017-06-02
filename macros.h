//////////////////////////////////////////////////////////////////////
//                            TECTRONIX								//
//                 Software Library for UZI_ROBOT					//				
//                             Enjoy!							 	//
//////////////////////////////////////////////////////////////////////

/**
 * @author : Diego Pandolfa
 *
 * @company : Tectronix
 *
 * @date : december 2016
 *
 * @version: 2.0
 *
 * @description : 
 *   Pines del arduino que se usan para el demo compatibles con la version Uzi v2.3
 */
#ifndef _MACROS_UZI_
#define _MACROS_UZI_

//------------------- Conectados directamente ----------------------//

/**
 * @macro : BUTTONS
 *
 * @description : 
 *   Están todos los bonotes conectados al mismo input,
 * sólo se diferencian por el nivel de tension en cada uno,
 * es decir, si la lectura está en un cierto rango de valores
 * correspondiente al divior de tension conectado al boton,
 * entonces dicho boton ha sido presionado.
 *
 * Posible error no abordado:
 * El botón no esta sincronizado.(el arduino podría detectar varios niveles de voltaje mientras se presiona el boton, es decir, onda no cuadrada)
 * EL voltaje no está estabilizado.(podrá tener rebotes)
 *
 * El rango de deteccion de los botones esta basado en que la fuente varia entre 5.5 - 4.5V regulados por el arduino.
 * Se desprecian las tolerancias de las resistencias.
 */
#define BUTTONS 		A0 
#define THR_HIGH_S1 	935 // 4.58V
#define THR_LOW_S1 		765 // 3.75V
#define THR_HIGH_S2 	763 // 3.93V -> 3.74V por solaparse con S1
#define THR_LOW_S2 		655 // 3.21V
#define THR_HIGH_S3 	653 // 3.44V -> 3.20V por solaparse con S2
#define THR_LOW_S3 		573 // 2.81V
#define THR_HIGH_S4 	561 // 2.75V
#define THR_LOW_S4 		459 // 2.25V
#define THR_HIGH_S5 	432 // 2.12V
#define THR_LOW_S5 		353 // 1.73V

/**
 * @macro : MOTOR_A 
 *
 */
#define MOTOR_A 7 //A1 v2.0 // derecha <-------------------favor revisar en PCB
#define MOTOR_B 6 //A2 v2.0 //izquierda <----visto desde atras

/**
 * @macro : STAND_BY_MOTOR
 *
 * @description: Pin designado para habilitar o deshabilitar las funciones de los motores
 */
#define STAND_BY_MOTOR 2 //A3 v2.0

/**
 * @macro : PWM_MOTOR_A
 *
 * @description : 
 *   Pin de salida hacia el puente H para setear de velocidad del motor A.
 *
 * Idem para PWM_MOTOR_B
 */
#define PWM_MOTOR_A 5
#define PWM_MOTOR_B 10 // 3 v2.0

//-------------------- Conectados a traves de un jumper ----------------------//

/**
 * @macro : RGB_LED_OUT 
 *
 * @description : 
 *   Pin que envia datos en una cadena de string hacia una cadena de LEDs RGB
 */
#define RGB_LED_FRONT 9
#define RGB_LED_BACK 3 // 10 v2.0
#define BRIGHTNESS 50
#define NUM_PIX 2

#define TRG_R 12 //pin 2 jumper 23
#define ECHO_R 4 //pin 3 jumper
#define TRG_L 12
#define ECHO_L 8

//---------- Macros de Maquina de estados para control BLE

#define REMOTE_CONTROL 42

#define IDLE			0
#define DISCONNECTED	1
#define CONNECTED		2

#define STOP	1
#define RUN 	2

#define MANUAL 2
#define AUTO 3
#define AUTO_ON 	69
#define AUTO_OFF 	75

#define UP		2
#define URIGHT 	3
#define RIGHT	4
#define DRIGHT	5
#define DOWN	6
#define DLEFT	7
#define LEFT	8
#define ULEFT	9

#define U 	85
#define UL 	49
#define UR 	50
#define D 	68
#define DL 	52
#define DR 	51
#define L 	76
#define R 	82
#define K	75 // stop

#define SET_VEL 	86

//-------- Block Programming ------------//

#define BREAK 47 // "/"

#define BLOCK_PROGRAMMING 35

/*           types           */
#define FIRST_LIGHT		"01"
#define SECOND_LIGHT	"02"
#define THIRD_LIGHT		"03"
#define FOURTH_LIGHT	"04"
#define ALL_LIGHT		"05"
#define RUTINE_LIGHT	"06"
#define BUZZER 			"07"
#define RUTINE_BUZZER 	"08"
#define MOVEMENT 		"09"
#define SONIC_L 		"10"
#define SONIC_R 		"11"
#define LINE_FOLLOWER_1 	"12"
#define LINE_FOLLOWER_2 	"13"
#define LINE_FOLLOWER_3 	"14"
#define LINE_FOLLOWER_4 	"15"
#define LINE_FOLLOWER_5 	"16"
#define TYPE_IDLE 			"26"

// ------------- LOW BATTERY -------------//
#define LOW_BATTERY 33 // "!" LOW BATTERY

#define BATTERY_LEVEL 	A2


//------------- Buzzer --------------------//

#define PIN_BUZZER 11

#define DO 		1
#define DO_ 	2
#define RE 		3
#define RE_ 	4
#define MI 		5
#define FA 		6
#define FA_ 	7
#define SOL 	8
#define SOL_ 	9
#define LA 		10
#define LA_ 	11
#define SI		12


// ------------- QRE Sensors ---------------//

#define QREI 	A1
#define QREIC 	A3
#define QREC 	A4
#define QREDC 	13
#define QRED 	A5


// ---------- types of display -------//
#define SONIC 	'A'
#define QRE 	'B'
#define RGB 	'C'
#define MOTOR 	'D'

// ---------- Colores para app----------------//
#define BLACK		0
#define BLUE		1
#define GREEN		2
#define CYAN		3
#define	RED 		4
#define MAGENTA_	5
#define YELLOW		6
#define WHITE		7

// -------------- Colores para USUARIO ---------//
#define NEGRO		0,0,0
#define AZUL		0,0,255
#define VERDE		0,255,0
#define CIAN		0,255,255
#define ROJO 		255,0,0
#define MAGENTA		255,0,255
#define AMARILLO	255,255,0
#define BLANCO		255,255,255

//---------- PID ---------//
#define KP 0.025
#define KI 0.0
#define KD 0.0
// faltan muchisimas mas macros, favor revisar esquemático y testear
#endif