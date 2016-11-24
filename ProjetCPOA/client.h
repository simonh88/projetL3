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
    std::string getAdresse() const;
    void setAdresse(const std::string &value);
    std::string getPrenom() const;
    std::string getNom() const;
    int getIdClient() const;
    void setPrenom(const std::string &value);
    void setNom(const std::string &value);
    void setIdClient(int value);
};

#endif // CLIENT_H
