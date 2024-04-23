#include "periodic_task.h" // Include the periodic task header
#include "display.h"       // Include the display header

static uint8_t current_hour = 10;   // Current hour (0-23)
static uint8_t current_minute = 10; // Current minute (0-59)

void clock_display_time()
{
    uint8_t seg1 = current_hour / 10;   // First digit of the hour
    uint8_t seg2 = current_hour % 10;   // Second digit of the hour
    uint8_t seg3 = current_minute / 10; // First digit of the minute
    uint8_t seg4 = current_minute % 10; // Second digit of the minute

    display_setValues(seg1, seg2, seg3, seg4); // Display the values
}

void clock_update_time()
{
    current_minute++; // Increment the minute

    if (current_minute == 60)
    { // Roll over when minute reaches 60
        current_minute = 0;
        current_hour++; // Increment the hour

        if (current_hour == 24)
        { // Roll over when hour reaches 24
            current_hour = 0;
        }
    }

    clock_display_time(); // Update the display
}

void clock_init()
{
    periodic_task_init_c(clock_update_time, 60000); // Set to call `update_time` every minute (60000 ms)
}
