#ifndef BUS_H
#define BUS_H
#include "vehicule.h"

class Bus : public Vehicule
{
private:
    int nbPlaces;
public:
    Bus(std::string &immatriculation, std::string modele, int nbPlaces, bool estDispo, double prixJournee);
    //virtual ~Bus();
    void setNbPlaces(const int value);
    int getNbPlaces() const;
};

#endif // BUS_H
