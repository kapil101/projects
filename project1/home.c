#include <mega32.h>
#include <delay.h>
#include <glcd_123.h>  
#include "adc_touchscreen.h"   
#include <stdio.h>   

#define RXB8 1
#define TXB8 0
#define UPE 2
#define OVR 3
#define FE 4
#define UDRE 5
#define RXC 7

#define FRAMING_ERROR (1<<FE)
#define PARITY_ERROR (1<<UPE)
#define DATA_OVERRUN (1<<OVR)
#define DATA_REGISTER_EMPTY (1<<UDRE)
#define RX_COMPLETE (1<<RXC)
char data1;     
#define RX_BUFFER_SIZE 8
char rx_buffer[RX_BUFFER_SIZE];
#if RX_BUFFER_SIZE<256
unsigned char rx_wr_index,rx_counter;
#else
unsigned int rx_wr_index,rx_rd_index,rx_counter;
#endif
bit rx_buffer_overflow;
interrupt [USART_RXC] void usart_rx_isr(void)
{
char status,data;
status=UCSRA;
data=UDR;  
data1=data;
if ((status & (FRAMING_ERROR | PARITY_ERROR | DATA_OVERRUN))==0)
{
rx_buffer[rx_wr_index]=data;
if (++rx_wr_index == RX_BUFFER_SIZE) rx_wr_index=0;
if (++rx_counter == RX_BUFFER_SIZE)
{
rx_counter=0;
rx_buffer_overflow=1;
};
};
}

