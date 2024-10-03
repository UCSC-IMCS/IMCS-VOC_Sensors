#include <SD.h>

const int sensorPin0 = A0;
const int sensorPin1 = A1;
const int sensorPin2 = A2;
int sensorData0;
int sensorData1;
int sensorData2;
File dataFile;

void setup() {
  Serial.begin(9600);
  
//  // Initialize SD card
//  if (!SD.begin(A0)) { // Change A0 to match your SD module's chip select pin
//    Serial.println("SD card initialization failed!");
//    return;
//  }
//  Serial.println("SD card initialized.");
//  
  // Set sensor pin as input
  pinMode(sensorPin0,INPUT);
  pinMode(sensorPin1,INPUT);
  pinMode(sensorPin2,INPUT);
  
//  // Open file for writing (will create file if not existing)
//  dataFile = SD.open("data.csv", FILE_WRITE);
//  if (!dataFile) {
//    Serial.println("Error opening data.csv");
//  } else {
//    // Write column title only if the file was opened successfully
//    dataFile.println("Sensor Data");
//    dataFile.flush(); // Ensure title is written to the card
//  }
}

void loop() {
  // Read sensor data
  sensorData0 = analogRead(sensorPin0);
  sensorData1 = analogRead(sensorPin1);
  sensorData2 = analogRead(sensorPin2);
  
  // Print sensor data to Serial monitor
//  Serial.print("Sensor Data: ");
Serial.print(sensorData0);
Serial.print(", ");
Serial.print(sensorData1);
Serial.print(", ");
Serial.println(sensorData2);

  
  // Append sensor data to file
//  if (dataFile) {
//    dataFile.println(sensorData);
//    dataFile.flush(); // Ensure data is written to the card
//  } else {
//    // Attempt to reopen file
//    dataFile = SD.open("data.csv", FILE_WRITE);
//    if (!dataFile) {
//      Serial.println("Error reopening data.csv");
//    } else {
//      Serial.println("File reopened successfully");
//    }
//  }
  
  delay(1000); 
}
