#include "parc.h"
#include <string>
#include <iostream>

Parc::Parc(std::string &nom, std::string &adresse, int &nbPlaces): nom(nom), adresse(adresse), nbPlaces(nbPlaces)
{

}

std::string Parc::getAdresse() const{
    return adresse;
}

std::string Parc::getNom() const{
    return nom;
}

int Parc::getNbPlaces() const{
    return nbPlaces;
}

void Parc::setAdresse(const std::string &value){
    adresse = value;
}

void Parc::setNbPlaces(int value){
    nbPlaces = value;
}

void Parc::setNom(const std::string &value){
    nom = value;
}

void Parc::setVehicule(Vehicule* veh){
    lesVehicules.setVehicule(veh);
}

Vehicule* Parc::getVehicule(int id){
    return lesVehicules.getVehicule(id);
}

Vehicule* Parc::getVehiculeByImmat(std::string immat){
    return lesVehicules.getVehiculeByImmat(immat);
}

int Parc::getVehiculesSize(){
    return lesVehicules.getSize();
}

bool Parc::containsVeh(std::string immat){
    bool res = false;
    int i=0;

    while( !res &&  i<getVehiculesSize()){
        Vehicule* v = getVehicule(i);

        //std::cout << v->getImmatriculation() << "-" << immat << std::endl;

        if(!v->getImmatriculation().compare(immat)){
            res = true;
        }

        i++;
    }

    return res;
}

void Parc::printParc(){
    std::cout << "-Parc : \n" << std::flush;
    std::cout << "      nom : " << nom << "\n" << std::flush;
    std::cout << "      adresse : " << adresse << "\n" << std::flush;
    std::cout << "      nbPlaces : " << nbPlaces << "\n" << std::flush;
}
