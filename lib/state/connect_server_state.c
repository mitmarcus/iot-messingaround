#include <state_coordinator.h>
#include <connect_server_state.h>
#include <wifi.h>   
#include <stddef.h>




State connect_server_state_switch(char* ip, int port){
    wifi_init(NULL);
    char buffer[100];
    wifi_command_create_TCP_connection(ip,port, NULL, buffer);
    return WORKING_STATE;
}
