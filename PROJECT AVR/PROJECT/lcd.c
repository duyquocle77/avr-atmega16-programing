/*****************************************************
This program was produced by the
CodeWizardAVR V2.05.0 Professional
Automatic Program Generator
� Copyright 1998-2010 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 28/12/2020
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
#include <delay.h>
// Alphanumeric LCD Module functions
#include <alcd.h>

// Declare your global variables here

void main(void)
{
// Declare your local variables here

// Input/Output Ports initialization
// Port A initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=P State6=P State5=P State4=P State3=P State2=P State1=P State0=P 
PORTA=0xFF;
DDRA=0x00;

// Port B initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTB=0x00;
DDRB=0x00;

// Port C initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTC=0x00;
DDRC=0x00;

// Port D initialization
// Func7=Out Func6=Out Func5=Out Func4=Out Func3=Out Func2=Out Func1=Out Func0=Out 
// State7=0 State6=0 State5=0 State4=0 State3=0 State2=0 State1=0 State0=0 
PORTD=0x00;
DDRD=0xFF;

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: Timer 0 Stopped
// Mode: Normal top=0xFF
// OC0 output: Disconnected
TCCR0=0x00;
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
TCCR2=0x00;
TCNT2=0x00;
OCR2=0x00;

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// INT2: Off
MCUCR=0x00;
MCUCSR=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=0x00;

// USART initialization
// USART disabled
UCSRB=0x00;

// Analog Comparator initialization
// Analog Comparator: Off
// Analog Comparator Input Capture by Timer/Counter 1: Off
ACSR=0x80;
SFIOR=0x00;

// ADC initialization
// ADC disabled
ADCSRA=0x00;

// SPI initialization
// SPI disabled
SPCR=0x00;

// TWI initialization
// TWI disabled
TWCR=0x00;

// Alphanumeric LCD initialization
// Connections specified in the
// Project|Configure|C Compiler|Libraries|Alphanumeric LCD menu:
// RS - PORTB Bit 0
// RD - PORTB Bit 1
// EN - PORTB Bit 2
// D4 - PORTB Bit 4
// D5 - PORTB Bit 5
// D6 - PORTB Bit 6
// D7 - PORTB Bit 7
// Characters/line: 16
lcd_init(16);

lcd_gotoxy(5,0);
lcd_puts("WELCOME");
lcd_gotoxy(6,1);
lcd_puts("TO AVR");
delay_ms(200); 
lcd_clear();
lcd_gotoxy(5,0);
lcd_puts("STARTING");
lcd_gotoxy(6,1);
lcd_puts("SYSTEM");
delay_ms(200); 
while (1)
      {
      if (PINA.0==0) {     
      if (PINA.7==0) {    
       PORTD.0=1;
       delay_ms(50);          
       lcd_clear();         
       lcd_gotoxy(3,1);        
       lcd_puts("Starting...."); 
       delay_ms(100);
       }
      else  {         
       PORTD.0=0;       
       lcd_clear();    
       };  
      PORTD.1=1;
      lcd_clear();
      lcd_gotoxy(8,0);
      lcd_putchar('P');
      lcd_gotoxy(4,1);
      lcd_puts("Ready !!!");
      delay_ms(100); 
      }
      else  {
      PORTD.0=0;
      PORTD.1=0;
      lcd_clear();    
      };
      
      if (PINA.1==0) {
      if (PINA.7==0) {
      lcd_clear();
      lcd_gotoxy(3,0);
      lcd_puts("WARNING!!!");  
      lcd_gotoxy(2,1);
      lcd_puts("Not allowed"); 
      delay_ms(100);
      } 
      else  { 
      lcd_clear();  
      }; 
      PORTD.2=1;
      lcd_clear();
      lcd_gotoxy(8,0);
      lcd_putchar('R');
      delay_ms(50); 
      }
      else  {       
      PORTD.2=0;
      lcd_clear();    
      };

      if (PINA.2==0) { 
       if (PINA.7==0) {
      PORTD.0=1;
      delay_ms(50);
      lcd_clear();
      lcd_gotoxy(3,1);
      lcd_puts("Starting....");  
      delay_ms(100);
      }
       else  { 
      PORTD.0=0;
      lcd_clear();   
      };    
      PORTD.3=1;
      lcd_clear();
      lcd_gotoxy(8,0);
      lcd_putchar('N');
      lcd_gotoxy(4,1);
      lcd_puts("Ready !!!");
      delay_ms(100);
      }
      else  {   
      PORTD.0=0;
      PORTD.3=0;
      lcd_clear();    
      }; 
      
      if (PINA.3==0) {
      if (PINA.7==0) {
      lcd_clear();
      lcd_gotoxy(3,0);
      lcd_puts("WARNING!!!");  
      lcd_gotoxy(2,1);
      lcd_puts("Not allowed");
      delay_ms(500);
      }
      else  { 
      lcd_clear();  
      };
      PORTD.4=1;
      lcd_clear();
      lcd_gotoxy(8,0);
      lcd_putchar('1');
      delay_ms(100); 
      }
      else  {
      PORTD.4=0;
      lcd_clear();    
      };
      
      if (PINA.4==0) {
      if (PINA.7==0) {
      lcd_clear();
      lcd_gotoxy(3,0);
      lcd_puts("WARNING!!!");  
      lcd_gotoxy(2,1);
      lcd_puts("Not allowed");  
      delay_ms(500);
      }
      else  { 
      lcd_clear();  
      };  
      PORTD.5=1;
      lcd_clear();
      lcd_gotoxy(8,0);
      lcd_putchar('D');
      delay_ms(100); 
      }
      else  { 
      PORTD.5=0;
      lcd_clear();    
      };
      }
}
