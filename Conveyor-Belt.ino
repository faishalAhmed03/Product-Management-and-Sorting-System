void setup() {

pinMode(2,INPUT);

pinMode(7,OUTPUT);

Serial.begin(9600);

}


void loop() {

  if (digitalRead(2) == 1)

{

  Serial.println(digitalRead(2));

  digitalWrite(7,HIGH);

}  


else{

    delay(5000);

    digitalWrite(7,LOW);

    }

}