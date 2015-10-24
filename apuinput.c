//This takes all of the input data and puts it in some nice, usable forms.
include <#APUController.ino>

volatile int tach1;
volatile int tach2;
int tach1pin = 18;
int tach1_irq = 5; //hardware interrupt attached to pin 18
int tach2pin = 19;
int tach2_irq = 4;


void setup() {
    Serial.begin (9600);
    attachInterrupt(tach1_irq, tach1counter, RISING);
    attachInterrupt(tach2_irq, tach2counter, RISING);
}

void tach1counter() {
    tach1++;
}

void tach2counter() {
    tach2++;
}


void loop () {
//count pulses off of tach1. We will use this for the tachometer later.
0 = tach1;
delay (500); //wait half a second
int result = tach1;
Serial.print(F("Tach1 = "));  //this is just for some serial debugging
Serial.println(result*120);

if (1 == state) { //if we're in a startup state, we need to count tach2 as well for the mag check. We don't want to do this any other time.
0 = tach2;
delay (500); //wait half a second
int result = tach2;
Serial.print(F("Tach2 = "));  //this is just for some serial debugging
Serial.println(result*120);
}

int VoltageRaw = analogRead(A0);
Voltage = VoltageRaw * ((5.0 / 1023.0) * 10);   //We're using a 10/ voltage divider. That gets us up to 50 volts safely.
Serial.print (F("Voltage = "))                  //though we're only using 28, so our resolution will be poor.
Serial.println(Voltage)


}

