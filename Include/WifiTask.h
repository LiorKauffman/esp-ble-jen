#ifndef _WIFI_TASK_H
#define _WIFI_TASK_H

#include "Task.h"

#include <netinet/in.h>
#include <string>
#include <vector>
#include <utility> 

class WifiTask : public Task
{
public:
    WifiTask();

    void SendPacket(const char* packet);

private:
    static constexpr auto _TASK_NAME = "Wifi Task";

    int32_t _sockFd;
    struct sockaddr_in _internetSocketAddress; 
    std::vector<std::pair<std::string, uint16_t>> _multicastSocketsProperties; 

    void _Run() override;
    void _InitWifiSettings();
};

#endif // _WIFI_TASK_H