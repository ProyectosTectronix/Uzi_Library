/**
 * Example for the lesson N° 3 - how to use the rgb leds.
 */


// Necessary Headers for control the RGB leds. 
#include <macros.h>
#include <Lights.h>

// Instantiation of the creation of a object type Lights. 
// using its default contructor: Lights () 
Lights prueba_de_rgb = Lights();

void setup() {
  prueba_de_rgb.init(); // Start of the RGB leds 
}

void loop() {
  prueba_de_rgb.setColor(0, ROJO);      // Switch on the LED 0 red 
  delay(250);                           // wait 250 ms
  prueba_de_rgb.setColor(1, AMARILLO);  // Switch on the LED 1 yellow
  delay(250);                           // wait 250 ms
  prueba_de_rgb.setColor(2, VERDE);     // Switch on the LED 2 green
  delay(250);                           // wait 250 ms
  prueba_de_rgb.setColor(3, CIAN);      // Switch on the LED 3 cyan
  delay(250);                           // wait 250 ms
  prueba_de_rgb.setColor(0, AZUL);      // Switch on the LED 0 blue
  delay(250);                           // wait 250 ms
  prueba_de_rgb.setColor(1, MAGENTA);   // witch on the LED 1 magenta
  delay(250);                           // wait 250 ms
  prueba_de_rgb.setColor(2, BLANCO);    // Switch on the LED 2 white
  delay(250);                           // wait 250 ms
  prueba_de_rgb.setColor(3, NEGRO);     // Switch off the LED 3
  delay(250);                           // wait 250 ms
}
