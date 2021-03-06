#include "application.h"
#include "lesclients.h"
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <QMessageBox>
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
    this->loadChauffeurs();
    this->loadParcs();
    this->loadVehicules();
    this->loadIndispoVeh();
    this->loadLocations();
    this->loadCtrlVehic();
    this->loadCtrlChauff();
}

void Application::loadClients(){

    ifstream fichier("../ProjetCPOA/data/clients.txt", ios::in);

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

            Client* c = new Client(id, client_Nom, client_Prenom, client_Adresse);
            lesClients.setClient(c);

            //c.printClient();
        }
    }
    else{
        //cerr << "Impossible d'ouvrir le fichier !" << endl;
    }
}

void Application::loadVehicules(){

    ifstream fichier("../ProjetCPOA/data/vehicules.txt", ios::in);

    if(fichier)
    {
        string ligne;
        while(getline(fichier, ligne))
        {
            //cout << ligne << endl;
            stringstream ss(ligne);
            string veh_Type, veh_Immatriculation, veh_Modele, veh_EstDispo, veh_PrixJournee, veh_Extra, veh_IdParc;

            getline(ss,veh_Type, ';');
            getline(ss,veh_Immatriculation, ';');
            getline(ss,veh_Modele, ';');
            getline(ss,veh_EstDispo, ';');
            getline(ss,veh_PrixJournee, ';');
            getline(ss,veh_Extra, ';');
            getline(ss,veh_IdParc, ';');

            bool estDispo = to_bool(veh_EstDispo);
            double prixJournee = atof(veh_PrixJournee.c_str());
            int idParc = atoi(veh_IdParc.c_str());

            if(!veh_Type.compare("Voiture")){

                int nbPlaces = atoi(veh_Extra.c_str());

                Voiture* veh = new Voiture(veh_Immatriculation, veh_Modele, nbPlaces, estDispo, prixJournee);
                lesVehicules.setVehicule(veh);

                lesParcs.getParc(idParc)->setVehicule(veh);

            }
            if(!veh_Type.compare("Bus")){

                int nbPlaces = atoi(veh_Extra.c_str());

                Bus* veh = new Bus(veh_Immatriculation, veh_Modele, nbPlaces, estDispo, prixJournee);
                lesVehicules.setVehicule(veh);

                lesParcs.getParc(idParc)->setVehicule(veh);
            }
            if(!veh_Type.compare("Velo")){

                bool assist = to_bool(veh_Extra);

                Velo* veh = new Velo(veh_Immatriculation, veh_Modele, estDispo, prixJournee, assist);
                lesVehicules.setVehicule(veh);

                lesParcs.getParc(idParc)->setVehicule(veh);
            }

            //cout << "size parc : " << lesParcs.getParc(idParc)->getVehiculesSize() << endl;

        }
    }
    else{
        //cerr << "Impossible d'ouvrir le fichier !" << endl;
    }
}

void Application::loadChauffeurs(){

    ifstream fichier("../ProjetCPOA/data/chauffeurs.txt", ios::in);

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

            Chauffeur* chauffeur = new Chauffeur(ch_Permis, ch_Nom, ch_Prenom, dispo);
            lesChauffeurs.addChauffeur(chauffeur);
        }
    }
    else{
        //cerr << "Impossible d'ouvrir le fichier !" << endl;
    }
}

void Application::loadParcs(){

    ifstream fichier("../ProjetCPOA/data/parcs.txt", ios::in);

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

            //cout << "Nom : " << parc_Nom << " - Adresse : " << parc_Adresse << " - nbPlaces : " << nbPlaces << endl ;

            Parc* parc = new Parc(parc_Nom, parc_Adresse, nbPlaces);
            lesParcs.addParc(parc);
        }
    }
    else{
        //cerr << "Impossible d'ouvrir le fichier !" << endl;
    }
}

void Application::loadIndispoVeh(){
    ifstream fichier("../ProjetCPOA/data/indispoVeh.txt", ios::in);

    if(fichier)
    {
        string ligne;
        while(getline(fichier, ligne))
        {
            //cout << ligne << endl;
            stringstream ss(ligne);
            string immatVeh, strDateDebut, strDateFin;

            getline(ss,immatVeh, ';');
            getline(ss,strDateDebut, ';');
            getline(ss,strDateFin, ';');

            Date dateDebut(strDateDebut);
            Date dateFin(strDateFin);

            Periode* p = new Periode(dateDebut, dateFin);

            Vehicule* v = lesVehicules.getVehiculeByImmat(immatVeh);

            v->addIndispo(p);
        }
    }
    else{
        //cerr << "Impossible d'ouvrir le fichier !" << endl;
    }
}

