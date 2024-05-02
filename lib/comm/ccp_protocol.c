#include "ccp_protocol.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024 // Maximum expected message length (adjust if needed)

// char *ccp_create_request(char *at, char *body)
// {
//     int length_of_message = strlen(body);
//     char request[length_of_message];
//     strcpy(at, request);
//     strcat(LINE_TERMINATOR, request);
//     strcat((char *)length_of_message, request);
//     strcat(LINE_TERMINATOR, request);
//     strcat(body, request);
//     strcat(LINE_TERMINATOR, request);
//     return request;
// }

// TODO: Check if struct is not better? Do TESTs
char *ccp_parse_response(char *response, char *status_buffer, int status_buffer_size)
{
    if (response == NULL)
        return NULL;

    char *response_parts[4]; // Array to store message parts (actionType, Response Code, Body length, Body)
    int num_parts = 0;
    char *token = strtok(response, LINE_TERMINATOR);

    while (token != NULL && num_parts < 4)
    {
        response_parts[num_parts++] = token;
        token = strtok(NULL, LINE_TERMINATOR);
    }

    char *actionType = response_parts[0];
    char *status = response_parts[1];
    int body_length = atoi(response_parts[2]);

    char *body = NULL;
    if (body_length > 0)
        body = response_parts[3];

    if (status_buffer != NULL && status_buffer_size > strlen(status))
    {
        strncpy(status_buffer, status, status_buffer_size - 1);
        status_buffer[status_buffer_size - 1] = '\0';
    }

    return body;
}