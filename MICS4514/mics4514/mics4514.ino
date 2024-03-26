
//--------------------------------------------------------------------
//append data to same doc

#include <SPI.h>
#include <SD.h>

#define PRE_PIN 2    
#define VNOX_PIN A0  
#define VRED_PIN A1  

#define PRE_HEAT_SECONDS 10

int vnox_value = 0;
int vred_value = 0;

File dataFile;

void setup() {
  // Initialize SD card
  if (!SD.begin(A0)) {
    Serial.println("SD initialization failed!");
    return;
  }
  Serial.println("SD initialization done.");

  // Setup preheater pin
  pinMode(PRE_PIN, OUTPUT);

  // Initialize serial port
  Serial.begin(9600);
  Serial.println("MiCS-4514 Test Read");
  Serial.print("Preheating...");

  // Wait for preheating
  digitalWrite(PRE_PIN, HIGH);
  delay(PRE_HEAT_SECONDS * 1000);
  digitalWrite(PRE_PIN, LOW);
  Serial.println("Done");

  // Open the data file in write mode
  dataFile = SD.open("data.csv", FILE_WRITE);
  if (!dataFile) {
    Serial.println("Error opening data file.");
    return;
  } else {
    Serial.println("Data file opened successfully.");
  }

  // Write header to the data file
  dataFile.println("Time,Vnox,Vred");
  dataFile.close();
}

void loop() {
  // Read analog values
  vnox_value = analogRead(VNOX_PIN);
  vred_value = analogRead(VRED_PIN);

  // Get current time in milliseconds
  unsigned long currentTime = millis();

  // Convert milliseconds to hours, minutes, and seconds
  unsigned long seconds = currentTime / 1000;
  unsigned long hours = seconds / 3600;
  seconds %= 3600;
  unsigned long minutes = seconds / 60;
  seconds %= 60;

  // Format the timestamp string
  char timestamp[20];
  sprintf(timestamp, "%02lu:%02lu:%02lu", hours, minutes, seconds);

  // Print timestamp and values to Serial monitor
  Serial.print("Time: ");
  Serial.print(timestamp);
  Serial.print(" Vnox: ");
  Serial.print(vnox_value);
  Serial.print(" Vred: ");
  Serial.println(vred_value);

  // Save values to SD card
  saveToSD(currentTime, vnox_value, vred_value);

   // Delay for 1 second
  delay(1000);
}

void saveToSD(unsigned long time, int vnox, int vred) {
  // Open the data file in append mode
  dataFile = SD.open("data.csv", FILE_WRITE);
  if (!dataFile) {
    Serial.println("Error opening data file.");
    return;
  }
  
  // Convert milliseconds to hours, minutes, and seconds
  unsigned long seconds = time / 1000;
  unsigned long hours = seconds / 3600;
  seconds %= 3600;
  unsigned long minutes = seconds / 60;
  seconds %= 60;

  // Format the timestamp string
  char timestamp[20];
  sprintf(timestamp, "%02lu:%02lu:%02lu", hours, minutes, seconds);

  // Write timestamp and data to the file
  dataFile.print(timestamp);
  dataFile.print(",");
  dataFile.print(vnox);
  dataFile.print(",");
  dataFile.println(vred);
  dataFile.close();
}



//----------------------------------------------------------------------
//code with sd card writing but issue with timestamp

//#include <SPI.h>
//#include <SD.h>
//
//
//#define PRE_PIN 2    // Changed to a non-SPI pin
//#define VNOX_PIN A0  // Changed to a non-SPI pin
//#define VRED_PIN A1  // Changed to a non-SPI pin
//
//#define PRE_HEAT_SECONDS 10
//
//int vnox_value = 0;
//int vred_value = 0;
//
//File dataFile;
//
//void setup()
//{
//  // Initialize SD card
//  if (!SD.begin(A0)) { 
//    Serial.println("SD initialization failed!");
//    return;
//  }
//  Serial.println("SD initialization done.");
//
//  // Setup preheater pin
//  pinMode(PRE_PIN, OUTPUT);
//
//  // Initialize serial port
//  Serial.begin(9600);
//  Serial.println("MiCS-4514 Test Read");
//  Serial.print("Preheating...");
//
//  // Wait for preheating
//  digitalWrite(PRE_PIN, HIGH);
//  delay(PRE_HEAT_SECONDS * 1000);
//  digitalWrite(PRE_PIN, LOW);
//  Serial.println("Done");
//
//  // Open the data file in write mode
//  dataFile = SD.open("data.csv", FILE_WRITE);
//  if (!dataFile) {
//    Serial.println("Error opening data file.");
//    return;
//  } else {
//    Serial.println("Data file opened successfully.");
//  }
//
//  // Write header to the data file
//  dataFile.println("Time,Vnox,Vred");
//  dataFile.close();
//}
//
//void loop()
//{
//  // Read analog values
//  vnox_value = analogRead(VNOX_PIN);
//  vred_value = analogRead(VRED_PIN);
//
//  // Print values to Serial monitor
//  Serial.print("Vnox: ");
//  Serial.print(vnox_value);
//  Serial.print(" Vred: ");
//  Serial.println(vred_value);
//
//  // Get current time
//  unsigned long currentTime = millis();
//
//  // Save values to SD card
//  saveToSD(currentTime, vnox_value, vred_value);
//
//   // Delay for 1 second
//  delay(1000);
//}
//
//void saveToSD(unsigned long time, int vnox, int vred) {
//  // Open the data file in append mode
//  dataFile = SD.open("data.csv", FILE_WRITE);
//  if (!dataFile) {
//    Serial.println("Error opening data file.");
//    return;
//  }
//  
//  // Write data to the file
//  dataFile.print(time);
//  dataFile.print(",");
//  dataFile.print(vnox);
//  dataFile.print(",");
//  dataFile.println(vred);
//  dataFile.close();
//}


//------------------------------------------
//code without sd card writing

//#define PRE_PIN 2
//#define VNOX_PIN A0
//#define VRED_PIN A1
//
//#define PRE_HEAT_SECONDS 10
//
//int vnox_value = 0;
//int vred_value = 0;
//
//void setup()
//{
//
//  // Setup preheater pin
//  pinMode(PRE_PIN, OUTPUT);
//
//  // Initialize serial port
//  Serial.begin(9600);
//  Serial.println("MiCS-4514 Test Read");
//  Serial.print("Preheating...");
//
//  // Wait for preheating
//  digitalWrite(PRE_PIN, 1);
//  delay(PRE_HEAT_SECONDS * 1000);
//  digitalWrite(PRE_PIN, 0);
//  Serial.println("Done");
//}
//
//void loop()
//{
//
//  // Read analog values, print them out, and wait
//  vnox_value = analogRead(VNOX_PIN);
//  vred_value = analogRead(VRED_PIN);
//  Serial.print("Vnox: ");
//  Serial.print(vnox_value, DEC);
//  Serial.print(" Vred: ");
//  Serial.println(vred_value, DEC);
//  delay(1000);
//}
