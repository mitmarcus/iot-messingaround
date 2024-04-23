#ifndef WINDOWS_TEST

#include "includes.h"
#include "timer.h"

Timer_Callback_t timer_callback_3;


void timer3_init(uint16_t frequency, Timer_Callback_t callback)
{
    timer_callback_3 = callback;         // Set the callback function
    TCCR3B |= (1 << WGM32);              // Set CTC mode
    OCR3A = frequency;                     // Set the compare value for 1 Hz at 16 MHz
    TIMSK3 |= (1 << OCIE3A);             // Enable compare match interrupt
    sei();                               // Enable global interrupts
    TCCR3B |= (1 << CS32) | (1 << CS30); // Start timer with prescaler 1024
}

void timer_3_stop()
{
    TCCR3B &= ~((1 << CS32) | (1 << CS31) | (1 << CS30)); // Stop the timer
}

/*
* @brief Initialize the timer with the given frequency and callback function.
*/
void timer_init(TIMER_t timer, Timer_Callback_t callback, uint16_t frequency){
    switch (timer)
    {
    case TIMER_3:
        timer3_init(frequency, callback);
        break;
    default:
        break;
    }
}


void timer_stop(TIMER_t timer){
    switch (timer)
    {
    case TIMER_3:
        timer_3_stop();
        break;
    default:
        break;
    }
}


ISR(TIMER3_COMPA_vect)
{
    if (timer_callback_3 != NULL)
    {
        timer_callback_3();
    }
}

#endif