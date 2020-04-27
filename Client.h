#ifndef CLIENT_H
#define CLIENT_H

// Définition de la classe Client

#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define PORT 8888
#define TRUE 1
#define HELLO_MESSAGE "Hello from client"
#define CONFIG_FILENAME ".config.json"

class Client
{
private:

    // File descriptor for the socket
    int sock = 0;

    // read return
    int valread;

    // Structure describing an Internet socket address
    struct sockaddr_in serv_addr;

    char buffer[1024] = {0};

public:
    int connection();
    void writeConfigFile(char*);
};

#endif
