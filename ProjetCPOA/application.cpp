#include "application.h"
#include "lesclients.h"
#include <iostream>
#include <fstream>

using namespace std;

Application::Application()
{

}

void Application::addVehicule(Vehicule veh)
{
    lesVehicules.setVehicule(veh);
}

void Application::addClient(std::string &client_Nom, std::string &client_Prenom, std::string &client_Adresse)
{
    int id = lesClients.getSize()+1;//Pour gerer quand c'est 0 et donc que le client n'existe pas
    Client c(id, client_Nom, client_Prenom, client_Adresse);
    lesClients.setClient(c);

    ofstream fichier("clients.txt", ios::out | ios::app);

    if(fichier)  // si l'ouverture a réussi
    {

        std::cout << "OK à l'ouverture !" << fichier << endl;

        fichier << id <<";"<< client_Nom <<";"<< client_Prenom <<";"<< client_Adresse << endl;

        fichier.flush();
        fichier.close();
    }
    else{  // sinon
        cerr << "Erreur à l'ouverture !" << endl;
    }

}

void Application::addLocation(int &loc_idClient, std::string &loc_refBanq, Date &loc_DateDebut, int &loc_Duree, bool &loc_assist, std::string &loc_immatVeh)
{
    int id = lesLocations.getSize();
    Vehicule v = lesVehicules.getVehiculeByImmat(loc_immatVeh);
    Client c = lesClients.getClient(loc_idClient);
    Location l(id, c, loc_refBanq, loc_DateDebut, loc_Duree, loc_assist, v);
    lesLocations.addLocation(l);

    afficherLocations();
    //lesClients.setClient(c);
}

void Application::addParc(Parc parc)
{
    lesParcs.addParc(parc);

    afficherParcs();
}

void Application::addChauffeur(Chauffeur chauffeur)
{
    lesChauffeurs.addChauffeur(chauffeur);

    afficherChauffeurs();
}

void Application::afficherClients(){
    for(int i = 0; i<lesClients.getSize(); i++){
        lesClients.getClient(i).printClient();
    }
}

void Application::afficherVehicules(){
    std::cout << "\n\n      - LISTE VEHICULES :\n" << std::flush;
    for(int i = 0; i<lesVehicules.getSize(); i++){
        lesVehicules.getVehicule(i).printVehicule();
    }
}

void Application::afficherChauffeurs()
{
    std::cout << "\n\n      - LISTE CHAUFFEURS :\n" << std::flush;
    for(int i = 0; i<lesChauffeurs.getSize(); i++){
        lesChauffeurs.getChauffeur(i).printChauffeur();
    }
}

void Application::afficherLocations(){
    std::cout << "\n\n      - LISTE LOCATIONS :\n" << std::flush;
    for(int i = 0; i<lesLocations.getSize(); i++){
        lesLocations.getLocation(i).printLocation();
    }
}

void Application::afficherParcs(){
    std::cout << "\n\n      - LISTE PARCS :\n" << std::flush;
    for(int i = 0; i<lesParcs.getSize(); i++){
        lesParcs.getParc(i).printParc();
    }
}


 //==========================INUTILE======================================//
int Application::getVehiculesSize(){
    return lesVehicules.getSize();
}

Vehicule Application::getVehiculeById(int id){
    return lesVehicules.getVehicule(id);
}

int Application::getClientsSize(){
    return lesClients.getSize();
}

Client Application::getClientById(int id){
    return lesClients.getClient(id);
}
