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
  int type = 2;
  long setPoint;
  float kp, ki, kd;

  while(!Serial.available());
  digitalWrite(13,LOW);
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
  long kp_aux, ki_aux, kd_aux;
  String mensage = Serial.readStringUntil('\n');
  sscanf(mensage.c_str(), "%d,%ld,%ld,%ld,%ld", TYPE, SETPOINT, &kp_aux, &ki_aux, &kd_aux);
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
    digitalWrite(DIRA,HIGH);
    digitalWrite(DIRB,LOW);
    me = constrain(me,1,255);
  }
  else if(me < 0){
    digitalWrite(DIRA,LOW);
    digitalWrite(DIRB,HIGH);
    me = constrain(me,-255,-1);
  }
  analogWrite(PWM,abs(me));
  if(abs(me) == 255){
    digitalWrite(13,HIGH);
  }
}

void PID(int TYPE, long SETPOINT, float KP, float KI, float KD){
  int index_encoder = 0;
  float error = 0, error_anterior = 0, error_anterior_anterior = 0;
  float error_integrativo = 0;
  float correction = 0, correction_anterior = 0, correction_anterior_anterior = 0 ;
  long lastPos = 0;
  long pos = 0;
  float vel = 0;
  float lastVel = 0;
  motor.write(0);
  lastPulse = 0;
  while(index_encoder < simulationTime/deltaT){
    if(millis() - tSimPastEncoder > deltaT){
      if(TYPE == 0){
        pos = getPosition();
        error = float(long(SETPOINT*nPulseTurn/360.0) - pos);
        correction = KP * error + KI * error_integrativo - KD * float((pos - lastPos));
        error_integrativo += error;
        error_integrativo = constrain(error_integrativo,-360.0*nPulseTurn/360.0,360.0*nPulseTurn/360.0);
        error_anterior = error;
        lastPos = pos;
        Data[index_encoder] = int(pos*360.0/float(nPulseTurn));
      }
      else if(TYPE == 1){
        vel = getVelocity();
        error = float(SETPOINT*nPulseTurn/60000.0) - vel;
        correction += KP * error + KI * error_integrativo - KD * (vel - lastVel);
        error_integrativo += error;
        error_integrativo = constrain(error_integrativo,-600.0,600.0);
        error_anterior = error;
        lastVel = vel;
        Data[index_encoder] = int(vel * 60000 / nPulseTurn);
      }
      else if(TYPE == 2){
        //Avanço de fase 10ms
        pos = getPosition();
        error = float(long(SETPOINT*nPulseTurn/360.0) - pos);
        correction = 54.26*error - 52.83*error_anterior + 0.9649*correction;
        error_anterior = error;
        Data[index_encoder] = int(pos*360.0/float(nPulseTurn));
      }
      else if(TYPE == 3){
        //P mao 10ms
        pos = getPosition();
        error = float(long(SETPOINT*nPulseTurn/360.0) - pos);
        correction = 1.035*error;
        Data[index_encoder] = int(pos*360.0/float(nPulseTurn));
      }
      else if(TYPE == 4){
        //PD mao 10ms
        pos = getPosition();
        error = float(long(SETPOINT*nPulseTurn/360.0) - pos);
        correction = 17.43*error - 16.77*error_anterior - correction;
        error_anterior = error;
        Data[index_encoder] = int(pos*360.0/float(nPulseTurn));
      }
      else if(TYPE == 5){
        //P MatLab 10ms
        pos = getPosition();
        error = float(long(SETPOINT*nPulseTurn/360.0) - pos);
        correction = 211.2*error - 421.7*error_anterior + 210.5*error_anterior_anterior + correction_anterior ;
        error_anterior = error;
        error_anterior_anterior = error_anterior;
        correction_anterior = correction;
        correction_anterior_anterior = correction_anterior;
        Data[index_encoder] = int(pos*360.0/float(nPulseTurn));
      }
      else if(TYPE == 6){
        //PD MatLab 10ms
        pos = getPosition();
        error = float(long(SETPOINT*nPulseTurn/360.0) - pos);
        correction = 0.2397*error - 0.2235*error_anterior + 0.8902*correction;
        error_anterior = error;
        Data[index_encoder] = int(pos*360.0/float(nPulseTurn));
      }
      correction = constrain(correction,-255.0,255.0);
      moveMotor(int(correction));
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

long getPosition(){
//  return long(motor.read() * 360.0 / nPulseTurn);
  return long(motor.read());
}
