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

void ENCA_ISR(void);
void ENCB_ISR(void);
void TIMER_ISR(void);

#define simulationTime 2000
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
float error = 0, error_anterior = 0, error_anterior_anterior = 0;
float error_integrativo = 0;
float correction = 0, correction_anterior = 0, correction_anterior_anterior = 0 ;
long lastPos = 0;
long pos = 0;
float vel = 0;
float lastVel = 0;

float velPulse_ms = 0;

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
    TMR1_StopTimer();
    moveMotor(0);
    initialize();
    while (1)
    {
        readMensage(&type, &setPoint, &kp, &ki, &kd);
        TMR1_StartTimer();
        moveMotor(100);
        PID();
        TMR1_StopTimer();
        moveMotor(0);
        sendMensage();
    }
}

void PID(){
    encoder = 0;
    lastPulse = 0;
    index_encoder = 0;
    velPulse_ms = 0;
    while(index_encoder < simulationTime/deltaT){
        if(type == 1){
            vel = getVelocity();
            Data[index_encoder] = vel * 60000.0 / (float) nPulseTurn;
        }
        else{
            pos = getPosition();
            Data[index_encoder] = pos * 360.0 / (float) nPulseTurn;
        }
        index_encoder++;
        __delay_ms(deltaT);
    }
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

void TIMER_ISR(void){
    velPulse_ms = (encoder - lastPulse)/1.0;
    lastPulse = encoder;
}

void moveMotor(int m){
    if(m>0){
        A_SetHigh();
        B_SetLow();
    }
    else if(m<0){
        A_SetLow();
        B_SetHigh();
    }
    PWM6_LoadDutyValue(abs(m));
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
        printf("%i",Data[index]);//Posicao
        printf(",");
        printf("%i",Time[index]);
        if (index < simulationTime/deltaT - 1) {
          printf(",");
        }
        __delay_ms(5);
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