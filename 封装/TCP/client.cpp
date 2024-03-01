#include <iostream>
#include <sys/types.h>
#include <sys/socket.h>
#include <error.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "tcp.hpp"


int main()
{
    tcp client(8888, "172.31.173.217", 0);
    client.clientInit();

    client.clientSend("123");

}