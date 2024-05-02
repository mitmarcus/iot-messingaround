#include "ccp_protocol.h"

char* ccp_create_request(char* at, char* body){
    
    int length_of_message = strlen(body);
    char request[length_of_message];
    strcpy(at, request);
    strcat(LINE_TERMINATOR, request);
    strcat((char*)length_of_message, request);
    strcat(LINE_TERMINATOR, request);
    strcat(body, request);
    strcat(LINE_TERMINATOR, request);
    return request;
}