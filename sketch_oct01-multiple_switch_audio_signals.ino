
/*
  Simple Arduino-Uno program for a three button circuit with three separate audio speaker signals.
  Author : Kanishka Rupasinghe, Copyright © 2021

  This is the code needed for the 3 button speaker circuit, which has to be uploaded to the arduino
  board for the speaker and buttons to function together with the circuit.

  Summary : The circuit has three buttons and a speaker (among other components including arduino board).
  When any one of the buttons is pressed, the sound signal of beeps and silences is sounded out by the speaker.
  Once a button is pressed, no other button's singal will be sounded, until the first signal of beeping has
  stopped. Any sequence and length of beeps and silences can be attached to any one of the buttons, as the
  as this sounding instruction is held in the code below, and is uploaded to the arduino board using the upload
  function of the Arduino IDE software.

  
  This code is provided to you by author Kanishka-R under the licence: The MIT License (MIT)
  Find the licence text at following web-page: https://mit-license.org/
  
*/


//speaker annode
//connecting the cathode cable of speaker to GND (ground) and
//annode cable of speaker to pin 13.
//below (at digitalwrite), this allows current to pass through the speaker
//from pin 13 to ground, and sound the speaker
//
const int SPEAKER = 13; 


//these are the pins looked at when button presses
//are checked for.
//
const int BUTTON_ONE = 7;
const int BUTTON_TWO = 5;
const int BUTTON_THREE = 3;


//these carry the signal of what each digital input pin reads
//if there is sufficient current at the pin, this variable is set to high
//if not, set to low
//
int b1_val = 0;
int b2_val = 0;
int b3_val = 0;


//this variable flag is used to indicate that the speaker is reserved (reserve = 0) for
//sounding the signal of that specific button pressed, until the sound signal
//is complete and reserve is set back to 1.
//
int reserve = 1;



//here, the setup section defines the roles of the pins at the start, 
//before the main loop is started.
//
void setup() {

  pinMode(SPEAKER, OUTPUT);
  
  pinMode(BUTTON_ONE, INPUT);
  pinMode(BUTTON_TWO, INPUT);
  pinMode(BUTTON_THREE, INPUT);

}



//after setup function, this set of instructions is repeated again
//and again, continously wihout end until the circuit is powered off
//
void loop() {

  //detect the input pins and set the detected value to the above declared
  //variables
  //
  b1_val = digitalRead(BUTTON_ONE);
  b2_val = digitalRead(BUTTON_TWO);
  b3_val = digitalRead(BUTTON_THREE);


  //if b1_val indicates that button one has been pressed,
  //and reserve flag shows that no other button has reserved the
  //speaker, then do what's in the if block.
  //
  if(b1_val == HIGH && reserve != 0){

    //reserve the speaker
    reserve = 0;

    //these instructions below makes the speaker
    //sound out a specific sound signal of beeps and
    //silences.
    //
    digitalWrite(SPEAKER, HIGH);  delay(2000);
    digitalWrite(SPEAKER, LOW);   delay(2000);
    digitalWrite(SPEAKER, HIGH);  delay(2000);
    digitalWrite(SPEAKER, LOW);   delay(100);


    //release reservation of speaker
    reserve = 1;
  }

  if(b2_val == HIGH && reserve != 0){

    reserve = 0;


    //below is morse code : the letters S.O.S

    //  S
    digitalWrite(SPEAKER, HIGH);  delay(100);
    digitalWrite(SPEAKER, LOW);   delay(50);
    digitalWrite(SPEAKER, HIGH);  delay(100);
    digitalWrite(SPEAKER, LOW);   delay(50);
    digitalWrite(SPEAKER, HIGH);  delay(100);
    digitalWrite(SPEAKER, LOW);   delay(300);


    // O
    digitalWrite(SPEAKER, HIGH);  delay(400);
    digitalWrite(SPEAKER, LOW);   delay(200);
    digitalWrite(SPEAKER, HIGH);  delay(400);
    digitalWrite(SPEAKER, LOW);   delay(200);
    digitalWrite(SPEAKER, HIGH);  delay(400);
    digitalWrite(SPEAKER, LOW);   delay(300);

    // S
    digitalWrite(SPEAKER, HIGH);  delay(100);
    digitalWrite(SPEAKER, LOW);   delay(50);
    digitalWrite(SPEAKER, HIGH);  delay(100);
    digitalWrite(SPEAKER, LOW);   delay(50);
    digitalWrite(SPEAKER, HIGH);  delay(100);
    digitalWrite(SPEAKER, LOW);   delay(50);

    reserve = 1;
  }

  if(b3_val == HIGH && reserve != 0){

    reserve = 0;

    digitalWrite(SPEAKER, HIGH);  delay(1000);
    digitalWrite(SPEAKER, LOW);   delay(100);
    

    digitalWrite(SPEAKER, HIGH);  delay(60);
    digitalWrite(SPEAKER, LOW);   delay(30);

    digitalWrite(SPEAKER, HIGH);  delay(60);
    digitalWrite(SPEAKER, LOW);   delay(30);

    digitalWrite(SPEAKER, HIGH);  delay(60);
    digitalWrite(SPEAKER, LOW);   delay(30);

    digitalWrite(SPEAKER, HIGH);  delay(60);
    digitalWrite(SPEAKER, LOW);   delay(30);

    digitalWrite(SPEAKER, HIGH);  delay(60);
    digitalWrite(SPEAKER, LOW);   delay(30);

    digitalWrite(SPEAKER, HIGH);  delay(60);
    digitalWrite(SPEAKER, LOW);   delay(30);

    digitalWrite(SPEAKER, HIGH);  delay(60);
    digitalWrite(SPEAKER, LOW);   delay(30);

    digitalWrite(SPEAKER, HIGH);  delay(60);
    digitalWrite(SPEAKER, LOW);   delay(30);

    digitalWrite(SPEAKER, HIGH);  delay(60);
    digitalWrite(SPEAKER, LOW);   delay(30);

    digitalWrite(SPEAKER, HIGH);  delay(60);
    digitalWrite(SPEAKER, LOW);   delay(30);


    digitalWrite(SPEAKER, HIGH);  delay(1000);
    digitalWrite(SPEAKER, LOW);   delay(100);

    
    reserve = 1;
  }

  
}
