#ifndef __UDP_H_
#define __UDP_H_
#include <netinet/in.h>
class UDP 
{
private:
    int m_sockfd;
    struct sockaddr_in m_serverAddr;
    struct sockaddr_in m_clientAddr;
    socklen_t m_clientAddrLen;

public:
    UDP();

    void bindServer(int port);

    void sendTo(const std::string& message, const std::string& ip, int port);

    std::string receiveFrom();

    void closeSocket();
};

#endif 