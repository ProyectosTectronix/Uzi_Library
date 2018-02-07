/**
 * Example for the Buzzer lesson.
 */
#include <macros.h> // Header file that includes all the macros used by the UZI robotic platform.
#include <Buzzer.h> // Header file that define the Buzzer class.

Buzzer prueba_de_buzzer = Buzzer(); // Instantation of a Buzzer by calling its constructor.

void setup() {
  // put your setup code here, to run once:
  prueba_de_buzzer.init(); // will sound a LA 440 for 500 ms for check  correct operation. 
}

void loop() {
  // put your main code here, to run repeatedly:
  prueba_de_buzzer.sound(DO, 1, 250); // DO_ for a DO#.
  prueba_de_buzzer.sound(RE, 1, 250); // RE_ for a RE#.
  prueba_de_buzzer.sound(MI, 1, 250); // will sound a MI for 250 ms.
  prueba_de_buzzer.sound(FA, 1, 250);
  prueba_de_buzzer.sound(SOL, 1, 250);
  prueba_de_buzzer.sound(LA, 1, 250);
  prueba_de_buzzer.sound(SI, 1, 250);
  prueba_de_buzzer.sound(DO, 2, 250);
}


