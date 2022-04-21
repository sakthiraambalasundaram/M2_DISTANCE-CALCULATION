#ifndef DISTANCE_H_INCLUDED
#define DISTANCE_H_INCLUDED


#include <avr/io.h>             // This header file includes the appropriate Input/output definitions for the device
#include <util/delay.h>         // to use delay function we need to include this library
#include <stdlib.h>             // we'll be using itoa() function to convert integer to character array that resides in this library

#define lcd_port PORTD          // we have connected the lcd on port D
#define lcd_data_dir  DDRD      // we're defining the direction of the pins, weather it is input or output
#define rs PD0                  // we need total six pin to show output on the LCD. Datapin 4, 5, 6, and 7 for sending the data to the lcd and Enable and RS pin for controlling
// the behavior of the LCD we have connected RS pin of LCD to port D pin 0
#define en PD1                  // we have connected Enable pin of LCD to port D pin 1

#define US_PORT PORTC           // we have connected the Ultrasonic sensor on port C. to use the ultrasonic we need two pins of the ultrasonic to be connected on port C
#define  US_PIN  PINC            // we need to initialize the pin resistor when we want to take input.
#define US_DDR  DDRC            // we need data-direction-resistor (DDR) to set the direction of data flow. input or output. we will define it later, now we're just naming it.

#define US_TRIG_POS PC0         // the trigger pin of ultrasonic sound sensor is connected to port C pin 0
#define US_ECHO_POS PC1         // the echo pin of the ultrasonic sound sensor is connected to port C pin 1

#define led1 PC2                // we've connected four of the LEDs to port C and one LED to port D. The first LED is connected to port C pin 2
#define led2 PC3                // The second LED is connected to port C pin 3 and so on for the rest of the LEDs....
#define led3 PC4
#define led4 PC5
#define led5 PD2

#define US_ERROR    -1      // we're defining two more variables two know if the ultrasonic sensor is working or not
#define US_NO_OBSTACLE  -2

int distance, previous_distance;

void HCSR04Init();
void HCSR04Trigger();

void lcd_command( unsigned char );


#endif // DISTANCE_H_INCLUDED
