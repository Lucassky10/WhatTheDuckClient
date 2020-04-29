#ifndef CLIENT_H
#define CLIENT_H

#include <vector>

// Définition de la classe Client

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#include "Client.h"

#include "Message.h"
#include "Socket.h"

#define PORT 8888
#define TRUE 1
#define HELLO_MESSAGE "Hello from client"

using namespace std;


class Client
{
private:

    static Client* instance;

    Client();

    // socket file descriptor
    int sock = 0;

    // read return
    int valread;

    // Structure describing an Internet socket address
    struct sockaddr_in serv_addr;

    char buffer[BUFFER_SIZE] = {0};

public:
    void connection();
    static void listen(int);
    int getSock();
    char* getBuffer();
    static Client* getInstance();
};

#endif
