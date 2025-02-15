/*****************************************************
This program was produced by the
CodeWizardAVR V2.05.0 Professional
Automatic Program Generator
� Copyright 1998-2010 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 26/05/2022
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


// Alphanumeric LCD Module functions
#include <alcd.h>
#include <stdlib.h>

#define LED PORTA.0 

// Declare your global variables here
unsigned int xung = 0;
void hienthilcd_1(unsigned char x, unsigned y)
{
    char *buffer;
    xung *= 10;
    itoa(xung, buffer);
    lcd_gotoxy(x, y);
    lcd_puts(buffer); 
}
 void hienthilcd_2(unsigned char x, unsigned y)
{
lcd_gotoxy(x ,y);
/*lcd_putchar(xung/10000000 +48);
lcd_putchar(xung/1000000%10 +48);
lcd_putchar(xung/100000%10 +48); */
lcd_putchar(xung/10000 +48);
lcd_putchar(xung/1000%10 +48);
lcd_putchar(xung/100%10 +48);
lcd_putchar(xung/10%10 +48);
lcd_putchar(xung%10 +48);
}

void main(void)
{
DDRA=(1<<DDA0);
PORTA=0x00;

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: 1000.000 kHz
// Mode: Normal top=0xFF
// OC0 output: Disconnected
TCCR0=(1<<CS02)|(1<<CS01)|(1<<CS00);
TCNT0=0x00;
OCR0=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer1 Stopped
// Mode: Normal top=0xFFFF
// OC1A output: Discon.
// OC1B output: Discon.
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=0x00;
TCCR1B=0x00;
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: Timer2 Stopped
// Mode: Normal top=0xFF
// OC2 output: Disconnected
ASSR=0x00;
TCCR2=0x07;
TCNT2=0x00;
OCR2=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=0x00;

// Alphanumeric LCD initialization
// Connections specified in the
// Project|Configure|C Compiler|Libraries|Alphanumeric LCD menu:
// RS - PORTD Bit 0
// RD - PORTD Bit 1
// EN - PORTD Bit 2
// D4 - PORTD Bit 4
// D5 - PORTD Bit 5
// D6 - PORTD Bit 6
// D7 - PORTD Bit 7
// Characters/line: 8
lcd_init(16);

while (1)
      {
       while(TCNT2 < 97);  
      //xung *= 10;      
      xung = (unsigned int) TCNT0;        
      LED = ~LED;
      hienthilcd_1(0,0); 
      hienthilcd_2(0,1);
      TCNT0 = 0;
      TCNT2 = 0;
      xung = 0;
      

      }
}
