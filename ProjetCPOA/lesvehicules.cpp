#include "lesvehicules.h"
#include "vehicule.h"

LesVehicules::LesVehicules()
{

}


Vehicule LesVehicules::getVehicule(int id) const
{
    return this->listVehicules.at(id);
}

void LesVehicules::setVehicule(const Vehicule &c)
{
    this->listVehicules.push_back(c);
}

int LesVehicules::getSize() const
{
    return this->listVehicules.size();
}
