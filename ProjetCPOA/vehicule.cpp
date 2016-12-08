#include "vehicule.h"
#include <iostream>

std::string Vehicule::getModele() const
{
    return modele;
}

void Vehicule::setModele(const std::string &value)
{
    modele = value;
}


Vehicule::Vehicule(){

}

Vehicule::Vehicule(std::string immatriculation, std::string modele, bool estDispo, double prixJournee):
    immatriculation(immatriculation), modele(modele), estDispo(estDispo), prixJournee(prixJournee)
{

}

Vehicule::~Vehicule(){

}


//-------------------------------- GETTERS --------------------------------------


std::string Vehicule::getUrlImage() const
{
    return this->urlImage;
}

double Vehicule::getPrixJournee() const
{
    return this->prixJournee;
}

std::string Vehicule::getImmatriculation() const
{
    return this->immatriculation;
}

bool Vehicule::getEstDispo() const
{
    return this->estDispo;
}

std::string Vehicule::getType() const
{
    return this->type;
}

Periode* Vehicule::getPeriode(int i)const{
    return this->periodeIndispo.at(i);
}

int Vehicule::getSizeIndispo(){
    return this->periodeIndispo.size();
}

//-------------------------------- SETTERS --------------------------------------


void Vehicule::setUrlImage(const std::string &value)
{
    this->urlImage = value;
}

void Vehicule::setPrixJournee(double value)
{
    this->prixJournee = value;
}

void Vehicule::setImmatriculation(const std::string &value)
{
    this->immatriculation = value;
}

void Vehicule::setEstDispo(bool value)
{
    this->estDispo = value;
}

void Vehicule::setType(const std::string &value)
{
    this->type = value;
}

void Vehicule::addIndispo(Periode* p){
    this->periodeIndispo.push_back(p);
}

void Vehicule::afficherIndispo(){
    std::cout << "liste indispo \`n" << std::flush;
    for(int i = 0; i< this->getSizeIndispo() ; i++){
        this->getPeriode(i)->afficher();
    }
}

void Vehicule::printVehicule(){
    std::cout << "- " << getType() << " : \n" << std::flush;
    std::cout << "     immat : " << getImmatriculation() << "\n" << std::flush;
    std::cout << "     modele : " << getModele() << "\n" << std::flush;
    std::cout << "     dispo ? : " << getEstDispo() << "\n" << std::flush;
    std::cout << "     prixJournee : " << getPrixJournee() << "\n" << std::flush;
}

