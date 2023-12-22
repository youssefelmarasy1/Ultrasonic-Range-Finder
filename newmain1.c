/* 
 * File:   newmain.c
 * Author: youss
 *
 * Created on October 30, 2022, 3:15 AM
 */

//#define F_CPU 14745600UL //change this to the crystal's frequency
#include <stdio.h>
#include <stdlib.h>
#include "defines.h"
#include "hd44780.h"
#include "lcd.h"
#include <avr/io.h>
#include <util/delay.h>

FUSES = {
	.low = 0xFF, // LOW {SUT_CKSEL=EXTXOSC_8MHZ_XX_16KCK_14CK_65MS, CKOUT=CLEAR, CKDIV8=CLEAR}
	.high = 0xD9, // HIGH {BOOTRST=CLEAR, BOOTSZ=2048W_3800, EESAVE=CLEAR, WDTON=CLEAR, SPIEN=SET, DWEN=CLEAR, RSTDISBL=CLEAR}
	.extended = 0xFF, // EXTENDED {BODLEVEL=DISABLED}
};

LOCKBITS = 0xFF; // {LB=NO_LOCK, BLB0=NO_LOCK, BLB1=NO_LOCK}
/*
 * 
 */
FILE lcd_str = FDEV_SETUP_STREAM ( lcd_putchar , NULL , _FDEV_SETUP_WRITE); // to create global variable for LCD stream

int main() {
    lcd_init(); //initializing the lcd
    
    
    //Variable declarations 
    uint16_t t0,t1; //t0 for rising edge, and t1 for falling edge
    double period_counts;
    double  time, distance;
    double max , min;
    
    DDRB &= ~(1 << PB0); //ensuring PB0 is an input (Echo)
    DDRB &= ~(1 << PB2); //ensuring PB2 is an input (Pushbutton)
    PORTB |= (1 << PB2); //enabling the pull up for the pushbutton pin
    
    DDRB |= (1 << PB1); //ensuring PB1 is an output (Trigger)
    TCCR1B |= ( 1 << CS10); //starting the clock counter
    
    while(1) {
 
    //This is our 10us trigger 
    PORTB |= (1 << PB1);
    _delay_us(10); 
    PORTB &= ~(1 << PB1);
    
    /*FOR DETECTING THE FIRST EVENT ----> RISING EDGE*/
    TCCR1B |= ( 1 << ICES1); //Configuration for capturing at rising edge
    TCCR1B &= ~(1 << ICNC1); //Turning off the noise canceler   
    TIFR1 |= (1 << ICF1); //Clearing the ICF1 flag just to be safe 
    while (!(TIFR1 & (1 << ICF1))); //Waiting for the first event to happen (the rising edge here)
    t0 = ICR1; //Capturing the time at which the rising edge happened
    
    
    TIFR1 |= (1 << ICF1); //Clearing the ICF1 flag so that we'll be able to detect the second event (falling edge)
    
    
    /*FOR DETECTING THE SECOND EVENT ----> FALLING EDGE*/
    TCCR1B &= ~( 1 << ICES1); //Configuration for capturing at falling edge
    while (!(TIFR1 & (1 << ICF1))); //Waiting for the second event to happen (the falling edge here)
    t1 = ICR1; //Capturing the time at which the falling edge happened
    TIFR1 |= (1 << ICF1); //Clearing the ICF1 flag so that we'll be able to detect the second event (falling edge)
    
    
    if (t1 < t0){
        period_counts = (65536 +t1) - t0;
    
    }//second curly brace for the if statement
    else {
        period_counts = t1-t0;
    
    }//second curly brace for the else statement
    
    
    /*Calculation of the time and distance for the ultrasonic wave to go to the object and back*/
    time = (period_counts/14745600); //(period counts)/clock frequency 
    distance = (time*34300)/2;
    
    //Printing the new min and max values when the push button is pressed
    
    if(!(PINB & (1 << PB2))){ //if the push button is pressed
         if(max == 0 && min == 0){ //if the maximum and minimum values are 0 as initialized, update the values to the current distance
        max = distance;
        min = distance;
    }
    if(distance > max && distance <= 70 && distance  >= 3){ // Determining and checking the maximum value as compared to our current distance when the push button is pressed
        max = distance; 
    }
    if(distance < min && distance <= 70 && distance >= 3){ // Determining and checking the minimum value as compared to our current distance when the push button is pressed
        min = distance;
    }
    }
    
    
    if(distance > 70 || distance < 3){ // checks if the distance is out of range and notifies user
        fprintf(&lcd_str, "\x1b\x01");
        fprintf(&lcd_str, "  Out of Range");
    }
    /*printing the distance, maximum, and minimum values and clearing the lcd after that*/
    fprintf(&lcd_str, "     %0.1f cm     ", distance); //printing the distance
    fprintf(&lcd_str, "\x1B\xC0max%0.1f min%0.1f ", max,min); //print the max and minimum values
    _delay_ms(100); //this delay significantly reduces the flickering on the lcd
    fprintf(&lcd_str, "\x1b\x01");// clearing the lcd 
    
   
    }//second curly brace for the big while loop
    
    
    
    
    return (EXIT_SUCCESS);
}





