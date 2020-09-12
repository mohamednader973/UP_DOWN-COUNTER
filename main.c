/*
 * sevensegment_driver.c
 *
 * Created: 9/12/2020 6:51:07 PM
 * Author : monad
 */ 

#include <avr/io.h>
#include "DIO_INOUT.h"
#define F_CPU 16000000UL
#include <util/delay.h>
int main(void)
{
    /* Replace with your application code */
    while (1) 
    {
		Uint8 i=0;
		Uint8 j=0;
		DIO_init(DIO_PORTB,PIN_ZERO,OUTPUT);
		DIO_init(DIO_PORTB,PIN_ONE,OUTPUT);
		DIO_init(DIO_PORTB,PIN_TWO,OUTPUT);
		DIO_init(DIO_PORTB,PIN_THREE,OUTPUT);
		DIO_init(DIO_PORTA,PIN_ZERO,OUTPUT);
		DIO_init(DIO_PORTA,PIN_ONE,OUTPUT);
		DIO_init(DIO_PORTA,PIN_TWO,OUTPUT);
		DIO_init(DIO_PORTA,PIN_THREE,OUTPUT);
		DIO_init(DIO_PORTD,PIN_ZERO,INPUT);
		DIO_init(DIO_PORTD,PIN_ONE,INPUT);
		if (((PIND_IO>>0)&1)==1)
		{
			for (i=0;i<=9;i++)
			{
				DIO_WRITE_DATA(DIO_PORTB,i);
				
				for (j=0;j<=9;j++)
				{
					DIO_WRITE_DATA(DIO_PORTA,j);
					_delay_ms(50);
				}
				
			}
			
		}
		if (((PIND_IO>>1)&1)==1)
		{
			for (i=9;i>=0;i--)
			{
				if (i==0xFF)
				{
					break;
				}
				DIO_WRITE_DATA(DIO_PORTB,i);
				
				for (j=9;j>=0;j--)
				{
					if (j==0xFF)
					{
						break;
					}
					DIO_WRITE_DATA(DIO_PORTA,j);
					_delay_ms(50);
				}
				
			}
			
		}


    }
}

