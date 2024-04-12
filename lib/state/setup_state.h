#pragma once




/*
@brief Initialize the setup state. During which the WiFi module is initialized and the connection to the Access Point is established.
if SSID and password are given the module will try to connect to the given Access Point and set it as default ap. 
if SSID and password are NULL the module will check if it's already connected to an Access Point. If it is, it will continue to the next state.
if it is not connected to an Access Point it will start a server and wait to recieve ssid and password and then it will connect to the given ap.
*/
void setup_state_init(char* ssid, char* password);