#include <uart.h>
#include <connect_wifi_state.h>
#include <stddef.h>
#include <wifi.h>
#include <state_coordinator.h>
int main()
{

  uart_pc_init(9600, NULL);
  start();

  while (1)
  {
  }
}