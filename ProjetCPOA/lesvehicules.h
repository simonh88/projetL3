#ifndef LESVEHICULES_H
#define LESVEHICULES_H
#include "vehicule.h"
#include <vector>

class LesVehicules
{
private:
    std::vector<Vehicule> listVehicules;
public:
    LesVehicules();
    Vehicule getVehicule(int id) const;
    void setVehicule(const Vehicule &c);
    int getSize() const;
};

#endif // LESVEHICULES_H
