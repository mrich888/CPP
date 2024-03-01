#include <iostream>
#include "udp.hpp"

int main() {
    UDP udpServer;
    udpServer.bindServer(6666);

    std::string receivedMessage = udpServer.receiveFrom();
    std::cout << "Received message: " << receivedMessage << std::endl;

    udpServer.closeSocket();

    return 0;
}