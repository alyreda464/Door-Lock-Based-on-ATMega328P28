#include "keypad.h"
#include "debounce_kp.h"

// masking the key presses according to the layout
char key [4][4] = {
	{'1','2','3','A'},
	{'4','5','6','B'},
	{'7','8','9','C'},
	{'*','0','#','D'}
};

char keypad_scan(){
	INPUT_PORT_DIRECTION &=~0xFF;//rows as inputs
	OUTPUT_PORT_DIRECTION &=~0xFF;//columns
	INPUR_PORT|=0xFF;
	
	for(int i=0;i<4;i++)
	{
		OUTPUT_PORT_DIRECTION |=(1<<i);
		OUTPUT_PORT &=~(1<<i); // Moves on the columns and puts 0 according to the turn
		
		for(int j=0;j<4;j++)
		{
			if( (INPUT_PIN & 1<<j) == 0) // checks if input from rows is also 0 (Active Low)
			{
				debounce(j);
				while(button==0) debounce(j); //handling long press on key in the function
				return key[j][i];
			}
			
		}
		OUTPUT_PORT_DIRECTION &=~0xFF; // Resets all port output to 1
		
	}
	
	return ' '; // clear the buffer key press to avoid condition mishandling 
}