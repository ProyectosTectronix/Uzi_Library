/**
 * Ejemplo para la Lección de Buzzer.
 */
#include <macros.h> // Archivo de cabecera que incluye todas las macros utilizadas por la plataforma robótica UZI.
#include <Buzzer.h> // Archivo de cabecera en donde se define la clase Buzzer

Buzzer prueba_de_buzzer = Buzzer(); // Instanciación de un Buzzer llamando a su constructor.

void setup() {
  // put your setup code here, to run once:
  prueba_de_buzzer.init(); // Sonara un LA 440 por 500 ms para verificar correcto funcionamiento.
  prueba_de_buzzer.sound(DO, 4, 250); // DO_ para un DO#.
  prueba_de_buzzer.sound(RE, 4, 250); // RE_ para un RE#.
  prueba_de_buzzer.sound(MI, 4, 250); // sonara un MI por 250 milisegundos.
  prueba_de_buzzer.sound(FA, 4, 250);
  prueba_de_buzzer.sound(SOL, 4, 250);
  prueba_de_buzzer.sound(LA, 4, 250);
  prueba_de_buzzer.sound(SI, 4, 250);
  prueba_de_buzzer.sound(DO, 5, 250);
}

void loop() {
  // put your main code here, to run repeatedly:
}