void Application::loadLocations(){
    ifstream fichier("../ProjetCPOA/data/locations.txt", ios::in);

    if(fichier)
    {
        string ligne;
        while(getline(fichier, ligne))
        {
            //cout << ligne << endl;
            stringstream ss(ligne);
            string strIdLocation, strIdClient, refBanq, strDateDebut, strDuree, strAssist, immatVeh;

            getline(ss,strIdLocation, ';');
            getline(ss,strIdClient, ';');
            getline(ss,refBanq, ';');
            getline(ss,strDateDebut, ';');
            getline(ss,strDuree, ';');
            getline(ss,strAssist, ';');
            getline(ss,immatVeh, ';');

            Date dateDebut(strDateDebut);
            int idLocation = atoi(strIdLocation.c_str());
            int idClient = atoi(strIdClient.c_str());
            int duree = atoi(strDuree.c_str());
            bool assist = to_bool(strAssist);

            Client* c = lesClients.getClient(idClient);
            Vehicule* v = lesVehicules.getVehiculeByImmat(immatVeh);
            Location* l = new Location(idLocation, c, refBanq, dateDebut, duree, assist, v);

            generateLocation(l);

            lesLocations.addLocation(l);
        }
    }
    else{
        //cerr << "Impossible d'ouvrir le fichier !" << endl;
    }
}

void Application::loadCtrlVehic(){
    ifstream fichier("../ProjetCPOA/data/ctrlVehic.txt", ios::in);

    if(fichier)
    {
        string ligne;
        while(getline(fichier, ligne))
        {
            //cout << ligne << endl;
            stringstream ss(ligne);
            string immat, strDateDebut, strDateFin;

            getline(ss,immat, ';');
            getline(ss,strDateDebut, ';');
            getline(ss,strDateFin, ';');

            Date dateDebut(strDateDebut);
            Date dateFin(strDateFin);

            Periode* p = new Periode(dateDebut,dateFin);
            Vehicule* v = getVehiculeByImmat(immat);
            v->addIndispo(p);

            ControleVehicule* cv = new ControleVehicule(immat,p);
            lesControlesVehicules.addControleVehicule(cv);

            //---AFFICHAGE cv->afficherControle();

        }
    }
    else{
        //cerr << "Impossible d'ouvrir le fichier !" << endl;
    }
}

void Application::loadCtrlChauff(){
    ifstream fichier("../ProjetCPOA/data/ctrlChauff.txt", ios::in);

    if(fichier)
    {
        string ligne;
        while(getline(fichier, ligne))
        {
            //cout << ligne << endl;
            stringstream ss(ligne);
            string idstr, strDateDebut, strDateFin;

            getline(ss,idstr, ';');
            getline(ss,strDateDebut, ';');
            getline(ss,strDateFin, ';');

            int id = atoi(idstr.c_str());
            Date dateDebut(strDateDebut);
            Date dateFin(strDateFin);

            Periode* p = new Periode(dateDebut,dateFin);
            Chauffeur* c = getChauffeur(id);
            c->addIndispo(p);

            ControleChauffeur* cc = new ControleChauffeur(id,p);
            lesControlesChauffeurs.addControleChauffeur(cc);

            //---AFFICHAGE cc->afficherControle();

        }
    }
    else{
        //cerr << "Impossible d'ouvrir le fichier !" << endl;
    }
}


//--------------------------------------- ADDER --------------------------------------------------


