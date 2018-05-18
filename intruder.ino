#include <SoftwareSerial.h>

#define trigPin 9
#define echoPin 8

SoftwareSerial BT(6,7); //TX, RX respetively


void setup() 
{ 
  BT.begin(9600);
  Serial.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration, distance;

  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) /29.1;
  if(distance<60.0){
   
  BT.println("Intrusion detected");
 
  }
 
  delay(500);
}

