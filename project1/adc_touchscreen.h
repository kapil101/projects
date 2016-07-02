#include <stdio.h>
#include <sleep.h>
#define   ADC_VREF_TYPE  0x40      
#define   VREF  5.00
unsigned int read_adc(unsigned char);
unsigned int adc_data; 
void adc_convert (unsigned int);   

unsigned int ss=0; 
unsigned int sss=0;   
unsigned int ssss=0;
unsigned int sssss=0;  
unsigned int ssssss=0;  
unsigned int sssssss=0; 
unsigned int ssssssss=0; 

unsigned int home=0;  
unsigned int ddd=0; 
unsigned int bbbb=0;  
unsigned int aa=0;                   
unsigned int bb=0;  
unsigned int cc=0;                   
unsigned int dd=0; 

unsigned int a1=0;                   
unsigned int b1=0;  
unsigned int c1=0;                   
unsigned int d1=0; 

unsigned int a2=0;                   
unsigned int b2=0;  
unsigned int c2=0;                   
unsigned int d2=0; 

unsigned int a3=0;                   
unsigned int b3=0;  
unsigned int c3=0;                   
unsigned int d3=0; 

unsigned int a4=0;                   
unsigned int b4=0;  
unsigned int c4=0;                   
unsigned int d4=0;  


unsigned int a11=0;                   
unsigned int b11=0;  
unsigned int c11=0;                   
unsigned int d11=0; 

unsigned int a22=0;                   
unsigned int b22=0;  
unsigned int c22=0;                   
unsigned int d22=0; 

unsigned int a33=0;                   
unsigned int b33=0;  
unsigned int c33=0;                   
unsigned int d33=0; 

unsigned int a44=0;                   
unsigned int b44=0;  
unsigned int c44=0;                   
unsigned int d44=0; 


unsigned int x,y,x1,y1;

interrupt [ADC_INT] void adc_isr(void)
{adc_data=ADCW;} 
 
unsigned int read_adc(unsigned char adc_input)
{ADMUX=ADC_VREF_TYPE;ADCSRA=0x8E;SFIOR&=0xEF;SFIOR|=0x10;
ADMUX=adc_input|ADC_VREF_TYPE;ADCSRA = ADCSRA | 0x40;MCUCR = 0x10;
sleep_enable();idle();return adc_data;
}             

void USART_Transmit( unsigned char data )
{UDR = data;while((UCSRA & 0x40) == 0);UCSRA = 0;delay_ms(10);}

void integer_lcd(int n)
{unsigned char c[6];unsigned int i=0;
 i=0;while(n>0){c[i]=(n%10)+48;n/=10;i++;}  
 while(i>0){ i--;}}         

void integer_lcd1(int n1)
{unsigned char c1[6];unsigned int i1=0;
i1=0;while(n1>0){c1[i1]=(n1%10)+48;n1/=10;i1++;}  
while(i1>0){ i1--; }}  
     
