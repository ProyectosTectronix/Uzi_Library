#include <Buzzer.h>
#include <Control_BLE_v2_0.h>
#include <Lights.h>
#include <macros.h>
#include <Motor.h>
#include <Ultrasonic_UZI.h>
#include <Uzi.h>

// Instantiation of the creation of an object of type Motor
// calling its default constructor: Motor()
Motor prueba_de_motor = Motor();

void setup() {
  // put your setup code here, to run once:
  prueba_de_motor.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  prueba_de_motor.forward(50);  // the robot advances at the speed 50
  delay(1000);                  // The robot waits for 1000 ms
  prueba_de_motor.stop(0);      // The robot stops
  delay(1000);                  // The robot waits for 1000 ms
  prueba_de_motor.backward(50); // The robot goes backward at the speed 50
  delay(1000);                  // The robot waits for  1000 ms
  prueba_de_motor.stop(0);      // The robot stops
  delay(1000);                  // The robot waits for 1000 ms
}