void main()
{
unsigned int i,ccc;  
bbbb=0;ccc=0;ddd=0;ss=0;sss=0;ssss=0;sssss=0;ssssss=0;sssssss=0;ssssssss=0;home=0;
aa=0; bb=0; cc=0; dd=0;
a1=a2=a3=a4=0;
b1=b2=b3=b4=0;
c1=c2=c3=c4=0;
d1=d2=d3=d4=0; 

a11=a22=a33=a44=0;
b11=b22=b33=b44=0;
c11=c22=c33=c44=0;
d11=d22=d33=d44=0;

PORTA=0x00;DDRA=0xCC; 
PORTB=0x00;DDRB=0xFE;
PORTC=0x00;DDRC=0xFF;
PORTD=0x00;DDRD=0x00;

UCSRA=0x00;
UCSRB=0x98;
UCSRC=0x86;
UBRRH=0x00;
UBRRL=0x67;
#asm("sei")
glcd_init();clear();
address_right(0xb8,0x40);rs=1;LCD_STRING(" TOUCH ");
address_right(0xbA,0x40);rs=1;LCD_STRING(" SCREEN "); 
address_right(0xbC,0x40);rs=1;LCD_STRING(" BASED "); 
address_right(0xbE,0x40);rs=1;LCD_STRING("RESTARENT");
delay_ms(3000); 
printf("\r\n"); 
printf("*****************************************************");printf("\r\n");    
printf(" E-MENU DISPLAY ORDERING USING TOUCH SCREEN & ZIGBEE ");printf("\r\n"); 
printf("*****************************************************");printf("\r\n");        
ss=1;ccc=1;ddd=0; 
st:delay_ms(200);
while(1)
{
//////////////////////////////////////
if(bbbb==1)
{  
address_right(0xb8,0x40);rs=1;LCD_STRING(" WATING ");
address_right(0xbA,0x40);rs=1;LCD_STRING(" FOR "); 
address_right(0xbC,0x40);rs=1;LCD_STRING(" CANTEEN "); 
address_right(0xbE,0x40);rs=1;LCD_STRING("RESPANCE");
delay_ms(200); 
////////////////////////////////////////////////////////
if(data1== '1'){clear();
address_right(0xb8,0x40);rs=1;LCD_STRING(" WAIT ");
address_right(0xbA,0x40);rs=1;LCD_STRING(" FOR "); 
address_right(0xbC,0x40);rs=1;LCD_STRING(" 10  "); 
address_right(0xbE,0x40);rs=1;LCD_STRING(" MIN ");
delay_ms(1000);}
///////////////////////////////////////////////////////////
if(data1== 'a'){clear();
address_right(0xb8,0x40);rs=1;LCD_STRING(" NO ");
address_right(0xbA,0x40);rs=1;LCD_STRING(" CHIKEN ");
address_right(0xbC,0x40);rs=1;LCD_STRING(" BIRYANI"); 
address_right(0xbE,0x40);rs=1;LCD_STRING(" SORRY");
delay_ms(1200);}  
///////////////////////////////////////////////////////////  
if(data1== 'b'){clear();
address_right(0xb8,0x40);rs=1;LCD_STRING(" NO ");
address_right(0xbA,0x40);rs=1;LCD_STRING(" FISH ");
address_right(0xbC,0x40);rs=1;LCD_STRING(" FRY  "); 
address_right(0xbE,0x40);rs=1;LCD_STRING(" SORRY");
delay_ms(1200);}
/////////////////////////////////////////////////////////
if(data1== 'c'){clear();
address_right(0xb8,0x40);rs=1;LCD_STRING(" NO ");
address_right(0xbA,0x40);rs=1;LCD_STRING(" MUTTON ");
address_right(0xbC,0x40);rs=1;LCD_STRING(" BIRYANI"); 
address_right(0xbE,0x40);rs=1;LCD_STRING(" SORRY");
delay_ms(1200);}
/////////////////////////////////////////////////////////
if(data1== 'd'){clear();
address_right(0xb8,0x40);rs=1;LCD_STRING(" NO ");
address_right(0xbA,0x40);rs=1;LCD_STRING(" PRAWNS ");
address_right(0xbC,0x40);rs=1;LCD_STRING(" CURRY"); 
address_right(0xbE,0x40);rs=1;LCD_STRING(" SORRY");
delay_ms(1200);}
/////////////////////////////////////////////////////////
if(data1== 'e'){clear();
address_right(0xb8,0x40);rs=1;LCD_STRING(" NO ");
address_right(0xbA,0x40);rs=1;LCD_STRING(" VEG ");
address_right(0xbC,0x40);rs=1;LCD_STRING(" BIRYANI"); 
address_right(0xbE,0x40);rs=1;LCD_STRING(" SORRY");
delay_ms(1200);}  
///////////////////////////////////////////////////////////  
if(data1== 'f'){clear();
address_right(0xb8,0x40);rs=1;LCD_STRING(" NO ");
address_right(0xbA,0x40);rs=1;LCD_STRING(" PALAK ");
address_right(0xbC,0x40);rs=1;LCD_STRING(" PANEER  "); 
address_right(0xbE,0x40);rs=1;LCD_STRING(" SORRY");
delay_ms(1200);}
/////////////////////////////////////////////////////////
if(data1== 'g'){clear();
address_right(0xb8,0x40);rs=1;LCD_STRING(" NO ");
address_right(0xbA,0x40);rs=1;LCD_STRING(" MANCHU ");
address_right(0xbC,0x40);rs=1;LCD_STRING(" RIA  "); 
address_right(0xbE,0x40);rs=1;LCD_STRING(" SORRY");
delay_ms(1200);}
/////////////////////////////////////////////////////////
if(data1== 'h'){clear();
address_right(0xb8,0x40);rs=1;LCD_STRING(" NO ");
address_right(0xbA,0x40);rs=1;LCD_STRING(" DAL ");
address_right(0xbC,0x40);rs=1;LCD_STRING(" TADKA"); 
address_right(0xbE,0x40);rs=1;LCD_STRING(" SORRY");
delay_ms(1200);}
/////////////////////////////////////////////////////////
if(data1== 'i'){clear();
address_right(0xb8,0x40);rs=1;LCD_STRING(" NO ");
address_right(0xbA,0x40);rs=1;LCD_STRING(" CHOCO ");
address_right(0xbC,0x40);rs=1;LCD_STRING("  LATE "); 
address_right(0xbE,0x40);rs=1;LCD_STRING(" SORRY");
delay_ms(1200);}  
///////////////////////////////////////////////////////////  
if(data1== 'j'){clear();
address_right(0xb8,0x40);rs=1;LCD_STRING(" NO ");
address_right(0xbA,0x40);rs=1;LCD_STRING(" VENNILA ");
address_right(0xbC,0x40);rs=1;LCD_STRING("ICE CREAM"); 
address_right(0xbE,0x40);rs=1;LCD_STRING(" SORRY");
delay_ms(1200);}
/////////////////////////////////////////////////////////
if(data1== 'k'){clear();
address_right(0xb8,0x40);rs=1;LCD_STRING(" NO ");
address_right(0xbA,0x40);rs=1;LCD_STRING(" BUTTER ");
address_right(0xbC,0x40);rs=1;LCD_STRING(" SCOTCH  "); 
address_right(0xbE,0x40);rs=1;LCD_STRING(" SORRY");
delay_ms(1200);}
/////////////////////////////////////////////////////////
if(data1== 'l'){clear();
address_right(0xb8,0x40);rs=1;LCD_STRING(" NO ");
address_right(0xbA,0x40);rs=1;LCD_STRING(" STRAW ");
address_right(0xbC,0x40);rs=1;LCD_STRING(" BERRY"); 
address_right(0xbE,0x40);rs=1;LCD_STRING(" SORRY");
delay_ms(1200);}
/////////////////////////////////////////////////////////
if(data1== 'm'){clear();
address_right(0xb8,0x40);rs=1;LCD_STRING(" NO ");
address_right(0xbA,0x40);rs=1;LCD_STRING(" SPRITE ");
address_right(0xbC,0x40);rs=1;LCD_STRING("       "); 
address_right(0xbE,0x40);rs=1;LCD_STRING(" SORRY");
delay_ms(1200);}  
///////////////////////////////////////////////////////////  
if(data1== 'n'){clear();
address_right(0xb8,0x40);rs=1;LCD_STRING(" NO ");
address_right(0xbA,0x40);rs=1;LCD_STRING(" THUMBS ");
address_right(0xbC,0x40);rs=1;LCD_STRING(" UP    "); 
address_right(0xbE,0x40);rs=1;LCD_STRING(" SORRY");
delay_ms(1200);}
/////////////////////////////////////////////////////////
if(data1== 'o'){clear();
address_right(0xb8,0x40);rs=1;LCD_STRING(" NO ");
address_right(0xbA,0x40);rs=1;LCD_STRING(" FANTA ");
address_right(0xbC,0x40);rs=1;LCD_STRING("      "); 
address_right(0xbE,0x40);rs=1;LCD_STRING(" SORRY");
delay_ms(1200);}
/////////////////////////////////////////////////////////
if(data1== 'p'){clear();
address_right(0xb8,0x40);rs=1;LCD_STRING(" NO ");
address_right(0xbA,0x40);rs=1;LCD_STRING(" MAAZA ");
address_right(0xbC,0x40);rs=1;LCD_STRING("       "); 
address_right(0xbE,0x40);rs=1;LCD_STRING(" SORRY");
delay_ms(1200);}
/////////////////////////////////////////////////////////
}
 
///////////////////////////////////////////////////////
if(bbbb==0)
{
/////////////////////////////////main menu  
if(ss==1){touchpad5();sss=1; aa=0;bb=0;cc=0;dd=0;ddd=0;
for(i=0;i<2;i++)adc_convert(i);delay_ms(100);}
/////////////////////////////////////////////////
if(aa==1){sssss=1;ddd=1;touchpad();
for(i=0;i<2;i++)adc_convert(i);delay_ms(100);}
///////////////////////////////////////////////
if(bb==1){ssss=1;ddd=1;touchpad1(); 
for(i=0;i<2;i++)adc_convert(i);delay_ms(100);}
//////////////////////////////////////////////
if(cc==1){ssssss=1;ddd=1;touchpad2(); 
for(i=0;i<2;i++)adc_convert(i);delay_ms(100);}
////////////////////////////////////////////////
if(dd==1){sssssss=1;ddd=1;touchpad3(); 
for(i=0;i<2;i++)adc_convert(i);delay_ms(100);}
///////////////////////////////////////////////
if(ccc==1){ssssssss=1;
for(i=0;i<2;i++)adc_convert(i);delay_ms(100);}
////////////////////////////////////////////////
if(ddd==1){home=1;
for(i=0;i<2;i++)adc_convert(i);delay_ms(100);}
////////////////////////////////////////////////////
goto st;
}  
}
}