#ifndef _LCD_H 
#define _LCD_H 
#include<at89c5131.h> 
/********************* LCD ******************************/ 
void lcd_config();// LCD  ������  
void lcd_clr();  // ��� �����
void lcd_line(char line_number,char p); //0-15 ������ 1,2 ����� ��� ����
void lcd_display(char character); //���� ��� �� ����
void lcd_string(char str[]); // ���� ������ �����
void shift_lcd(char direction,char times);//shift the lcd display
void delay_lcd();//delay the lcd
send_command(unsigned char command);
send_data(char data_to_lcd);
 /********************************************************/
/*************** LCD connecting to the port **************/ 
#define PORT_LCD P0 
sbit E =P3^1; 
sbit RS=P3^2; 
 /*********************************************************/
#endif /* _LCD_H */    
 
