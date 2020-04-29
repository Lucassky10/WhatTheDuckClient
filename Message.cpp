#include "Message.h"

using namespace std;

typedef struct
{ 
    char type;
    int message;
} Header;

// Get type
messageType Message::getType() {
    return type;
}

// Get text for enum
string Message::getTextForEnum(int enumVal)
{
    return enumMessageTypes[enumVal];
}

/**
 * Asking Configuration
 */

// Asking configuration Message
AskingConfigurationMessage::AskingConfigurationMessage() {
    // Asking configuration type
    type = ASKING_CONFIGURATION;
}

// Construct asking configuration message
string AskingConfigurationMessage::constructMessage() {
    message = to_string(type);
    return message;
}

/**
 * Configuration
 */

// Configuration Message
ConfigurationMessage::ConfigurationMessage() {
    // Configuration type
    type = CONFIGURATION;
}

// Construct configuration message
string ConfigurationMessage::constructMessage() {
    message = to_string(type) + DELIMITER + data;
    return message;
}

// Construct get message
void ConfigurationMessage::setMessage(string data) {
    setData(data);
}

// Set Message
void ConfigurationMessage::setData(string configData) {
    data = configData;
}

// Get data
string ConfigurationMessage::getData() {
    return data;
}

/**
 * Duck Found Message
 */
DuckFoundMessage::DuckFoundMessage() {
    type = DUCK_FOUND;
}

// Construct configuration message
string DuckFoundMessage::constructMessage() {
    message = to_string(type) + DELIMITER + to_string(duckId);
    return message;
}

void DuckFoundMessage::setDuckId(int id) {
    duckId = id;
}
