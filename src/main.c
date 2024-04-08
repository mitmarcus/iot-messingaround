#include "wifi.h"
#include <util/delay.h>
#include <stdlib.h>

int main()
{
  wifi_init();
  // TODO: We should find a way to abstract our credentials so we do not need to change them all the time.
  wifi_command_join_AP("CAPRI_SUN", "p455w0rd");                       // Wi-fi name, Password
  wifi_command_create_TCP_connection("192.168.137.1", 23, NULL, NULL); // Server IP, PORT, Callback, Buffer
  while (1)
  {
    wifi_command_TCP_transmit("Hello from Arduino from SEP\n", 28);
    _delay_ms(2000);
  }
}