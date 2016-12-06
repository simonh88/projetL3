#include "parc.h"
#include <string>
#include <iostream>

Parc::Parc(std::string &nom, std::string &adresse, int &nbPlaces): nom(nom), adresse(adresse), nbPlaces(nbPlaces)
{

}

std::string Parc::getAdresse() {
    return adresse;
}

std::string Parc::getNom() {
    return nom;
}

int Parc::getNbPlaces() {
    return nbPlaces;
}

void Parc::setAdresse( std::string &value){
    adresse = value;
}

void Parc::setNbPlaces(int value){
    nbPlaces = value;
}

void Parc::setNom( std::string &value){
    nom = value;
}

void Parc::setVehicule(Vehicule &veh){
    lesVehicules.setVehicule(veh);
}

Vehicule Parc::getVehicule(int id){
    return lesVehicules.getVehicule(id);
}

int Parc::getVehiculesSize(){
    return lesVehicules.getSize();
}

void Parc::printParc(){
    std::cout << "-Parc : \n" << std::flush;
    std::cout << "      nom : " << nom << "\n" << std::flush;
    std::cout << "      adresse : " << adresse << "\n" << std::flush;
    std::cout << "      nbPlaces : " << nbPlaces << "\n" << std::flush;
}
