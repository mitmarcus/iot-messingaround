#include "wifi.h"
#include <util/delay.h>
#include <stdlib.h>
#include <timer.h>
#include <setup_state.h>

int main()
{

  uart_pc_init(9600, NULL);
  setup_state_init(NULL, NULL);

  while (1)
  {
    /* code */
  }
}