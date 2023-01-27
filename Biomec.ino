
const int trigPinF = 47;
const int echoPinF = 49;
const int buzzer = 8;
const int vibF = 32;
const int vibR = 30;
const int vibL = 28;
const int trigPinR = 53;
const int echoPinR = 51;
const int trigPinL = 50;
const int echoPinL = 52;




void setup() 
{
  
  pinMode(trigPinF, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPinF, INPUT); // Sets the echoPin as an Input
  pinMode(buzzer, OUTPUT);
    pinMode(vibF, OUTPUT);
  pinMode(vibR, OUTPUT);
   pinMode(vibL, OUTPUT);
  pinMode(trigPinR, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPinR, INPUT); // Sets the echoPin as an Input
  pinMode(trigPinL, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPinL, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600);
   
}

void Forw()
{
  int distanceF;
  int safetyDistanceF;
  long durationF;


  digitalWrite(trigPinF, LOW);


  delayMicroseconds(2);

  digitalWrite(trigPinF, HIGH);
//  delayMicroseconds(2);

  digitalWrite(trigPinF, LOW);
  delayMicroseconds(2);
  durationF = pulseIn(echoPinF, HIGH);

  delayMicroseconds(2);

  distanceF = durationF * 0.034 / 2;

  safetyDistanceF = distanceF;
  Serial.print("DistanceF: ");
  Serial.println(distanceF);
if ((safetyDistanceF <50)&&(safetyDistanceF >=30))
{
   digitalWrite(vibF, HIGH);
  analogWrite(buzzer, 10);
  delay(1000);
 analogWrite(buzzer, 0);
 digitalWrite(vibF, LOW);
 delay(1000);
}
else if((safetyDistanceF <30)&&(safetyDistanceF >=10))
 {
   analogWrite(buzzer, 10);
    digitalWrite(vibF, HIGH);
   delay(500);
   analogWrite(buzzer, 0);
    digitalWrite(vibF, LOW);
   delay(10);
  }
  else if (safetyDistanceF <10)
  {
analogWrite(buzzer, 10);
 digitalWrite(vibF, HIGH);
  
}
else
{
  analogWrite(buzzer, 0);
   digitalWrite(vibF, LOW);
  }

}

void Right()
{
  int safetyDistanceR;
  long durationR;
  int distanceR;
  digitalWrite(trigPinR, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPinR, HIGH);
  //delayMicroseconds(2);
  digitalWrite(trigPinR, LOW);
  delayMicroseconds(2);
  durationR = pulseIn(echoPinR, HIGH);

  distanceR = durationR * 0.034 / 2;
  safetyDistanceR = distanceR;
  Serial.print("DistanceR: ");
  Serial.println(distanceR);
if (safetyDistanceR <50)
{
   digitalWrite(vibR, HIGH);
  
  delay(1000);
 analogWrite(buzzer, 0);

 delay(1000);
}

}


void Left()
{
  long durationL;
  int distanceL;
  int safetyDistanceL;

  digitalWrite(trigPinL, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPinL, HIGH);
 // delayMicroseconds(2);
  digitalWrite(trigPinL, LOW);
  delayMicroseconds(2);
  durationL = pulseIn(echoPinL, HIGH);
  distanceL = durationL * 0.034 / 2;
  safetyDistanceL = distanceL;
  Serial.print("DistanceL: ");
  Serial.println(distanceL);
  if (safetyDistanceL <50)
{
   digitalWrite(vibL, HIGH);
  
  delay(1000);
 
 digitalWrite(vibL, LOW);
 delay(1000);
}
}

void loop()
{

   Forw();
  delay(100);
   Right();
  delay(100);
   Left();
  delay(100);
}
