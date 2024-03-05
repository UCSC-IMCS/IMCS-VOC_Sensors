#include <Arduino.h>

// the setup routine runs once when you press reset:
void setup()
{
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop()
{
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(20);
}

// int sensorPin = A5;
// int sensorData;
// void setup()
// {
//   Serial.begin(9600);
//   pinMode(sensorPin, INPUT);
// }
// void loop()
// {
//   sensorData = analogRead(sensorPin);
//   Serial.print("Sensor Data:");

//   delay(100);
// }
