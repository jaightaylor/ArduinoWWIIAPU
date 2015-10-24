#include <Arduino.h>
#inclute <apudisplay.cpp>
#include <apuengine.cpp>
#include <apuinput.cpp>
#include <apuoutput.cpp>
#include

//setup some variables
boolean startrelay = 0;  //define starter relay position
boolean fuelrelay = 0;  //fuel relay position
boolean oilrelay = 0;   //oil relay position
boolean tachselect = 0; //tachometer select (may not be used...)
float   cht = 0;
float   Voltage = 0;
byte    state = 0; // 0=stop, 1=startup, 2=run, 3=shutdown
unsigned int    throttle = 0; //this might be pwm to a servo
unsigned int    genfield = 0; //raw pwm value for gen field regulator
const int StartButtonPin = 2; //Start Button (momentary)
const int StopButtonPint = 3; //Stop Button (momentary)

void setup()
{
	Serial.begin(9600);

	// initialize the digital pin as an output.
	// Pin 13 has an LED connected on most Arduino boards:
	pinMode(2, INPUT);
	pinMode(3, INPUT);
	pinMode(13, OUTPUT); //generic LED pin. Might use for diagnostics.
}

void loop()
{
// read the state of the starter button
{
    buttonStateStart = digitalRead(StartButtonPin) //pin 2
    buttonStateStop = digitalRead(StopButtonPin) //pin 3

    //check to see if button is pressed, if it is, set state to 1 to intialize startup:
    if (buttonStateStart == HIGH) {
            1 = state;
    }
    // read the state of the shutdown button
{
    buttonState = digitalRead(StopButtonPintButtonPin)

    //check to see if button is pressed, if it is, set state to 4 to initalize shutdown:
    if (buttonStateStop == HIGH) {
            4 = state;
    }

    //LED Diagnostics

        if (3 == state) {       // if in shutdown state, blink LED 3 times a second
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(333);              // wait 250
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(333);              // wait 33

        if (2 == state) {       // if in shutdown state, blink LED 2 times a second
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);              // wait 500
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(500);              // wait 500

        if (1 == state) {       // if in shutdown state, blink LED 1 time per second
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait 1000
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait 1000
    }
        if (0 == state) {       // if in shutdown state 1 short blink per second
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(100);              // wait 100
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait 1000
    }

}
