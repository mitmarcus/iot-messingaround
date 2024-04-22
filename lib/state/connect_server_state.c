#include <state_coordinator.h>
#include <connect_server_state.h>
#include <wifi.h>   
#include <stddef.h>




State connect_server_state_switch(char* ip, int port){
    wifi_init(NULL);
    wifi_command_create_TCP_connection("192.168.28.1",18, NULL, NULL);
    return WORKING_STATE;
}
