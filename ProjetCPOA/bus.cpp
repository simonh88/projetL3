#include "bus.h"
#include "vehicule.h"

Bus::Bus(std::string immatriculation, std::string modele, int nbPlaces, bool estDispo, double prixJournee):
    Vehicule(immatriculation, modele, estDispo, prixJournee), nbPlaces(nbPlaces)
{

}

void Bus::setNbPlaces(int value)
{
    this->nbPlaces = value;
}

int Bus::getNbPlaces() const
{
    return this->nbPlaces;
}

