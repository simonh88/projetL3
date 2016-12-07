#include "leschauffeurs.h"
#include "chauffeur.h"

LesChauffeurs::LesChauffeurs()
{

}

Chauffeur* LesChauffeurs::getChauffeur(int id){
    return this->listChauffeurs.at(id);
}

int LesChauffeurs::getSize(){
    return this->listChauffeurs.size();
}

void LesChauffeurs::addChauffeur(Chauffeur* &chau){
    this->listChauffeurs.push_back(chau);
}
