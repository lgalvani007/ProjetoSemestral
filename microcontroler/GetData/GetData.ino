#define ENCODER_OPTIMIZE_INTERRUPTS
#include <Encoder.h>

#define PWM 6
#define DIRA 4
#define DIRB 5
#define ENCA 2
#define ENCB 3

Encoder motor(ENCA, ENCB);

const int simulationTime = 2000;
const int deltaT = 10;
long Data[simulationTime/deltaT];
int Time[simulationTime/deltaT];
unsigned long tSimPastEncoder = 0;

unsigned long tPast = 0;
long lastPulse = 0;
long nPulseTurn = 1200;

void setup() {
  Serial.begin(9600);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  pinMode(13,OUTPUT);
  initialize();
}

void loop() {
  while(!Serial.available()){
  }
  int velocity = Serial.parseInt();
  if(velocity != 0){
    motorStep(velocity);
    sendMensage();
  }
}

void initialize(){
  for(int index = 0; index < simulationTime/deltaT; index++){
    Time[index] = deltaT*index;
  }
}

void sendMensage(){
  for (int index = 0; index < simulationTime/deltaT; index++) {
    Serial.print(Data[index]);//Posicao
//    Serial.print(F(","));
//    Serial.print(Time[index]);
    Serial.print(F("\n"));
  }
}

void moveMotor(int me){
  if(me>0){
    digitalWrite(DIRA,HIGH);
    digitalWrite(DIRB,LOW);
    me = constrain(me,25,255);
  }
  else if(me < 0){
    digitalWrite(DIRA,LOW);
    digitalWrite(DIRB,HIGH);
    me = constrain(me,-255,-25);
  }
  analogWrite(PWM,abs(me));
}

void motorStep(int velocity){
  int index_encoder = 0;
  moveMotor(velocity);
  motor.write(0);
  while(index_encoder < simulationTime/deltaT){
    if(millis() - tSimPastEncoder > deltaT){
      Data[index_encoder] = motor.read();
      tSimPastEncoder = millis();
      index_encoder++;
    }
  }
  moveMotor(0);
}

float getVelocity(){
  float velPulse_ms = (motor.read() - lastPulse)/float(millis() - tPast);
  lastPulse = motor.read();
  tPast = millis(); 
  return velPulse_ms;
}
