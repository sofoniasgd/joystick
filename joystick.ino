#include "UnoJoy.h"

int buttonstate[]={0,0,0,0,0,0,0,0} ;

int buttonpins[] = {
  2, 3, 4, 5, 6, 7, 8, 9
};

int joyx = A0;
int joyy = A1;
int slide = A2;
int x = 0;
int y =0;
int s =0;

void setup()
{
  //Serial.begin(9600);
 
for (int i = 0; i<8; i++) {
     pinMode(buttonpins[i], INPUT);

 };
setupUnoJoy();
}

void loop()
{
  
dataForController_t controllerData = getControllerData();
setControllerData(controllerData);
 /* 
  for(int i = 0; i<8;i++){
  
  buttonstate[i] = digitalRead(buttonpins[i]);
  };
  
  
  //Serial.print("buttonStates  ");
  for(int i = 0; i<8;i++){
  
  Serial.print(buttonstate[i]);
  Serial.print("   ");

  };

 x = analogRead(joyx)/4;
 y = analogRead(joyy)/4;
 s = analogRead(slide)/4;
 
 Serial.print(x);
 Serial.print("   ");
 Serial.print(y); 
 Serial.print("   ");
 Serial.print(s);
 Serial.print("   ");
 Serial.println("   ");

  
}
*/
}
dataForController_t getControllerData(void){
  
  // Set up a place for our controller data
  //  Use the getBlankDataForController() function, since
  //  just declaring a fresh dataForController_t tends
  //  to get you one filled with junk from other, random
  //  values that were in those memory locations before
  dataForController_t controllerData = getBlankDataForController();
  // 
  controllerData.dpadLeftOn = digitalRead(2);
  controllerData.dpadRightOn = digitalRead(3);
  controllerData.dpadUpOn = digitalRead(4);
  controllerData.dpadDownOn = digitalRead(5);
  controllerData.squareOn = digitalRead(7);
  controllerData.circleOn = digitalRead(6);
  controllerData.triangleOn = digitalRead(9);
  controllerData.crossOn = digitalRead(8);
  controllerData.leftStickX = analogRead(joyx)/4;
  controllerData.leftStickY = analogRead(joyy)/4;
  controllerData.rightStickY = analogRead(slide)/4;

  // And return the data!
  return controllerData;
}
