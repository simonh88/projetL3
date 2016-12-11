#include "controlevehicule.h"

ControleVehicule::ControleVehicule(std::string immat, Periode* p)
{
    this->immatVehicule = immat;
    this->inactivite = p;
}

Periode* ControleVehicule::getInactivite() const{
    return this->inactivite;
}

std::string ControleVehicule::getImmatVehicule() const{
    return this->immatVehicule;
}


void ControleVehicule::setInactivite(Periode* value){
    this->inactivite = value;
}

void ControleVehicule::setImmatVehicule(const std::string &value){
    this->immatVehicule=value;
}


void ControleVehicule::afficherControle(){
    std::cout << "Controle vehicule du " << std::endl;
    inactivite->afficher();
    std::cout << "Pour le vehicule " << immatVehicule << std::endl<< std::endl;
}