void Application::addVehicule(Vehicule* veh, int extra, int idParc)
{
    Parc* parc = lesParcs.getParc(idParc);

    //cout << "idParc: " << idParc << endl;
    //cout << "addVehicule adr getParc : " << parc << endl;
    //cout << "Parc name : " << parc->getNom() << endl;

    //cout << "Parc Size avant : " << parc->getVehiculesSize() << endl;
    parc->setVehicule(veh);
    //cout << "Parc Size apres : " << parc->getVehiculesSize() << endl;




    ofstream fichier("../ProjetCPOA/data/vehicules.txt", ios::out | ios::app);

    if(fichier){

        fichier << veh->getType() <<";"<< veh->getImmatriculation() <<";"<< veh->getModele() <<";"<< veh->getEstDispo() <<";"<< veh->getPrixJournee() <<";"<< extra <<";"<< idParc << endl;

        fichier.flush();
        fichier.close();
    }
    else{
        //cerr << "Erreur à l'ouverture !" << endl;
    }
}

void Application::addClient(std::string &client_Nom, std::string &client_Prenom, std::string &client_Adresse)
{
    int id = lesClients.getSize()+1;//Pour gerer quand c'est 0 et donc que le client n'existe pas
    Client* c = new Client(id, client_Nom, client_Prenom, client_Adresse);
    lesClients.setClient(c);

    ofstream fichier("../ProjetCPOA/data/clients.txt", ios::out | ios::app);

    if(fichier){

        fichier << id <<";"<< client_Nom <<";"<< client_Prenom <<";"<< client_Adresse << endl;

        fichier.flush();
        fichier.close();
    }
    else{
        //cerr << "Erreur à l'ouverture !" << endl;
    }

}

void Application::addLocation(int &loc_idClient, std::string &loc_refBanq, Date &loc_DateDebut, int &loc_Duree, bool &loc_assist, std::string &loc_immatVeh, std::string &loc_prix)
{
    int id = lesLocations.getSize();
    Vehicule* v = lesVehicules.getVehiculeByImmat(loc_immatVeh);
    Date dateFin = loc_DateDebut.ajouter(loc_Duree-1);
    Periode* p = new Periode(loc_DateDebut,dateFin);
    v->addIndispo(p);
    //v->afficherIndispo();

    Date d = loc_DateDebut.ajouter(0);
    bool fin = false;
    //On vérifie que le client veut une assistance
    if(loc_assist == 1){
        int i =0;


        bool dispo;
        std::cout << lesChauffeurs.getSize() << std::flush;
        //Boucle permettant de parcourir la liste des chauffeurs et de savoir si on en a trouvé un dispo
        while(i < lesChauffeurs.getSize() && fin==false){
            int j = 0;
            Chauffeur* chauf = lesChauffeurs.getChauffeur(i);
            dispo=true;
            //Boucle permettant de parcourir la liste d'indispo
            //Pour savoir si le chauffeur est dispo
            while(j < chauf->getSizeIndispo() && dispo == true){
                //Si la durée est 1 : On regarde si le chauffeur est dispo a la date prévue
                if(loc_Duree == 1){
                    if(!chauf->getPeriode(j)->estDispo(d)){
                        dispo = false;
                    }
                    //Si la durée est supérieur a 1 : on parcourir la liste et on regarde s'il est dispo tous les jours
                }else{
                    for(int k = 0 ; k < loc_Duree ; k++){
                        if(!chauf->getPeriode(j)->estDispo(d)){
                            dispo = false;
                        }
                        d = d.ajouter(1);
                    }
                }
                j++;
            }
            if(dispo == true){
                chauf->addIndispo(p);
                fin = true;
            }
            i++;
        }
        //Si on a pas trouvé de chauffeur dispo
        if(fin == false && dispo == false){
            QMessageBox messageBox;
            messageBox.critical(0,"Error","Aucun chauffeur disponible pour la periode demande. Votre location ne sera pas enregistrée.");
            messageBox.setFixedSize(500,200);
            std::cout << "Aucun chauffeur disponible pour la periode demande" << std::flush;
        }
    }

    bool locOk = false;
    if(loc_assist ==0){
        //v->setEstDispo(false);// On rend le vehicule indisponible
        Client* c = lesClients.getClient(loc_idClient);
        Location* l = new Location(id, c, loc_refBanq, loc_DateDebut, loc_Duree, loc_assist, v);
        lesLocations.addLocation(l);
       //---AFFICHAGE  afficherLocations();

        generateLocation(l);

        //lesClients.setClient(c);
        locOk = true;
    }else{
        if(fin == true){
            Client* c = lesClients.getClient(loc_idClient);
            Location* l = new Location(id, c, loc_refBanq, loc_DateDebut, loc_Duree, loc_assist, v);
            lesLocations.addLocation(l);
            //---AFFICHAGE afficherLocations();

            generateLocation(l);

            locOk = true;
        }
    }


    if(locOk == 1){
        ofstream fichier("../ProjetCPOA/data/locations.txt", ios::out | ios::app);

        std::string strDateDebut = loc_DateDebut.toString();

        if(fichier){

            fichier << id <<";"<< loc_idClient <<";"<< loc_refBanq <<";"<< strDateDebut <<";"<< loc_Duree <<";"<< loc_assist <<";"<< loc_immatVeh <<";"<< loc_prix << endl;

            fichier.flush();
            fichier.close();
        }


        ofstream fichier2("../ProjetCPOA/data/indispoVeh.txt", ios::out | ios::app);

        std::string strDateDebut2 = loc_DateDebut.toString();
        std::string strDateFin = dateFin.toString();

        if(fichier){

            fichier << loc_immatVeh <<";"<< strDateDebut2 <<";"<< strDateFin << endl;

            fichier.flush();
            fichier.close();
        }
    }
}

