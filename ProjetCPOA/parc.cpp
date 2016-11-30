#include "parc.h"
#include <string>

Parc::Parc()
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

void Parc::printParc(){
    std::cout << "-Parc : \n" << std::flush;
    std::cout << "      nom : " << nom << "\n" << std::flush;
    std::cout << "      adresse : " << adresse << "\n" << std::flush;
    std::cout << "      nbPlaces : " << nbPlaces << "\n" << std::flush;
}
