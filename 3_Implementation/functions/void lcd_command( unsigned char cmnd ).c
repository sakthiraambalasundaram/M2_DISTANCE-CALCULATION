#include "distance.h"


void lcd_command( unsigned char cmnd )
{
	// in order to send command to the lcd first we need to write the command on the data pins. then set the RS pin to zero and enable pin to high
	// then wait for one microseconds and set the enable pin to low, this process repeats again. We're using 4 bit data communication but the data is 8-bit
	// so we will send the data divinding it into two section. Higher 4 bit and lower 4 bit
	// the following lines of codes are used to send higher 4 bits of data
	lcd_port = (lcd_port & 0x0F) | (cmnd & 0xF0);  // this line writes the command on the data pins of the lcd connected to th microcontroller portD pin 4 to 7
	lcd_port &= ~ (1<<rs);
	lcd_port |= (1<<en);
	_delay_us(1);
	lcd_port &= ~ (1<<en);

	// wait 200 microseconds
	_delay_us(200);

	// send the lower 4 bit of the data
	lcd_port = (lcd_port & 0x0F) | (cmnd << 4);
	lcd_port |= (1<<en);
	_delay_us(1);
	lcd_port &= ~ (1<<en);
	_delay_ms(2);
}

void lcd_clear()
{
	lcd_command (0x01);   // this line clears the LCD screen
	_delay_ms(2);         // waits for two milliseconds
	lcd_command (0x80);   // this line sets the cursor to the row 1 column 1
}


void lcd_print (char *str)
{
	// this function will be used to display the string on the LCD screen
	int i;
	for(i=0; str[i]!=0; i++)
	{
		// we can not send the whole string to the LCD we need to send character by character
		// data sending is same as sending a command. there is one difference, in this case the RS pin will be set to HIGH while the RS pin was set to zero in case of the command sending
		lcd_port = (lcd_port & 0x0F) | (str[i] & 0xF0);
		lcd_port |= (1<<rs);
		lcd_port|= (1<<en);
		_delay_us(1);
		lcd_port &= ~ (1<<en);
		_delay_us(200);
		lcd_port = (lcd_port & 0x0F) | (str[i] << 4);
		lcd_port |= (1<<en);
		_delay_us(1);
		lcd_port &= ~ (1<<en);
		_delay_ms(2);
	}
}



void lcd_setCursor(unsigned char x, unsigned char y){    // this function will be used to set cursor. the place where we want to display the data
	unsigned char adr[] = {0x80, 0xC0};    // the 16x2 LCD has two rows first row has a value of 0x80. So let's say we want to go to the seconds column of first row
	// we just need to send the command with adding 2 with the initial value. So, it will be (0x80 + 2) this is how the code works
	lcd_command(adr[y-1] + x-1);
	_delay_us(100);
}
