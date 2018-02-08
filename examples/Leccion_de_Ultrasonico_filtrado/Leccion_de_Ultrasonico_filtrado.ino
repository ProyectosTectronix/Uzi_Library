/**
 * Please review the Ultrasound Lesson before reviewing this lesson.
 */

#include <macros.h>
#include <Ultrasonic_UZI.h>

Ultrasonic_UZI sonico = Ultrasonic_UZI();
float lectura_raw_izq = 0;
float lectura_raw_der = 0;
float medicion_izq = 0;
float medicion_der = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  sonico.init();
}

void loop() {
  // put your main code here, to run repeatedly:
  lectura_raw_izq = sonico.read(0, 30);
  delay(20);
  lectura_raw_der = sonico.read(1, 30);
  delay(20);

/**
 * Below is a way to filter or soften the effect of outliers measurements.
 * The following lines of code get a weighted average of the pure measurement and the previous measurement.
 * The central idea of this application is to give inertia to the measurement obtained so that the readings
 * not persistent over time do not affect the final measurement.
 * 
 * Here is a very extreme case where the readings would be very noisy and therefore they would not be of utility. 
 * 
 * 
 * The average weighted with 10% to the RAW reading, while the previous measurement with 90%.
 * 
 * It should be noted that using this technique to introduce delay in the measurement, in this particular case  
 * the measurement takes 40 readings to stabilize if an object appears out of nowhere.
 * 
 * This is a variable to consider for the evasion of obstacles, since, if the robot advances very fast
 * the measurement may not reach to detect the presence of an obstacle making the robot collide before dodging. 
 * 
 */
  medicion_izq = 0.1*lectura_raw_izq + 0.9*medicion_izq;
  medicion_der = 0.1*lectura_raw_der + 0.9*medicion_der;

  String tmp = "";
  tmp += "La lectura RAW izq. es : ";
  tmp += lectura_raw_izq;
  tmp += "\t";
  tmp += "La medición izq. filtrada es : ";
  tmp += (int)medicion_izq;
  tmp += "\t\t\t";
  tmp += "La lectura RAW der. es : ";
  tmp += lectura_raw_der;
  tmp += "\t";
  tmp += "La medición der. filtrada es : ";
  tmp += (int)medicion_der;
  Serial.println(tmp);
}

