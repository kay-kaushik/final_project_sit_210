


int smokeA0=A0;
int buzzer =11;
float sensorValue;
int redLed = 2;
void setup() {
  pinMode(buzzer,OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(smokeA0,INPUT);
  Serial.begin(9600); // sets the serial port to 9600
  noTone(buzzer);
 
}

void loop() {
  sensorValue=analogRead(smokeA0);
  Serial.println(sensorValue);
  
  if(sensorValue > 200)
  {
    tone(buzzer,1000,200);
    digitalWrite(redLed, HIGH);
  }
  else
  {
     noTone(buzzer);
  }
 
  delay(2000); // wait 2s for next reading
}