void adc_convert (unsigned int ch)  
{
if(ch==0){PORTA.2=1;PORTA.3=0;delay_ms(16);x = read_adc(ch);x=x*VREF;
x1=x;//address_right(0xbd,0x40);rs=1;
integer_lcd(x1);}
else if(ch==1){PORTA.2=0;PORTA.3=1; delay_ms(16);y = read_adc(ch);
y=y*VREF;y1=y;//address_right(0xbf,0x40);rs=1;
integer_lcd(y1);}                          
///////////////////main menu////////////////////////////////////////
if(sss==1)
{
////////////////////////////////////////////////////////////////////////////
if((x1>=365)&&(x1<=860)){if((y1>=1635)&&(y1<=2500)){ddd=0;aa=1;bb=0;cc=0;dd=0;sss=0; ss=0;delay_ms(500);}}
////////////////////////////////////////////////////////////////////////////
if((x1>=500)&&(x1<=920)){if((y1>=470)&&(y1<=1500)){ddd=0;aa=0;bb=1;cc=0;dd=0;sss=0; ss=0;delay_ms(500);}}
///////////////////////////////////////////////////////////////////////////
if((x1>=720)&&(x1<=1240)){if((y1>=1400)&&(y1<=2100)){ddd=0;aa=0;bb=0;dd=0;cc=1;sss=0;ss=0;delay_ms(500);}}
////////////////////////////////////////////////////////////////////////////
if((x1>=1000)&&(x1<=1500)){if((y1>=360)&&(y1<=1400)){ddd=0;aa=0;bb=0;cc=0;dd=1;sss=0;ss=0;delay_ms(500);}}
/////////////////////////////////////////////////////////////////////////
}
///////////////////NON veg menu////////////////////////////////////////
if(sssss==1)
{
///////////////////////////////////////////////////////////////////////////
if((x1>=365)&&(x1<=860)){if((y1>=1635)&&(y1<=2500))
{aa=0;sssss=0;ss=1;clear();a11=a11+1;
address_right(0xb8,0x40);rs=1;LCD_STRING(" CHIKEN ");
address_right(0xbA,0x40);rs=1;LCD_STRING(" BIRYANI"); 
address_right(0xbC,0x40);rs=1;LCD_STRING(" selected");a1=2;delay_ms(1000); }}
/////////////////////////////////////////////////////////////////////////////
if((x1>=500)&&(x1<=920)){if((y1>=470)&&(y1<=1500))
{aa=0;sssss=0;ss=1;clear();b11=b11+1;
address_right(0xb8,0x40);rs=1;LCD_STRING(" FISH ");
address_right(0xbA,0x40);rs=1;LCD_STRING(" FRY  "); 
address_right(0xbC,0x40);rs=1;LCD_STRING(" selected");b1=2;delay_ms(1000); }}
//////////////////////////////////////////////////////////////////////////////
if((x1>=720)&&(x1<=1240)){if((y1>=1400)&&(y1<=2100))
{aa=0;sssss=0;ss=1;clear();c11=c11+1;
address_right(0xb8,0x40);rs=1;LCD_STRING(" MUTTON ");
address_right(0xbA,0x40);rs=1;LCD_STRING(" BIRYANI  "); 
address_right(0xbC,0x40);rs=1;LCD_STRING(" selected");c1=2;delay_ms(1000); }}
//////////////////////////////////////////////////////////////////////////////
if((x1>=1000)&&(x1<=1500)){if((y1>=360)&&(y1<=1400))
{aa=0;sssss=0;ss=1;clear();d11=d11+1;
address_right(0xb8,0x40);rs=1;LCD_STRING(" PRAWNS ");
address_right(0xbA,0x40);rs=1;LCD_STRING(" CURRY  "); 
address_right(0xbC,0x40);rs=1;LCD_STRING(" selected");d1=2;delay_ms(1000); }}
//////////////////////////////////////////////////////////////////////////////
}
///////////////////veg menu///////////////////////////////////////////////////////
if(ssss==1)
{
///////////////////////////////////////////////////////////////////////////////////
if((x1>=365)&&(x1<=860)){if((y1>=1635)&&(y1<=2500))
{bb=0;ssss=0;ss=1;clear();a22=a22+1;
address_right(0xb8,0x40);rs=1;LCD_STRING(" VEG     ");
address_right(0xbA,0x40);rs=1;LCD_STRING(" BIRYANI "); 
address_right(0xbC,0x40);rs=1;LCD_STRING(" selected");delay_ms(1000);a2=2;}}
////////////////////////////////////////////////////////////////////////////////////
if((x1>=500)&&(x1<=920)){if((y1>=470)&&(y1<=1500))
{bb=0;ssss=0;ss=1;clear();b22=b22+1;
address_right(0xb8,0x40);rs=1;LCD_STRING(" PALAK   ");
address_right(0xbA,0x40);rs=1;LCD_STRING(" PANEER  "); 
address_right(0xbC,0x40);rs=1;LCD_STRING(" selected");delay_ms(1000);b2=2;}}
/////////////////////////////////////////////////////////////////////////////////////
if((x1>=720)&&(x1<=1240)){if((y1>=1400)&&(y1<=2100))
{bb=0;ssss=0;ss=1;clear();c22=c22+1;
address_right(0xb8,0x40);rs=1;LCD_STRING(" MANCHU  ");
address_right(0xbA,0x40);rs=1;LCD_STRING(" RIA     "); 
address_right(0xbC,0x40);rs=1;LCD_STRING(" selected");delay_ms(1000);c2=2;}}
//////////////////////////////////////////////////////////////////////////////////////
if((x1>=1000)&&(x1<=1500)){if((y1>=360)&&(y1<=1400))
{bb=0;ssss=0;ss=1;clear();d22=d22+1;
address_right(0xb8,0x40);rs=1;LCD_STRING(" DAL     ");
address_right(0xbA,0x40);rs=1;LCD_STRING(" TADKA   "); 
address_right(0xbC,0x40);rs=1;LCD_STRING(" selected");delay_ms(1000);d2=2;}}
///////////////////////////////////////////////////////////////////////////////////////
}    
///////////////////ice cream cups menu///////////////////////////////////////////////////////
if(ssssss==1)
{
///////////////////////////////////////////////////////////////////////////////////
if((x1>=365)&&(x1<=860)){if((y1>=1635)&&(y1<=2500))
{cc=0;ssssss=0;ss=1;clear();a44=a44+1;
address_right(0xb8,0x40);rs=1;LCD_STRING("  CHOCO  ");
address_right(0xbA,0x40);rs=1;LCD_STRING("   LATE  "); 
address_right(0xbC,0x40);rs=1;LCD_STRING(" selected");delay_ms(1000);a4=2;}}
////////////////////////////////////////////////////////////////////////////////////
if((x1>=500)&&(x1<=920)){if((y1>=470)&&(y1<=1500))
{cc=0;ssssss=0;ss=1;clear();b44=b44+1;
address_right(0xb8,0x40);rs=1;LCD_STRING(" VENNILA ");
address_right(0xbA,0x40);rs=1;LCD_STRING("         "); 
address_right(0xbC,0x40);rs=1;LCD_STRING(" selected");delay_ms(1000);b4=2;}}
/////////////////////////////////////////////////////////////////////////////////////
if((x1>=720)&&(x1<=1240)){if((y1>=1400)&&(y1<=2100))
{cc=0;ssssss=0;ss=1;clear();c44=c44+1;
address_right(0xb8,0x40);rs=1;LCD_STRING(" BUTTER  ");
address_right(0xbA,0x40);rs=1;LCD_STRING(" SCOTCH  "); 
address_right(0xbC,0x40);rs=1;LCD_STRING(" selected");delay_ms(1000);c4=2;}}
//////////////////////////////////////////////////////////////////////////////////////
if((x1>=1000)&&(x1<=1500)){if((y1>=360)&&(y1<=1400))
{cc=0;ssssss=0;ss=1;clear();d44=d44+1;
address_right(0xb8,0x40);rs=1;LCD_STRING(" STRAW   ");
address_right(0xbA,0x40);rs=1;LCD_STRING(" BERRY   "); 
address_right(0xbC,0x40);rs=1;LCD_STRING(" selected");delay_ms(1000);d4=2;}}
///////////////////////////////////////////////////////////////////////////////////////
}
///////////////////sprite menu///////////////////////////////////////////////////////
if(sssssss==1)
{
///////////////////////////////////////////////////////////////////////////////////
if((x1>=365)&&(x1<=860)){if((y1>=1635)&&(y1<=2500))
{dd=0;sssssss=0;ss=1;clear();a33=a33+1;
address_right(0xb8,0x40);rs=1;LCD_STRING(" SPRITE  ");
address_right(0xbA,0x40);rs=1;LCD_STRING("         "); 
address_right(0xbC,0x40);rs=1;LCD_STRING(" selected");delay_ms(1000);a3=2;}}
////////////////////////////////////////////////////////////////////////////////////
if((x1>=500)&&(x1<=920)){if((y1>=470)&&(y1<=1500))
{dd=0;sssssss=0;ss=1;clear();b33=b33+1;
address_right(0xb8,0x40);rs=1;LCD_STRING(" THUMBS  ");
address_right(0xbA,0x40);rs=1;LCD_STRING("  UP     "); 
address_right(0xbC,0x40);rs=1;LCD_STRING(" selected");delay_ms(1000);b3=2;}}
/////////////////////////////////////////////////////////////////////////////////////
if((x1>=720)&&(x1<=1240)){if((y1>=1400)&&(y1<=2100))
{dd=0;sssssss=0;ss=1;clear();c33=c33+1;
address_right(0xb8,0x40);rs=1;LCD_STRING(" FANTA   ");
address_right(0xbA,0x40);rs=1;LCD_STRING("         "); 
address_right(0xbC,0x40);rs=1;LCD_STRING(" selected");delay_ms(1000);c3=2;}}
//////////////////////////////////////////////////////////////////////////////////////
if((x1>=1000)&&(x1<=1500)){if((y1>=360)&&(y1<=1400))
{dd=0;sssssss=0;ss=1;clear();d33=d33+1;
address_right(0xb8,0x40);rs=1;LCD_STRING(" MAAZA   ");
address_right(0xbA,0x40);rs=1;LCD_STRING("         "); 
address_right(0xbC,0x40);rs=1;LCD_STRING(" selected");delay_ms(1000);d3=2;}}
///////////////////////////////////////////////////////////////////////////////////////
}
///////////////////home///////////////////////////////////////////////////////
if(home==1)
{
///////////////////////////////////////////////////////////////////////////////////
if((x1>=1575)&&(x1<=2000)){if((y1>=345)&&(y1<=940))
{
ss=1; 
ddd=0;
ssss=0;
sssss=0;
ssssss=0;
sssssss=0;
ssssssss=0; 
delay_ms(1000);
sss=0;
sssss=0;
ssss=0;
ssssss=0;
sssssss=0;
ssssssss=0; 
}
}
}

///////////////////confrom///////////////////////////////////////////////////////
if(ssssssss==1)
{
///////////////////////////////////////////////////////////////////////////////////
if((x1>=1175)&&(x1<=1380)){if((y1>=1620)&&(y1<=1940))
{
 ssss=0;
 sssss=0;
 ssssss=0;
 sssssss=0;
 ssssssss=0;
 
clear();
address_right(0xb8,0x40);   
rs=1;
LCD_STRING(" YOUR ");
address_right(0xbA,0x40);   
rs=1;
LCD_STRING(" ORDER IS "); 
address_right(0xbC,0x40);   
rs=1;
LCD_STRING(" CONFORMED "); 
address_right(0xbE,0x40);   

delay_ms(1000); 


printf("TABLE NO--121");printf("\r\n");    
printf("SELECTED ITEMS");printf("\r\n");


///////////////////NON VEG ITEMS////////////////////////////////////////////////////////
if((a1==0)&&(b1==0)&& (c1==0)&&(d1==0))
{printf("NO NON VEG ITEMS ");printf("\r\n");}
/////////////////////////
if((a1==2)&&(b1==2)&& (c1==2)&&(d1==2))
{
integer_lcd1(a11);USART_Transmit((a11/10) + 0x30);USART_Transmit((a11%10) + 0x30);delay_ms(200);
printf("--CHIKEN BIRYANI ");printf("\r\n");
integer_lcd1(b11);USART_Transmit((b11/10) + 0x30);USART_Transmit((b11%10) + 0x30);delay_ms(200);
printf("--FISH FRY ");printf("\r\n");  
integer_lcd1(c11);USART_Transmit((c11/10) + 0x30);USART_Transmit((c11%10) + 0x30);delay_ms(200);
printf("--MUTTON BIRYANI");printf("\r\n");
integer_lcd1(d11);USART_Transmit((d11/10) + 0x30);USART_Transmit((d11%10) + 0x30);delay_ms(200);
printf("--PRAWNS CURRY ");printf("\r\n");
}
////////////////////////////
if((a1==2)&&(b1==2)&& (c1==2)&&(d1==0))
{
integer_lcd1(a11);USART_Transmit((a11/10) + 0x30);USART_Transmit((a11%10) + 0x30);delay_ms(200);
printf("--CHIKEN BIRYANI ");printf("\r\n");
integer_lcd1(b11);USART_Transmit((b11/10) + 0x30);USART_Transmit((b11%10) + 0x30);delay_ms(200);
printf("--FISH FRY ");printf("\r\n");  
integer_lcd1(c11);USART_Transmit((c11/10) + 0x30);USART_Transmit((c11%10) + 0x30);delay_ms(200);
printf("--MUTTON BIRYANI");printf("\r\n");
}
//////////////////////////////
if((a1==0)&&(b1==2)&& (c1==2)&&(d1==2))
{
integer_lcd1(b11);USART_Transmit((b11/10) + 0x30);USART_Transmit((b11%10) + 0x30);delay_ms(200);
printf("--FISH FRY ");printf("\r\n");  
integer_lcd1(c11);USART_Transmit((c11/10) + 0x30);USART_Transmit((c11%10) + 0x30);delay_ms(200);
printf("--MUTTON BIRYANI");printf("\r\n");
integer_lcd1(d11);USART_Transmit((d11/10) + 0x30);USART_Transmit((d11%10) + 0x30);delay_ms(200);
printf("--PRAWNS CURRY ");printf("\r\n");
}
/////////////////////////////
if((a1==2)&&(b1==0)&& (c1==2)&&(d1==2))
{
integer_lcd1(a11);USART_Transmit((a11/10) + 0x30);USART_Transmit((a11%10) + 0x30);delay_ms(200);
printf("--CHIKEN BIRYANI ");printf("\r\n");
integer_lcd1(c11);USART_Transmit((c11/10) + 0x30);USART_Transmit((c11%10) + 0x30);delay_ms(200);
printf("--MUTTON BIRYANI");printf("\r\n");
integer_lcd1(d11);USART_Transmit((d11/10) + 0x30);USART_Transmit((d11%10) + 0x30);delay_ms(200);
printf("--PRAWNS CURRY ");printf("\r\n");
}
//////////////////////////////
if((a1==2)&&(b1==2)&& (c1==0)&&(d1==2))
{
integer_lcd1(a11);USART_Transmit((a11/10) + 0x30);USART_Transmit((a11%10) + 0x30);delay_ms(200);
printf("--CHIKEN BIRYANI ");printf("\r\n");
integer_lcd1(b11);USART_Transmit((b11/10) + 0x30);USART_Transmit((b11%10) + 0x30);delay_ms(200);
printf("--FISH FRY ");printf("\r\n");  
integer_lcd1(d11);USART_Transmit((d11/10) + 0x30);USART_Transmit((d11%10) + 0x30);delay_ms(200);
printf("--PRAWNS CURRY ");printf("\r\n");
} 
///////////////////////////////
if((a1==2)&&(b1==0)&& (c1==0)&&(d1==0))
{
integer_lcd1(a11);USART_Transmit((a11/10) + 0x30);USART_Transmit((a11%10) + 0x30);delay_ms(200);
printf("--CHIKEN BIRYANI ");printf("\r\n");
}
//////////////////////////////
if((a1==0)&&(b1==2)&& (c1==0)&&(d1==0))
{
integer_lcd1(b11);USART_Transmit((b11/10) + 0x30);USART_Transmit((b11%10) + 0x30);delay_ms(200);
printf("--FISH FRY ");printf("\r\n");  
}
////////////////////////////
if((a1==0)&&(b1==0)&& (c1==2)&&(d1==0))
{
integer_lcd1(c11);USART_Transmit((c11/10) + 0x30);USART_Transmit((c11%10) + 0x30);delay_ms(200);
printf("--MUTTON BIRYANI");printf("\r\n");
}
/////////////////////////////
if((a1==0)&&(b1==0)&& (c1==0)&&(d1==2))
{
integer_lcd1(d11);USART_Transmit((d11/10) + 0x30);USART_Transmit((d11%10) + 0x30);delay_ms(200);
printf("--PRAWNS CURRY ");printf("\r\n");
}
//////////////////////////////////
if((a1==2)&&(b1==2)&& (c1==0)&&(d1==0))
{
integer_lcd1(a11);USART_Transmit((a11/10) + 0x30);USART_Transmit((a11%10) + 0x30);delay_ms(200);
printf("--CHIKEN BIRYANI ");printf("\r\n");
integer_lcd1(b11);USART_Transmit((b11/10) + 0x30);USART_Transmit((b11%10) + 0x30);delay_ms(200);
printf("--FISH FRY ");printf("\r\n");  
}
////////////////////////////////////
if((a1==2)&&(b1==0)&& (c1==2)&&(d1==0))
{
integer_lcd1(a11);USART_Transmit((a11/10) + 0x30);USART_Transmit((a11%10) + 0x30);delay_ms(200);
printf("--CHIKEN BIRYANI ");printf("\r\n");
integer_lcd1(c11);USART_Transmit((c11/10) + 0x30);USART_Transmit((c11%10) + 0x30);delay_ms(200);
printf("--MUTTON BIRYANI");printf("\r\n");
}
///////////////////////////////////
if((a1==2)&&(b1==0)&& (c1==0)&&(d1==2))
{
integer_lcd1(a11);USART_Transmit((a11/10) + 0x30);USART_Transmit((a11%10) + 0x30);delay_ms(200);
printf("--CHIKEN BIRYANI ");printf("\r\n");
integer_lcd1(d11);USART_Transmit((d11/10) + 0x30);USART_Transmit((d11%10) + 0x30);delay_ms(200);
printf("--PRAWNS CURRY ");printf("\r\n");
}                                  
//////////////////////////////////
if((a1==0)&&(b1==2)&& (c1==2)&&(d1==0))
{
integer_lcd1(b11);USART_Transmit((b11/10) + 0x30);USART_Transmit((b11%10) + 0x30);delay_ms(200);
printf("--FISH FRY ");printf("\r\n");  
integer_lcd1(c11);USART_Transmit((c11/10) + 0x30);USART_Transmit((c11%10) + 0x30);delay_ms(200);
printf("--MUTTON BIRYANI");printf("\r\n");
}
/////////////////////////////////////
if((a1==0)&&(b1==2)&& (c1==0)&&(d1==2))
{
integer_lcd1(b11);USART_Transmit((b11/10) + 0x30);USART_Transmit((b11%10) + 0x30);delay_ms(200);
printf("--FISH FRY ");printf("\r\n");  
integer_lcd1(d11);USART_Transmit((d11/10) + 0x30);USART_Transmit((d11%10) + 0x30);delay_ms(200);
printf("--PRAWNS CURRY ");printf("\r\n");
}
///////////////////////////////////
if((a1==0)&&(b1==0)&& (c1==2)&&(d1==2))
{
integer_lcd1(c11);USART_Transmit((c11/10) + 0x30);USART_Transmit((c11%10) + 0x30);delay_ms(200);
printf("--MUTTON BIRYANI");printf("\r\n");
integer_lcd1(d11);USART_Transmit((d11/10) + 0x30);USART_Transmit((d11%10) + 0x30);delay_ms(200);
printf("--PRAWNS CURRY ");printf("\r\n");
} 

  
//////////////////////////////VEG ITEMS////////////////////////////
///////////////////VEG ITEMS//////
if((a2==0)&&(b2==0)&& (c2==0)&&(d2==0))
{printf("NO  VEG ITEMS ");printf("\r\n");}
///////////////////
if((a2==2)&&(b2==2)&& (c2==2)&&(d2==2))
{
integer_lcd1(a22);USART_Transmit((a22/10) + 0x30);USART_Transmit((a22%10) + 0x30);delay_ms(200);
printf("--VEG BIRYANI");printf("\r\n");
integer_lcd1(b22);USART_Transmit((b22/10) + 0x30);USART_Transmit((b22%10) + 0x30);delay_ms(200);
printf("--PALAK PANEER");printf("\r\n");  
integer_lcd1(c22);USART_Transmit((c22/10) + 0x30);USART_Transmit((c22%10) + 0x30);delay_ms(200);
printf("--MANCHURIA ");printf("\r\n");
integer_lcd1(d22);USART_Transmit((d22/10) + 0x30);USART_Transmit((d22%10) + 0x30);delay_ms(200);
printf("--DAL TADKA");printf("\r\n");
}
//////////////////////////
if((a2==2)&&(b2==2)&& (c2==2)&&(d2==0))
{
integer_lcd1(a22);USART_Transmit((a22/10) + 0x30);USART_Transmit((a22%10) + 0x30);delay_ms(200);
printf("--VEG BIRYANI");printf("\r\n");
integer_lcd1(b22);USART_Transmit((b22/10) + 0x30);USART_Transmit((b22%10) + 0x30);delay_ms(200);
printf("--PALAK PANEER");printf("\r\n");  
integer_lcd1(c22);USART_Transmit((c22/10) + 0x30);USART_Transmit((c22%10) + 0x30);delay_ms(200);
printf("--MANCHURIA ");printf("\r\n");
}
//////////////////////////
if((a2==0)&&(b2==2)&& (c2==2)&&(d2==2))
{
integer_lcd1(b22);USART_Transmit((b22/10) + 0x30);USART_Transmit((b22%10) + 0x30);delay_ms(200);
printf("--PALAK PANEER");printf("\r\n");  
integer_lcd1(c22);USART_Transmit((c22/10) + 0x30);USART_Transmit((c22%10) + 0x30);delay_ms(200);
printf("--MANCHURIA ");printf("\r\n");
integer_lcd1(d22);USART_Transmit((d22/10) + 0x30);USART_Transmit((d22%10) + 0x30);delay_ms(200);
printf("--DAL TADKA");printf("\r\n");
}
//////////////////////////////
if((a2==2)&&(b2==0)&& (c2==2)&&(d2==2))
{
integer_lcd1(a22);USART_Transmit((a22/10) + 0x30);USART_Transmit((a22%10) + 0x30);delay_ms(200);
printf("--VEG BIRYANI");printf("\r\n");
integer_lcd1(c22);USART_Transmit((c22/10) + 0x30);USART_Transmit((c22%10) + 0x30);delay_ms(200);
printf("--MANCHURIA ");printf("\r\n");
integer_lcd1(d22);USART_Transmit((d22/10) + 0x30);USART_Transmit((d22%10) + 0x30);delay_ms(200);
printf("--DAL TADKA");printf("\r\n");
}
////////////////////////////
if((a2==2)&&(b2==2)&& (c2==0)&&(d2==2))
{
integer_lcd1(a22);USART_Transmit((a22/10) + 0x30);USART_Transmit((a22%10) + 0x30);delay_ms(200);
printf("--VEG BIRYANI");printf("\r\n");
integer_lcd1(b22);USART_Transmit((b22/10) + 0x30);USART_Transmit((b22%10) + 0x30);delay_ms(200);
printf("--PALAK PANEER");printf("\r\n");  
integer_lcd1(d22);USART_Transmit((d22/10) + 0x30);USART_Transmit((d22%10) + 0x30);delay_ms(200);
printf("--DAL TADKA");printf("\r\n");
}
//////////////////////////////
if((a2==2)&&(b2==0)&& (c2==0)&&(d2==0))
{
integer_lcd1(a22);USART_Transmit((a22/10) + 0x30);USART_Transmit((a22%10) + 0x30);delay_ms(200);
printf("--VEG BIRYANI");printf("\r\n");
}
/////////////////////////////////////
if((a2==0)&&(b2==2)&& (c2==0)&&(d2==0))
{
integer_lcd1(b22);USART_Transmit((b22/10) + 0x30);USART_Transmit((b22%10) + 0x30);delay_ms(200);
printf("--PALAK PANEER");printf("\r\n");  
}
/////////////////////////////////////////
if((a2==0)&&(b2==0)&& (c2==2)&&(d2==0))
{
integer_lcd1(c22);USART_Transmit((c22/10) + 0x30);USART_Transmit((c22%10) + 0x30);delay_ms(200);
printf("--MANCHURIA ");printf("\r\n");
}
////////////////////////////////////////
if((a2==0)&&(b2==0)&& (c2==0)&&(d2==2))
{
integer_lcd1(d22);USART_Transmit((d22/10) + 0x30);USART_Transmit((d22%10) + 0x30);delay_ms(200);
printf("--DAL TADKA");printf("\r\n");
}
//////////////////////////////////
if((a2==2)&&(b2==2)&& (c2==0)&&(d2==0))
{
integer_lcd1(a22);USART_Transmit((a22/10) + 0x30);USART_Transmit((a22%10) + 0x30);delay_ms(200);
printf("--VEG BIRYANI");printf("\r\n");
integer_lcd1(b22);USART_Transmit((b22/10) + 0x30);USART_Transmit((b22%10) + 0x30);delay_ms(200);
printf("--PALAK PANEER");printf("\r\n");  
}
///////////////////////////////////////
if((a2==2)&&(b2==0)&& (c2==2)&&(d2==0))
{
integer_lcd1(a22);USART_Transmit((a22/10) + 0x30);USART_Transmit((a22%10) + 0x30);delay_ms(200);
printf("--VEG BIRYANI");printf("\r\n");
integer_lcd1(c22);USART_Transmit((c22/10) + 0x30);USART_Transmit((c22%10) + 0x30);delay_ms(200);
printf("--MANCHURIA ");printf("\r\n");
}
/////////////////////////////////
if((a2==2)&&(b2==0)&& (c2==0)&&(d2==2))
{
integer_lcd1(a22);USART_Transmit((a22/10) + 0x30);USART_Transmit((a22%10) + 0x30);delay_ms(200);
printf("--VEG BIRYANI");printf("\r\n");
integer_lcd1(d22);USART_Transmit((d22/10) + 0x30);USART_Transmit((d22%10) + 0x30);delay_ms(200);
printf("--DAL TADKA");printf("\r\n");
}
/////////////////////////////////////
if((a2==0)&&(b2==2)&& (c2==2)&&(d2==0))
{
integer_lcd1(b22);USART_Transmit((b22/10) + 0x30);USART_Transmit((b22%10) + 0x30);delay_ms(200);
printf("--PALAK PANEER");printf("\r\n");  
integer_lcd1(c22);USART_Transmit((c22/10) + 0x30);USART_Transmit((c22%10) + 0x30);delay_ms(200);
printf("--MANCHURIA ");printf("\r\n");
}
//////////////////////////////////
if((a2==0)&&(b2==2)&& (c2==0)&&(d2==2))
{
integer_lcd1(b22);USART_Transmit((b22/10) + 0x30);USART_Transmit((b22%10) + 0x30);delay_ms(200);
printf("--PALAK PANEER");printf("\r\n");  
integer_lcd1(d22);USART_Transmit((d22/10) + 0x30);USART_Transmit((d22%10) + 0x30);delay_ms(200);
printf("--DAL TADKA");printf("\r\n");
}
///////////////////////////////////////
if((a2==0)&&(b2==0)&& (c2==2)&&(d2==2))
{
integer_lcd1(c22);USART_Transmit((c22/10) + 0x30);USART_Transmit((c22%10) + 0x30);delay_ms(200);
printf("--MANCHURIA ");printf("\r\n");
integer_lcd1(d22);USART_Transmit((d22/10) + 0x30);USART_Transmit((d22%10) + 0x30);delay_ms(200);
printf("--DAL TADKA");printf("\r\n");
}   
//////////////////////////////COOL DRINKS ITEMS////////////////////////////
///////////////////ICE CREAM//////
if((a3==0)&&(b3==0)&& (c3==0)&&(d3==0))
{printf("NO  COOL DRINKS ITEMS ");printf("\r\n");}
///////////////////////////////
if((a3==2)&&(b3==2)&& (c3==2)&&(d3==2))
{
integer_lcd1(a33);USART_Transmit((a33/10) + 0x30);USART_Transmit((a33%10) + 0x30);delay_ms(200);
printf("--SPRITE");printf("\r\n");
integer_lcd1(b33);USART_Transmit((b33/10) + 0x30);USART_Transmit((b33%10) + 0x30);delay_ms(200);
printf("--THUMBS UP ");printf("\r\n");  
integer_lcd1(c33);USART_Transmit((c33/10) + 0x30);USART_Transmit((c33%10) + 0x30);delay_ms(200);
printf("--FANTA ");printf("\r\n");
integer_lcd1(d33);USART_Transmit((d33/10) + 0x30);USART_Transmit((d33%10) + 0x30);delay_ms(200);
printf("--MAAZA ");printf("\r\n");
}
////////////////////////////
if((a3==2)&&(b3==2)&& (c3==2)&&(d3==0))
{
integer_lcd1(a33);USART_Transmit((a33/10) + 0x30);USART_Transmit((a33%10) + 0x30);delay_ms(200);
printf("--SPRITE");printf("\r\n");
integer_lcd1(b33);USART_Transmit((b33/10) + 0x30);USART_Transmit((b33%10) + 0x30);delay_ms(200);
printf("--THUMBS UP ");printf("\r\n");  
integer_lcd1(c33);USART_Transmit((c33/10) + 0x30);USART_Transmit((c33%10) + 0x30);delay_ms(200);
printf("--FANTA ");printf("\r\n");
}
///////////////////////////////////
if((a3==0)&&(b3==2)&& (c3==2)&&(d3==2))
{
integer_lcd1(b33);USART_Transmit((b33/10) + 0x30);USART_Transmit((b33%10) + 0x30);delay_ms(200);
printf("--THUMBS UP ");printf("\r\n");  
integer_lcd1(c33);USART_Transmit((c33/10) + 0x30);USART_Transmit((c33%10) + 0x30);delay_ms(200);
printf("--FANTA ");printf("\r\n");
integer_lcd1(d33);USART_Transmit((d33/10) + 0x30);USART_Transmit((d33%10) + 0x30);delay_ms(200);
printf("--MAAZA ");printf("\r\n");
}
////////////////////////////////////////
if((a3==2)&&(b3==0)&& (c3==2)&&(d3==2))
{
integer_lcd1(a33);USART_Transmit((a33/10) + 0x30);USART_Transmit((a33%10) + 0x30);delay_ms(200);
printf("--SPRITE");printf("\r\n");
integer_lcd1(c33);USART_Transmit((c33/10) + 0x30);USART_Transmit((c33%10) + 0x30);delay_ms(200);
printf("--FANTA ");printf("\r\n");
integer_lcd1(d33);USART_Transmit((d33/10) + 0x30);USART_Transmit((d33%10) + 0x30);delay_ms(200);
printf("--MAAZA ");printf("\r\n");
}
/////////////////////////////////////////
if((a3==2)&&(b3==2)&& (c3==0)&&(d3==2))
{
integer_lcd1(a33);USART_Transmit((a33/10) + 0x30);USART_Transmit((a33%10) + 0x30);delay_ms(200);
printf("--SPRITE");printf("\r\n");
integer_lcd1(b33);USART_Transmit((b33/10) + 0x30);USART_Transmit((b33%10) + 0x30);delay_ms(200);
printf("--THUMBS UP ");printf("\r\n");  
integer_lcd1(d33);USART_Transmit((d33/10) + 0x30);USART_Transmit((d33%10) + 0x30);delay_ms(200);
printf("--MAAZA ");printf("\r\n");
}
////////////////////////////////////
if((a3==2)&&(b3==0)&& (c3==0)&&(d3==0))
{
integer_lcd1(a33);USART_Transmit((a33/10) + 0x30);USART_Transmit((a33%10) + 0x30);delay_ms(200);
printf("--SPRITE");printf("\r\n");
}
/////////////////////////////////////////
if((a3==0)&&(b3==2)&& (c3==0)&&(d3==0))
{
integer_lcd1(b33);USART_Transmit((b33/10) + 0x30);USART_Transmit((b33%10) + 0x30);delay_ms(200);
printf("--THUMBS UP ");printf("\r\n");  
}
/////////////////////////////////////
if((a3==0)&&(b3==0)&& (c3==2)&&(d3==0))
{
integer_lcd1(c33);USART_Transmit((c33/10) + 0x30);USART_Transmit((c33%10) + 0x30);delay_ms(200);
printf("--FANTA ");printf("\r\n");
}
/////////////////////////////////////////
if((a3==0)&&(b3==0)&& (c3==0)&&(d3==2))
{
integer_lcd1(d33);USART_Transmit((d33/10) + 0x30);USART_Transmit((d33%10) + 0x30);delay_ms(200);
printf("--MAAZA ");printf("\r\n");
}
//////////////////////////////////////////////////////
if((a3==2)&&(b3==2)&& (c3==0)&&(d3==0))
{
integer_lcd1(a33);USART_Transmit((a33/10) + 0x30);USART_Transmit((a33%10) + 0x30);delay_ms(200);
printf("--SPRITE");printf("\r\n");
integer_lcd1(b33);USART_Transmit((b33/10) + 0x30);USART_Transmit((b33%10) + 0x30);delay_ms(200);
printf("--THUMBS UP ");printf("\r\n");  
}
////////////////////////////////////
if((a3==2)&&(b3==0)&& (c3==2)&&(d3==0))
{
integer_lcd1(a33);USART_Transmit((a33/10) + 0x30);USART_Transmit((a33%10) + 0x30);delay_ms(200);
printf("--SPRITE");printf("\r\n");
integer_lcd1(c33);USART_Transmit((c33/10) + 0x30);USART_Transmit((c33%10) + 0x30);delay_ms(200);
printf("--FANTA ");printf("\r\n");
}
/////////////////////////////////////////
if((a3==2)&&(b3==0)&& (c3==0)&&(d3==2))
{
integer_lcd1(a33);USART_Transmit((a33/10) + 0x30);USART_Transmit((a33%10) + 0x30);delay_ms(200);
printf("--SPRITE");printf("\r\n");
integer_lcd1(d33);USART_Transmit((d33/10) + 0x30);USART_Transmit((d33%10) + 0x30);delay_ms(200);
printf("--MAAZA ");printf("\r\n");
}
//////////////////////////////////
if((a3==0)&&(b3==2)&& (c3==2)&&(d3==0))
{
integer_lcd1(b33);USART_Transmit((b33/10) + 0x30);USART_Transmit((b33%10) + 0x30);delay_ms(200);
printf("--THUMBS UP ");printf("\r\n");  
integer_lcd1(c33);USART_Transmit((c33/10) + 0x30);USART_Transmit((c33%10) + 0x30);delay_ms(200);
printf("--FANTA ");printf("\r\n");
}
////////////////////////////////
if((a3==0)&&(b3==2)&& (c3==0)&&(d3==2))
{
integer_lcd1(b33);USART_Transmit((b33/10) + 0x30);USART_Transmit((b33%10) + 0x30);delay_ms(200);
printf("--THUMBS UP ");printf("\r\n");  
integer_lcd1(d33);USART_Transmit((d33/10) + 0x30);USART_Transmit((d33%10) + 0x30);delay_ms(200);
printf("--MAAZA ");printf("\r\n");
}

if((a3==0)&&(b3==0)&& (c3==2)&&(d3==2))
{
integer_lcd1(c33);USART_Transmit((c33/10) + 0x30);USART_Transmit((c33%10) + 0x30);delay_ms(200);
printf("--FANTA ");printf("\r\n");
integer_lcd1(d33);USART_Transmit((d33/10) + 0x30);USART_Transmit((d33%10) + 0x30);delay_ms(200);
printf("--MAAZA ");printf("\r\n");
}   
//////////////////////////////ICE CREAM ITEMS////////////////////////////
///////////////////ICE CREAM//////
if((a4==0)&&(b4==0)&& (c4==0)&&(d4==0))
{printf("NO  ICE CREAM ITEMS ");printf("\r\n");}
/////////////////////////////
if((a4==2)&&(b4==2)&& (c4==2)&&(d4==2))
{
integer_lcd1(a44);USART_Transmit((a44/10) + 0x30);USART_Transmit((a44%10) + 0x30);delay_ms(200);
printf("--CHOCOLATE");printf("\r\n");
integer_lcd1(b44);USART_Transmit((b44/10) + 0x30);USART_Transmit((b44%10) + 0x30);delay_ms(200);
printf("--VANNILA");printf("\r\n");  
integer_lcd1(c44);USART_Transmit((c44/10) + 0x30);USART_Transmit((c44%10) + 0x30);delay_ms(200);
printf("--BUTTER SCOTCH");printf("\r\n");
integer_lcd1(d44);USART_Transmit((d44/10) + 0x30);USART_Transmit((d44%10) + 0x30);delay_ms(200);
printf("--STRAW BERRY");printf("\r\n");
}
//////////////////////////////
if((a4==2)&&(b4==2)&& (c4==2)&&(d4==0))
{
integer_lcd1(a44);USART_Transmit((a44/10) + 0x30);USART_Transmit((a44%10) + 0x30);delay_ms(200);
printf("--CHOCOLATE");printf("\r\n");
integer_lcd1(b44);USART_Transmit((b44/10) + 0x30);USART_Transmit((b44%10) + 0x30);delay_ms(200);
printf("--VANNILA");printf("\r\n");  
integer_lcd1(c44);USART_Transmit((c44/10) + 0x30);USART_Transmit((c44%10) + 0x30);delay_ms(200);
printf("--BUTTER SCOTCH");printf("\r\n");
}
//////////////////////////////////
if((a4==0)&&(b4==2)&& (c4==2)&&(d4==2))
{
integer_lcd1(b44);USART_Transmit((b44/10) + 0x30);USART_Transmit((b44%10) + 0x30);delay_ms(200);
printf("--VANNILA");printf("\r\n");  
integer_lcd1(c44);USART_Transmit((c44/10) + 0x30);USART_Transmit((c44%10) + 0x30);delay_ms(200);
printf("--BUTTER SCOTCH");printf("\r\n");
integer_lcd1(d44);USART_Transmit((d44/10) + 0x30);USART_Transmit((d44%10) + 0x30);delay_ms(200);
printf("--STRAW BERRY");printf("\r\n");
}
////////////////////////////////////
if((a4==2)&&(b4==0)&& (c4==2)&&(d4==2))
{
integer_lcd1(a44);USART_Transmit((a44/10) + 0x30);USART_Transmit((a44%10) + 0x30);delay_ms(200);
printf("--CHOCOLATE");printf("\r\n");
integer_lcd1(c44);USART_Transmit((c44/10) + 0x30);USART_Transmit((c44%10) + 0x30);delay_ms(200);
printf("--BUTTER SCOTCH");printf("\r\n");
integer_lcd1(d44);USART_Transmit((d44/10) + 0x30);USART_Transmit((d44%10) + 0x30);delay_ms(200);
printf("--STRAW BERRY");printf("\r\n");
}
/////////////////////////////////////
if((a4==2)&&(b4==2)&& (c4==0)&&(d4==2))
{
integer_lcd1(a44);USART_Transmit((a44/10) + 0x30);USART_Transmit((a44%10) + 0x30);delay_ms(200);
printf("--CHOCOLATE");printf("\r\n");
integer_lcd1(b44);USART_Transmit((b44/10) + 0x30);USART_Transmit((b44%10) + 0x30);delay_ms(200);
printf("--VANNILA");printf("\r\n");  
integer_lcd1(d44);USART_Transmit((d44/10) + 0x30);USART_Transmit((d44%10) + 0x30);delay_ms(200);
printf("--STRAW BERRY");printf("\r\n");
}    
///////////////////////////////////////
if((a4==2)&&(b4==0)&& (c4==0)&&(d4==0))
{
integer_lcd1(a44);USART_Transmit((a44/10) + 0x30);USART_Transmit((a44%10) + 0x30);delay_ms(200);
printf("--CHOCOLATE");printf("\r\n");
}
///////////////////////////////////////////
if((a4==0)&&(b4==2)&& (c4==0)&&(d4==0))
{
integer_lcd1(b44);USART_Transmit((b44/10) + 0x30);USART_Transmit((b44%10) + 0x30);delay_ms(200);
printf("--VANNILA");printf("\r\n");  
}
//////////////////////////////////////////
if((a4==0)&&(b4==0)&& (c4==2)&&(d4==0))
{
integer_lcd1(c44);USART_Transmit((c44/10) + 0x30);USART_Transmit((c44%10) + 0x30);delay_ms(200);
printf("--BUTTER SCOTCH");printf("\r\n");
}
///////////////////////////////////////////
if((a4==0)&&(b4==0)&& (c4==0)&&(d4==2))
{
integer_lcd1(d44);USART_Transmit((d44/10) + 0x30);USART_Transmit((d44%10) + 0x30);delay_ms(200);
printf("--STRAW BERRY");printf("\r\n");
}
////////////////////////////////////////////////////
if((a4==2)&&(b4==2)&& (c4==0)&&(d4==0))
{
integer_lcd1(a44);USART_Transmit((a44/10) + 0x30);USART_Transmit((a44%10) + 0x30);delay_ms(200);
printf("--CHOCOLATE");printf("\r\n");
integer_lcd1(b44);USART_Transmit((b44/10) + 0x30);USART_Transmit((b44%10) + 0x30);delay_ms(200);
printf("--VANNILA");printf("\r\n");  
}
//////////////////////////////////
if((a4==2)&&(b4==0)&& (c4==2)&&(d4==0))
{
integer_lcd1(a44);USART_Transmit((a44/10) + 0x30);USART_Transmit((a44%10) + 0x30);delay_ms(200);
printf("--CHOCOLATE");printf("\r\n");
integer_lcd1(c44);USART_Transmit((c44/10) + 0x30);USART_Transmit((c44%10) + 0x30);delay_ms(200);
printf("--BUTTER SCOTCH");printf("\r\n");
}                                 
/////////////////////////////////////
if((a4==2)&&(b4==0)&& (c4==0)&&(d4==2))
{
integer_lcd1(a44);USART_Transmit((a44/10) + 0x30);USART_Transmit((a44%10) + 0x30);delay_ms(200);
printf("--CHOCOLATE");printf("\r\n");
integer_lcd1(d44);USART_Transmit((d44/10) + 0x30);USART_Transmit((d44%10) + 0x30);delay_ms(200);
printf("--STRAW BERRY");printf("\r\n");
}
//////////////////////////////////
if((a4==0)&&(b4==2)&& (c4==2)&&(d4==0))
{
integer_lcd1(b44);USART_Transmit((b44/10) + 0x30);USART_Transmit((b44%10) + 0x30);delay_ms(200);
printf("--VANNILA");printf("\r\n");  
integer_lcd1(c44);USART_Transmit((c44/10) + 0x30);USART_Transmit((c44%10) + 0x30);delay_ms(200);
printf("--BUTTER SCOTCH");printf("\r\n");
}                                 
/////////////////////////////////
if((a4==0)&&(b4==2)&& (c4==0)&&(d4==2))
{
integer_lcd1(b44);USART_Transmit((b44/10) + 0x30);USART_Transmit((b44%10) + 0x30);delay_ms(200);
printf("--VANNILA");printf("\r\n");  
integer_lcd1(d44);USART_Transmit((d44/10) + 0x30);USART_Transmit((d44%10) + 0x30);delay_ms(200);
printf("--STRAW BERRY");printf("\r\n");
}
if((a4==0)&&(b4==0)&& (c4==2)&&(d4==2))
{
integer_lcd1(c44);USART_Transmit((c44/10) + 0x30);USART_Transmit((c44%10) + 0x30);delay_ms(200);
printf("--BUTTER SCOTCH");printf("\r\n");
integer_lcd1(d44);USART_Transmit((d44/10) + 0x30);USART_Transmit((d44%10) + 0x30);delay_ms(200);
printf("--STRAW BERRY");printf("\r\n");
}   
bbbb=1;
clear();
delay_ms(1000); 
a1=a2=a3=a4=0;
b1=b2=b3=b4=0;
c1=c2=c3=c4=0;
d1=d2=d3=d4=0;
}
/////////
}
}
}