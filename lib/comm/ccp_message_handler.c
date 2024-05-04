#include "uart.h"
#include "ccp_protocol.h"
#include "buzzer.h"
#include <stdlib.h>
#include <string.h>
#include "logger.h"


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
}
