#ifndef APPLICATION_H
#define APPLICATION_H
#include "lesclients.h"
#include "leslocations.h"
#include "lesvehicules.h"
#include "lesparcs.h"
#include "leschauffeurs.h"
#include "lescontrolesvehicules.h"

class Application
{
private:
    LesLocations lesLocations;
    LesVehicules lesVehicules;
    LesClients lesClients;
    LesParcs lesParcs;
    LesChauffeurs lesChauffeurs;
    LesControlesVehicules lesControlesVehicules;
public:
    Application();
    void addVehicule(Vehicule* veh, int nbPlaces, int idParc);
    void addClient(std::string &client_Nom, std::string &client_Prenom, std::string &client_Adresse);
    void addLocation(int &loc_idClient, std::string &loc_refBanq, Date &loc_DateDebut, int &loc_Duree, bool &loc_assist, std::string &loc_immatVeh);
    void addParc(Parc* parc);
    void addChauffeur(Chauffeur* chauffeur);
    void afficherClients();
    void afficherVehicules();
    void afficherChauffeurs();
    void addControleVehic(Date &debut, Date &fin, Vehicule* vehic);

    int getVehiculesSize(int idParc);
    Vehicule* getVehiculeById(int id, int idParc);
    Vehicule* getVehiculeByImmat(std::string immatVeh);
    int getClientsSize();
    Client* getClientById(int id);
    void afficherLocations();
    void afficherParcs();

    bool to_bool(std::string &s);

    void loadData();
    void loadClients();
    void loadVehicules();
    void loadChauffeurs();
    void loadParcs();
    void loadIndispoVeh();
    void loadLocations();

    int getParcsSize();
    Parc* getParc(int id);
    int getLocationsSize();
    Location* getLocation(int id);
    int getChauffeursSize();
    Chauffeur* getChauffeur(int id);
};

#endif // APPLICATION_H
