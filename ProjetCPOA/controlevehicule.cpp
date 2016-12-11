#include "controlevehicule.h"

ControleVehicule::ControleVehicule(std::string nom, Periode* p)
{
    this->nomVehicule = nom;
    this->inactivite = p;
}

Periode* ControleVehicule::getInactivite() const{
    return this->inactivite;
}

std::string ControleVehicule::getNomVehicule() const{
    return this->nomVehicule;
}


void ControleVehicule::setInactivite(Periode* value){
    this->inactivite = value;
}

void ControleVehicule::setNomVehicule(const std::string &value){
    this->nomVehicule=value;
}


void ControleVehicule::afficherControle(){
    std::cout << "Controle vehicule du " << std::flush;
    inactivite->afficher();
    std::cout << "Pour le vehicule " << nomVehicule << std::flush;
}
