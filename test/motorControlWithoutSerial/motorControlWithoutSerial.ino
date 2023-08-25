#define ENCODER_OPTIMIZE_INTERRUPTS
#include <Encoder.h>

#define PWM 6
#define DIRA 4
#define DIRB 5
#define ENCA 2
#define ENCB 3

Encoder motor(ENCA, ENCB);

int type;
long setPoint;
float kp, ki, kd;

const int simulationTime = 5000;
const int deltaT = 10;
int EncoderPulse[simulationTime/deltaT];
int Velocity[simulationTime/deltaT];
int Position[simulationTime/deltaT];
int Time[simulationTime/deltaT];
unsigned long tSimPastEncoder = 0;

unsigned long tPast = 0;
int lastPulse = 0;
int positionAngular = 0;
float velPulse_ms = 0;
long nPulseTurn = 1200;

int lastPos = 0;
int pos = 0;
float vel = 0;
float lastVel = 0;

void setup() {
  Serial.begin(9600);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  pinMode(13,OUTPUT);
  initialize();
}

void loop() {
  type = 1;
  setPoint = 180;
  kp = 0.5;
  ki = 0.001;
  kd = 5;
  PID();
}

void initialize(){
  for(int index = 0; index < simulationTime/deltaT; index++){
    Time[index] = deltaT*index;
  }
}

void readMensage(){
  int kp_aux, ki_aux, kd_aux;
  String mensage = Serial.readStringUntil('\n');
  sscanf(mensage.c_str(), "%d,%d,%d,%d,%d", &type, &setPoint, &kp_aux, &ki_aux, &kd_aux);
  kp = kp_aux/1000.0;
  ki = ki_aux/1000.0;
  kd = kd_aux/1000.0;
}

void sendMensage(){
  for (int i = 0; i < simulationTime/deltaT; i++) {
    if(type == 0){
      Serial.print(Position[i]);//Posicao
    }
    else{
      Serial.print(Velocity[i]);//Velocidade
    }
    Serial.print(",");
    Serial.print(Time[i]);
    if (i < simulationTime/deltaT - 1) {
      Serial.print(",");
    }
  }
  Serial.print("\n");
}

void moveMotor(int me){
  if(me>0){
    me = constrain(me,25,255);
    digitalWrite(DIRA,HIGH);
    digitalWrite(DIRB,LOW);
  }
  if(me < 0){
    digitalWrite(DIRA,LOW);
    digitalWrite(DIRB,HIGH);
    me = constrain(me,-255,-25);
  }
  analogWrite(PWM,abs(me));
}

void PID(long SETPOINT, float KP, float KI, float KD){
  motor.write(0);
  int index_encoder = 0;
  float error = 0, error_anterior = 0;
  float error_integrativo = 0;
  int correction = 0;
  while(index_encoder < simulationTime/deltaT){
    
    if(millis() - tSimPastEncoder > deltaT){
      EncoderPulse[index_encoder] = motor.read();
      tSimPastEncoder = millis();
      index_encoder++;

      if(type == 0){
        pos = getPosition();
        error = setPoint - pos;
        correction = kp * error + ki * error_integrativo - kd * (pos - lastPos);
        error_integrativo += error;
        error_anterior = error;
        lastPos = pos;
      }
      else{
        vel = getVelocity();
        error = setPoint*nPulseTurn/60000.0 - vel;
        correction += kp * error + ki * error_integrativo - kd * (vel - lastVel);
        error_integrativo += error;
        error_anterior = error;
        lastVel = vel;
      }
      correction = constrain(correction,-255,255);
      moveMotor(correction);
    }
  }    
  moveMotor(0);
}

void dataConverter(){
  if(type == 0){ //posicao
    for(int index = 0; index < simulationTime/deltaT;  index++){
      Position[index] = EncoderPulse[index] * 360.0 / nPulseTurn;
    }
  }
  else{ //velocidade
    Velocity[0] = 0;
    for(int index = 1; index < simulationTime/deltaT;  index++){
      Velocity[index] = int((EncoderPulse[index] - EncoderPulse[index-1]) / float(Time[index] - Time[index-1]) * 60000 / nPulseTurn);
    }
  }
}

float getVelocity(){
  float velPulse_ms = (motor.read() - lastPulse)/float(millis() - tPast);
  lastPulse = motor.read();
  tPast = millis(); 
  return velPulse_ms;
}

int getPosition(){
  return positionAngular = motor.read() * 360.0 / nPulseTurn;
}
