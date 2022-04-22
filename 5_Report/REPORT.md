# DISTANCE METER.

## INTRODUCTION :
  
  Distance meter is the name suggest , the sensor that used in this project that detects the object when it come nears.The sensor will send ultra sonic ray. After receiving that signal, The Micro controller which compute with data in mathematical forum.and display the distance in LCD Display.
  
 
 
 # OBJECTIVE : 
 
 
 * To design and develop a prototype for an Distance meter that can Calculate the object when it recognises with Ultrasonic rays produced by the Object(Humans,Animals,Object,etc..).


# Components:

1. ATmega 328P(16 MHz)- 1.
2. Ultra sonic sensor(SR04-21) - 1.
3. LCD Display (Hd44780-11) - 1.
4. Capacitor - 2 * 22pF.
5. voltage source - 5v.

# SOFTWARE USED :

* SimulIDE
* Visual Studio
* ATMEL Studio 7(powered by visual studio power shell)
* Audrino IDE

# DESCRIPTION :

# ATMEGA328
 
 * Microchip's ATmega328 is an 8-bit, 28-pin AVR Microcontroller that uses RISC architecture and includes a 32KB flash-type programme memory.
 * The Atmega328 microcontroller is found in the Arduino UNO, Arduino Pro Mini, and Arduino Nano boards.
 * It can function at voltages ranging from 3.3 to 5.5 volts, but we usually choose 5 volts as a standard.
 * Cost-effectiveness, low power consumption, programming lock for security, and true timer counter with independent oscillator are only a few of its outstanding      qualities.
 * It's most commonly found in Embedded Systems. Take a look at these Real-Life Embedded System Examples; we can design all of them with this Microcontroller.

![fig:1.Atmega328 pin diagram](https://user-images.githubusercontent.com/65847751/164680071-7801fed2-4a24-4510-be26-ef2d35bf946d.png)

# LCD Display(hd44780)
  The most commonly used Character based LCDs are based on Hitachi’s HD44780 controller or other which are compatible with HD44580. we will discuss about character based LCDs, their interfacing with various microcontrollers, various interfaces (8-bit/4-bit), programming, special stuff and tricks you can do with these simple looking LCDs which can give a new look to your application.
  
   The most commonly used LCDs found in the market today are 1 Line, 2 Line or 4 Line LCDs which have only 1 controller and support at most of 80 charachers, whereas LCDs supporting more than 80 characters make use of 2 HD44780 controllers.
   
   ![LED_PIN_Diagram](https://user-images.githubusercontent.com/65847751/164681152-2bc9e49c-6385-41fa-9317-8abb03843e5e.png)
   
# Ultra sonic sensor (SR04)
 
  The HC-SR04 Ultrasonic Distance Sensor is a sensor used for detecting the distance to an object using sonar. It's ideal for any robotics projects your have which require you to avoid objects, by detecting how close they are you can steer away from them!

![HC-SR04-1](https://user-images.githubusercontent.com/65847751/164682006-829587cf-763e-4440-9195-c58d22cd379c.jpg)


# WORKING PRINCIPLE :

After wiring and connecting all of the devices and connecting them to the switch,check all of the necessary setups to see if anything is missing. Following the connection setup, In the next step is to submit/upload the code to the microcontroller and power up the circuit. After upload the code,press the simulatation button once the system is turns ON,press the regulate voltage to turn on.the distance will be calculate and it will be show the out put

![Distance meter](https://user-images.githubusercontent.com/65847751/164699418-cbcc132e-a4b9-49f3-a887-48c397ecb119.png)

# Applications:

# Advantage:

* Compact
* Fast / Time Saver
* System memory—stores previous measurements 
* One man job
* Magnification features are available
* Energy saving

# Disadvantage:

* More expensive
* Requires batteries or power source
* Need steady hands for precise reading
* Not as effective when measuring short distances
* Light conditions and good weather are important
