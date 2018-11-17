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
int writeValue;
int readValue;
// notes in the melody:


int whole = 1200;
int half = whole/2;
int quarter = whole/4;
int eighth = whole/8;
int sixteenth = whole / 16;
int triplet = quarter / 3;
int motorPin = 9;
void setup() {
  // initialize the pushbutton pin as an input:
  Serial.begin(9600);
  pinMode(3, INPUT);
  pinMode(motorPin, OUTPUT);  // set up the pin as an OUTPUT
}

void loop() {


  if(buttonPressed){playDespacito();}
  //if (buttonPressed){moveMotor();}
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


void playDespacito(){
    digitalWrite(motorPin, HIGH);
 // The variable names correspond to the keys on the keypad:
  int buttonPressed = digitalRead(3);  // keypad pin 3
  playNote(NOTE_D6, half);
  playNote(NOTE_CS6, half);
  // Measure one
  playNote(NOTE_B6,quarter);
  playNote(NOTE_FS5, quarter);
  playNote(NOTE_FS5, eighth, true);
  playNote(NOTE_FS5, eighth, true);
  playNote(NOTE_FS5, eighth, true);
  playNote(NOTE_FS5, eighth, true);
  //measure two 
  playNote(NOTE_FS5, eighth);
  playNote(NOTE_B6, eighth, true);
  playNote(NOTE_B6, eighth, true);
  playNote(NOTE_A6, eighth);
  playNote(NOTE_B6, quarter);
  playNote(NOTE_A6, eighth);
  playNote(NOTE_B6, eighth);

  //measure three
  playNote(NOTE_B6, eighth);
  playNote(NOTE_G5, quarter+eighth);
  playNote(NOTE_G5, eighth, true);
  playNote(NOTE_G5, eighth, true);
  playNote(NOTE_G5, eighth, true);
  playNote(NOTE_G5, eighth, true);

  //measure 4
  playNote(NOTE_G5, eighth);
  playNote(NOTE_B6, eighth, true);
  playNote(NOTE_B6, eighth, true);
  playNote(NOTE_B6, eighth, true);
  playNote(NOTE_B6, quarter);
  playNote(NOTE_CS6, eighth);
  playNote(NOTE_D6, eighth);

  // measure 5
  playNote(NOTE_D6, eighth);
  playNote(NOTE_A6, eighth+quarter);
  playNote(NOTE_A6, eighth, true);
  playNote(NOTE_A6, eighth, true);
  playNote(NOTE_A6, eighth, true);
  playNote(NOTE_A6, eighth, true);

  //measure 6
  playNote(NOTE_A6, eighth, true);
  playNote(NOTE_D6, eighth, true);
  playNote(NOTE_D6, eighth, true);
  playNote(NOTE_D6, eighth, true);
  playNote(NOTE_D6, quarter);
  playNote(NOTE_E6, eighth, true);
  playNote(NOTE_E6, eighth);

  //measure 7
  playNote(NOTE_E6, eighth);
  playNote(NOTE_CS6, eighth+quarter);
  delay(half);
  
}



/*
  Try to create your own song.
*/
