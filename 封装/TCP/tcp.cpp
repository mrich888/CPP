#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <error.h>
#include <stdlib.h>
#include <cstring>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "tcp.hpp"


tcp::~tcp()
{
  
    close(m_sockfd);
}

/* 客户端初始化 */
void tcp :: clientInit()
{
    m_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (m_sockfd == -1)
    {
        perror("socker error");
    }
 
    m_serverAdd.sin_family = AF_INET;
    m_serverAdd.sin_port = htons(m_port);
    int ret = inet_pton(AF_INET, m_localIP, (void *)&m_serverAdd.sin_addr.s_addr);
    if (ret != 1)
    {
        perror("inet_pton error");
    }

    /* 客户端连接 */
    ret = connect(m_sockfd, (struct sockaddr *)&m_serverAdd, sizeof(m_serverAdd));
    if (ret == -1)
    {
        perror("connect error");
    }
}


/* 客户端发送信息 */
bool tcp::clientSend(const char* message)
{
    int readBytes = write(m_sockfd, message, sizeof(message));
    if (readBytes < 0)
    {
        perror("read error");
        return false;
    }
    std :: cout << message << std :: endl;
    return true;
}

/* 客户端接收信息 */
int tcp:: clientRec(size_t bufferSize)
{
    char buffer[bufferSize];
    int readBytes = read(m_sockfd, buffer,  bufferSize);
    if (readBytes == -1)
    {
        perror("read error");
        exit(-1);
    }
    std :: cout << buffer << std :: endl;
    return 0;
}

/* 服务器初始化 */
void tcp::serverInit()
{
    m_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (m_sockfd == -1)
    {
        perror("socket error");
    }
   
    m_localAdd.sin_family = AF_INET;
    m_localAdd.sin_port = htons(m_port);
    m_localAdd.sin_addr.s_addr = htonl(INADDR_ANY);

    int  m_localAddLen = sizeof(m_localAdd);

    /* 设置端口复用 */
    int enableOpt = 1;
    int ret = setsockopt(m_sockfd, SOL_SOCKET, SO_REUSEADDR, (void *) &enableOpt, sizeof(enableOpt));
    if (ret == -1)
    {
        perror("setsockopt error");
    }

    /* 绑定服务器端口信息 */
    ret = bind(m_sockfd, (struct sockaddr *)&m_localAdd, m_localAddLen);
    if (ret == -1)
    {
        perror("bind error");
    }
    /* 监听 */
    ret = listen(m_sockfd, m_max_listen);
    if (ret == -1)
    {
        perror("listen error");
    }
}

/* 服务器accept */
int tcp::serverAccept()
{
    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen = sizeof(clientAddress);
    m_acceptfd = accept(m_sockfd, (struct sockaddr *)&clientAddress, &clientAddressLen);
    if (m_acceptfd == -1)
    {
        perror("accept error");
    }
    return m_acceptfd;
}

/* 服务器发送信息 */
bool tcp::serverSend(const char* message)
{
    int readBytes = write(m_sockfd, message, sizeof(message));
    if (readBytes < 0)
    {
        perror("read error");
        return false;
    }
    
    return true;
}

/* 服务器接收信息 */
int tcp::serverRec(int acceptfd, size_t bufferSize)
{
    char buffer[bufferSize];
    m_acceptfd = acceptfd;
    int readBytes = read(m_acceptfd, buffer,  bufferSize);
    if (readBytes == -1)
    {
        perror("read error");
        exit(-1);
    }
    std :: cout << buffer << std :: endl;

    return 0;
}
