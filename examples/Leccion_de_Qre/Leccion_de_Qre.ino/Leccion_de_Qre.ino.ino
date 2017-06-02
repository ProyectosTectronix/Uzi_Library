#include <macros.h> // Archivo con todas las macros de la plataforma Uzi
#include <Qre.h>    // Archivo con las definiciones de un objeto Qre.

Qre prueba_de_qre = Qre(); // Instanciación de la Creación de  un objeto del tipo Qre usando su contructor por defecto: Qre().
int *qres; // Variable que guardará el estado lógico de cada Qre.

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); // Se establece comunicación serial para ver el estado de los Qre por el Serial Monitor de este IDE.
  prueba_de_qre.init(); // Se inicializan los Qre.
}

void loop() {
  // put your main code here, to run repeatedly:
  qres = prueba_de_qre.read(); // Se lee estado de los 5 Qre

  /**
   * Se escriben los valores de cada Qre en el puerto serial.
   */
  String tmp = "";
  for(int i=0; i<5; i++){
    Serial.print(tmp + "qre[" + i + "] : " + qres[i] + "\t\t");  
  }
  Serial.println();
}
