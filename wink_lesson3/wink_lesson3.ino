#include "WinkHardware.h"

int baseSpeed = 100;

int D3Left, D3leftOff, D3leftOn;
int D4Center, D4centerOff, D4centerOn;
int D5Right, D5rightOff, D5rightOn;

int leftOuter, leftInner, rightInner, rightOuter;
int leftLineSensorValueOff, rightLineSensorValueOff;
int lemTurn;

float lowerRatio, lowerMultiplyer;
float higherRatio, higherMultiplyer;

float conRatio, conThreshold;

//int multiplyerLeft;
//int multiplyerRight;
 
void setup(){
  hardwareBegin();        //initialize Wink's brain to work with his circuitry
  playStartChirp();       //Play startup chirp and blink eyes
  Serial.begin(57600);
  delay(1000);            //startup timer

  lowerRatio = 50 / 1.8;
  higherRatio = 50 / 2.2;
  lowerMultiplyer = baseSpeed / lowerRatio;
  higherMultiplyer = baseSpeed / higherRatio;

  conRatio = 50 / 2;
  conThreshold = baseSpeed / conRatio;

  D4Center = constrain(D4Center, 0, 180);
  
}
void loop(){
  // you can begin writing your own code here
  //Serial.print("My name is Wink!\n");

  //readFrontValues();
  readLineValues();

  //labyrinth();
  lemmings();
  
  //printFrontValues();
  //printLineValues();
  
  Serial.println(lemTurn);
  /*
  Serial.println(lowerRatio);
  Serial.println(lowerMultiplyer);
  Serial.println(higherRatio);
  Serial.println(higherMultiplyer);
  */
  //delay(300);
}
