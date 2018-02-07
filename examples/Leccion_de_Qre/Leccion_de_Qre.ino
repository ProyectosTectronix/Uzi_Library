#include <macros.h> // File with all macros of the Uzi platform.
#include <Qre.h>    // File with the definitions of the object Qre.

Qre prueba_de_qre = Qre(); // Instantiation of the creation of a Qre object using its default constructor.
int *qres; // Variable that will save the logical state of each Qre.
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200); // Serial communication is established to see the status of the Qre by the Serial Monitor of this IDE.
  prueba_de_qre.init(); // The Qre are initialized.
}

void loop() {
  // put your main code here, to run repeatedly:
  qres = prueba_de_qre.read(); // It reads state of the 5 Qre

  /**
   * The values of each Qre are written to the serial port.
   */
  String tmp = "";
  for(int i=0; i<5; i++){
    Serial.print(tmp + "qre[" + i + "] : " + qres[i] + "\t\t");  
  }
  Serial.println();
}
