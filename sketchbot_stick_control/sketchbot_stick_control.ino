/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO 
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino model, check
  the Technical Specs of your board  at https://www.arduino.cc/en/Main/Products
  
  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
  
  modified 2 Sep 2016
  by Arturo Guadalupi
  
  modified 8 Sep 2016
  by Colby Newman
*/


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(2,OUTPUT); // X step
  pinMode(3,OUTPUT); // Y step
  pinMode(5,OUTPUT); // X direction
  pinMode(6,OUTPUT); // Y direction
  pinMode(8,OUTPUT); // enable line for steppers
 
  pinMode(A0,INPUT_PULLUP); // reset/hold/controller0
  pinMode(A1,INPUT_PULLUP); // reset/hold/controller0
  pinMode(A2,INPUT_PULLUP); // reset/hold/controller0
  pinMode(A3,INPUT_PULLUP); // reset/hold/controller0
  
  digitalWrite(5,HIGH);
  digitalWrite(8,LOW); // enable steppers (active low)
}

int phase = 0;

int xdir = LOW;
int ydir = LOW;
// the loop function runs over and over again forever
void loop() {
  digitalWrite(5,xdir);
  digitalWrite(6,ydir);
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  if ( ! digitalRead(A0) ) {
    xdir = LOW;
    digitalWrite(2, LOW);   // turn the LED on (HIGH is the voltage level)
  }
  if ( ! digitalRead(A1) ) { // hold line / left long axis
    xdir = HIGH;
    digitalWrite(2, LOW);   // turn the LED on (HIGH is the voltage level)
  }
  if ( ! digitalRead(A2) ) {
    ydir = LOW;
    digitalWrite(3, LOW);   // turn the LED on (HIGH is the voltage level)
  }
  if ( ! digitalRead(A3) ) {
    ydir = HIGH;
    digitalWrite(3, LOW);   // turn the LED on (HIGH is the voltage level)
  }
  delayMicroseconds(100);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  digitalWrite(2, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(3, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(5, HIGH);    // turn the LED off by making the voltage LOW
  digitalWrite(6, HIGH);    // turn the LED off by making the voltage LOW
  delayMicroseconds(100);                       // wait for a second
/*  
 * 
 if (phase&1) {
    digitalWrite(A0,HIGH);
  } else {
    digitalWrite(A0,LOW);
  }
  if (phase&2) {
    digitalWrite(A1,HIGH);
  } else {
    digitalWrite(A1,LOW);
  }
  if (phase&4) {
    digitalWrite(A2,HIGH);
  } else {
    digitalWrite(A2,LOW);
  }
  if (phase&8) {
    digitalWrite(A3,HIGH);
  } else {
    digitalWrite(A3,LOW);
  }
  phase = ( phase + 1 ) & 0x0f;
  */
}

