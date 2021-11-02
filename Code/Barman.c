/****************************************************************************
		************************* Final Exam *****************************
			  *********************** 13 *****************************
						******************************************
											
 Title:		Barman
 Author:	David Alexander Kaufman (AK-D)
 Class:		13    	
 File:	    Barman.c Vr.1 27/04/2011
 Target:    AT89C5131
 							
 DESCRIPTION:
 
       Displays the different menus and drinks available.
       Operates the 3 pumps.

 USAGE:
 
       Use the # , * keys to cycle through the menus                                                    
       Choose each drink by the corresponding number.
       
*****************************************************************************/

#include <at89c5131.h>
#include <stdio.h> 		//For SPrintf 		
#include "lcd_p.h" 		//For LCD Functions 
#include "KeyP_p.h" 	//For KeyPad Functions

//== prototype ==//
char str[16];													//LCD Array
sbit pump1 = P1^0; 												//Port Pump 1
sbit pump2 = P1^1; 												//Port Pump 2
sbit pump3 = P1^2; 												//Port Pump 3
unsigned char menu = 1;	 										//Menu Counter
void Ch_menu_drink(unsigned char menu); 						//Displays The Different Menus & Drinks 
void op_pump(char T1,char T2,char T3); 							//Operating The Pumps
void delay(unsigned long time1,unsigned long time2);			//Delay


//==================================== BARMAN ========================================//
																   
void main() 
 {				
 																		
	//====================== Start ====================// 
	P1 = 0;
				
	lcd_config();
	lcd_line(1,3);
	lcd_string(" Barman ");
	delay(75,250);   		
	lcd_line(2,2);  
	lcd_string("David Kaufman");
	delay(75,250); 		
	lcd_clr();
	Ch_menu_drink(menu);
	
	//================== Change Menu ==================//
	while(1)
	{
		switch(key())
		{
			case '#':
						menu++;   						//Increase for next menu
						if (menu > 3){ menu = 1;} 		//Go to first menu
						Ch_menu_drink(menu);			//Display the menu
						break;
			
		
			case '*':
						menu--;							//Decrease for previous menu
						if (menu < 1){ menu = 3;}		//Go to last menu
						Ch_menu_drink(menu);			//Display the menu
						break;			
		}//switch
	}//while	
}//main


//================================= Display Menu & Choose Drinks ============================//   
void Ch_menu_drink(unsigned char menu)
{
	while(menu)
	{
		while(keyready==1);
		switch(menu)
		{
			case 1:
					lcd_clr();
					lcd_line(1,3);
					lcd_string("1.Drink A");
					lcd_line(2,3);
					lcd_string("2.Drink B");
					if (key()=='1')							//Drink 1
						{
							lcd_line(1,3);
							lcd_string("1.Drink A");
							lcd_line(2,2);
							lcd_string("Please Wait...");
							op_pump(3,4,5);
							lcd_clr();						//Drink is done
							lcd_line(2,5);
							lcd_string("Done!");
							delay(95,250);
							Ch_menu_drink(menu);			//Return to current menu
							
					   }
					else if(key()=='2')						//Drink 2
						{
							lcd_line(1,3);
							lcd_string("2.Drink B");
							lcd_line(2,2);
							lcd_string("Please Wait...");
							op_pump(3,5,4);
							lcd_clr();						//Drink is done
							lcd_line(2,5);
							lcd_string("Done!");
							delay(95,250);
							Ch_menu_drink(menu);			//Return to current menu
						}
					break;
	
			case 2:
					lcd_clr();
					lcd_line(1,3);
					lcd_string("3.Drink C");
					lcd_line(2,3);
					lcd_string("4.Drink D");
					if (key()=='3')							//Drink 3
						{
							lcd_line(1,3);
							lcd_string("3.Drink C");
							lcd_line(2,2);
							lcd_string("Please Wait...");
							op_pump(4,3,5);
							lcd_clr();						//Drink is done
							lcd_line(2,5);
							lcd_string("Done!");
							delay(95,250);
							Ch_menu_drink(menu);			//Return to current menu
					   }
					else if(key()=='4')						//Drink 4
						{
							lcd_line(1,3);
							lcd_string("4.Drink D");
							lcd_line(2,2);
							lcd_string("Please Wait...");
							op_pump(4,5,3);
							lcd_clr();						//Drink is done
							lcd_line(2,5);
							lcd_string("Done!");
							delay(95,250);
							Ch_menu_drink(menu);			//Return to current menu
						}	
					break;
		
			case 3:
					lcd_clr();
					lcd_line(1,3);
					lcd_string("5.Drink E");
					lcd_line(2,3);
					lcd_string("6.Drink F");
					if (key()=='5')
						{
							lcd_line(1,3);					//Drink 5
							lcd_string("5.Drink E");
							lcd_line(2,2);
							lcd_string("Please Wait...");
							op_pump(5,3,4);
							lcd_clr();						//Drink is done
							lcd_line(2,5);
							lcd_string("Done!");
							delay(95,250);
							Ch_menu_drink(menu);			//Return to current menu
					   }
					else if(key()=='6')						//Drink 6
						{
							lcd_line(1,3);
							lcd_string("6.Drink F");
							lcd_line(2,2);
							lcd_string("Please Wait...");
							op_pump(5,4,3);
							lcd_clr();						//Drink is done
							lcd_line(2,5);
							lcd_string("Done!");
							delay(95,250);
							Ch_menu_drink(menu);			//Return to current menu
						}	
						
					break;
				
			default:
						op_pump(0,0,0);
										
		}//switch menu
		if (key()=='#' || key()=='*')
			return;
	}//while

}//disp_menu  				


//================================= Operate Pumps ====================================//  
void op_pump(char T1,char T2,char T3)
{
	pump1 = 1; 				//Pump1
	delay(10,T1*100000);
	pump1 = 0;
	
	pump2 = 1; 				//Pump2
	delay(10,T2*100000);
	pump2 = 0;
	
	pump3 = 1;				//Pump3
	delay(10,T3*100000);
	pump3 = 0;
	
}//op_pump


//==================================== Delay =========================================//																				
 
void delay(unsigned long time1,unsigned long time2)
{
	int i,j;
	for(i=0;i<time1;i++)
  		for(j=0;j<time2;j++);
  		
}//dealy
