#define PRE_PIN 18 
#define PRE_HEAT_SECONDS 10

const int sensorPin0 = 12; //mq3
const int sensorPin1 = 33; //mq2
const int sensorPin2 = 14; //mq6
const int sensorPin3 = 4; //mq9
const int sensorPin4 = 34; //mq8
const int sensorPin5 = 21; //mq5
const int sensorPin6 = 32; //mics_Vnox
const int sensorPin7 = 35; //mics_Vred


int sensorData0;
int sensorData1;
int sensorData2;
int sensorData3;
int sensorData4;
int sensorData5;
int sensorData6;
int sensorData7;

void setup() {

  // Setup preheater pin
  pinMode(PRE_PIN, OUTPUT);
  
  Serial.begin(115200);

  Serial.print("Preheating...");

  // Wait for preheating
  digitalWrite(PRE_PIN, HIGH);
  delay(PRE_HEAT_SECONDS * 1000);
  digitalWrite(PRE_PIN, LOW);
  Serial.println("Preheating Done");
  
  // Set sensor pin as input
  pinMode(sensorPin0,INPUT);
  pinMode(sensorPin1,INPUT);
  pinMode(sensorPin2,INPUT);
  pinMode(sensorPin3,INPUT);
  pinMode(sensorPin4,INPUT);
  pinMode(sensorPin5,INPUT);
  pinMode(sensorPin6,INPUT);
  pinMode(sensorPin7,INPUT);
  
}

void loop() {
  
  // Read sensor data
  sensorData0 = analogRead(sensorPin0);
  sensorData1 = analogRead(sensorPin1);
  sensorData2 = analogRead(sensorPin2);
  sensorData3 = analogRead(sensorPin3);
  sensorData4 = analogRead(sensorPin4);
  sensorData5 = analogRead(sensorPin5);
  sensorData6 = analogRead(sensorPin6);
  sensorData7 = analogRead(sensorPin7);
  
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
  Serial.println(sensorData7);
  
delay(1000); 
}
