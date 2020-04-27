#include "Client.h"

using namespace std;

int Client::connection()
{
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
    {
        printf("\nInvalid address/ Address not supported \n");
        exit(EXIT_FAILURE);
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("\nConnection Failed \n");
        exit(EXIT_FAILURE);
    }

    //send(sock, HELLO_MESSAGE, strlen(HELLO_MESSAGE), 0);
    //printf("Hello message sent\n");
    //valread = read(sock, buffer, 1024);
    //printf("%s\n", buffer);

    if ((valread = read(sock, buffer, 1024)) > 0) {
        // Write config file
        writeConfigFile(buffer);
    }
}

void Client::writeConfigFile(char *data)
{
    cout << "Tentative de récupération du fichier de configuration" << endl;
    ofstream configFile;
    configFile.open(CONFIG_FILENAME);
    configFile << data << endl;
    cout << "Récupération du fichier de configuration OK" << endl;
}

// Add Client
// Add Message with sub messages