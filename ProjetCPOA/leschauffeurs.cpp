#include "leschauffeurs.h"
#include "Chauffeur.h"

LesChauffeurs::LesChauffeurs()
{

}

Chauffeur LesChauffeurs::getChauffeur(int id){
    return this->listChauffeurs.at(id);
}

int LesChauffeurs::getSize(){
    return this->listLocation.size();
}

void LesChauffeurs::addChauffeur(const Parc &p){
    this->listChauffeurs.push_back(p);
}
