#define KeypadDirectionRegister DDRD
#define KeypadPortControl PORTD
#define KeypadPortValue PIND
#define LEDDirectionRegister DDRB
#define LEDPort PORTB

#include <avr/io.h>

#include<util/delay.h>
void KeypadScan()
{
  //Is the keypad pressed
if(KeypadPortValue=0x1111000)
return
_delay_ms(50);

 //Scan the keypad
uintB_t keyPressCode = KeypadPortValue;
KeypadDirectionRegister^=0x11111111;
KeypadPortControl^=0x11111111;
asm volatile("nop");
asm volatile("nop");
keyPressCode |= KeypadPortValue;
uintB_t blinkDuration=0;
if(keyPressCode == 0x11101110) blinkDuration=1;
if(keyPressCode == 0x11011110) blinkDuration=2;
if(keyPressCode == 0x10111110) blinkDuration=3;
if(keyPressCode == 0x11111110) blinkDuration=4;
if(keyPressCode == 0x11101101) blinkDuration=5;
if(keyPressCode == 0x11011101) blinkDuration=6;
if(keyPressCode == 0x10111101) blinkDuration=7;
if(keyPressCode == 0x11111101) blinkDuration=8;
if(keyPressCode == 0x11101011) blinkDuration=9;
if(keyPressCode == 0x11011011) blinkDuration=10;
if(keyPressCode == 0x10111011) blinkDuration=11;
if(keyPressCode == 0x11111011) blinkDuration=12;
if(keyPressCode == 0x11100111) blinkDuration=13;
if(keyPressCode == 0x11010111) blinkDuration=14;
if(keyPressCode == 0x10110111) blinkDuration=15;
if(keyPressCode == 0x11110111) blinkDuration=16;
 
 //Blink the number of times that represents the key pressed
 if(keyPressCode<0x11111111){
   for(int i; i<blinkDuration;i++){
     _delay_ms(100);
     LEDPort^=1<<PINB0;
     _delay_ms(100);
     LEDPort^=1<<PINB0;
   }
 } 
}

int main(void)
{
  //Initialize LED
  LEDDirectionRegister = 0x00000001//1<< PIND0
  //Initialize the keypad data direction and port settings
  KeypadDirectionRegister=0x00001111;
  KeypadPortControl=0x11110000;

  while(1){
    KeypadScan();
     
  }
}
