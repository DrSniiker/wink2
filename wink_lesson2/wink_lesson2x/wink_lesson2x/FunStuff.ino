/*

Wink Robot:  FunStuff  Rev01.01  12/2015

This code includes various "animation" things Wink can do. For example, sounds,
lighting sequences, dance moves, etc. Users are encouraged to build their own
"animations" and share their work on the forum.  http://forum.plumgeek.com/

This code was written by Kevin King and 
Dustin Soodak for Plum Geek LLC.
Portions from other open source projects where noted.
This code is licensed under:
Creative Commons Attribution-ShareAlike 2.0 Generic (CC BY-SA 2.0)
https://creativecommons.org/licenses/by-sa/2.0/

Visit http://www.plumgeek.com for Wink information.
Visit http://www.arduino.cc to learn about the Arduino.

*/

#include "FunStuff.h"


// ***************************************************
// Short Animations
// ***************************************************


void playStartChirp(void){//Ver. 1.0, Kevin King   
  // This is the startup sequence that plays when Wink is reset(put in begin())
  // feel free to edit this function to make your Wink do something different when he starts up
  eyesBlue(100);  // blue at 100 brightness
  beep(10);       // beep for 10 milliseconds
  delay(40);      // wait another 40 milliseconds
  eyesOff();      // turn the eyes back off
  
}


// ***************************************************
// end Short Animations
// ***************************************************

void printValues(void){ 
  Serial.print(D3Left);
  Serial.print("\t");
  Serial.print(D4Center);
  Serial.print("\t");
  Serial.println(D5Right);
  /*
  Serial.print(D3leftOff);
  Serial.print("\t");
  Serial.print(D3leftOn);
  Serial.print("\t");
  Serial.println(D3Left);
  */
}

void readFrontValues(void){
  digitalWrite(10, LOW);
  delay(21);
  D3leftOff = analogRead(AmbientSenseLeft);
  D4centerOff = analogRead(AmbientSenseCenter);
  D5rightOff = analogRead(AmbientSenseRight);  
  
  digitalWrite(10, HIGH);
  delay(11);
  D3leftOn = analogRead(AmbientSenseLeft);
  D4centerOn = analogRead(AmbientSenseCenter);
  D5rightOn = analogRead(AmbientSenseRight);

  D3Left = abs(D3leftOn - D3leftOff);
  D4Center = abs(D4centerOn - D4centerOff);
  D5Right = abs(D5rightOn - D5rightOff);
  /*
  D3Left = map(D3Left, 0, 1023, 0, 2040);
  D5Right = map(D5Right, 0, 1023, 0, 2040);
  D4Center = map(D4Center, 0, 1023, 0, 510);
  */
}

void labyrinth(void){
  //multiplyerLeft = constrain(D3Left, 0, 10);
  //multiplyerRight = constrain(D5Right, 0, 10);
  
  if(D4Center > (baseSpeed + baseSpeed / 5)){
    motors(baseSpeed - D4Center, baseSpeed - D4Center);
    //delay(300);
  }
  else if(D3Left + 2 > D5Right){
    motors(baseSpeed + D3Left * higherMultiplyer, baseSpeed - D3Left * lowerMultiplyer);
    //delay(500);
  }
  else if(D5Right + 2 > D3Left){
    motors(baseSpeed - D5Right * lowerMultiplyer, baseSpeed + D5Right * higherMultiplyer);
    //delay(200);
  }
}
