#include "wifi_connect_state_test/test_wifi_connect_state.h"
#include "ccp_protocol_test/test_ccp_protocol.h"
#include "unity.h"

int main(void)
{
  UNITY_BEGIN();
  RUN_TEST(starting_with_specified_credentials_finishes_the_state);
  RUN_TEST(starting_with_null_credentials_finishes_the_state_if_is_already_connected_to_wifi);
  RUN_TEST(ccp_test_build_request_without_body);
  RUN_TEST(ccp_test_build_request_with_body);
  RUN_TEST(ccp_test_build_response_without_body);
  RUN_TEST(ccp_test_build_response_with_body);
  RUN_TEST(ccp_test_at_from_str);
  RUN_TEST(ccp_test_at_from_str2);

  return UNITY_END();
}

void tearDown(void)
{
  // clean stuff up here
}

void setUp(void)
{
}