void Application::addParc(Parc* parc)
{
    //std::cout << "adr addParc : " << parc << std::endl;

    lesParcs.addParc(parc);

    //---AFFICHAGE afficherParcs();

    ofstream fichier("../ProjetCPOA/data/parcs.txt", ios::out | ios::app);

    if(fichier){

        fichier << parc->getNom() <<";"<< parc->getAdresse() <<";"<< parc->getNbPlaces() << endl;

        fichier.flush();
        fichier.close();
    }
    else{
        //cerr << "Erreur à l'ouverture !" << endl;
    }
}

void Application::addChauffeur(Chauffeur* chauffeur)
{
    lesChauffeurs.addChauffeur(chauffeur);

    //---AFFICHAGE afficherChauffeurs();

    ofstream fichier("../ProjetCPOA/data/chauffeurs.txt", ios::out | ios::app);

    if(fichier){

        fichier << chauffeur->getNoPermis() <<";"<< chauffeur->getNom() <<";"<< chauffeur->getPrenom() <<";"<< chauffeur->getDispo() << endl;

        fichier.flush();
        fichier.close();
    }
    else{
        //cerr << "Erreur à l'ouverture !" << endl;
    }
}

void Application::addControleVehic(Date &dateDeb, Date &dateFin, Vehicule* vehic){
    Periode* p = new Periode(dateDeb,dateFin);
    vehic->addIndispo(p);
    std::string immatVehic = vehic->getImmatriculation();
    ControleVehicule* cv = new ControleVehicule(immatVehic,p);
    //---AFFICHAGE cv->afficherControle();
    lesControlesVehicules.addControleVehicule(cv);

    ofstream fichier("../ProjetCPOA/data/ctrlVehic.txt", ios::out | ios::app);

    if(fichier){

        fichier << immatVehic <<";"<< dateDeb.toString() <<";"<< dateFin.toString() << endl;

        fichier.flush();
        fichier.close();
    }
    else{
        //cerr << "Erreur à l'ouverture !" << endl;
    }
}

void Application::addControleChauff(Date &dateDeb, Date &dateFin, Chauffeur* c, int id){
    Periode* p = new Periode(dateDeb,dateFin);
    c->addIndispo(p);

    ControleChauffeur* cc = new ControleChauffeur(id,p);
    //---AFFICHAGE cc->afficherControle();
    lesControlesChauffeurs.addControleChauffeur(cc);

    ofstream fichier("../ProjetCPOA/data/ctrlChauff.txt", ios::out | ios::app);

    if(fichier){

        fichier << id <<";"<< dateDeb.toString() <<";"<< dateFin.toString() << endl;

        fichier.flush();
        fichier.close();
    }
    else{
        //cerr << "Erreur à l'ouverture !" << endl;
    }
}


//--------------------------------------- AFFICHEURS --------------------------------------------------



void Application::afficherClients(){
    for(int i = 0; i<lesClients.getSize(); i++){
        lesClients.getClient(i)->printClient();
    }
}

void Application::afficherVehicules(){
    std::cout << "\n\n      - LISTE VEHICULES :\n" << std::flush;
    for(int i = 0; i<lesVehicules.getSize(); i++){
        lesVehicules.getVehicule(i)->printVehicule();
    }
}

