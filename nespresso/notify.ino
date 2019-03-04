int sensorValue = 0;
int sensorLow = 1023;
int sensorHigh = 0;
int loops = 0;

void setup() {
  Serial.begin(9600);
  
  while(millis() < 4000){
    sensorValue = analogRead(A0);
    if(sensorValue > sensorHigh){
      sensorHigh = sensorValue; 
    }
    if(sensorValue < sensorLow){
      sensorLow = sensorValue;  
    }
  }
}

void loop() {
  sensorValue = analogRead(A0);

  if(sensorValue >= sensorHigh){
    loops++;  
  }else{
    loops=0;  
  }

  if(loops > 5){
    tone(8, 1000, 30);
    delay(200);
    tone(8, 1200, 40);
    delay(200);
    tone(8, 1300, 50);
    delay(200);
    tone(8, 1500, 60);
    loops = 0;
      
  }else{
    delay(250);
  }

}
