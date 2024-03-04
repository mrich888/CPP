#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <error.h>
#include <stdlib.h>
#include <cstring>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "udp.hpp"

const int BUF_SIZE = 128;

UDP :: UDP() 
{
    m_sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (m_sockfd == -1) {
        perror("socket error");
        exit(-1);
    }
}

void UDP :: bindServer(int port) 
{
    memset(&m_serverAddr, 0, sizeof(m_serverAddr));
    m_serverAddr.sin_family = AF_INET;
    m_serverAddr.sin_port = htons(port);
    m_serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);

    int ret = bind(m_sockfd, (struct sockaddr*)&m_serverAddr, sizeof(m_serverAddr));
    if (ret == -1) {
        perror("bind error");
        exit(-1);
    }
}

void UDP :: sendTo(const std::string& message, const std::string& ip, int port) 
{
    struct sockaddr_in destAddr;
    memset(&destAddr, 0, sizeof(destAddr));
    destAddr.sin_family = AF_INET;
    destAddr.sin_port = htons(port);
    inet_pton(AF_INET, ip.c_str(), &destAddr.sin_addr);

    sendto(m_sockfd, message.c_str(), message.size(), 0, (struct sockaddr*)&destAddr, sizeof(destAddr));
}

std::string UDP :: receiveFrom() {
    char buffer[BUF_SIZE];
    memset(buffer, 0, sizeof(buffer));
    m_clientAddrLen = sizeof(m_clientAddr);

    int readBytes = recvfrom(m_sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*)&m_clientAddr, &m_clientAddrLen);
    if (readBytes < 0) {
        perror("recvfrom error");
        exit(-1);
    }

    return std::string(buffer);
}

void UDP :: closeSocket() 
{
    close(m_sockfd);
}
