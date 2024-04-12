#pragma once
#include <stdint.h>
#include <timer.h>
#include "uart.h"

/**
 * @brief Type definition for timer callback.
 * This is a type for a method that will be executed as callback when the timer interrupt is triggered.
 * 
 */
typedef void (*Timer_Callback_t)();

// enum for different timers
typedef enum {
    TIMER_3    
} TIMER_t;

void timer_init(TIMER_t timer, Timer_Callback_t callback, uint16_t frequency);

void timer_stop(TIMER_t timer);