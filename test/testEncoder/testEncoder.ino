#define ENCODER_OPTIMIZE_INTERRUPTS
#include <Encoder.h>

#define PWM 6
#define DIRA 4
#define DIRB 5
#define ENCA 2
#define ENCB 3

#define nPulseTurn 1200

Encoder motor(ENCA, ENCB);

unsigned long tPast = 0;
long lastPulse = 0;
int vel_RPM = 0;
int positionAngular = 0;
float velPulse_ms = 0;


void setup(){
  Serial.begin(9600);
  motor.write(motor.read());
}

void loop(){
  Serial.println(getPosition());

}

float getVelocity(){
  unsigned long tNow = millis();
  long newPulse = motor.read();
  float velPulse_ms = (newPulse - lastPulse)/float(tNow - tPast);
  lastPulse = newPulse;
  tPast = tNow; 
  return velPulse_ms;
//  return vel_RPM = velPulse_ms * 60000.0 / nPulseTurn;
}

int getPosition(){
  return positionAngular = motor.read() * 360.0 / nPulseTurn;
}
