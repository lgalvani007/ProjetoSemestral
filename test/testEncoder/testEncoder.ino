#define ENCODER_OPTIMIZE_INTERRUPTS
#include <Encoder.h>

#define PWM 6
#define DIRA 4
#define DIRB 5
#define ENCA 2
#define ENCB 3

#define nPulseTurn 300

Encoder motor(ENCA, ENCB);

unsigned long tPast = 0;
long lastPulse = 0;
int vel_RPM = 0;
int positionAngular = 0;

void setup(){
  Serial.begin(9600);
  motor.write(motor.read());
}

void loop(){
  Serial.println(motor.read());
}

void getVelocity(){
  unsigned long tNow = millis();
  long newPulse = motor.read();
  float velPulse_ms = (newPulse - lastPulse)/(tNow - tPast);
  lastPulse = newPulse;
  tPast = tNow;
  vel_RPM = velPulse_ms * 60000 / nPulseTurn;
}

void getPosition(){
  positionAngular = motor.read() * 360 / nPulseTurn;
}
