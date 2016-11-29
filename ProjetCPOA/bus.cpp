#include "bus.h"
#include "vehicule.h"

Bus::Bus(std::string immatriculation, std::string modele, int nbPlaces, bool estDispo, double prixJournee):
    Vehicule(immatriculation, modele, estDispo, prixJournee), nbPlaces(nbPlaces)
{
    this->type = "Bus";
}

void Bus::setNbPlaces(int value)
{
    this->nbPlaces = value;
}

int Bus::getNbPlaces() const
{
    return this->nbPlaces;
}

