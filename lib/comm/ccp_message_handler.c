#include "uart.h"
void ccp_message_handler_handle(char *message)
{
    uart_pc_send_string_blocking(message);
}