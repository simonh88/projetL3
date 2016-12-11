#ifndef LESCONTROLESVEHICULES_H
#define LESCONTROLESVEHICULES_H
#include <vector>
#include "controlevehicule.h"


class LesControlesVehicules
{
private:
    std::vector<ControleVehicule*> listControleVehicule;
public:
    LesControlesVehicules();
    ControleVehicule* getControleVehicule(int id);
    int getSize();
    void addControleVehicule(ControleVehicule* vehic);
};

#endif // LESCONTROLESCHAUFFEURS_H
