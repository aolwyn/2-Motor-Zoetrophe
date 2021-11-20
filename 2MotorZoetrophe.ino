const int controlPin1 = 2;
const int controlPin2 = 3;
const int controlPin3 = 6;
const int controlPin4 = 7;
const int enablePin = 9;
const int enablePin2 = 10;
const int dSwitchPin = 4;
const int oOSSSP = 5;
const int potPin = A0;
int oOSS = 0;
int poOSS = 0;
int dSS =0;
int pdSS = 0;
int motorEnabled = 0;
int motorSpeed = 0;
int motorDirection = 1;

void setup()
 {
  pinMode(dSwitchPin, INPUT);
  pinMode(oOSSSP, INPUT);
  pinMode(controlPin1, OUTPUT);
  pinMode(controlPin2, OUTPUT);
  pinMode(controlPin3, OUTPUT);
  pinMode(controlPin4, OUTPUT);
  pinMode(enablePin, OUTPUT);
  pinMode(enablePin2, OUTPUT);
  digitalWrite(enablePin, LOW);
 }
void loop()
 {
  oOSS = digitalRead(oOSSSP);
  delay(1);
  dSS = digitalRead(dSwitchPin);
  motorSpeed = analogRead(potPin)/4;
  if(oOSS != poOSS)
   {
    if(oOSS == HIGH)
     {
      motorEnabled = !motorEnabled;
     }
   }
  if (dSS != pdSS)
   {
    if (dSS == HIGH)
     {
      motorDirection = !motorDirection;
     } 
   } 
  if(motorDirection == 1) 
   {
    digitalWrite(controlPin1, HIGH);
    digitalWrite(controlPin2, LOW);
    digitalWrite(controlPin3, HIGH);
    digitalWrite(controlPin4, LOW);
   } 
  else
   { 
    digitalWrite(controlPin1, LOW);
    digitalWrite(controlPin2, HIGH);
    digitalWrite(controlPin3, LOW);
    digitalWrite(controlPin4, HIGH);
   }
  if(motorEnabled == 1)
   {
    analogWrite(enablePin, motorSpeed);
    analogWrite(enablePin2, motorSpeed);
   }
  else
   {
    analogWrite(enablePin, 0);
    analogWrite(enablePin2, 0);
   }
  pdSS = dSS;
  poOSS = oOSS;
 }
