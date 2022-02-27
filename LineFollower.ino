#include <AFMotor.h>
int sensorA;
int sensorB;
int sensorC;
int sensorD;
AF_DCMotor motorA(2);
AF_DCMotor motorB(3);

void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  Serial.begin(9600);
  motorA.setSpeed(200);
  motorB.setSpeed(200);
  motorA.run(RELEASE);
  motorB.run(RELEASE);

}

void loop() {
sensorA=analogRead(A0);
sensorB=analogRead(A1);
sensorC=analogRead(A2);
sensorD=analogRead(A3);
Serial.println(sensorC);
//Serial.println(sensorD);
if (sensorB<500 and sensorA>500){
  motorB.run(FORWARD);
  motorA.run(RELEASE);
  delay(80);
}
else if (sensorA<500 and sensorB>500){
  motorA.run(FORWARD);
  motorB.run(RELEASE);
  delay(80);
}
else if (sensorA>500 and sensorB>500){
  motorA.run(FORWARD);
  motorB.run(FORWARD);
}
else if (sensorC>100){
  motorA.run(RELEASE);
  motorB.run(FORWARD);
  delay(700);
}
else if (sensorD>100){
  motorA.run(FORWARD);
  motorB.run(RELEASE);
  delay(700);
}
else{
  motorA.run(RELEASE);
  motorB.run(RELEASE);  
}


}
