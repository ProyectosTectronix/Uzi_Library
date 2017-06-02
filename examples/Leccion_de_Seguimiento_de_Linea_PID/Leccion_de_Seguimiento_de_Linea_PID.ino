#include <macros.h>
#include <Qre.h>
#include <Motor.h>

Motor motores = Motor();
Qre linea = Qre();

int qres = 0;
int referencia = 3000; // 1000 al 5000, 3000 es el centro.
float error_prev = 0;
float error_p = 0;
float error_i = 0;
float error_d = 0;
int actuacion = 0;

float Kp = 0.025;
float Ki = 0.1;
float Kd = 0.01;

void setup() {
  // put your setup code here, to run once:
  motores.init();
  linea.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  qres = linea.readLine();

  error_p = referencia - qres;
  error_i += error_p;
  error_d = error_p - error_prev;
  error_prev = error_p;

  actuacion = Kp*error_p + Ki*error_i + Kd*error_d;

  actuacion = (actuacion > 100)?(100):
              (actuacion < -100)?(-100):
              (actuacion);

  motores.differentialFWD(100 - actuacion, 100 + actuacion); 
}
