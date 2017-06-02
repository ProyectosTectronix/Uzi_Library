#include <macros.h>
#include <Ultrasonic_UZI.h>

Ultrasonic_UZI prueba_de_sonico = Ultrasonic_UZI();
int lectura_sensor_izq = 0; // variable para guardar las lecturas del sensor izquierdo.
int lectura_sensor_der = 0; // variables para guardar las lecturas del sensor derecho.

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); // Se inicia el puerto serial para visualizar las lecturas por el Serial Monitor de esta IDE.
  prueba_de_sonico.init(); // Se inicializan los sensores ultrasónicos.
}

void loop() {
  // put your main code here, to run repeatedly:
  lectura_sensor_izq = prueba_de_sonico.read(0 /* sensor de la izquierda */, 30 /* ignorar medicion de objetos mas lejanos que 30 cm */); // Se hace la lectura del sensor de la izquierda
  delay(20);                // Se recomienda usar un delay entre las lecturas de cada sensor,
                            // ya que la señal de triger de uno puede ser recibida por el echo
                            // del otro obteniendo mediciones outliers.
                            // Se usa 20 ms ya que es el tiempo estimado de lectura a máximo rango.
  lectura_sensor_der = prueba_de_sonico.read(1, 30); // Se hace la lectura del sensor de la derecha.
  delay(20);
  Serial.print("lectura raw de la izquierda : " + lectura_sensor_izq + "\t\t");
  Serial.print("lectura raw de la derecha : " + lectura_sensor_der);
  Serial.println();
}
