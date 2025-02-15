/*****************************************************
This program was produced by the
CodeWizardAVR V2.05.0 Professional
Automatic Program Generator
� Copyright 1998-2010 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 18/05/2022
Author  : NeVaDa
Company : 
Comments: 


Chip type               : ATmega16
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 256
*****************************************************/

#include <mega16.h>
#include <stdio.h>
#include <stdlib.h>
#include <delay.h>

#define DK1 PORTA.0
#define DK2 PORTA.1
#define DK3 PORTA.2
#define DK4 PORTA.3
#define LED PORTB

#define sbi(port, bit) {(port) |= (bit);}
#define cbi(port, bit) {(port) &= ~(bit);}
#define tbi(port, bit) {(port) ^= (bit);}

const unsigned char num[17] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E, 0xBF};

void seg2digit(unsigned char x)
{
unsigned char temp, a, b;
temp = x;
b = temp % 10;
a = temp / 10;

DK1 = 0;
LED = num[a];
delay_ms(5);
DK1 = 1; 
        
DK2 = 0;
LED = num[b];
delay_ms(5);
DK2 = 1;   
}

void seg4digit(unsigned long x)
{
unsigned long temp;
unsigned char a, b, c, d;
temp = x;
d = temp % 10;
temp = temp / 10;
c = temp % 10;
temp = temp / 10;
b= temp % 10;
a = temp / 10;

DK1 = 0;
LED = num[a];
delay_ms(5);
DK1 = 1; 
        
DK2 = 0;
LED = num[b];
delay_ms(5);
DK2 = 1;   

DK3 = 0;
LED = num[c];
delay_ms(5);
DK3 = 1; 
        
DK4 = 0;
LED = num[d];
delay_ms(5);
DK4 = 1;   
}

void main(void)
{
unsigned char i, y;
unsigned long x;

PORTA=0xFF;
DDRA=0xFF;


PORTB=0xFF;
DDRB=0xFF;


PORTC=0x00;
DDRC=0x01;


PORTD=0x00;
DDRD=0x00;
x = 990;
y = 0;
i = 0;
while (1)   
      {     
             seg2digit(y);
             i++;
             if(i > 100) //100*(5+5)=1000ms=1s
             {             
             if(y < 60)
             {
             y++;
             
             }
             else
             {
             y = 0;
             }  
             i = 0;
             } 
             if(y%10==0)
             {            
             PORTC=0x01;
             delay_ms(1000);
             PORTC=0x00;
             }
      }
}
