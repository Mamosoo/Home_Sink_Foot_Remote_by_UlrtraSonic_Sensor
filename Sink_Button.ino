int trigPin = 13; // int trig pin (ultrasonic sensor)
int echoPin = 12; // int echo pin (ultrasonic sensor)
int relayPin = 8; // int relay pin
 
 
void setup(){
  
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT); // send
  pinMode(echoPin, INPUT); // get
  pinMode(relayPin, OUTPUT); // send
  
}
 

void loop(){
  
  float duration, distance;
  digitalWrite(trigPin, HIGH);
  delay(100);
  digitalWrite(trigPin, LOW);
 


  distance = ((float)(340 * duration) / 10000) / 2; // measure distance

  if (distance <= 10.0)
  {
    digitalWrite(relayPin, HIGH); // puts high on relay when the feet croos the sensor(to replace the frs sensor)
  }
  else if (distance <= 3.0)
  {
    digitalWrite(relayPin, LOW); // put low on rlay when the feet cover the sensor
  }
  else
  {
    digitalWrite(relayPin, LOW); // put low when not using sink
  }
 delay(1000);


  Serial.print("Duration:");
  Serial.print(duration);
  Serial.print("\nDIstance:");
  Serial.print(distance);
  Serial.println("cm\n");
  delay(1000);
}

