float sensor=A14;
float gas_value;

void setup(){
pinMode(sensor,INPUT);
Serial.begin(115200);
}
void loop(){
gas_value=analogRead(sensor);
Serial.println(gas_value);
delay(600);
}
