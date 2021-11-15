//#include <main.h>
#include <LCD.h>
#include <lcd.c>
#use i2c(MASTER, SDA = PIN_C4, SCL = PIN_C3)
#include "ds1307.c"
#include <stdio.h>
#include <string.h> 
#define Slave_add 0x68
#define Read 1
#define Write 0
int8 sec,min,hrs,day,month,yr,dow;
char RF_ID[13];
//char c;
char valid[13]="AB123456789A";
//char unvalid[13]="BC123456789A";
//char tid[13]="AB123456789A";

void lcd_puts (char *s)
{
   while (*s)
   {
      lcd_putc(*s);
      s++;
   }
}

void main()
{
   //char lcd[16];
   //int count=0;
   lcd_init();
   delay_ms(10);
   ds1307_init();
   lcd_putc("Bonjour!!");
   delay_ms(10);
   setup_uart(9600);
   delay_ms(1000);
   // Set date : 15-11-2021
   // Set time : thu 2 - 15 gio, 35 phut 10 giay
   //ds1307_set_date_time(15,11,21,2,15,35,10);
   
   ds1307_get_date(day,month,yr,dow); 
   delay_ms(100);
   //ds1307_get_time(hrs,min,sec);
   lcd_gotoxy(1,2);
   lcd_putc(day/10+48);
   lcd_putc(day%10+48);
   lcd_putc(45);
   lcd_putc(month/10+48);
   lcd_putc(month%10+48);
   lcd_putc(45);
   lcd_putc(yr/10+48);
   lcd_putc(yr%10+48);
   delay_ms(1000);
   while(TRUE)
   {
      lcd_gotoxy(1,1);
      lcd_putc("Insert your card");
      delay_ms(500);
      gets(RF_ID);
      lcd_puts(RF_ID);
      if(strcmp(valid, RF_ID)==0)
      {
         //if (c=='A')
         //{
         lcd_putc("\f");
         lcd_gotoxy(1,1);
         lcd_putc("Nguyen Tin");
         ds1307_get_time(hrs,min,sec);
         delay_ms(100);
         lcd_gotoxy(1,2);
         lcd_putc(hrs/10+48);
         lcd_putc(hrs%10+48);
         lcd_putc(45);
         lcd_putc(min/10+48);
         lcd_putc(min%10+48);
         lcd_putc(45);
         lcd_putc(sec/10+48);
         lcd_putc(sec%10+48);
         output_high(PIN_D1);
         output_high(PIN_D2);
         output_high(PIN_D3);
         delay_ms(1000);
         output_low(PIN_D1);
         output_low(PIN_D2);
         delay_ms(3000);
         output_low(PIN_D3);
         //}
      }
      else
      {
         lcd_putc("\f");
         lcd_gotoxy(1,1);
         lcd_putc("Invalid card!");
         output_high(PIN_D0);
         output_high(PIN_D2);
         delay_ms(2000);
         output_low(PIN_D0);
         output_low(PIN_D2);
      }
      lcd_putc("\f");
      //}
   }

}

