#ifndef MESSAGE_H
#define MESSAGE_H

// Définition de la classe Message

enum typeMessage { CONNECTION, CONFIG, DUCK_FOUND, DUCK_FOUND_CLIENT, ALL_DUCKS_FOUND, COORDINATES };

class Message
{
private:
    // Type
    char* type;
    char* message;

public:

    virtual ~Message() {}
    virtual char* constructMessage() = 0;
    virtual char* getMessage() = 0;
    char* getType();
};

// 1. Message sent by client
class ConnectionMessage : public Message
{
private:
    // Connection type
    typeMessage type = CONNECTION;

public:

    
};

// 2. Config initialisation
class ConfigMessage : public Message
{
private:
    // Config type
    typeMessage type = CONFIG;

    // Config (ducks)
    char* data;

public:
    // Get config
    char* getConfig();
};

// 3. Duck found
class DuckFoundMessage : public Message
{
private:
    // Duck found type
    typeMessage type = DUCK_FOUND;

    // Duck id
    int duckId;

public:
    // Get duck id
    int getDuckId();
};

// 4. Duck found by a client
class DuckFoundClientMessage : public Message
{
private:
    // Duck found by a client type
    typeMessage type = DUCK_FOUND_CLIENT;

public:
    
};

// 5. All ducks found
class AllDucksFoundMessage : public Message
{
private:
    // All ducks found
    typeMessage type = ALL_DUCKS_FOUND;

public:
    
};

// 6. Coordinates sent by client
class CoordinatesMessage : public Message
{
private:
    // Coordinates
    typeMessage type = COORDINATES;

    // Position (x, y, z)
    int position[];

public:
    // Get position
    int* getPosition();
};

#endif
