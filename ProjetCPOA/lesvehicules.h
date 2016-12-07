#ifndef LESVEHICULES_H
#define LESVEHICULES_H
#include "vehicule.h"
#include <vector>

class LesVehicules
{
private:
    std::vector<Vehicule*> listVehicules;
public:
    LesVehicules();
    Vehicule* getVehicule(int id);
    void setVehicule(Vehicule* c);
    int getSize() const;
    Vehicule* getVehiculeByImmat(std::string immat);
};

#endif // LESVEHICULES_H
