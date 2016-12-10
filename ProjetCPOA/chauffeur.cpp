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

Periode* Chauffeur::getPeriode(int i) const{
    return this->periodeIndispo.at(i);
}

int Chauffeur::getSizeIndispo(){
    return this->periodeIndispo.size();
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


void Chauffeur::addIndispo(Periode* p){
    this->periodeIndispo.push_back(p);
}

void Chauffeur::afficherIndispo(){
    std::cout << "liste indispo \n" << std::flush;
    for(int i = 0; i< this->getSizeIndispo() ; i++){
        this->getPeriode(i)->afficher();
    }
}

void Chauffeur::printChauffeur(){
    std::cout << "- Chauffeur : \n" << std::flush;
    std::cout << "      Nom : " << nom << "\n" << std::flush;
    std::cout << "      Prenom : " << prenom << "\n" << std::flush;
    std::cout << "      Disponibilité : " << estDispo << "\n" << std::flush;
    std::cout << "      Permis : " << noPermis << "\n" << std::flush;
}
