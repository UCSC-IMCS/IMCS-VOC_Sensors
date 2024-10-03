#define PRE_PIN 2
#define PRE_HEAT_SECONDS 10

const int sensorPin0 = A15; //mq2
const int sensorPin1 = A1; //mq3
const int sensorPin2 = A2; //mq5
const int sensorPin3 = A3; //mq6
const int sensorPin4 = A4; //mq8
const int sensorPin5 = A5; //mq9
const int sensorPin6 = A14; //mics_Vred
const int sensorPin7 = A7; //mics_Vnox
const int sensorPin8 = A8; //mq214


int sensorData0;
int sensorData1;
int sensorData2;
int sensorData3;
int sensorData4;
int sensorData5;
int sensorData6;
int sensorData7;
int sensorData8;

bool preheatingDone = false; // to track preheating status

void setup() {
//  Setup preheater pin
  pinMode(PRE_PIN, OUTPUT);
 
  Serial.begin(115200);
//  Serial.println("Preheating...");

  // Start preheating
  digitalWrite(PRE_PIN, HIGH);
  delay(PRE_HEAT_SECONDS * 1000);
  digitalWrite(PRE_PIN, LOW);

  // Preheating done, start sending sensor data
  preheatingDone = true;
}

void loop() {
  if (preheatingDone) { // Only send sensor data after preheating
    // Read sensor data
    sensorData0 = analogRead(sensorPin0);
    sensorData1 = analogRead(sensorPin1);
    sensorData2 = analogRead(sensorPin2);
    sensorData3 = analogRead(sensorPin3);
    sensorData4 = analogRead(sensorPin4);
    sensorData5 = analogRead(sensorPin5);
    sensorData6 = analogRead(sensorPin6);
    sensorData7 = analogRead(sensorPin7);
    sensorData8 = analogRead(sensorPin8);

   
    // Print sensor data to Serial monitor
    Serial.print(sensorData0);
    Serial.print(", ");
    Serial.print(sensorData1);
    Serial.print(", ");
    Serial.print(sensorData2);
    Serial.print(", ");
    Serial.print(sensorData3);
    Serial.print(", ");
    Serial.print(sensorData4);
    Serial.print(", ");
    Serial.print(sensorData5);
    Serial.print(", ");
    Serial.print(sensorData6);
    Serial.print(", ");
    Serial.print(sensorData7);
    Serial.print(", ");
    Serial.println(sensorData8);
  }
 
  delay(1000);
}
