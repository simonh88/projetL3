#include "voiture.h"
#include "string.h"

Voiture::Voiture(std::string immatriculation, std::string modele, int nbPlaces, bool estDispo, double prixJournee):
    Vehicule::Vehicule(immatriculation, modele, estDispo, prixJournee), nbPlaces(nbPlaces)
{
    this->type = "Voiture";
}
/*Voiture::~Voiture(){

}*/

void Voiture::setNbPlaces(const int value)
{
    this->nbPlaces = value;
}

int Voiture::getNbPlaces() const
{
    return this->nbPlaces;
}



