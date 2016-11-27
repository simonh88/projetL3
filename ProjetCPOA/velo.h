#ifndef VELO_H
#define VELO_H
#include "vehicule.h"

class Velo : public Vehicule
{
public:
    Velo(std::string &immatriculation, std::string modele, bool estDispo, double prixJournee);
    //virtual ~Velo();
};

#endif // VELO_H
