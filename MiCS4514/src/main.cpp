#include <Arduino.h>

const int CO_PIN = A0;  // Analog pin for CO
const int NO2_PIN = A1; // Analog pin for NO2

void setup()
{
  Serial.begin(9600); // Initialize serial communication
}

void loop()
{
  // Read analog values from the sensor
  int coValue = analogRead(CO_PIN);
  int no2Value = analogRead(NO2_PIN);

  // Convert analog values to voltage
  float coVoltage = coValue * (5.0 / 1023.0);
  float no2Voltage = no2Value * (5.0 / 1023.0);

  // Convert voltage to concentration (values specific to the sensor)
  float coConcentration = coVoltage * 1000 / 0.05;
  float no2Concentration = no2Voltage * 1000 / 0.05;

  // Print the values
  Serial.print("CO Concentration: ");
  Serial.print(coConcentration);
  Serial.println(" ppm");

  Serial.print("NO2 Concentration: ");
  Serial.print(no2Concentration);
  Serial.println(" ppm");

  delay(1000); // Delay for stability
}
