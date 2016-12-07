#include "lesvehicules.h"
#include "vehicule.h"
#include <vector>
#include <algorithm>

LesVehicules::LesVehicules()
{

}


Vehicule* LesVehicules::getVehicule(int id)
{
    return this->listVehicules.at(id);
}

void LesVehicules::setVehicule(Vehicule* c)
{
    this->listVehicules.push_back(c);
}

int LesVehicules::getSize() const
{
    return this->listVehicules.size();
}

Vehicule* LesVehicules::getVehiculeByImmat(std::string immat)
{
    Vehicule* v;
    for(int i = 0; i<listVehicules.size(); i++){
        if(listVehicules.at(i)->getImmatriculation().compare(immat) == 0){
            v = listVehicules.at(i);
            break;
        }
    }
    return v;
}
