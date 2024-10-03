#include <SPI.h>
#include <SD.h>

const int sensorPin = A0;
int sensorData;
File dataFile;

void setup() {
  Serial.begin(9600);

  // Initialize SD card
  if (!SD.begin(A0)) {
    Serial.println("SD card initialization failed!");
    return;
  }
  Serial.println("SD card initialized.");

  // Open file for writing
  dataFile = SD.open("datalog.csv", FILE_WRITE);
  if (!dataFile) {
    Serial.println("Error opening datalog.csv!");
    return;
  }
  Serial.println("Logging data to datalog.csv...");
  dataFile.println("Sensor Data");
}

void loop() {
  // Read sensor data
  sensorData = analogRead(sensorPin);
  
  // Print sensor data to serial monitor
  Serial.print("Sensor Data: ");
  Serial.println(sensorData);

  // Log sensor data to CSV file
  if (dataFile) {
    dataFile.print(sensorData);
    dataFile.println();
  } else {
    Serial.println("Error writing to datalog.csv!");
  }

  delay(100); // Adjust delay as needed
}
