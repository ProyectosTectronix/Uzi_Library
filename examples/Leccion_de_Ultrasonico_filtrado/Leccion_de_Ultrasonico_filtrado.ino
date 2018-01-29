/**
 * Favor revisar la Lección de Ultrasónicos antes de revisar esta lección.
 */

#include <macros.h>
#include <Ultrasonic_UZI.h>

Ultrasonic_UZI sonico = Ultrasonic_UZI();
float lectura_raw_izq = 0;
float lectura_raw_der = 0;
float medicion_izq = 0;
float medicion_der = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  sonico.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  lectura_raw_izq = sonico.read(0, 30);
  delay(20);
  lectura_raw_der = sonico.read(1, 30);
  delay(20);

/**
 * A continuación se muestra una forma de filtrar o amortiguar el efecto de las mediciones outliers.
 * Las siguientes lineas de código obtienen un promedio ponderado de la medición pura y la medición anterior.
 * La idea central de esta aplicación es darle inercia a la medición obtenida para que las lecturas
 * no persistentes en el tiempo no afecten a la medicion final.
 * 
 * Aca se muestra un caso bastante extremo en donde las lecturas serían muy ruidosas y por ello éstas no 
 * serían de ultilidad.
 * 
 * El promedio pondera con el 10% a la lectura RAW, mientras que a la medición anterior con un 90%.
 * 
 * Cabe destacar que utilizar esta técnica introduce retardo en la medición, en este caso en particular
 * la medición tarda 40 lecturas en estabilizarse si un objeto aparece de la nada.
 * 
 * Esto es una variable a considerar para la evasión de obstáculos, ya que, si el robot avanza muy rápido
 * la medición puede no alcanzar a detectar la presencia de un obstáculo haciendo que el robot choque antes 
 * de esquivarlo.
 */
  medicion_izq = 0.1*lectura_raw_izq + 0.9*medicion_izq;
  medicion_der = 0.1*lectura_raw_der + 0.9*medicion_der;

  String tmp = "";
  tmp += "La lectura RAW izq. es : ";
  tmp += lectura_raw_izq;
  tmp += "\t";
  tmp += "La medición izq. filtrada es : ";
  tmp += (int)medicion_izq;
  tmp += "\t\t\t";
  tmp += "La lectura RAW der. es : ";
  tmp += lectura_raw_der;
  tmp += "\t";
  tmp += "La medición der. filtrada es : ";
  tmp += (int)medicion_der;
  Serial.println(tmp);
}
