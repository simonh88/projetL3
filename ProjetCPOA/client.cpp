#include "client.h"
#include <string>


std::string Client::getAdresse() const
{
    return adresse;
}

void Client::setAdresse(const std::string &value)
{
    adresse = value;
}

std::string Client::getPrenom() const
{
    return prenom;
}



std::string Client::getNom() const
{
    return nom;
}

int Client::getIdClient() const
{
    return idClient;
}



void Client::setPrenom(const std::string &value)
{
    prenom = value;
}

void Client::setNom(const std::string &value)
{
    nom = value;
}

void Client::setIdClient(int value)
{
    idClient = value;
}

Client::Client()
{


}

