#include "uart.h"
#include "ccp_protocol.h"
#include "buzzer.h"
#include <stdlib.h>
#include <string.h>
#include "logger.h"
#include "wifi.h"

void ccp_handle_time_at(char *message);
void ccp_handle_message_at(char *message);

void ccp_message_handler_handle(char *message)
{
    CCP_ACTION_TYPE at = ccp_at_from_str(message);
    log_info("recived message:");
    log_info(message);

    switch (at)
    {
    case CCP_AT_TM:
        /* code */
        break;
    case CCP_AT_MS:
        ccp_handle_message_at(message);
    default:
        break;
    }
}

void ccp_handle_time_at(char *message)
{
    // extract data from message
    // set time
}

void ccp_handle_message_at(char *message)
{
    buzzer_beep();
    // extract data from message
    // display_message
    char response[30];
    ccp_create_response(response, CCP_AT_MS, CCP_STATUS_OK, "Message received");
    uint8_t response_data[30];
    memcpy(response_data, response, strlen(response));
    wifi_command_TCP_transmit(response_data, 30);
}
