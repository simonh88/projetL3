#include "lesparcs.h"
#include "parc.h"

LesParcs::LesParcs()
{

}

Parc LesParcs::getParc(int id){
    return this->listParc.at(id);
}

int LesParcs::getSize(){
    return this->listLocation.size();
}

void LesParcs::addParc(const Parc &p){
    this->listParc.push_back(p);
}
