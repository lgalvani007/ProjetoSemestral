/**
  @Generated Pin Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    pin_manager.h

  @Summary:
    This is the Pin Manager file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  @Description
    This header file provides APIs for driver for .
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.8
        Device            :  PIC16F18877
        Driver Version    :  2.11
    The generated drivers are tested against the following:
        Compiler          :  XC8 2.36 and above
        MPLAB 	          :  MPLAB X 6.00	
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

#ifndef PIN_MANAGER_H
#define PIN_MANAGER_H

/**
  Section: Included Files
*/

#include <xc.h>

#define INPUT   1
#define OUTPUT  0

#define HIGH    1
#define LOW     0

#define ANALOG      1
#define DIGITAL     0

#define PULL_UP_ENABLED      1
#define PULL_UP_DISABLED     0

// get/set ENCA aliases
#define ENCA_TRIS                 TRISCbits.TRISC1
#define ENCA_LAT                  LATCbits.LATC1
#define ENCA_PORT                 PORTCbits.RC1
#define ENCA_WPU                  WPUCbits.WPUC1
#define ENCA_OD                   ODCONCbits.ODCC1
#define ENCA_ANS                  ANSELCbits.ANSC1
#define ENCA_SetHigh()            do { LATCbits.LATC1 = 1; } while(0)
#define ENCA_SetLow()             do { LATCbits.LATC1 = 0; } while(0)
#define ENCA_Toggle()             do { LATCbits.LATC1 = ~LATCbits.LATC1; } while(0)
#define ENCA_GetValue()           PORTCbits.RC1
#define ENCA_SetDigitalInput()    do { TRISCbits.TRISC1 = 1; } while(0)
#define ENCA_SetDigitalOutput()   do { TRISCbits.TRISC1 = 0; } while(0)
#define ENCA_SetPullup()          do { WPUCbits.WPUC1 = 1; } while(0)
#define ENCA_ResetPullup()        do { WPUCbits.WPUC1 = 0; } while(0)
#define ENCA_SetPushPull()        do { ODCONCbits.ODCC1 = 0; } while(0)
#define ENCA_SetOpenDrain()       do { ODCONCbits.ODCC1 = 1; } while(0)
#define ENCA_SetAnalogMode()      do { ANSELCbits.ANSC1 = 1; } while(0)
#define ENCA_SetDigitalMode()     do { ANSELCbits.ANSC1 = 0; } while(0)

// get/set ENCB aliases
#define ENCB_TRIS                 TRISCbits.TRISC2
#define ENCB_LAT                  LATCbits.LATC2
#define ENCB_PORT                 PORTCbits.RC2
#define ENCB_WPU                  WPUCbits.WPUC2
#define ENCB_OD                   ODCONCbits.ODCC2
#define ENCB_ANS                  ANSELCbits.ANSC2
#define ENCB_SetHigh()            do { LATCbits.LATC2 = 1; } while(0)
#define ENCB_SetLow()             do { LATCbits.LATC2 = 0; } while(0)
#define ENCB_Toggle()             do { LATCbits.LATC2 = ~LATCbits.LATC2; } while(0)
#define ENCB_GetValue()           PORTCbits.RC2
#define ENCB_SetDigitalInput()    do { TRISCbits.TRISC2 = 1; } while(0)
#define ENCB_SetDigitalOutput()   do { TRISCbits.TRISC2 = 0; } while(0)
#define ENCB_SetPullup()          do { WPUCbits.WPUC2 = 1; } while(0)
#define ENCB_ResetPullup()        do { WPUCbits.WPUC2 = 0; } while(0)
#define ENCB_SetPushPull()        do { ODCONCbits.ODCC2 = 0; } while(0)
#define ENCB_SetOpenDrain()       do { ODCONCbits.ODCC2 = 1; } while(0)
#define ENCB_SetAnalogMode()      do { ANSELCbits.ANSC2 = 1; } while(0)
#define ENCB_SetDigitalMode()     do { ANSELCbits.ANSC2 = 0; } while(0)

// get/set RC4 procedures
#define RC4_SetHigh()            do { LATCbits.LATC4 = 1; } while(0)
#define RC4_SetLow()             do { LATCbits.LATC4 = 0; } while(0)
#define RC4_Toggle()             do { LATCbits.LATC4 = ~LATCbits.LATC4; } while(0)
#define RC4_GetValue()              PORTCbits.RC4
#define RC4_SetDigitalInput()    do { TRISCbits.TRISC4 = 1; } while(0)
#define RC4_SetDigitalOutput()   do { TRISCbits.TRISC4 = 0; } while(0)
#define RC4_SetPullup()             do { WPUCbits.WPUC4 = 1; } while(0)
#define RC4_ResetPullup()           do { WPUCbits.WPUC4 = 0; } while(0)
#define RC4_SetAnalogMode()         do { ANSELCbits.ANSC4 = 1; } while(0)
#define RC4_SetDigitalMode()        do { ANSELCbits.ANSC4 = 0; } while(0)

