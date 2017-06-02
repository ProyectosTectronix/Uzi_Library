#include <Buzzer.h>
#include <Control_BLE_v2_0.h>
#include <Lights.h>
#include <macros.h>
#include <Ultrasonic_UZI.h>

Control_BLE control = Control_BLE();
Lights rgb = Lights();
Buzzer buzz = Buzzer();
int data;
bool c = false;
void setup(){
  Serial.begin(115200);
  while(!Serial);
  control.init();
  buzz.init();
  rgb.init();
  }

void loop(){
  if(Serial.available()>0){
    data = Serial.read();
    control.updateStateBLEConection(true);
    control.updateStateMachine();
    control.updateStateUZI(data);
    control.updateStateDirection(data);
    //Serial.println(data);
    if(data == 66){
      buzz.happy();
    }
    if(data == 70){
      if(!c){
        rgb.connected();
      }
      else{
        rgb.disconnected();
      }
      c = !c;
    }
  }
  control.updateStateAction(data);
  delay(1);
}
