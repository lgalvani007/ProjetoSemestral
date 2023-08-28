/* Encoder Library - Basic Example
 * http://www.pjrc.com/teensy/td_libs_Encoder.html
 *
 * This example code is in the public domain.
 */

#include <Encoder.h>
#define PWM 6
#define DIRA 4
#define DIRB 5
#define ENCA 2
#define ENCB 3

// Change these two numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
Encoder myEnc(2, 3);
//   avoid using pins with LEDs attached

void setup() {
  Serial.begin(9600);
  Serial.println("Basic Encoder Test:");
}

void loop() {
    for(int i = -100; i < 100; i++){
      moveMotor(i);
      Serial.println(myEnc.read());
      delay(10);
    }
}

void moveMotor(int me){
  if(me>0){
    me = constrain(me,20,255);
    digitalWrite(DIRA,HIGH);
    digitalWrite(DIRB,LOW);
  }
  if(me < 0){
    digitalWrite(DIRA,LOW);
    digitalWrite(DIRB,HIGH);
    me = constrain(me,-255,-20);
  }
  analogWrite(PWM,abs(me));
}
