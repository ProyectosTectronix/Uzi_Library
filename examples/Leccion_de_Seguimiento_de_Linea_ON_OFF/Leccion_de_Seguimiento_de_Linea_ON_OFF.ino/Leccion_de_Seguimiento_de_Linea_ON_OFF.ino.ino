#include <macros.h>
#include <Qre.h>
#include <Motor.h>

Motor motores = Motor(); // Creación del Objeto Motor.
Qre linea = Qre(); // Creación del Objeto Qre.

int *qres; // Variable que guardará el estado de los 5 Qres

void setup() {
  // put your setup code here, to run once:
  motores.init(); // Inicialización de los motores
  linea.init(); // Inicialización de los Qres
}

/**
 * A continuación se muestra una rutina sensilla de como seguir una linea negra sobre una superficie lisa y blanca.
 */
void loop() {
  // put your main code here, to run repeatedly:
  qres = linea.read(); // Se lee el estado de los Qres.
  if((qres[0] == 0) && (qres[1] == 0) && (qres[2] == 0) && (qres[3] == 0) && (qres[4] == 0)){ // Si no hay linea avanza.
    motores.forward(50);  
  }
  else if(qres[2] == 1){ // Si hay linea al centro avanza recto.
    motores.forward(50);  
  }
  else if(qres[0] == 1){ // Si hay linea a la extrema izquierda avanza girando a la derecha.
    motores.differentialFWD(50,100);  
  }
  else if(qres[4] == 1){ // Si hay linea a la extrema derecha avanza girando a la izquierda.
    motores.differentialFWD(100,50);
  }
  else{
    motores.stop(0);  // Si no se cumple ningun caso, detente.
  }
}
