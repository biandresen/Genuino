//MATERIAL USED:                                    1 Genuino Uno, 
//                                                  1 small breadboard
//                                                  1 temperature sensor
//                                                  3 LED(3 red) 
//                                                  Resistors (200 Ohm for each LED)
//
//INTENTION OF THE PROJECT
//  For IDLE:                                       Ambient temperature (baseline)
//  For touching the sensor:                        Change input based on temperature. For each 2 degrees celsius over baseline an LED will light up




//Declaring constants
const int sensorPin = A0;
const float baselineTemp = 25.0;

//Runs once. Pin configuration/functionality 
void setup() {                     
Serial.begin (9600);        //Opens serial port
for(int pinNumber = 2; pinNumber<5; pinNumber++){
  pinMode(pinNumber, OUTPUT);
  digitalWrite(pinNumber, LOW);
  }
}

void loop() {   
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Value: ");       
  Serial.print(sensorVal);             
                 
float voltage = (sensorVal/1024.0) * 5.0;
Serial.print(", Volts: ");
Serial.print(voltage);

Serial.print(", degrees C: ");
float temperature = (voltage - 0.5) * 100;
Serial.println(temperature);

//Arguements for when LED should light up in referance to the baseline/ambient temperature
if(temperature < baselineTemp+2){
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
} else if(temperature >= baselineTemp+2 &&
        temperature < baselineTemp+4){
        digitalWrite(2, HIGH);
        digitalWrite(3, LOW);
        digitalWrite(4, LOW);
} else if(temperature >= baselineTemp+4 &&
        temperature < baselineTemp+6){
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
} else if(temperature >= baselineTemp+6){
        digitalWrite(2, HIGH);
        digitalWrite(3, HIGH);
        digitalWrite(4, HIGH);
}
delay(10);                                      //Delaying the update frequency of the serial print information
}
