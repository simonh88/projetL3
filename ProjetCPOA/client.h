#ifndef CLIENT_H
#define CLIENT_H
#include <string>

class Client
{

private:
    int idClient;
    std::string nom;
    std::string prenom;
    std::string adresse;

public:
    Client();
};

#endif // CLIENT_H
