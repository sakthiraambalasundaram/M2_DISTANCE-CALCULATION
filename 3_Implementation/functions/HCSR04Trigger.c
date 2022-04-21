#include "distance.h"

void HCSR04Trigger()
{   // this function will generate ultrasonic sound wave for 15 microseconds
	//Send a 10uS pulse on trigger line

	US_PORT|=(1<<US_TRIG_POS);  //high

	_delay_us(15);        //wait 15uS

	US_PORT&=~(1<<US_TRIG_POS); //low
}

uint16_t GetPulseWidth()
{
	// this function will be used to measure the pulse duration. When the ultra sound echo back after hitting an object
	// the microcontroller will read the pulse using the echo pin of the ultrasonic sensor connected to it.

	uint32_t i,result;

	// Section - 1: the following lines of code before the section - 2 is checking if the ultrasonic is working or not
	// it check the echo pin for a certain amount of time. If there is no signal it means the sensor is not working or not connect properly
	for(i=0;i<600000;i++)
	{
		if(!(US_PIN & (1<<US_ECHO_POS)))
		continue; //Line is still low, so wait
		else
		break;    //High edge detected, so break.
	}

	if(i==600000)
	return US_ERROR;  //Indicates time out

	//High Edge Found

	// Section -2 : This section is all about preparing the timer for counting the time of the pulse. Timers in microcontrllers is used for timimg operation
	//Setup Timer1
	TCCR1A=0X00;
	TCCR1B=(1<<CS11); // This line sets the resolution of the timer. Maximum of how much value it should count.
	TCNT1=0x00;     // This line start the counter to start counting time

	// Section -3 : This section checks weather the there is any object or not
	for(i=0;i<600000;i++)                // the 600000 value is used randomly to denote a very small amount of time, almost 40 miliseconds
	{
		if(US_PIN & (1<<US_ECHO_POS))
		{
			if(TCNT1 > 60000) break; else continue;   // if the TCNT1 value gets higher than 60000 it means there is not object in the range of the sensor
		}
		else
		break;
	}

	if(i==600000)
	return US_NO_OBSTACLE;  //Indicates time out

	//Falling edge found

	result=TCNT1;          // microcontroller stores the the value of the counted pulse time in the TCNT1 register. So, we're returning this value to the
	// main function for utilizing it later

	//Stop Timer
	TCCR1B=0x00;

	if(result > 60000)
	return US_NO_OBSTACLE;  //No obstacle
	else
	return (result>>1);
}


/*
Using LCD with avr microcontrollers is a bit tricky. It is hard to explain in code comments. I highly recommend to watch the following video and read the article
to have a clear understanding of how LCD works with microcontrollers
Video: https://www.youtube.com/watch?v=7-DK8kNHvlA&list=PLE72E4CFE73BD1DE1&index=19
Article: https://newbiehack.com/MicrocontrollersABeginnersGuideIntroductionandInterfacinganLCD.aspx
The article clearly explains the working of the LCD. Please read it throughly
*/
void initialize (void)
{
	lcd_data_dir = 0xFF;     // this will set the LCD pins connected on the microcontroller as output
	_delay_ms(15);           // to show data on the LCD we need to send commands first then the data
	lcd_command(0x02);       // this command returns the cursor to the first row and first column position
	lcd_command(0x28);       // please refer to this link to understand meaning of all the commands https://www.electronicsforu.com/technology-trends/learn-electronics/16x2-lcd-pinout-diagram
	lcd_command(0x0c);
	lcd_command(0x06);
	lcd_command(0x01);
	_delay_ms(2);
}
