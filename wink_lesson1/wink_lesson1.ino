/*

  Wink Robot
  Wink_BaseSketch_Rev01_03
  Version 1.3 01/2016

  This is a basic sketch that can be used as a starting point
  for various functionality of the Wink robot.

  This code was written by Kevin King and
  Dustin Soodak for Plum Geek LLC.
  Portions from other open source projects where noted.
  This code is licensed under:
  Creative Commons Attribution-ShareAlike 2.0 Generic (CC BY-SA 2.0)
  https://creativecommons.org/licenses/by-sa/2.0/
  Visit http://www.plumgeek.com for Wink information.
  Visit http://www.arduino.cc to learn about the Arduino.

*/

#include "WinkHardware.h"  // Leave this line first. Do not edit this line. This causes Arduino
// to include background functions when turning your code into
// machine language Wink can understand.


// Below is the "setup" function. It runs one time as soon as Wink turns on. You can add stuff
// to this function if you want, but hardwareBegin() should always be the first code in the list.

void setup() {
  hardwareBegin();        //initialize Wink's brain to work with his circuitry
  playStartChirp();       //Play startup chirp and blink eyes
  delay(1500);            //startup timer

}


// Below is the "loop" function. This is where you'll write most of your code. Whatever is included
// inside the "loop" function will run over and over until Wink runs out of power or you turn him off.

void loop() {

  // you can begin writing your own code here

  eyesRed(69);
  delay(1420);
  eyesGreen(69);
  delay(1420);
  eyesBlue(69);
  delay(1420);

  while(true) {
    waitForButton();
      for (int i = 0; i <= 4; i++) {
        leftRed(69);
        rightBlue(69);
        motors(69 - 21, 69);
        beep(210);
        delay(420);
        beStill();
  
        rightRed(69);
        leftBlue(69);
        motors(69, 69 - 21);
        beep(210);
        delay(420);
        beStill();
    }
  }


  //motors(50, 48);



} //closing curly of the “loop()” function
