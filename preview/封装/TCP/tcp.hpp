#ifndef __TCP_H_
#define __TCP_H_

/* TCP */
class tcp
{
public:
    /* 构造函数 */
    tcp(unsigned int port, const char * localIP, int sockfd):m_port(port), m_localIP(strdup(localIP)), m_sockfd(sockfd)
    {}//客户端
    tcp(unsigned int port, int max_listen, int sockfd, int acceptfd):m_port(port), m_max_listen(max_listen), m_sockfd(sockfd), m_acceptfd(acceptfd)
    {}
    /* 客户端初始化  */
    void clientInit();
    /* 客户端发送信息 */
    bool clientSend(const char* message);
    /* 客户端接收信息 */
    int clientRec(size_t bufferSize);
    /* 服务器初始化 + 监听 */
    void serverInit();
    /* 服务器的accept */
    int serverAccept();
    /* 服务器发送信息 */
    bool serverSend(const char* message);
    /* 服务器接收信息 */
    int serverRec(int acceptfd, size_t bufferSize);

    ~tcp();
    

private:
    int m_sockfd;
    unsigned int m_port;//刚开始给
    int m_max_listen;//刚开始给
    struct sockaddr_in m_localAdd;
    struct sockaddr_in m_serverAdd;
    const char * m_localIP; //刚开始给
    int m_acceptfd;

};

#endif //__TCP_H_