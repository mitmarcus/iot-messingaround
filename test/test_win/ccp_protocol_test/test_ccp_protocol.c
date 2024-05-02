#include <unity.h>
#include <ccp_protocol.h>
#include <stdio.h>
void ccp_test_build_request_without_body()
{
    char buffer[100];
    ccp_create_request("TM", "", buffer);
    TEST_ASSERT_EQUAL_STRING("TM\r\n0\r\n\r\n", buffer);
}

void ccp_test_build_request_with_body()
{
    char buffer[100];
    ccp_create_request("MS", "Hello, World!", buffer);
    TEST_ASSERT_EQUAL_STRING("MS\r\n13\r\nHello, World!\r\n", buffer);
}

void ccp_test_build_response_without_body()
{
    char buffer[100];
    ccp_create_response(buffer, "TM", CCP_OK, "");
    TEST_ASSERT_EQUAL_STRING("TM\r\n1\r\n0\r\n\r\n", buffer);
}

void ccp_test_build_response_with_body()
{
    char buffer[100];
    ccp_create_response(buffer, "MS", CCP_SERVER_ERROR, "Internal Server Error");
    TEST_ASSERT_EQUAL_STRING("MS\r\n2\r\n21\r\nInternal Server Error\r\n", buffer);
}

