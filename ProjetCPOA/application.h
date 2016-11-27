#ifndef APPLICATION_H
#define APPLICATION_H
#include "lesclients.h"
#include "leslocations.h"
#include "lesvehicules.h"


class Application
{
private:
    LesLocations lesLocations;
    LesVehicules lesVehicules;
    LesClients lesClients;
public:
    Application();
    void addVehicule(Vehicule veh);
    void addClient(std::string &client_Nom, std::string &client_Prenom, std::string &client_Adresse);
    void addLocation(Location loc);
    void afficherClients();
};

#endif // APPLICATION_H
