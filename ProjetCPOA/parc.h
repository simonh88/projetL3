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

    std::string getNom() ;
    std::string getAdresse() ;
    int getNbPlaces() ;

    void setNom( std::string &value);
    void setAdresse( std::string &value);
    void setNbPlaces(int value);

    void printParc();
    void setVehicule(Vehicule &veh);
    Vehicule getVehicule(int id);
    int getVehiculesSize();
};

#endif // PARC_H
