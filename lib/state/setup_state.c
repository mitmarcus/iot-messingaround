#include "setup_state.h"
#include "wifi.h"
#include <stdlib.h>
#include <stdint.h>
#include <timer.h>
#include <string.h>

static uint8_t *recieveBuffer;
static uint8_t recieveBufferIndex;

// calback when the server is up for receiving data from the client
void receive_data_callback(uint8_t byte)
{
    recieveBuffer[recieveBufferIndex++] = byte;
}

void clear_buffer()
{
    memset(recieveBuffer, 0, 128);
    recieveBufferIndex = 0;
}


// Callback that is triggered by the timer. It checks the buffer for ssid and pass and then sends the command to connect to the AP
void wifi_change_server_callback()
{
    char *ssidIndex = strstr((char *)recieveBuffer, "ssid:");
    char *passIndex = strstr((char *)recieveBuffer, "pass:");

    if (ssidIndex != NULL && passIndex != NULL)
    {
        timer_stop(TIMER_3);
        int ssidLength = ssidIndex[5] - '0'; // Length of ssid
        int passLength = passIndex[5] - '0'; // Length of pass

        char *ssidStart = &ssidIndex[6];
        char *passStart = &passIndex[6];
        char *ssidEnd = &ssidIndex[6 + ssidLength];
        char *passEnd = &passIndex[6 + passLength];

        char *ssid = (char *)calloc(1, ssidEnd - ssidStart + 1);
        char *pass = (char *)calloc(1, passEnd - passStart + 1);

        memcpy(ssid, ssidStart, ssidEnd - ssidStart);
        memcpy(pass, passStart, passEnd - passStart);

        wifi_command_join_AP(ssid, pass);
    }
    clear_buffer();
}

void setup_state_init(char *ssid, char *pass)
{
    wifi_init(NULL);
    wifi_command_reset();
    _delay_ms(5000);
    wifi_command_set_mode_to_1();
    // If ssid and pass is not NULL, then the device should connect to the wifi
    if (ssid != NULL && pass != NULL)
    {
        wifi_command_join_AP(ssid, pass);
    }
    else
    {
        // Check if the device is already connected to the AP
        if (wifi_command_check_AP_connection() == CONNECTED)
        {
            uart_pc_send_string_blocking("Connected to AP\n");
        }
        // If not connected to an AP, start a server and wait for ssid and pass
        else
        {
            //This part in not completely finished but it works more or less.
            wifi_init(receive_data_callback);
            wifi_command_set_mode_to_2();
            wifi_command_setup_AP("SEP4-SmartClock", "MHDK2024");
            wifi_command_enable_multiple_connections();
            recieveBuffer = (uint8_t *)malloc(128);
            recieveBufferIndex = 0;
            wifi_command_setup_server(80, receive_data_callback);
            timer_init(TIMER_3, wifi_change_server_callback, 15624);
        }
    }
}
