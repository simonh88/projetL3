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
    void addLocation(int &loc_idClient, std::string &loc_refBanq, Date &loc_DateDebut, int &loc_Duree, bool &loc_assist, std::string &loc_immatVeh);
    void afficherClients();
    void afficherVehicules();

    int getVehiculesSize();
    Vehicule getVehiculeById(int id);
    int getClientsSize();
    Client getClientById(int id);
    void afficherLocations();
};

#endif // APPLICATION_H
