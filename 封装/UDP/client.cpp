#include <iostream>
#include "udp.hpp"

int main() 
{
    UDP udpClient;
    udpClient.sendTo("ABcDe", "172.31.173.217", 6666);

    udpClient.closeSocket();

    return 0;
}