void Application::afficherChauffeurs()
{
    std::cout << "\n\n      - LISTE CHAUFFEURS :\n" << std::flush;
    for(int i = 0; i<lesChauffeurs.getSize(); i++){
        lesChauffeurs.getChauffeur(i)->printChauffeur();
    }
}

void Application::afficherLocations(){
    std::cout << "\n\n      - LISTE LOCATIONS :\n" << std::flush;
    for(int i = 0; i<lesLocations.getSize(); i++){
        lesLocations.getLocation(i)->printLocation();
    }
}

void Application::afficherParcs(){
    std::cout << "\n\n      - LISTE PARCS :\n" << std::flush;
    for(int i = 0; i<lesParcs.getSize(); i++){
        lesParcs.getParc(i)->printParc();
    }
}


//---------------------------------------- GETTERS ---------------------------------------------------


int Application::getVehiculesSize(int idParc){
    Parc* parc = getParc(idParc);
    //std::cout << "Nom du parc : " << parc->getNom() << std::endl;
    //parc.lesVehicules.listVehicules
    return parc->getVehiculesSize();
}

Vehicule* Application::getVehiculeById(int id, int idParc){
    Parc* parc = getParc(idParc);

    //cout << "adr parc veh : " << &parc << endl;

    return parc->getVehicule(id);
}

Vehicule* Application::getVehiculeByImmat(std::string immatVeh){
    return lesVehicules.getVehiculeByImmat(immatVeh);
}

int Application::getClientsSize(){
    return lesClients.getSize();
}

Client* Application::getClientById(int id){
    return lesClients.getClient(id);
}

int Application::getParcsSize(){
    return lesParcs.getSize();
}

Parc* Application::getParc(int id){
    return lesParcs.getParc(id);
}

int Application::getLocationsSize(){
    return lesLocations.getSize();
}

Location* Application::getLocation(int id){
    return lesLocations.getLocation(id);
}

int Application::getChauffeursSize()
{
    return lesChauffeurs.getSize();
}

Chauffeur *Application::getChauffeur(int id)
{
    return lesChauffeurs.getChauffeur(id);
}

Parc* Application::getParcByVeh(std::string immat){
    for(int i=0;i<getParcsSize();i++){
        Parc* p = getParc(i);

        if (p->containsVeh(immat)){
            return p;
        }
    }

    return getParc(0);
}


//-------------------------------------- OTHERS ---------------------------------------------

void Application::generateLocation(Location* l){

    Client* c = l->getCli();
    Vehicule* v = l->getVehic();


    std::stringstream chemin;
    chemin << "../ProjetCPOA/locations/loc_" << l->getIdLocation() << ".txt" ;

    QString path = QString::fromStdString(chemin.str());


    ofstream fichier(chemin.str().c_str(), ios::out | ios::trunc);

    if(fichier){

        fichier << "RECAPITULATIF LOCATION No : " << l->getIdLocation() << endl << endl << endl;

        fichier  << "Client :" << endl;
        fichier << "    - Id : " << c->getIdClient() << endl;
        fichier << "    - Nom : " << c->getNom() << endl;
        fichier << "    - Prenom : " << c->getPrenom() << endl;
        fichier << "    - Adresse : " << c->getAdresse() << endl << endl;

        fichier  << "Vehicule :" << endl;
        fichier << "    - Type : " << v->getType() << endl;
        fichier << "    - Modele : " << v->getModele() << endl;
        fichier << "    - Immatriculation :" << v->getImmatriculation() << endl;
        fichier << "    - Prix Journée : " << v->getPrixJournee() << endl << endl;

        fichier  << "Location :" << endl;
        fichier << "    - Id : " << l->getIdLocation() << endl;
        fichier << "    - Mode de Paiement : " << l->getModePaiement() << endl;
        fichier << "    - Date Début : " << l->getDateDebut().toString() << endl;
        fichier << "    - Date Fin : " << l->getDateFin().toString() << endl;

        //bool assist = to_bool(l->getAssistance());

        if(l->getAssistance()){
            fichier << "    - Assistance : Oui" << endl << endl;
        }

        else{
            fichier << "    - Assistance : Non" << endl;
        }


        fichier.flush();
        fichier.close();
    }
}
