/**
 * Ejemplo para Leccion 3 - Como usar los LEDs RGB
 */


// HEADERS necesarios para controlar los LEDs RGB
#include <macros.h>
#include <Lights.h>

// Instanciación de la creación de un objeto del tipo Lights
// usando su contructor por defecto: Lights()
Lights prueba_de_rgb = Lights();

void setup() {
  prueba_de_rgb.init(); // Inicialización de los LEDs RGB
}

void loop() {
  prueba_de_rgb.setColor(0, ROJO);      // Enciende el LED 0 de color rojo
  delay(250);                           // Espera 250 milisegundos
  prueba_de_rgb.setColor(1, AMARILLO);  // Enciende el LED 1 de color amarillo
  delay(250);                           // Espera 250 milisegundos
  prueba_de_rgb.setColor(2, VERDE);     // Enciende el LED 2 de color verde
  delay(250);                           // Espera 250 milisegundos
  prueba_de_rgb.setColor(3, CIAN);      // Enciende el LED 3 de color cian
  delay(250);                           // Espera 250 milisegundos
  prueba_de_rgb.setColor(0, AZUL);      // Enciende el LED 0 de color azul
  delay(250);                           // Espera 250 milisegundos
  prueba_de_rgb.setColor(1, MAGENTA);   // Enciende el LED 1 de color magenta
  delay(250);                           // Espera 250 milisegundos
  prueba_de_rgb.setColor(2, BLANCO);    // Enciende el LED 2 de color blanco
  delay(250);                           // Espera 250 milisegundos
  prueba_de_rgb.setColor(3, NEGRO);     // Apaga el LED 3
  delay(250);                           // Espera 250 milisegundos
}
