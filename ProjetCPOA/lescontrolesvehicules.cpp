#include "lescontrolesvehicules.h"

LesControlesVehicules::LesControlesVehicules()
{

}

void LesControlesVehicules::addControleVehicule(ControleVehicule *vehic){
    listControleVehicule.push_back(vehic);
}

int LesControlesVehicules::getSize(){
    return listControleVehicule.size();
}

ControleVehicule* LesControlesVehicules::getControleVehicule(int id){
    return listControleVehicule.at(id);
}
