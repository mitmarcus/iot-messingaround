#include <string.h>
#include <stdio.h>
#include <unity.h>
#include <unity_internals.h>
#include <stdlib.h>
#include "connect_wifi_state.h"
#include "../../fff.h"
#include <wifi.h>
#include <periodic_task.h>
#include <state_coordinator.h>
#include <uart.h>

FAKE_VALUE_FUNC0(WIFI_ERROR_MESSAGE_t, wifi_command_set_mode_to_1);
FAKE_VALUE_FUNC0(WIFI_ERROR_MESSAGE_t, wifi_command_set_mode_to_2);
FAKE_VALUE_FUNC0( WIFI_ERROR_MESSAGE_t, wifi_command_set_mode_to_3);
FAKE_VALUE_FUNC2(WIFI_ERROR_MESSAGE_t, wifi_command_join_AP, char *, char *);
FAKE_VALUE_FUNC2(WIFI_ERROR_MESSAGE_t, wifi_command_setup_AP, char *, char *);
FAKE_VALUE_FUNC0(WIFI_ERROR_MESSAGE_t, wifi_command_enable_multiple_connections);
FAKE_VALUE_FUNC0(WIFI_ERROR_MESSAGE_t, wifi_command_reset);
FAKE_VALUE_FUNC2(WIFI_ERROR_MESSAGE_t, wifi_command_setup_server, uint16_t, UART_Callback_t);
FAKE_VOID_FUNC1(wifi_init, UART_Callback_t);
FAKE_VALUE_FUNC0(WIFI_AP_CONNECTION, wifi_command_check_AP_connection);

FAKE_VOID_FUNC(uart_pc_send_string_blocking, char *);
FAKE_VOID_FUNC2(uart_pc_init, uint32_t, UART_Callback_t);

FAKE_VOID_FUNC(periodic_task_init_a, PERIODIC_TASK_CALLBACK, uint32_t);

void starting_with_specified_credentials_finishes_the_state()
{
  wifi_command_check_AP_connection_fake.return_val = CONNECTED;
  State state = connect_wifi_state_switch("ssid", "pass");
  TEST_ASSERT_EQUAL(SERVER_CONNECT_STATE, state);
  RESET_FAKE(wifi_command_check_AP_connection);
}

void starting_with_null_credentials_finishes_the_state_if_is_already_connected_to_wifi()
{
  wifi_command_check_AP_connection_fake.return_val = CONNECTED;
  State state = connect_wifi_state_switch(NULL, NULL);
  TEST_ASSERT_EQUAL(SERVER_CONNECT_STATE, state);
  RESET_FAKE(wifi_command_check_AP_connection);
}
