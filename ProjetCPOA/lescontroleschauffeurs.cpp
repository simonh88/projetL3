#include "lescontroleschauffeurs.h"

LesControlesChauffeurs::LesControlesChauffeurs()
{

}

void LesControlesChauffeurs::addControleChauffeur(ControleChauffeur *cc){
    listControleChauffeur.push_back(cc);
}

int LesControlesChauffeurs::getSize(){
    return listControleChauffeur.size();
}

ControleChauffeur* LesControlesChauffeurs::getControleChauffeur(int id){
    return listControleChauffeur.at(id);
}
