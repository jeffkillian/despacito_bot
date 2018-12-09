/*
  CoMotion MakerSpace 2018
  Edited by: Ramon Qu
  Arduino 101 Basic Workshop
  12 - Melody
  Plays a melody
  circuit:
   8-ohm speaker on digital pin 8
  This example code is in the public domain.
  http://www.arduino.cc/en/Tutorial/Tone
*/
#include "pitches.h"
#include <Servo.h>  
int writeValue;
int readValue;
Servo servo1;
// notes in the melody:

  int beginPos = 20;
  int endPos = beginPos+80;



int whole = 2*670;
int half = whole/2;
int quarter = whole/4;
int eighth = whole/8;
int sixteenth = whole / 16;
int triplet = quarter / 3;
int servoPin = 11;
int servoPos = 0;
boolean hasReset = true; // Allow you to move it back to starting position
void setup() {
  Serial.begin(9600);
  pinMode(3, INPUT);
//  pinMode(motorPin, OUTPUT);  // set up the pin as an OUTPUT
  servo1.attach(servoPin, 900, 2100);  //Connect the servo to pin 9
  servo1.write(beginPos);    // Tell servo to go to beginning position
}

void loop() {
  int buttonPressed = digitalRead(3);  // keypad pin 3
  if (buttonPressed) {
    if (hasReset){
      playDespacito();
    }else{
      hasReset = true;
      servo1.write(beginPos);
      delay(1000);
    }
  }

}


void playNote(int note, int duration, boolean isRepeated = false){\
  // isrepeated will play the note for less time, but insert a break before the next note so that you can tell two of the same notes played sequentially are different notes.
  int playDuration = duration;
  if (isRepeated) { // Halve it
    playDuration = duration / 2;
  }
  tone(2, note*2, playDuration);
  delay(playDuration);
  if (isRepeated){
    delay(playDuration);
  }
}

void playBeat(boolean goHard = false){

  if (servoPos < endPos) {
    servoPos = endPos;
    if (goHard){
      servoPos = 155;
    }
  }
  else {
    servoPos = beginPos;
    if (goHard){
      servoPos = 0;
    }
  }
  servo1.write(servoPos);    // Tell servo to go to 90 degrees
  //delay(400);
}


void playDespacito(){
   
  // each measure is 16, beats are on 1, 6, 11

  playNote(NOTE_D6, half);
  playNote(NOTE_CS6, half);
  // Measure one
  playBeat();
  playNote(NOTE_B6,quarter);
  playBeat();
  playNote(NOTE_FS5,  eighth);
  
  playNote(NOTE_FS5,  eighth, true);
 
  playNote(NOTE_FS5, eighth, true);
  playBeat();
  playNote(NOTE_FS5, sixteenth);
  
  playNote(NOTE_FS5, sixteenth, true);
  playNote(NOTE_FS5, eighth, true);

  playNote(NOTE_FS5, eighth, true);
  
  
  //measure two 
  playBeat();
  playNote(NOTE_FS5, eighth);
  playNote(NOTE_B6, eighth, true);
  playNote(NOTE_B6, eighth, true);
  playBeat();
  playNote(NOTE_A6, eighth);
  playNote(NOTE_B6, eighth+sixteenth);
  playBeat();
  playNote(NOTE_B6, sixteenth);
  playNote(NOTE_A6, eighth);
  playNote(NOTE_B6, eighth);

  //measure three
  playBeat();
  playNote(NOTE_B6, eighth);
  playNote(NOTE_G5, quarter);
  playBeat();
  playNote(NOTE_G5, eighth);
  playNote(NOTE_G5, eighth, true);
  playNote(NOTE_G5, sixteenth);
  playBeat();
  playNote(NOTE_G5, sixteenth, true);
  playNote(NOTE_G5, eighth, true);
  playNote(NOTE_G5, eighth, true);

  //measure 
  playBeat();
  playNote(NOTE_G5, eighth);
  playNote(NOTE_B6, eighth, true);
  playNote(NOTE_B6, eighth, true);
   playBeat();
  playNote(NOTE_B6, eighth, true);
  playNote(NOTE_B6, eighth+sixteenth);
  playBeat();
  playNote(NOTE_B6, sixteenth);
  playNote(NOTE_CS6, eighth);
  playNote(NOTE_D6, eighth);

  // measure 5
  playBeat();
  playNote(NOTE_D6, eighth);
  playNote(NOTE_A6, quarter);
  playBeat();
  playNote(NOTE_A6, eighth);
  playNote(NOTE_A6, eighth, true);
  playNote(NOTE_A6, sixteenth);
  playBeat();
  playNote(NOTE_A6, sixteenth, true);
  playNote(NOTE_A6, eighth, true);
  playNote(NOTE_A6, eighth, true);

  //measure 6
  playBeat();
  playNote(NOTE_A6, eighth, true);
  playNote(NOTE_D6, eighth, true);
  playNote(NOTE_D6, eighth, true);
  playBeat(true);
  playNote(NOTE_D6, eighth, true);
  playNote(NOTE_D6, eighth+sixteenth);
  playBeat(true);
  playNote(NOTE_D6, sixteenth);
  playNote(NOTE_E6, eighth, true);
  playNote(NOTE_E6, eighth);

  //measure 7
  playBeat(true);
  playNote(NOTE_E6, eighth);
  playNote(NOTE_CS6, eighth+quarter);
  delay(half);
  hasReset = false;
  
}



/*
  Try to create your own song.
*/
