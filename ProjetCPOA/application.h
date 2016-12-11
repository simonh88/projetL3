#ifndef APPLICATION_H
#define APPLICATION_H
#include "lesclients.h"
#include "leslocations.h"
#include "lesvehicules.h"
#include "lesparcs.h"
#include "leschauffeurs.h"
#include "lescontrolesvehicules.h"
#include "lescontroleschauffeurs.h"

class Application
{
private:
    LesLocations lesLocations;
    LesVehicules lesVehicules;
    LesClients lesClients;
    LesParcs lesParcs;
    LesChauffeurs lesChauffeurs;
    LesControlesVehicules lesControlesVehicules;
    LesControlesChauffeurs lesControlesChauffeurs;
public:
    Application();
    void addVehicule(Vehicule* veh, int nbPlaces, int idParc);
    void addClient(std::string &client_Nom, std::string &client_Prenom, std::string &client_Adresse);
    void addLocation(int &loc_idClient, std::string &loc_refBanq, Date &loc_DateDebut, int &loc_Duree, bool &loc_assist, std::string &loc_immatVeh, std::string &loc_prix);
    void addParc(Parc* parc);
    void addChauffeur(Chauffeur* chauffeur);
    void afficherClients();
    void afficherVehicules();
    void afficherChauffeurs();
    void addControleVehic(Date &debut, Date &fin, Vehicule* vehic);
    void addControleChauff(Date &dateDeb, Date &dateFin, Chauffeur* c, int id);

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
    void loadCtrlVehic();
    void loadCtrlChauff();

    int getParcsSize();
    Parc* getParc(int id);
    int getLocationsSize();
    Location* getLocation(int id);
    int getChauffeursSize();
    Chauffeur* getChauffeur(int id);
    Parc* getParcByVeh(std::string immat);
};

#endif // APPLICATION_H
