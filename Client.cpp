#include "Client.h"
#include "Message.h"

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

    // Send connection message
    AskingConfigurationMessage *askingConfigurationMessage = new AskingConfigurationMessage(); 
    string message = askingConfigurationMessage->constructMessage();
    cout << "Sending asking configuration" << endl;
    send(sock, message.c_str(), strlen(message.c_str()), 0);

    if ((valread = read(sock, buffer, 1024)) > 0) {
        
        // Parse buffer
        string message(buffer);

        cout << "CLIENT: " << message << endl;

        // Elements
        vector<string> elts;
        size_t position;
        string elt;
        while ((position = message.find(DELIMITER)) != string::npos) {
            elt = message.substr(0, position);
            elts.push_back(elt);
            message.erase(0, position + strlen(DELIMITER));
        }
        elts.push_back(message);

        // Get message type
        int messageTypeNumber = stoi(elts[0]);
        enum messageType type = static_cast<messageType>(messageTypeNumber);

        // Check if the message received is "configuration"
        if(type == CONFIGURATION) {
            cout << "Receiving configuration message" << endl;

            // Construct configuration message
            ConfigurationMessage *configurationMessage = new ConfigurationMessage();
            configurationMessage->setMessage(elts[1]);
         
            // Write config file
            writeConfigFile(configurationMessage->getData());
        }
    }
}

void Client::listen() {
    while(TRUE);
}

void Client::writeConfigFile(string data)
{
    cout << "Tentative de récupération du fichier de configuration" << endl;
    ofstream configFile;
    configFile.open(CONFIG_FILENAME);
    configFile << data << endl;
    cout << "Récupération du fichier de configuration OK" << endl;
}