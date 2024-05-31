#include "../Include/WifiTask.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fstream>
#include <iostream>

WifiTask::WifiTask() :
    Task(_TASK_NAME),
    _multicastSocketsProperties()
{
    _InitWifiSettings();

    struct ip_mreq mreq;

    // Create a UDP socket
    if ((_sockFd = socket(AF_INET, SOCK_DGRAM, 0)) == -1)
    {
        printf("Could not create socket");
    }

    printf("Socket created \n");

    // Prepare the sockaddr_in structure
    _internetSocketAddress.sin_family = AF_INET;
    _internetSocketAddress.sin_port = htons(_multicastSocketsProperties.at(0).second);
    _internetSocketAddress.sin_addr.s_addr = inet_addr(_multicastSocketsProperties.at(0).first.c_str());

    // Join multicast group
    mreq.imr_multiaddr.s_addr = inet_addr(_multicastSocketsProperties.at(0).first.c_str());
    mreq.imr_interface.s_addr = htonl(INADDR_ANY);

    if (setsockopt(_sockFd, IPPROTO_IP, IP_ADD_MEMBERSHIP, (char *)&mreq, sizeof(mreq)) < 0)
    {
        printf("Error joining multicast group");
    }
}

void WifiTask::_Run()
{
    char buffer[1300];

    while (true)
    {
        memset(buffer, 0, sizeof(buffer));

        ssize_t len = recvfrom(_sockFd, buffer, sizeof(buffer), 0, NULL, NULL);

        if (len < 0) {
            perror("recvfrom");
            exit(1);
        }

        printf("Received: %s\n", buffer);
    }
    
}

void WifiTask::SendPacket(const char* packet)
{
    // Send a message to the multicast group
    if (sendto(_sockFd, packet, strlen(packet), 0, (struct sockaddr*)&_internetSocketAddress, sizeof(_internetSocketAddress)) < 0) {
        printf("Send failed\n");
    }
    else
    {
        printf("Send Packet Passed\n");
    }
    // Close the socket
}

void WifiTask::_InitWifiSettings()
{
    std::ifstream file ("../Files/WifiSettings.txt");

    if (!file)
    {
        printf("Unable to open file\n");
        exit(1);
    }

    std::string line;

    while(std::getline(file, line))
    {
        auto subStrIndex = line.find(" ");

        std::string tempStr(&line.at(subStrIndex + 1));
        subStrIndex = tempStr.find(" ");

        _multicastSocketsProperties.push_back(std::make_pair(std::string(tempStr.data(), subStrIndex), std::atoi(&tempStr.at(subStrIndex+1))));

        std::cout <<"File Content "<<line << '\n';
    }

    file.close();
}



// int main() {
//     std::ifstream file("example.txt");

//     if (!file) {
//         std::cerr << "Unable to open file";
//         return 1;
//     }

//     std::string line;
//     while (std::getline(file, line)) {
//         std::cout << line << '\n';
//     }

//     file.close();

//     return 0;
// }
