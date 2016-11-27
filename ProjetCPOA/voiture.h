#ifndef VOITURE_H
#define VOITURE_H
#include "vehicule.h"

class Voiture : public Vehicule
{
private:
    int nbPlaces;
public:
    Voiture(std::string immatriculation, std::string modele, int nbPlaces, bool estDispo, double prixJournee);
    //virtual ~Voiture();
    void setNbPlaces(const int value);
    int getNbPlaces() const;
};

#endif // VOITURE_H
