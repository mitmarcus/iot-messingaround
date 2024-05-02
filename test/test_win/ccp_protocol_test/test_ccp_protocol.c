
#include <unity.h>

void cpp_test_build_request()
{
}

void cpp_test_build_response()
{
    char response[] = "MS\r\n1\r\n10\r\nHello\nWorld\r\n";
    char status_buffer[10];
    int status_buffer_size = sizeof(status_buffer);

    char *data = ccp_parse_response(response, status_buffer, status_buffer_size);

    if (data == NULL)
    {
        printf("Error\n");
    }
    else
    {
        printf("Status code: %s\n", status_buffer);
        printf("Body: %s\n", data);
    }
}
