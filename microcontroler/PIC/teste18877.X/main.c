/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F18877
        Driver Version    :  2.00
*/

/*
    (c) 2018 Microchip Technology Inc. and its subsidiaries. 
    
    Subject to your compliance with these terms, you may use Microchip software and any 
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
    license terms applicable to your use of third party software (including open source software) that 
    may accompany Microchip software.
    
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
    FOR A PARTICULAR PURPOSE.
    
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
    SOFTWARE.
*/

#include "mcc_generated_files/mcc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
                         Main application
 */
void moveMotor(int);
void sendMensage(void);
void initialize(void);
void readMensage(int *, long *, float *, float *, float *);
void PID(void);
float getVelocity(void);
long getPosition(void);
void inicializaControle(void);
float constrain(float, float, float);

void ENCA_ISR(void);
void ENCB_ISR(void);
void TIMER_ISR(void);

#define simulationTime 3000
#define  deltaT 10
int Data[simulationTime/deltaT];
int Time[simulationTime/deltaT];
unsigned long tSimPastEncoder = 0;

unsigned long tPast = 0;
long lastPulse = 0;
long nPulseTurn = 600;

long encoder = 0;

int type;
long setPoint;
float kp, ki, kd;

int index_encoder = 0;
int index_encoder_anterior = 1;
float error = 0, error_anterior = 0, error_anterior_anterior = 0;
float error_integrativo = 0;
float correction = 0, correction_anterior = 0, correction_anterior_anterior = 0 ;
long lastPos = 0;
long pos = 0;
float vel = 0;
float lastVel = 0;

float velPulse_ms = 0;

volatile uint16_t timer1ReloadVal=(uint16_t)((0x63 << 8) | 0xC0);

void main(void)
{
    // initialize the device
    SYSTEM_Initialize();
    IOCCF1_SetInterruptHandler(ENCA_ISR);
    IOCCF2_SetInterruptHandler(ENCB_ISR);
    TMR1_SetInterruptHandler(TIMER_ISR);
    // When using interrupts, you need to set the Global and Peripheral Interrupt Enable bits
    // Use the following macros to:

    // Enable the Global Interrupts
    INTERRUPT_GlobalInterruptEnable();

    // Enable the Peripheral Interrupts
    INTERRUPT_PeripheralInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();
    TMR1_StartTimer();
    moveMotor(0);
    initialize();
    while (1)
    {
        readMensage(&type, &setPoint, &kp, &ki, &kd);
        inicializaControle();
        PID();
        TMR1_StopTimer();
        sendMensage();
    }
//    while(1){
//        moveMotor(-100);
//    }
}

void PID(){
    while(index_encoder < simulationTime/deltaT){
        if(index_encoder != index_encoder_anterior){
            if(type == 1){
                vel = getVelocity();
                error = (float) (setPoint*nPulseTurn/60000.0) - vel;
                correction += kp * error + ki * error_integrativo - kd * (vel - lastVel);
                error_integrativo += error;
                error_integrativo = constrain(error_integrativo,-600.0,600.0);
                lastVel = vel;
                Data[index_encoder] = vel * 60000.0 / ((float) nPulseTurn);
                velPulse_ms = (encoder - lastPulse)/10.0;
                lastPulse = encoder;
            }
            else{
                pos = getPosition();
                error = (float) ((setPoint*nPulseTurn/360.0) - pos);
                correction = kp * error + ki * error_integrativo - kd * (float) (pos - lastPos);
                error_integrativo += error;
                error_integrativo = constrain(error_integrativo,-360.0*nPulseTurn/360.0,360.0*nPulseTurn/360.0);
                lastPos = pos;
                Data[index_encoder] = pos * 360.0 / ((float) nPulseTurn);
            }
            index_encoder_anterior = index_encoder;
            correction = constrain(correction,-255.0,255.0);
            moveMotor((int) correction);
        }
    }
    moveMotor(0);
}
void TIMER_ISR(void){
    index_encoder++;
}

float constrain(float VAR, float MIN, float MAX){
    if(VAR < MIN){
        return MIN;
    }
    else if(VAR > MAX){
        return MAX;
    }
    else{
        return VAR;
    }
}

void inicializaControle(void){
    encoder = 0;
    lastPulse = 0;
    index_encoder = 0;
    velPulse_ms = 0;
    error = 0;
    error_anterior = 0;
    error_anterior_anterior = 0;
    error_integrativo = 0;
    correction = 0;
    correction_anterior = 0;
    correction_anterior_anterior = 0 ;
    lastPos = 0;
    pos = 0;
    vel = 0;
    lastVel = 0;
    TMR1_StartTimer();
}

void ENCA_ISR(void){
    if (ENCB_GetValue() == 1) {
        encoder++;
    } 
    else{
        encoder--;
    }
} 

void ENCB_ISR(void){
    if (ENCA_GetValue() == 0) {
        encoder++;
    } 
    else{
        encoder--;
    }
}

void moveMotor(int m){
    if(m>0){
        A_SetHigh();
        B_SetLow();
    }
    else{
        A_SetLow();
        B_SetHigh();
        m = -1 * m;
    }
    PWM6_LoadDutyValue(m);
}

void initialize(){
    for(int index = 0; index < simulationTime/deltaT; index++){
        Time[index] = deltaT*index;
    }
}

void readMensage(int *TYPE, long *SETPOINT, float *KP, float *KI, float *KD){
    int i = 0;
    unsigned char receivedString[30];
    int value[5];
    while(1){
        if(EUSART_is_rx_ready()){
            unsigned char receivedChar = EUSART_Read();
            if(receivedChar == '\n' || receivedChar == '\r'){
                receivedString[i] = '\0';
                break;
            }
            else{
                receivedString[i] = receivedChar;
                i++;
            }
        }
    }
    char *token;
    token = strtok(receivedString,",");
    int j = 0;
    while(token != NULL){
        value[j] = atoi(token);
        token = strtok(NULL,",");
        j++;
    }
    *TYPE = value[0];
    *SETPOINT = value[1];
    *KP = value[2]/1000.0;
    *KI = value[3]/1000.0;
    *KD = value[4]/1000.0;
    receivedString[0] = '\0';
}

void sendMensage(){
    for (int index = 0; index < simulationTime/deltaT; index++) {
        printf("%i,%i",Data[index],Time[index]);//Posicao
        if (index < simulationTime/deltaT - 1) {
          printf(",");
        }
        __delay_ms(1);
    }
    printf("\n");
}

float getVelocity(){
  return velPulse_ms;
}

long getPosition(){
//  return long(motor.read() * 360.0 / nPulseTurn);
  return encoder;
}
/**
 End of File
*/