#include "velo.h"

Velo::Velo(std::string immatriculation, std::string modele, bool estDispo, double prixJournee, bool assist):
    Vehicule(immatriculation, modele, estDispo, prixJournee)
{
    this->type = "Velo";
    this->assistElec = assist;
}
/*Velo::~Velo(){

}*/

