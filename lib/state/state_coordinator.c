#include "state_coordinator.h"
#include "connect_wifi_state.h"
#include "connect_server_state.h"
#include "working_state.h"
#include <stddef.h>

void state_coordinator(State state)
{
    while (1)
    {
        switch (state)
        {
        case WIFI_CONNECT_STATE:
            state_coordinator(connect_wifi_state_switch("ssid", "password"));
            break;
        case SERVER_CONNECT_STATE:
            state_coordinator(connect_server_state_switch("192.168.28.4", 18));
            break;
        case WORKING_STATE:
            state_coordinator(working_state_switch());
            break;
        }
    }
}

void start()
{
    display_time();
    state_coordinator(WORKING_STATE);
}