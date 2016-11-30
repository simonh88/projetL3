#include "chauffeur.h"
#include <string>
Chauffeur::Chauffeur()
{

}


bool Chauffeur::getDispo(){
    return estDispo;
}

std::string Chauffeur::getNom(){
    return nom;
}

std::string Chauffeur::getPrenom(){
    return prenom;
}

int Chauffeur::getNoPermis(){
    return noPermis;
}

void Chauffeur::setNom(const std::string &value){
    nom = value;
}

void Chauffeur::setPrenom(const std::string &value){
    prenom = value;
}


void Chauffeur::setDispo(bool value){
    estDispo = value;
}

void Chauffeur::setPermis(int value){
    noPermis = value;
}


void Chauffeur::printChauffeur(){
    std::cout << "- Chauffeur : \n" << std::flush;
    std::cout << "      Nom : " << nom << "\n" << std::flush;
    std::cout << "      Prenom : " << prenom << "\n" << std::flush;
    std::cout << "      Disponibilité : " << estDispo << "\n" << std::flush;
    std::cout << "      Permis : " << noPermis << "\n" << std::flush;
}
