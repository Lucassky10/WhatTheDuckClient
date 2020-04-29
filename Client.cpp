#include "Client.h"

using namespace std;

void Client::connection()
{
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        cout << endl << "Socket creation error" << endl;
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
    {
        cout << endl << "Invalid address/ Address not supported" << endl;
        exit(EXIT_FAILURE);
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        cout << endl <<  "Connection Failed" << endl;
        exit(EXIT_FAILURE);
    }

    // Send asking configuration message
    AskingConfigurationMessage *askingConfigurationMessage = new AskingConfigurationMessage(); 
    string acMessage = askingConfigurationMessage->constructMessage();
    Socket::sendMessage(sock, acMessage);

    // Receive message (configuration) and do action
    string message = Socket::receiveMessage(sock, buffer);
    Socket::action(message);
}

void Client::listen() {
    while(TRUE);
}