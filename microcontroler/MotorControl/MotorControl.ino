#define PWM 6
#define DIRA 4
#define DIRB 5
#define ENCA 2
#define ENCB 3

int type = 2, setPoint, kp_aux, ki_aux, kd_aux;
float kp, ki, kd;

const int simulationTime = 1000;
const int deltaT = 100;
int EncoderPulse[simulationTime/deltaT];
int Velocity[simulationTime/deltaT];
int Position[simulationTime/deltaT];
float Time[simulationTime/deltaT];

void setup() {
  Serial.begin(9600);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  pinMode(13,OUTPUT);
  initialize();
}

void loop() {
  while(!Serial.available()){
    digitalWrite(13,LOW);
  }
  readMensage();
  PID();
  dataConverter();
  delay(1000);
  sendMensage();
}

void initialize(){
  for(int index = 0; index < simulationTime/deltaT; index++){
    Time[index] = deltaT*index;
  }
}

void readMensage(){
  String mensage = Serial.readStringUntil('\n');
  sscanf(mensage.c_str(), "%d,%d,%d,%d,%d", &type, &setPoint, &kp_aux, &ki_aux, &kd_aux);
  kp = kp_aux/1000.0;
  ki = ki_aux/1000.0;
  kd = kd_aux/1000.0;
}

void sendMensage(){
  for (int i = 0; i < simulationTime/deltaT; i++) {
    Serial.print(Time[i]);
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
    digitalWrite(DIRA,HIGH);
    digitalWrite(DIRB,LOW);
  }
  else{
    digitalWrite(DIRA,LOW);
    digitalWrite(DIRB,HIGH);
  }
  analogWrite(PWM,abs(me));
}

void PID(){
  if(type == 0){ //posicao
  
  }
  else{ //velocidade
    
  }
}

void dataConverter(){
  if(type == 0){ //posicao
  
  }
  else{ //velocidade
    
  }
}
