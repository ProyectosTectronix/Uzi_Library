#include <macros.h>
#include <Ultrasonic_UZI.h>

Ultrasonic_UZI prueba_de_sonico = Ultrasonic_UZI();
int lectura_sensor_izq = 0; // variable to save the left sensor readings.
int lectura_sensor_der = 0; // variable to save the right sensor readings.

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); // The serial port is started to view the readings by the Serial Monitor of this IDE.
  prueba_de_sonico.init(); // Ultrasonic sensors are initialized.
}

void loop() {
  // put your main code here, to run repeatedly:
  lectura_sensor_izq = prueba_de_sonico.read(0 /* sensor on the left */, 30 /* ignore measurement of objects farther than 30 cm */); // The sensor on the left is read
  delay(20);                // It is recommended to use a delay between the readings of each sensor,
                            // since the triger signal of one can be received by the ECHO
                            // From the other obtaining outliers measurements.
                            // 20 ms is used since it is the estimated time of reading at maximum rank.
  lectura_sensor_der = prueba_de_sonico.read(1, 30); // Se hace la lectura del sensor de la derecha.
  delay(20);
  Serial.print("lectura raw de la izquierda : " + lectura_sensor_izq + "\t\t");
  Serial.print("lectura raw de la derecha : " + lectura_sensor_der);
  Serial.println();
}
