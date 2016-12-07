#ifndef PARC_H
#define PARC_H
#include <string>
#include "lesvehicules.h"

class Parc
{
private:
    std::string nom;
    std::string adresse;
    int nbPlaces;
    LesVehicules lesVehicules;

public:
    Parc(std::string &nom, std::string &adresse, int &nbPlaces);

    std::string getNom() const;
    std::string getAdresse() const;
    int getNbPlaces() const;

    void setNom(const std::string &value);
    void setAdresse(const std::string &value);
    void setNbPlaces(int value);

    void printParc();
    void setVehicule(Vehicule* veh);
    Vehicule* getVehicule(int id);
    int getVehiculesSize();
    Vehicule *getVehiculeByImmat(std::string immat);
};

#endif // PARC_H
