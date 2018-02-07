#include <macros.h>
#include <Qre.h>
#include <Motor.h>

Motor motores = Motor(); //Creation of the Motor Object.
Qre linea = Qre(); // Creation of the Qre Object.

int qres[5]; // Variable that will save the state of the 5 Qres
void setup() {
  // put your setup code here, to run once:
  motores.init(); // Initialization of the motors
  linea.init(); // Initialization of the Qres
}

/**
 * Below is a simple routine of how to follow a black line on a smooth white surface.
 */
void loop() {
  // put your main code here, to run repeatedly:
  qres = linea.read(); // The state of the Qres is read.
  if((qres[0] == 0) && (qres[1] == 0) && (qres[2] == 0) && (qres[3] == 0) && (qres[4] == 0)){ // If there is no line, it advances.
    motores.forward(50);  
  }
  else if(qres[2] == 1){ // If there is a line to the center, go straight.
    motores.forward(50);  
  }
  else if(qres[0] == 1){ // If there is a line to the far left, move forward to the right.
    motores.differentialFWD(50,100);  
  }
  else if(qres[4] == 1){ // If there is a line to the far right, move forward to the left.
    motores.differentialFWD(100,50);
  }
  else{
    motores.stop(0);  // If no case is met, stop.
  }
}
