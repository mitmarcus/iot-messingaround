#include <uart.h>
#include <connect_wifi_state.h>
#include <stddef.h>
#include <wifi.h>
#include <state_coordinator.h>
#include <display.h>
#include <clock.h>
int main()
{

  uart_pc_init(9600, NULL);
  display_init();
  clock_init();
  start();

  while (1)
  {
  }
}