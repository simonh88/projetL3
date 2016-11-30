#ifndef APPLICATION_H
#define APPLICATION_H
#include "lesclients.h"
#include "leslocations.h"
#include "lesvehicules.h"
#include "lesparcs.h"
#include "leschauffeurs.h"

class Application
{
private:
    LesLocations lesLocations;
    LesVehicules lesVehicules;
    LesClients lesClients;
    LesParcs lesParcs;
    LesChauffeurs lesChauffeurs;
public:
    Application();
    void addVehicule(Vehicule veh);
    void addClient(std::string &client_Nom, std::string &client_Prenom, std::string &client_Adresse);
    void addLocation(int &loc_idClient, std::string &loc_refBanq, Date &loc_DateDebut, int &loc_Duree, bool &loc_assist, std::string &loc_immatVeh);
    void addParc(Parc parc);
    void addChauffeur(Chauffeur chauffeur);
    void afficherClients();
    void afficherVehicules();
    void afficherChauffeurs();

    int getVehiculesSize();
    Vehicule getVehiculeById(int id);
    int getClientsSize();
    Client getClientById(int id);
    void afficherLocations();
    void afficherParcs();
};

#endif // APPLICATION_H