// get/set RC5 procedures
#define RC5_SetHigh()            do { LATCbits.LATC5 = 1; } while(0)
#define RC5_SetLow()             do { LATCbits.LATC5 = 0; } while(0)
#define RC5_Toggle()             do { LATCbits.LATC5 = ~LATCbits.LATC5; } while(0)
#define RC5_GetValue()              PORTCbits.RC5
#define RC5_SetDigitalInput()    do { TRISCbits.TRISC5 = 1; } while(0)
#define RC5_SetDigitalOutput()   do { TRISCbits.TRISC5 = 0; } while(0)
#define RC5_SetPullup()             do { WPUCbits.WPUC5 = 1; } while(0)
#define RC5_ResetPullup()           do { WPUCbits.WPUC5 = 0; } while(0)
#define RC5_SetAnalogMode()         do { ANSELCbits.ANSC5 = 1; } while(0)
#define RC5_SetDigitalMode()        do { ANSELCbits.ANSC5 = 0; } while(0)

// get/set A aliases
#define A_TRIS                 TRISDbits.TRISD0
#define A_LAT                  LATDbits.LATD0
#define A_PORT                 PORTDbits.RD0
#define A_WPU                  WPUDbits.WPUD0
#define A_OD                   ODCONDbits.ODCD0
#define A_ANS                  ANSELDbits.ANSD0
#define A_SetHigh()            do { LATDbits.LATD0 = 1; } while(0)
#define A_SetLow()             do { LATDbits.LATD0 = 0; } while(0)
#define A_Toggle()             do { LATDbits.LATD0 = ~LATDbits.LATD0; } while(0)
#define A_GetValue()           PORTDbits.RD0
#define A_SetDigitalInput()    do { TRISDbits.TRISD0 = 1; } while(0)
#define A_SetDigitalOutput()   do { TRISDbits.TRISD0 = 0; } while(0)
#define A_SetPullup()          do { WPUDbits.WPUD0 = 1; } while(0)
#define A_ResetPullup()        do { WPUDbits.WPUD0 = 0; } while(0)
#define A_SetPushPull()        do { ODCONDbits.ODCD0 = 0; } while(0)
#define A_SetOpenDrain()       do { ODCONDbits.ODCD0 = 1; } while(0)
#define A_SetAnalogMode()      do { ANSELDbits.ANSD0 = 1; } while(0)
#define A_SetDigitalMode()     do { ANSELDbits.ANSD0 = 0; } while(0)

// get/set RD1 procedures
#define RD1_SetHigh()            do { LATDbits.LATD1 = 1; } while(0)
#define RD1_SetLow()             do { LATDbits.LATD1 = 0; } while(0)
#define RD1_Toggle()             do { LATDbits.LATD1 = ~LATDbits.LATD1; } while(0)
#define RD1_GetValue()              PORTDbits.RD1
#define RD1_SetDigitalInput()    do { TRISDbits.TRISD1 = 1; } while(0)
#define RD1_SetDigitalOutput()   do { TRISDbits.TRISD1 = 0; } while(0)
#define RD1_SetPullup()             do { WPUDbits.WPUD1 = 1; } while(0)
#define RD1_ResetPullup()           do { WPUDbits.WPUD1 = 0; } while(0)
#define RD1_SetAnalogMode()         do { ANSELDbits.ANSD1 = 1; } while(0)
#define RD1_SetDigitalMode()        do { ANSELDbits.ANSD1 = 0; } while(0)

