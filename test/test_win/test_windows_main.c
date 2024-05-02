#include "wifi_connect_state_test/test_wifi_connect_state.h"
#include "unity.h"


int main(void)
{
  UNITY_BEGIN();
  RUN_TEST(starting_with_specified_credentials_finishes_the_state);
  RUN_TEST(starting_with_null_credentials_finishes_the_state_if_is_already_connected_to_wifi);
  return UNITY_END();
}

void tearDown(void)
{
  // clean stuff up here
}

void setUp(void)
{
}
