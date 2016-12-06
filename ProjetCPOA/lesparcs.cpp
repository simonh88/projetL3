#include "lesparcs.h"
#include "parc.h"
#include <iostream>

LesParcs::LesParcs()
{

}

Parc& LesParcs::getParc(int id){
    Parc &parc = this->listParc.at(id);

    std::cout << "lesParcs getParc : " << &parc << std::endl;

    return parc;
}

int LesParcs::getSize(){
    return this->listParc.size();
}

void LesParcs::addParc(Parc* p){

    std::cout << "lesparcs addparc : " << p << std::endl;

    this->listParc.push_back(*p);
}
