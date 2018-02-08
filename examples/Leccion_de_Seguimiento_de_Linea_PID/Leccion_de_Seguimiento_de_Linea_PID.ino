#include <macros.h>
#include <Qre.h>
#include <Motor.h>

Motor motores = Motor();
Qre linea = Qre();

int qres = 0;
int reference = 3000; // 1000 to 5000, 3000 is the middle.
float error_prev = 0;
float error_p = 0;
float error_i = 0;
float error_d = 0;
int actuation = 0;

float Kp = 0.03;
float Ki = 0.001;
float Kd = 0.01;

void setup() {
  // put your setup code here, to run once:
  motores.init();
  linea.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  qres = linea.readLine();

  error_p = reference - qres;
  error_i += error_p;
  error_d = error_p - error_prev;
  error_prev = error_p;

  actuation = Kp*error_p + Ki*error_i + Kd*error_d;

  error_i = (actuation > 100)?(0):
              (actuation < -100)?(0):
              (error_i);

  actuation = (actuation > 100)?(100):
              (actuation < -100)?(-100):
              (actuation);

  motores.differentialFWD(100 - actuation, 100 + actuation);
}