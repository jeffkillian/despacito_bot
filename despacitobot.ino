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
int notes[12] = {100,
NOTE_B5,
NOTE_C6,
NOTE_D6,
NOTE_DS6,
NOTE_E6,
NOTE_F6,
NOTE_FS6,
NOTE_G6,
NOTE_GS6,
NOTE_A6,
NOTE_AS6};

void setup() {
  // initialize the pushbutton pin as an input:
  Serial.begin(9600);
  /*
  Set pins 2-13 as inputs and enable the internal pull-up resistor 
  with the INPUT_PULLUP constant.  Wire each of these pins directly 
  to a unique pin on the keypad thus addressing each key.  
  The common terminal is connected to ground. 
  */
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP); 
}

void loop() {
 // The variable names correspond to the keys on the keypad:
  int seven = digitalRead(3);  // keypad pin 3
  int four = digitalRead(4);  // keypad pin 4
  int one = digitalRead(5);  // keypad pin 5
  int zero = digitalRead(6);  // keypad pin 6
  int eight = digitalRead(7);  // keypad pin 7
  int five = digitalRead(8);  // keypad pin 8
  int two = digitalRead(9);  // keypad pin 9
  int pound = digitalRead(10);  // keypad pin 10
  int nine = digitalRead(11);  // keypad pin 11
  int six = digitalRead(12);  // keypad pin 12
  int three = digitalRead(13);  // keypad pin 13
  
  // When the digitalRead() of a pin returns 0 the corresponding 
  // key label is printed via Serial.
  if(!seven){playDespacito();}
  if(!four){playNoteIndex(4);}
  if(!one){playNoteIndex(1);}
  if(!zero){playNoteIndex(10);}
  if(!eight){playNoteIndex(8);}
  if(!five){playNoteIndex(5);}
  if(!two){playNoteIndex(2);}
  if(!pound){playNoteIndex(11);}
  if(!nine){playNoteIndex(9);}
  if(!six){playNoteIndex(6);}
  if(!three){playNoteIndex(3);}
  
  
 
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

void playNoteIndex(int noteIndex) {
    Serial.println(noteIndex);
   tone(2, notes[noteIndex]*2, 50);
}




/*
  Try to create your own song.
*/
