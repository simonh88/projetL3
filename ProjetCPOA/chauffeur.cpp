#include "chauffeur.h"
#include <string>
#include <iostream>

Chauffeur::Chauffeur(std::string &noPermis, std::string &nom, std::string &prenom, bool &estDispo): noPermis(noPermis),
    nom(nom), prenom(prenom), estDispo(estDispo)
{

}


bool Chauffeur::getDispo() const{
    return estDispo;
}

std::string Chauffeur::getNom() const{
    return nom;
}

std::string Chauffeur::getPrenom() const{
    return prenom;
}

std::string Chauffeur::getNoPermis() const{
    return noPermis;
}

void Chauffeur::setNom(const std::string &value){
    nom = value;
}

void Chauffeur::setPrenom(const std::string &value){
    prenom = value;
}


void Chauffeur::setDispo(bool &value){
    estDispo = value;
}

void Chauffeur::setPermis(std::string &value){
    noPermis = value;
}


void Chauffeur::printChauffeur(){
    std::cout << "- Chauffeur : \n" << std::flush;
    std::cout << "      Nom : " << nom << "\n" << std::flush;
    std::cout << "      Prenom : " << prenom << "\n" << std::flush;
    std::cout << "      Disponibilité : " << estDispo << "\n" << std::flush;
    std::cout << "      Permis : " << noPermis << "\n" << std::flush;
}
