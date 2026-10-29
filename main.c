#include "stm32l476xx.h"
#include "LCD.h"

int main(void){
	//SET UP
	LCD_Init();
	LCD_Clear();
	
	unsigned char values[4][4] = {   {'1','2','3','A'},{'4','5','6','B'},{'7','8','9','C'},{'*','0','#','D'}   };
	int states[4][4] = {0};
	int loc = 0; //location
	
	//set all rows initially to 1(which sets them to high impedenace mode);
	GPIOB->ODR |= (0xF<<7);
	
		
		
		
	//Coderun code
	while(1)
	{
		for(int r = 0; r<4;r++)
		{
				//set row to 0
				GPIOB->ODR &= ~(1u << (7 + r) );
				//delay_ms(40);
				
				for(int c = 0; c<4;c++)
				{
					int input;
					switch (c)
					{
						case 0: 
							input  = ((GPIOB -> IDR >> 11) & 1u); //pin 11
							break;
						case 1: 
							input  = ((GPIOB -> IDR >> 12) & 1u); //pin 12
							break;
						case 2:
							input  = ((GPIOB -> IDR >> 13) & 1u); //pin 13
							break;
						case 3:
							input  = ((GPIOB -> IDR >> 14) & 1u);//pin 14
					}
						//delay_ms(40);
					
					
					//state 0
					if(states[r][c] == 0)
					{
						if (input == 0)
							states[r][c] = 1;
						else
							 states[r][c] = 0;
					}
					//state 1
					else if(states[r][c] == 1)
					{
						if (input == 0)
							states[r][c] = 2;
						else
							 states[r][c] =0;
					}
					//State 2
					else
					{
						if (input == 0)
							states[r][c] = 2;
						else
						{
							 states[r][c] = 0;
							 LCD_DisplayChar(loc,values[r][c]);
							 loc++;
						}
					}
				
			
			}
		  //set Row back to 1
			GPIOB->ODR |= (1u << (7 + r) );
		
		}	
		
	
	}

}