// get/set LED aliases
#define LED_TRIS                 TRISDbits.TRISD2
#define LED_LAT                  LATDbits.LATD2
#define LED_PORT                 PORTDbits.RD2
#define LED_WPU                  WPUDbits.WPUD2
#define LED_OD                   ODCONDbits.ODCD2
#define LED_ANS                  ANSELDbits.ANSD2
#define LED_SetHigh()            do { LATDbits.LATD2 = 1; } while(0)
#define LED_SetLow()             do { LATDbits.LATD2 = 0; } while(0)
#define LED_Toggle()             do { LATDbits.LATD2 = ~LATDbits.LATD2; } while(0)
#define LED_GetValue()           PORTDbits.RD2
#define LED_SetDigitalInput()    do { TRISDbits.TRISD2 = 1; } while(0)
#define LED_SetDigitalOutput()   do { TRISDbits.TRISD2 = 0; } while(0)
#define LED_SetPullup()          do { WPUDbits.WPUD2 = 1; } while(0)
#define LED_ResetPullup()        do { WPUDbits.WPUD2 = 0; } while(0)
#define LED_SetPushPull()        do { ODCONDbits.ODCD2 = 0; } while(0)
#define LED_SetOpenDrain()       do { ODCONDbits.ODCD2 = 1; } while(0)
#define LED_SetAnalogMode()      do { ANSELDbits.ANSD2 = 1; } while(0)
#define LED_SetDigitalMode()     do { ANSELDbits.ANSD2 = 0; } while(0)

// get/set B aliases
#define B_TRIS                 TRISDbits.TRISD3
#define B_LAT                  LATDbits.LATD3
#define B_PORT                 PORTDbits.RD3
#define B_WPU                  WPUDbits.WPUD3
#define B_OD                   ODCONDbits.ODCD3
#define B_ANS                  ANSELDbits.ANSD3
#define B_SetHigh()            do { LATDbits.LATD3 = 1; } while(0)
#define B_SetLow()             do { LATDbits.LATD3 = 0; } while(0)
#define B_Toggle()             do { LATDbits.LATD3 = ~LATDbits.LATD3; } while(0)
#define B_GetValue()           PORTDbits.RD3
#define B_SetDigitalInput()    do { TRISDbits.TRISD3 = 1; } while(0)
#define B_SetDigitalOutput()   do { TRISDbits.TRISD3 = 0; } while(0)
#define B_SetPullup()          do { WPUDbits.WPUD3 = 1; } while(0)
#define B_ResetPullup()        do { WPUDbits.WPUD3 = 0; } while(0)
#define B_SetPushPull()        do { ODCONDbits.ODCD3 = 0; } while(0)
#define B_SetOpenDrain()       do { ODCONDbits.ODCD3 = 1; } while(0)
#define B_SetAnalogMode()      do { ANSELDbits.ANSD3 = 1; } while(0)
#define B_SetDigitalMode()     do { ANSELDbits.ANSD3 = 0; } while(0)

/**
   @Param
    none
   @Returns
    none
   @Description
    GPIO and peripheral I/O initialization
   @Example
    PIN_MANAGER_Initialize();
 */
void PIN_MANAGER_Initialize (void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handling routine
 * @Example
    PIN_MANAGER_IOC();
 */
void PIN_MANAGER_IOC(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF1 pin functionality
 * @Example
    IOCCF1_ISR();
 */
void IOCCF1_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF1 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF1 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF1_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF1_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF1 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF1_SetInterruptHandler() method.
    This handler is called every time the IOCCF1 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF1_SetInterruptHandler(IOCCF1_InterruptHandler);

*/
extern void (*IOCCF1_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF1 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF1_SetInterruptHandler() method.
    This handler is called every time the IOCCF1 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF1_SetInterruptHandler(IOCCF1_DefaultInterruptHandler);

*/
void IOCCF1_DefaultInterruptHandler(void);


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Interrupt on Change Handler for the IOCCF2 pin functionality
 * @Example
    IOCCF2_ISR();
 */
void IOCCF2_ISR(void);

/**
  @Summary
    Interrupt Handler Setter for IOCCF2 pin interrupt-on-change functionality

  @Description
    Allows selecting an interrupt handler for IOCCF2 at application runtime
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF2_SetInterruptHandler(MyInterruptHandler);

*/
void IOCCF2_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for IOCCF2 pin

  @Description
    This is a dynamic interrupt handler to be used together with the IOCCF2_SetInterruptHandler() method.
    This handler is called every time the IOCCF2 ISR is executed and allows any function to be registered at runtime.
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF2_SetInterruptHandler(IOCCF2_InterruptHandler);

*/
extern void (*IOCCF2_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for IOCCF2 pin

  @Description
    This is a predefined interrupt handler to be used together with the IOCCF2_SetInterruptHandler() method.
    This handler is called every time the IOCCF2 ISR is executed. 
    
  @Preconditions
    Pin Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    PIN_MANAGER_Initialize();
    IOCCF2_SetInterruptHandler(IOCCF2_DefaultInterruptHandler);

*/
void IOCCF2_DefaultInterruptHandler(void);



#endif // PIN_MANAGER_H
/**
 End of File
*/