#include <uart.h>
#include <connect_wifi_state.h>
#include <stddef.h>
#include <wifi.h>
#include <state_coordinator.h>
#include <display.h>
#include <clock.h>
#include <util/delay.h>

int main()
{

  uart_pc_init(9600, NULL);
  display_init();
  clock_init();
  wifi_init(NULL);
  wifi_command_reset(); //reset the module. Because sometimes it just makes it work -_('o')_-  Software development at its best.
  _delay_ms(5000);
  start();

  while (1)
  {
  }
}