#include "ccp_protocol.h"
#include <string.h>
#include <stdio.h>

const char *status_code_to_string(CCP_STATUS_CODE code);

const char *LINE_TERMINATOR = "\r\n";

void ccp_create_request(char *at, char *body, char *request)
{
    int length_of_message = strlen(body);
    char length_string[10];
    sprintf(length_string, "%d", length_of_message);
    strcpy(request, at);
    strcat(request, LINE_TERMINATOR);
    strcat(request, length_string);
    strcat(request, LINE_TERMINATOR);
    strcat(request, body);
    strcat(request, LINE_TERMINATOR);
}

void ccp_create_response(char *response, char *at, CCP_STATUS_CODE code, char *body)
{
    int length_of_message = strlen(body);
    char length_string[10];
    sprintf(length_string, "%d", length_of_message);
    strcpy(response, at);
    strcat(response, LINE_TERMINATOR);
    strcat(response, status_code_to_string(code));
    strcat(response, LINE_TERMINATOR);
    strcat(response, length_string);
    strcat(response, LINE_TERMINATOR);
    strcat(response, body);
    strcat(response, LINE_TERMINATOR);
}

const char *status_code_strings[] = {
    [CCP_OK] = "1",
    [CCP_SERVER_ERROR] = "2",
    [CCP_BAD_REQUEST] = "0",
    [CCP_UNAUTHENTICATED] = "3",
    [CCP_NUM_STATUS_CODES] = "Unknown" // Default string for unknown status codes
};

const char *status_code_to_string(CCP_STATUS_CODE code)
{
    if (code >= 0 && code < CCP_NUM_STATUS_CODES)
        return status_code_strings[code];
    else
        return status_code_strings[CCP_NUM_STATUS_CODES]; // Return the default string
}