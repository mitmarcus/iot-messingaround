#include <working_state.h>
#include <state_coordinator.h>
#include <wifi.h>
#include "ccp_message_handler.h"
#include "uart.h"
#include "logger.h"

static char message_buffer[128];

void tcp_callback()
{
    ccp_message_handler_handle(message_buffer);
}

State working_state_switch(char* ip, int port)
{
    log_info("Entered working state");
    //I was not able to find any other way to change the tcp_callback, despite it only means reassign a single variable in wifi.c
    //This is a workaround, the module tries to connect to the server it is already connected as a result nothing really happens. However, the callback and buffer are changed.
    //However it takes 10 seconds
    wifi_command_create_TCP_connection(ip, port, tcp_callback, message_buffer);

    while (1)
    {
        /* code */
    }

    return WORKING_STATE;
}
