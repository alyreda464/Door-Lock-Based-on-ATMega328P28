#include <avr/io.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include "LCD.h"
#include "keypad.h"
#include "debounce_kp.h"

// COnnection of pins
// LCD PORT D

char ENTER[] = "ENTER UR PASS";
char correct[] = "Correct Password";
char wrong[] = "Wrong Password";

char PASSWORD[] = "1234";

int main(void)
{
	int i=0;
	LCD_Init(16);
	char checkPASSWORD[4] ;
	while (1)
	{
		
		LCD_Clear();
		LCD_GoToXY(0,0);
		LCD_PutStr(ENTER);
		while (i < 4)
		{
			char x = keypad_scan();
			_delay_ms(60);
			if ( x =='1')
			{
				checkPASSWORD[i] = '1';
				
				LCD_GoToXY(i,1);
				LCD_PutChar('1');
				i++;
			}
			if ( x =='2')
			{
				checkPASSWORD[i] = '2';
				
				LCD_GoToXY(i,1);
				LCD_PutChar('2');
				i++;
			}
			if ( x =='3')
			{
				checkPASSWORD[i] = '3';
				
				LCD_GoToXY(i,1);
				LCD_PutChar('3');
				i++;
			}
	     	if ( x =='4')
	     	{
		     	checkPASSWORD[i] = '4';
		     	
		     	LCD_GoToXY(i,1);
		     	LCD_PutChar('4');
		     	i++;
	     	}
			if ( x =='5')
			{
				checkPASSWORD[i] = '5';
				
				LCD_GoToXY(i,1);
				LCD_PutChar('5');
				i++;
			}
	     	if ( x =='6')
	     	{
		     	checkPASSWORD[i] = '6';
		     	
		     	LCD_GoToXY(i,1);
		     	LCD_PutChar('6');
		     	i++;
	     	}
			if ( x =='7')
			{
				checkPASSWORD[i] = '7';
				
				LCD_GoToXY(i,1);
				LCD_PutChar('7');
				i++;
			}
			if ( x =='8')
			{
				checkPASSWORD[i] = '8';
				
				LCD_GoToXY(i,1);
				LCD_PutChar('8');
				i++;
			}
			if ( x =='9')
			{
				checkPASSWORD[i] = '9';
				
				LCD_GoToXY(i,1);
				LCD_PutChar('9');
				i++;
			}
				if ( x =='0')
				{
					checkPASSWORD[i] = '0';
					
					LCD_GoToXY(i,1);
					LCD_PutChar('0');
					i++;
				}
				
			_delay_ms(60);
		
			
			
		}
		
		

			if ( PASSWORD[0] == checkPASSWORD[0] && PASSWORD[1] == checkPASSWORD[1] && PASSWORD[2] == checkPASSWORD[2] && PASSWORD[3] == checkPASSWORD[3] )
			{
				LCD_Clear();
				LCD_GoToXY(0,0);
				LCD_PutStr(correct);
				PORTD=0b00010000;
				_delay_ms(20);
				i = 0;
			}

			if ( PASSWORD[0] != checkPASSWORD[0] || PASSWORD[1] != checkPASSWORD[1] || PASSWORD[2] != checkPASSWORD[2] || PASSWORD[3] != checkPASSWORD[3] )
			{
				LCD_Clear();
				LCD_GoToXY(0,0);
				LCD_PutStr(wrong);
				_delay_ms(20);
				i=0;
			}
		
	}
		
}