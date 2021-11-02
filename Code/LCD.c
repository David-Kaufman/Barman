#include<absacc.h>
#include "lcd_p.h" 
//=============================================================//
//===============================LCD===========================// 
//=============================================================//
 
//== prototype ==// 
void delay_lcd(); // פנימית השהייה
send_command(unsigned char command);    //שולחת מילת בקרה יחד עם האותות 
send_data(char data_to_lcd);            //שולחת מילת נתונים יחד עם האותות  
   
//==============================================================//
 
 
void delay_lcd()  //small delay_lcd 
 {
	int timer=200; 
	while(timer--); 
 }

 
//=======================CONFIG THE LCD=======================//   
void lcd_config()         	//Initialization of The LCD 
 {
	delay_lcd();          
	send_command(0x3f);     //8bit,2 line,5*7 dot 
	delay_lcd(); 
	send_command(0x0c);     //display on ,cursor on,cursor blink 
	delay_lcd();                       
	send_command(0x01);     //clear_display 
	delay_lcd();                       
	send_command(0x06);   	// increment cursor,no display shift             
    
 }
 
void lcd_clr()      //Initialization of The LCD 
 {
	delay_lcd();                       
	send_command(0x01);  	 //clear_display 
 }
 
 
//===========================LCD LINE NUMBER====================// 
void lcd_line(char line_number,char p) 
 {
	switch(line_number) 
	{ 
		case 1: 
				delay_lcd(); 
				send_command(0x80+p);   
				break; 
	
		case 2: 
				delay_lcd(); 
				send_command(0xc0+p);    
				break; 
	} 
  }
  
  
//================DISPLAY THE CHARACTER ON THE LCD=================// 
void lcd_display(char character)      
 {
	delay_lcd(); 
	send_data(character);    //Send The character to the LCD        
 }
 
void lcd_string(char str[]) 
{ 
	int i=0;
	while(str[i]) 
	{ 
			delay_lcd(); 
			send_data(str[i++]);    
	} 	
		
}	
 
send_command(unsigned char command) 
 {
	RS=0; 
	PORT_LCD=command; 
	E=0; 
	delay_lcd(); 
	E=1; 
	delay_lcd(); 
	E=0; 
 }
 
send_data(char data_to_lcd) 
 {
	RS=1; 
	PORT_LCD=data_to_lcd; 
	E=0; 
	delay_lcd(); 
	E=1; 
	delay_lcd(); 
	E=0; 
 }
 
//================SHIFT LCD=================//
void shift_lcd(char direction,char times)
{
  					
	switch(direction)
	{
	case 1:
	{
			int i,j;
			int n = times;
			while(n!=0)
			{
  				send_command(0x1C);  	//Shift the entire display to right
  				for(i=0;i<75;i++)
  					for(j=0;j<2500;j++);
  				n--;
			}
			break;
	}	
	case 2:
	{
			int i,j;
			int n = times;
			while(n!=0)
			{
  				send_command(0x18);  	//Shift the entire display to left
  				for(i=0;i<75;i++)
  					for(j=0;j<2500;j++);
  				n--;
			}
			break;
	}
	}
}


