#include "client.h"
#include <string>
#include <iostream>


//-------------------------------- CONSTRUCTORS --------------------------------


Client::Client()
{


}



Client::Client(int id, std::string &nom2, std::string &prenom2, std::string &adresse2): idClient(id), nom(nom2), prenom(prenom2), adresse(adresse2)
{

}


//-------------------------------- GETTERS -------------------------------------



std::string Client::getAdresse() const
{
    return adresse;
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


//-------------------------------- SETTERS -------------------------------------


void Client::setAdresse(const std::string &value)
{
    adresse = value;
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


//-------------------------------- OTHERS -------------------------------------


void Client::printClient(){
    std::cout << "- Client : \n" << std::flush;
    std::cout << "     id : " << idClient << "\n" << std::flush;
    std::cout << "     nom : " << nom << "\n" << std::flush;
    std::cout << "     prenom : " << prenom << "\n" << std::flush;
    std::cout << "     adresse : " << adresse << "\n" << std::flush;
}
