#include "wifi.h"
#include <util/delay.h>
#include <stdlib.h>
#include <timer.h>

void sendHello(){
  uart_pc_send_string_blocking("Hello\n");
}

int main()
{
  uart_pc_init(9600, NULL);
  timer_init(TIMER_3, sendHello, 15624);
  uart_pc_send_string_blocking("Starting\n");

  while (1)
  {
    /* code */
  }
  
}