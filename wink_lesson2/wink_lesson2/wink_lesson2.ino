#include "WinkHardware.h"

int baseSpeed = 40;

int D3Left, D3leftOff, D3leftOn;
int D4Center, D4centerOff, D4centerOn;
int D5Right, D5rightOff, D5rightOn;

int multiplyerLeft;
int multiplyerRight;
 
void setup() {
  hardwareBegin();        //initialize Wink's brain to work with his circuitry
  playStartChirp();       //Play startup chirp and blink eyes
  Serial.begin(57600);
  delay(1000);            //startup timer
}

void loop() {
  // you can begin writing your own code here
  //Serial.print("My name is Wink!\n");

  readValues();

  printValues();
     
  avoid();
  
  //delay(300);
}
