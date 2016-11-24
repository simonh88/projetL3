#include "vehicule.h"

std::string Vehicule::getModele() const
{
    return modele;
}

void Vehicule::setModele(const std::string &value)
{
    modele = value;
}

Vehicule::Vehicule()
{

}

Vehicule::~Vehicule(){

}



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

