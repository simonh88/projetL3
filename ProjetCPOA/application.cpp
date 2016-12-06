#include "application.h"
#include "lesclients.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include "vehicule.h"
#include "voiture.h"
#include "velo.h"
#include "bus.h"

using namespace std;

Application::Application()
{
    this->loadData();
}




//--------------------------------------- LOADER --------------------------------------------------

bool Application::to_bool(std::string &s) {
     return s != "0";
}

void Application::loadData(){
    this->loadClients();
    this->loadVehicules();
    this->loadChauffeurs();
    this->loadParcs();
}

void Application::loadClients(){

    ifstream fichier("clients.txt", ios::in);

    if(fichier)
    {
        string ligne;
        while(getline(fichier, ligne))
        {
            //cout << ligne << endl;
            stringstream ss(ligne);
            string client_Id,client_Nom,client_Prenom,client_Adresse;

            getline(ss,client_Id, ';');
            getline(ss,client_Nom, ';');
            getline(ss,client_Prenom, ';');
            getline(ss,client_Adresse, ';');

            //cout << "id : " <<client_Id<< " - nom : " <<client_Nom<< " - prenom : " <<client_Prenom<< " - adresse : " <<client_Adresse<< endl;

            int id = atoi(client_Id.c_str());

            Client c(id, client_Nom, client_Prenom, client_Adresse);
            lesClients.setClient(c);

            //c.printClient();
        }
    }
    else{
        //cerr << "Impossible d'ouvrir le fichier !" << endl;
    }
}

void Application::loadVehicules(){

    ifstream fichier("vehicules.txt", ios::in);

    if(fichier)
    {
        string ligne;
        while(getline(fichier, ligne))
        {
            //cout << ligne << endl;
            stringstream ss(ligne);
            string veh_Type, veh_Immatriculation, veh_Modele, veh_EstDispo, veh_PrixJournee, veh_Extra;

            getline(ss,veh_Type, ';');
            getline(ss,veh_Immatriculation, ';');
            getline(ss,veh_Modele, ';');
            getline(ss,veh_EstDispo, ';');
            getline(ss,veh_PrixJournee, ';');
            getline(ss,veh_Extra, ';');

            bool estDispo = to_bool(veh_EstDispo);
            double prixJournee = atof(veh_PrixJournee.c_str());

            if(!veh_Type.compare("Voiture")){
                int nbPlaces = atoi(veh_Extra.c_str());
                Voiture veh(veh_Immatriculation, veh_Modele, nbPlaces, estDispo, prixJournee);
                lesVehicules.setVehicule(veh);
            }
            if(!veh_Type.compare("Bus")){
                int nbPlaces = atoi(veh_Extra.c_str());
                Bus veh(veh_Immatriculation, veh_Modele, nbPlaces, estDispo, prixJournee);
                lesVehicules.setVehicule(veh);
            }
            if(!veh_Type.compare("Velo")){
                bool assist = to_bool(veh_Extra);
                Velo veh(veh_Immatriculation, veh_Modele, estDispo, prixJournee, assist);
                lesVehicules.setVehicule(veh);
            }

        }
    }
    else{
        //cerr << "Impossible d'ouvrir le fichier !" << endl;
    }
}

void Application::loadChauffeurs(){

    ifstream fichier("chauffeurs.txt", ios::in);

    if(fichier)
    {
        string ligne;
        while(getline(fichier, ligne))
        {
            //cout << ligne << endl;
            stringstream ss(ligne);
            string ch_Permis, ch_Nom, ch_Prenom, ch_EstDispo;

            getline(ss,ch_Permis, ';');
            getline(ss,ch_Nom, ';');
            getline(ss,ch_Prenom, ';');
            getline(ss,ch_EstDispo, ';');

            bool dispo = to_bool(ch_EstDispo);

            //cout << "Permis : " << ch_Permis << " - Nom : " << ch_Nom << " - Prenom : " << ch_Prenom << " - dispo : " << ch_EstDispo << endl ;

            Chauffeur chauffeur(ch_Permis, ch_Nom, ch_Prenom, dispo);
            lesChauffeurs.addChauffeur(chauffeur);
        }
    }
    else{
        //cerr << "Impossible d'ouvrir le fichier !" << endl;
    }
}

