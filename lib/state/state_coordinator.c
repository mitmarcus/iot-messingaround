#include "state_coordinator.h"
#include "connect_wifi_state.h"
#include <stddef.h>

void state_coordinator(State state)
{
    while (1)
    {
        switch (state)
        {
        case WIFI_CONNECT_STATE:
            state_coordinator(connect_wifi_state_switch(NULL, NULL));
            break;
        case SERVER_CONNECT_STATE:
            break;
        }
    }
}

void start()
{
    State state = WIFI_CONNECT_STATE;
    state_coordinator(state);
}