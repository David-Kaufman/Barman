#ifndef _KeyP_H 
#define _KeyP_H 
#include<at89c5131.h> 
/********************* KeyPad ******************************/ 
char key(); 
/********************************************************/
/*************** KeyPad connecting to the port **************/ 
#define PORT_KeyP P2 
sbit keyready =P3^0; 

 /*********************************************************/
#endif /* _KeyP_H */     
