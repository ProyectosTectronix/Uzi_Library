/**
 * Example for the Buzzer lesson.
 */
#include <macros.h> // Header file that includes all the macros used by the UZI robotic platform.
#include <Buzzer.h> // Header file that define the Buzzer class.

Buzzer prueba_de_buzzer = Buzzer(); // Instantation of a Buzzer by calling its constructor.

void setup() {
  // put your setup code here, to run once:
  prueba_de_buzzer.init(); // Sonara un LA 440 por 500 ms para verificar correcto funcionamiento.
  prueba_de_buzzer.sound(DO, 7, 250); // DO_ for a DO#.
  prueba_de_buzzer.sound(RE, 7, 250); // RE_ for a RE#.
  prueba_de_buzzer.sound(MI, 7, 250); // will sound a MI for 250 ms.
  prueba_de_buzzer.sound(FA, 7, 250);
  prueba_de_buzzer.sound(SOL, 7, 250);
  prueba_de_buzzer.sound(LA, 7, 250);
  prueba_de_buzzer.sound(SI, 7, 250);
  prueba_de_buzzer.sound(DO, 8, 250);
}

void loop() {
  // put your main code here, to run repeatedly:
}
