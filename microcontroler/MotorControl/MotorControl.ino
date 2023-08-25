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
int Data[simulationTime/deltaT];
int Time[simulationTime/deltaT];
unsigned long tSimPastEncoder = 0;

unsigned long tPast = 0;
int lastPulse = 0;
long nPulseTurn = 1200;

void setup() {
  Serial.begin(9600);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  pinMode(13,OUTPUT);
  initialize();
}

void loop() {
  int type = 2;
  long setPoint;
  float kp, ki, kd;

  while(!Serial.available()){
    digitalWrite(13,HIGH);
  }
  readMensage(&type, &setPoint, &kp, &ki, &kd);
  PID(type,setPoint,kp,ki,kd);
  sendMensage(type);
}

void initialize(){
  for(int index = 0; index < simulationTime/deltaT; index++){
    Time[index] = deltaT*index;
  }
}

void readMensage(int *TYPE, long *SETPOINT, float *KP, float *KI, float *KD){
  int kp_aux, ki_aux, kd_aux;
  String mensage = Serial.readStringUntil('\n');
  sscanf(mensage.c_str(), "%d,%d,%d,%d,%d", TYPE, SETPOINT, &kp_aux, &ki_aux, &kd_aux);
  *KP = kp_aux/1000.0;
  *KI = ki_aux/1000.0;
  *KD = kd_aux/1000.0;
}

void sendMensage(int TYPE){
  for (int index = 0; index < simulationTime/deltaT; index++) {
    Serial.print(Data[index]);//Posicao
    Serial.print(F(","));
    Serial.print(Time[index]);
    if (index < simulationTime/deltaT - 1) {
      Serial.print(F(","));
    }
  }
  Serial.print(F("\n"));
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

void PID(int TYPE, long SETPOINT, float KP, float KI, float KD){
  int index_encoder = 0;
  float error = 0, error_anterior = 0;
  float error_integrativo = 0;
  int correction = 0;
  int lastPos = 0;
  int pos = 0;
  float vel = 0;
  float lastVel = 0;
  motor.write(0);
  lastPulse = 0;
  while(index_encoder < simulationTime/deltaT){
    if(millis() - tSimPastEncoder > deltaT){
      if(TYPE == 0){
        pos = getPosition();
        error = SETPOINT - pos;
        correction = KP * error + KI * error_integrativo - KD * (pos - lastPos);
        error_integrativo += error;
        error_anterior = error;
        lastPos = pos;
        Data[index_encoder] = pos;
      }
      else{
        vel = getVelocity();
        error = SETPOINT*nPulseTurn/60000.0 - vel;
        correction += KP * error + KI * error_integrativo - KD * (vel - lastVel);
        error_integrativo += error;
        error_anterior = error;
        lastVel = vel;
        Data[index_encoder] = int(vel * 60000 / nPulseTurn);
      }
      correction = constrain(correction,-255,255);
      moveMotor(correction);
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

int getPosition(){
  return motor.read() * 360.0 / nPulseTurn;
}
