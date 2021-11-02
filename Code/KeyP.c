#include<absacc.h> 
#include "KeyP_p.h" 
//================================================================//
//===============================KetPad===========================// 
//================================================================//
 
char key()  
 {   
		code char  table[16]={"123A456B789C*0#D"}; 
		char data_key; 
   	
		while (keyready==0);    	// wait to press key        
		data_key=table[P2&0xf];                
		//while (keyready==1);     	// wait to release key
		return(data_key);
		
 } 
 

