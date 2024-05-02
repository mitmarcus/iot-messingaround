#pragma once

typedef enum
{
    CCP_OK,
    CCP_SERVER_ERROR,
    CCP_BAD_REQUEST,
    CCP_UNAUTHENTICATED,
    CCP_NUM_STATUS_CODES
} CCP_STATUS_CODE;

void ccp_create_request(char *at, char *body, char *request);

void ccp_create_response(char *response, char *at, CCP_STATUS_CODE code, char *body);