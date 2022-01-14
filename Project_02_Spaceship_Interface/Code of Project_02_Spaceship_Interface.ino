//MATERIAL USED:               1 Genuino Uno, 
//                             1 small breadboard
//                             1 switch
//                             3 LED(2 red, 1 green) 
//                             Resistors (10kOhm for pulldown switch and 220Ohm for each LED)
//
//INTENTION OF THE PROJECT
//  For IDLE:                 Green LED ON
//  For switch activated:     Red LEDs alternate ON/OFF with 250ms interval
//  For switch released:      Back to IDLE after 250ms

 
//Runs once. Pin configuration/functionality 
void setup() {                     
  pinMode(2,INPUT); 
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
}

//Actuation of the LEDs by functions/statements
void loop() {                     
  int switchState = 0;            //Declaration of variable (integer)
  switchState = digitalRead(2);   //Checking the state of pin 2

//Setting the various LEDs high and low
  if (switchState == LOW) {
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  }
  else {
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);

    delay(250);
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    delay(250);
  }
}
