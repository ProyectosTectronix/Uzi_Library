#include <Buzzer.h>
#include <Control_BLE_v2_0.h>
#include <Lights.h>
#include <macros.h>
#include <Motor.h>
#include <Ultrasonic_UZI.h>
#include <Uzi.h>

Control_BLE control = Control_BLE();
Lights rgb = Lights();
Buzzer buzz = Buzzer();
int data;
bool c = false;
int cont = 0;

void setup(){
  Serial.begin(115200);
  while(!Serial);
  control.init();
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
      if(cont == 8){
        cont = 0;
      }
      else{
        cont = cont;
      }
      switch(cont){
        case 0:
          rgb.happy();
          buzz.happy();
        break;
        case 1:
          rgb.scary();
          buzz.scary();
        break;
        case 2:
          rgb.badboy();
          buzz.march();
        break;
        case 3:
          rgb.connected();
          buzz.r3d3();
        break;
        case 4:
          rgb.badboy();
          buzz.car();
        break;
        case 5:
          rgb.happy();
          buzz.tatan();
        break;
        case 6:
          buzz.barata();
        break;
        case 7:
          buzz.ranger();
        break;
        default:
          rgb.happy();
          buzz.happy();
        break;
      }
      cont++;
    }
    if(data == 70){
      rgb.rainbow();
      if(!c){
        rgb.connected();
      }
      else{
        rgb.disconnected();
      }
      c = !c;
    }
    if(data == 35){ // # configuracion
      String my_name = "";
      if(Serial.available()>0){
        char data_incomming = Serial.read();
        while(data_incomming != BREAK){
          my_name += data_incomming;
          data_incomming = Serial.read();  
        }
      }
      delay(1);
      Serial.print("+++");
      while(Serial.available() == 0);
      Serial.print("AT+NAME=" + my_name + "\r\n");
      while(Serial.available() == 0);
      Serial.print("AT+EXIT\r\n");
    }
  }
  control.updateStateAction(data);
  delay(1);
}
