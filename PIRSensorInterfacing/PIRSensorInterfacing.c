/*
 * SensorInterfacing.c
 *
 * Created: 03-Oct-19 07:13:47 PM
 * Modified: 03-Oct-19 2:52:12 PM
 * Author: Debdut
 * Modifier: Debdut
 */ 

#define F_CPU 14745600UL
//#define F_CPU 16000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdbool.h>
#include "lcd.h"
#include "pir.h"

void port_init();
void init_devices(void);

//Function to initialize PORTS
void port_init()
{
	pir_init();
	lcd_init();
}

//Function to initialize all devices
void init_devices (void)
{
	cli(); //Clears the global interrupts
	port_init();
	sei();   //Enables the global interrupts
}

int main(void)
{
	init_devices();
	
	lcd_cursor(1,3);
	lcd_string("HACTOBER-2K19");
	lcd_cursor(2,4);
	lcd_string("OPENSOURCE");
	_delay_ms(2000);
	lcd_clear();
	
	lcd_cursor(2,5);
	lcd_string("DETECTED!");
	
	while (1)
	{
		//lcd_clear();
		
		if(update_pir_sensor())
		{
			lcd_cursor(1,4);
			lcd_string("  MOTION ");
		}
		else
		{
			lcd_cursor(1,4);
			lcd_string("NO MOTION");
		}
		
		_delay_ms(100);
	}
}