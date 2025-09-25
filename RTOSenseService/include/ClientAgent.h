#include <iostream>
#include <string>
#include <vector>
#include <mqueue.h>
#include <curl/curl.h>
#include <cstring>

class ClientAgent
{
    // List of Android client endpoints
    std::vector<std::string> clients = {
        "http://172.27.47.127:5000/sensor",
    };

    public:
        ClientAgent() {}
        bool sendToClient(const std::string &jsonData);
};