void Application::loadParcs(){

    ifstream fichier("parcs.txt", ios::in);

    if(fichier)
    {
        string ligne;
        while(getline(fichier, ligne))
        {
            //cout << ligne << endl;
            stringstream ss(ligne);
            string parc_Nom, parc_Adresse, parc_NbPlaces;

            getline(ss,parc_Nom, ';');
            getline(ss,parc_Adresse, ';');
            getline(ss,parc_NbPlaces, ';');

            int nbPlaces = atoi(parc_NbPlaces.c_str());

            cout << "Nom : " << parc_Nom << " - Adresse : " << parc_Adresse << " - nbPlaces : " << nbPlaces << endl ;

            Parc parc(parc_Nom, parc_Adresse, nbPlaces);
            lesParcs.addParc(&parc);
        }
    }
    else{
        //cerr << "Impossible d'ouvrir le fichier !" << endl;
    }
}


//--------------------------------------- ADDER --------------------------------------------------


void Application::addVehicule(Vehicule veh, int extra, int idParc)
{
    Parc parc = lesParcs.getParc(idParc);

    cout << "adr getParc : " << &parc << endl;

    parc.setVehicule(veh);


    ofstream fichier("vehicules.txt", ios::out | ios::app);

    if(fichier){

        fichier << veh.getType() <<";"<< veh.getImmatriculation() <<";"<< veh.getModele() <<";"<< veh.getEstDispo() <<";"<< veh.getPrixJournee() <<";"<< extra << endl;

        fichier.flush();
        fichier.close();
    }
    else{
        cerr << "Erreur à l'ouverture !" << endl;
    }
}

void Application::addClient(std::string &client_Nom, std::string &client_Prenom, std::string &client_Adresse)
{
    int id = lesClients.getSize()+1;//Pour gerer quand c'est 0 et donc que le client n'existe pas
    Client c(id, client_Nom, client_Prenom, client_Adresse);
    lesClients.setClient(c);

    ofstream fichier("clients.txt", ios::out | ios::app);

    if(fichier){

        fichier << id <<";"<< client_Nom <<";"<< client_Prenom <<";"<< client_Adresse << endl;

        fichier.flush();
        fichier.close();
    }
    else{
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

void Application::addParc(Parc* parc)
{
    std::cout << "adr addParc : " << parc << std::endl;

    lesParcs.addParc(parc);

    afficherParcs();

    ofstream fichier("parcs.txt", ios::out | ios::app);

    if(fichier){

        fichier << parc->getNom() <<";"<< parc->getAdresse() <<";"<< parc->getNbPlaces() << endl;

        fichier.flush();
        fichier.close();
    }
    else{
        cerr << "Erreur à l'ouverture !" << endl;
    }
}

void Application::addChauffeur(Chauffeur chauffeur)
{
    lesChauffeurs.addChauffeur(chauffeur);

    afficherChauffeurs();

    ofstream fichier("chauffeurs.txt", ios::out | ios::app);

    if(fichier){

        fichier << chauffeur.getNoPermis() <<";"<< chauffeur.getNom() <<";"<< chauffeur.getPrenom() <<";"<< chauffeur.getDispo() << endl;

        fichier.flush();
        fichier.close();
    }
    else{
        cerr << "Erreur à l'ouverture !" << endl;
    }
}


//--------------------------------------- AFFICHEURS --------------------------------------------------



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



int Application::getVehiculesSize(int idParc){
    Parc parc = getParc(idParc);
    std::cout << "Nom du parc : " << parc.getNom() << std::endl;
    //parc.lesVehicules.listVehicules
    return parc.getVehiculesSize();
}

Vehicule Application::getVehiculeById(int id, int idParc){
    Parc parc = getParc(idParc);

    cout << "adr parc veh : " << &parc << endl;

    return parc.getVehicule(id);
}

int Application::getClientsSize(){
    return lesClients.getSize();
}

Client Application::getClientById(int id){
    return lesClients.getClient(id);
}

int Application::getParcsSize(){
    return lesParcs.getSize();
}

Parc Application::getParc(int id){
    return lesParcs.getParc(id);
}
