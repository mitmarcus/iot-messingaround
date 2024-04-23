#pragma once

#include <stdint.h>        // For standard integer types
#include "periodic_task.h" // For the periodic task functions

// Function to initialize the clock and periodic task
void clock_init(void);

// Function to update the time by one minute and refresh the display
void clock_update_time(void);

// Function to display the current time in HH:MM format
void clock_display_time(void);