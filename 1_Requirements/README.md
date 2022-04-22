# **REQUIREMENTS** 
## Hardware Requirements:-
a)	 Ram 2GB or higher.

b)	 Minimum 250GB hard disk space.

c)	 Intel/AMD powered system.

d)	 Processor speed 2.0 GHZ or higher

## Software Requirements: -
a)	 Windows 7 or higher versions, Linux- Ubuntu v18.04.4 or higher version.

b)	 Visual Studio, ATMEL Studio 7(powered by visual studio power shell), Audrino IDE

c)    Simul IDE_1.0.0 RC2.

## Component Required:-

1) ATmega 328P(16 MHz)- 1.
2) Ultra sonic sensor(SR04-21) - 1.
3) LCD Display (Hd44780-11) - 1.
4) Capacitor - 2 * 22pF
5) voltage source - 5v.

## Functional Requirements: -

In this project we used the concept of file handling, data structures, pointer, functions and Multi file programming.
And we design the project in Atmega 328 with GPIO (Digital input or Output) and Interrupt. With the help of ultra sonic sensor the signal passes and recive with the help of we can calculate the distance.While varing the voltage regulator the distance would be calculated in this simulation. The distance calculated will be displayed in LCD Display. 

The basic user-defined functions used in this project are listed below:

a) HCSR04Init - We are setting the trigger pin as output as it will generate ultrasonic sound wave.

b) HCSR04Trigger - This function will generate ultrasonic sound wave for 15 microseconds and Send a 10 MS pulse on trigger line
    
1) uint16_t GetPulseWidth - It will be used to measure the pulse duration. When the ultra sound echo back after hitting an object and the microcontroller will read the pulse using the echo pin of the ultrasonic sensor connected to it.
    
2) initialize - it will connected with Microcontroller and LCD. 

c) lcd_command - In order to send command to the lcd first we need to write the command on the data pins. then set the RS pin to zero and enable pin to high.Then wait for one microseconds and set the enable pin to low, this process repeats again. We're using 4 bit data communication but the data is 8-bit.So we will send the data divinding it into two section. Higher 4 bit and lower 4 bit.
