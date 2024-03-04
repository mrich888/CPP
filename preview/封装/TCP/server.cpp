
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

const int BUFSIZE = 128;

int main()
{
    tcp server(8888, 10, 0, 0);
    server.serverInit();

    int acceptfd = server.serverAccept();
    server.serverRec(acceptfd, BUFSIZE);
 
   
}