#include <Buzzer.h>
#include <Control_BLE_v2_0.h>
#include <Lights.h>
#include <macros.h>
#include <Motor.h>
#include <Ultrasonic_UZI.h>
#include <Uzi.h>

// Instanciación de la creación de un objeto del tipo Motor
// llamando a su construtor por defecto: Motor()
Motor prueba_de_motor = Motor();

void setup() {
  // put your setup code here, to run once:
  prueba_de_motor.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  prueba_de_motor.forward(50);  // El robot avanza con velocidad 50
  delay(1000);                  // El robot espera por 1000 milisegundos
  prueba_de_motor.stop(0);      // El robot se detiene
  delay(1000);                  // El robot espera por 1000 milisegundos
  prueba_de_motor.backward(50); // El robot retrocede con velocidad 50
  delay(1000);                  // El robot espera por 1000 milisegundos
  prueba_de_motor.stop(0);      // El robot se detiene
  delay(1000);                  // El robot espera por 1000 milisegundos
}

