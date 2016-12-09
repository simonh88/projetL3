#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <sstream>
#include "client.h"
#include "vehicule.h"
#include "voiture.h"
#include "velo.h"
#include "bus.h"
#include "application.h"
#include "parc.h"
#include "chauffeur.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btn_addClient, SIGNAL(clicked()), this, SLOT(form_addClient()));
    connect(ui->btn_addClient2, SIGNAL(clicked()), this, SLOT(form_addClient()));
    connect(ui->btn_addVehicule, SIGNAL(clicked()), this, SLOT(form_addVehicule()));
    connect(ui->btn_addChauffeur, SIGNAL(clicked()), this, SLOT(form_addChauffeur()));
    connect(ui->btn_addParc, SIGNAL(clicked()), this, SLOT(form_addParc()));
    connect(ui->btn_addLocation, SIGNAL(clicked()), this, SLOT(form_addLocation()));


    connect(ui->valid_addClient, SIGNAL(clicked()), this, SLOT(valid_addClient()));

    connect(ui->valid_addVehicule, SIGNAL(clicked()), this, SLOT(valid_addVehicule()));
    //---------Attachement des fonctions aux groupes de boutons---------/
    connect(ui->choixTypeVeh, SIGNAL(buttonClicked(int)), this, SLOT(select_typeVeh(int))) ;
    connect(ui->choixLocVeh, SIGNAL(buttonClicked(int)), this, SLOT(select_locVeh(int)));

    //----------------MAJ PRIX DANS LOCATIONS----------------------------------//
    connect(ui->add_locDuree, SIGNAL(valueChanged(int)), this, SLOT(majPrixLoc()));
    connect(ui->add_locVehicule, SIGNAL(currentIndexChanged(int)), this, SLOT(majPrixLoc()));


    connect(ui->valid_addLocation, SIGNAL(clicked()), this, SLOT(refresh_ListVehAfterValid()));

    connect(ui->add_locParc, SIGNAL(currentIndexChanged(int)), this, SLOT(select_parc(int)));

    connect(ui->valid_addLocation, SIGNAL(clicked()), this, SLOT(valid_addLocation()));
    connect(ui->valid_addParc, SIGNAL(clicked()), this, SLOT(valid_addParc()));
    connect(ui->valid_addChauffeur, SIGNAL(clicked()), this, SLOT(valid_addChauffeur()));

    this->refresh();
}

MainWindow::~MainWindow()
{
    delete ui;
}



//----------------------- REFRESH --------------------------------


void MainWindow::refresh(){
    this->refresh_ListVeh("0", -1);
    this->refresh_ListClient();
    this->refresh_ListParc();
}

void MainWindow::refresh_ListVehAfterValid(){
    int idParc = ui->add_locParc->currentIndex();
    select_parc(idParc);
}

//Si on envoi null au type de vehicule alors on ajoute tout les vehicules
//Sinon c'est soit Velo soit Bus soit Voiture
//Attention aux majs
void MainWindow::refresh_ListVeh(std::string typeVehicule, int idParc){
    //Vehicule = 0 TOUT LES VEHICULES
    //Vehicule = 1 VOITURES
    //Vehicule = 2 BUS
    //Vehicule = 3 VELO
    QComboBox *listVeh = ui->add_locVehicule;

    listVeh->clear();

    //std::cout << "refresh_ListVeh" << std::endl;

    if(idParc >= 0){

        //std::cout << "On refresh les vehicules dans location : " << std::endl;
        //std::cout << "Size du parc :  "<< application.getVehiculesSize(idParc) << std::endl;

        for(int i=0; i<application.getVehiculesSize(idParc);i++){
            Vehicule* veh = application.getVehiculeById(i, idParc);
            if(veh->getEstDispo()){
               if(typeVehicule.empty()){
                   listVeh->addItem(QString::fromStdString(veh->getModele()), QString::fromStdString(veh->getImmatriculation()));
               }else if(veh->getType().compare(typeVehicule) == 0){
                   QDate dateDebut = ui->add_locDateDebut->date();
                   std::string strDate = dateDebut.toString("dd/MM/yyyy").toStdString();
                   Date d(strDate);
                   int j = 0;
                   bool dispo = true;
                   while(j<veh->getSizeIndispo()){
                        if(!veh->getPeriode(j)->estDispo(d)){
                            dispo = false;
                        }
                        j++;
                   }
                   if(dispo){
                        listVeh->addItem(QString::fromStdString(veh->getModele()), QString::fromStdString(veh->getImmatriculation()));
                   }
               }
            }
        }
    }
}

void MainWindow::refresh_ListClient(){
    QComboBox *listClient = ui->add_locClient;

    listClient->clear();

    for(int i=0; i<application.getClientsSize();i++){
        Client* client = application.getClientById(i);

        listClient->addItem(QString::fromStdString(client->getNom()+" "+client->getPrenom()), QString::number(client->getIdClient()));
    }
}


void MainWindow::refresh_ListParc(){
    //Dans la frame des vehicules
    QComboBox *listParc = ui->add_vehParc;
    listParc->clear();
    //Dans la frame des locations
    QComboBox *listParc2 = ui->add_locParc;
    listParc2->clear();

    for(int i = 0; i<application.getParcsSize(); i++){
        Parc* parc = application.getParc(i);
        listParc2->addItem(QString::fromStdString(parc->getNom()), QString::number(i));
        listParc->addItem(QString::fromStdString(parc->getNom()), QString::number(i));
    }
}

//----------- VALIDATION FORMULAIRE CHAUFFEUR --------------------

void MainWindow::valid_addChauffeur(){
    QString nom = ui->add_chauffeurNom->toPlainText();
    QString prenom = ui->add_chauffeurPrenom->toPlainText();
    //QString adresse = ui->add_chauffeurAdresse->toPlainText();
    //QString mail = ui->add_chauffeurMail->toPlainText();
    //QString = ui->add_chauffeurNaissance
    bool dispo = ui->add_chauffeurDispo->isChecked();
    QString permis = ui->add_chauffeurPermis->toPlainText();

    bool check = true;
    if(nom.trimmed().isEmpty()){
        check = false;
    }
    if(prenom.trimmed().isEmpty()){
        check = false;
    }
    if(permis.trimmed().isEmpty()){
        check = false;
    }

    if(check){
        std::string nomstr = nom.toStdString();
        std::string prenomstr = prenom.toStdString();
        std::string permisstr = permis.toStdString();

    //std::cout << "Dispo :  "<< dispo << std::flush;
        Chauffeur* chauffeur = new Chauffeur(permisstr, nomstr, prenomstr, dispo);
        application.addChauffeur(chauffeur);

        ui->add_chauffeurMail->setText("");
        ui->add_chauffeurAdresse->setText("");
        ui->add_chauffeurNom->setText("");
        ui->add_chauffeurPrenom->setText("");
        ui->add_chauffeurPermis->setText("");
    }

}


//----------- VALIDATION FORMULAIRE PARC -------------------------

void MainWindow::valid_addParc(){
    QString nom = ui->add_parcNom->toPlainText();
    QString adresse = ui->add_parcAdresse->toPlainText();
    int nbPlaces = ui->add_parcPlaces->value();

    bool check = true;
    if(nom.trimmed().isEmpty()){
        check = false;
    }
    if(adresse.trimmed().isEmpty()){
        check = false;
    }

    if(check){
        std::string nomstr = nom.toStdString();
        std::string adressestr = adresse.toStdString();
        Parc* parc = new Parc(nomstr, adressestr, nbPlaces);

        //std::cout << "adr create Parc : " << parc << std::endl;

        application.addParc(parc);
        ui->add_parcAdresse->setText("");
        ui->add_parcNom->setText("");
        ui->add_parcPlaces->setValue(0);
        refresh_ListParc();
    }

}


//----------- VALIDATION FORMULAIRE CLIENT ------------------------




void MainWindow::valid_addClient(){
    QString nom = ui->add_clientNom->toPlainText();
    QString prenom = ui->add_clientPrenom->toPlainText();
    QString adresse = ui->add_clientAdresse->toPlainText();
    QDate dateNaissance = ui->add_clientNaissance->date();
    //QString naissance = ui->add_clientNaissance->date().toString("dd MM yyyy");
    QString mail = ui->add_clientMail->toPlainText();
    QString permis = ui->add_clientPermis->toPlainText();

    bool check = true;

    if(nom.trimmed().isEmpty()){
        check = false;
    }

    if(prenom.trimmed().isEmpty()){
        check = false;
    }

    if(adresse.trimmed().isEmpty()){
        check = false;
    }

    /*if(dateNaissance.operator >(QDate::currentDate())){
        check = false;
    }

    if(mail.trimmed().isEmpty()){
        check = false;
    }

    if(permis.trimmed().isEmpty()){
        check = false;
    }*/

    if(check){
        //std::cout << "form addClient OK\n\n" << std::flush;

        std::string client_Nom = nom.toStdString();
        std::string client_Prenom = prenom.toStdString();
        std::string client_Adresse = adresse.toStdString();
        /*Client c(client_Nom, client_Prenom, client_Adresse);*/

        //c.printClient();
        application.addClient(client_Nom, client_Prenom, client_Adresse);
        //application.afficherClients();

        ui->add_clientNom->setText("");
        ui->add_clientPrenom->setText("");
        ui->add_clientAdresse->setText("");
        ui->add_clientMail->setText("");
        ui->add_clientPermis->setText("");

        //Redirection sur l'index acceuil a voir si on rajoute message ou non
        ui->tabWidget->setCurrentIndex(0);
        this->refresh();
    }

    //std::cout << naissance.toStdString() << std::flush;
}




//----------- VALIDATION FORMULAIRE VEHICULE ------------------------




void MainWindow::valid_addVehicule(){
    //std::cout << "form addVeh\n\n" << std::flush;

    int idParc = ui->add_vehParc->currentData().toInt();
    QString immat = ui->add_vehImmat->toPlainText();
    QString modele = ui->add_vehModele->toPlainText();
    QDate dateCT = ui->add_vehCT->date();
    int nbPlaces = ui->add_vehPlaces->value();
    double prixJournee = ui->add_vehPrix->value();
    bool assistElec = ui->add_vehAssistElec->isChecked();
    int typeVeh = ui->choixTypeVeh->checkedId();
    bool estDispo = ui->add_vehDispo->isChecked();

    bool check = true;

    if(immat.trimmed().isEmpty()) check = false;
    if(modele.trimmed().isEmpty()) check = false;
    if(prixJournee == 0.00) check = false;
    std::string strImmatriculation = immat.toStdString();
    std::string strModele = modele.toStdString();

    switch(typeVeh)
    {
        case -3: //VOITURE
         {
            //std::cout << "form addVeh voiture ok\n\n" << std::flush;

            Voiture* v = new Voiture(strImmatriculation, strModele, nbPlaces, estDispo, prixJournee);
            application.addVehicule(v, nbPlaces, idParc);

            //Instanciation nouvelle voiture
        }
        break;
        case -2: //BUS
        {
            //std::cout << "form addVeh bus ok\n\n" << std::flush;
            Bus* b = new Bus(strImmatriculation, strModele, nbPlaces, estDispo, prixJournee);
            application.addVehicule(b, nbPlaces, idParc);
        }
        break;
        case -4: //VELO
        {
            //std::cout << "form addVeh velo ok\n\n" << std::flush;

            Velo* v = new Velo(strImmatriculation, strModele, estDispo, prixJournee, assistElec);
            application.addVehicule(v, assistElec, idParc);

        }
        break;
        default:
        {
            //std::cout << "form addVeh choix veh a faire\n\n" << std::flush;
            check = false;
        }
        break;
    }

   //application.afficherVehicules();
   ui->add_vehModele->setText("");
   ui->add_vehImmat->setText("");
   ui->add_vehPlaces->setValue(0);
   ui->add_vehPrix->setValue(0);

   //this->refresh_ListVeh();

}

void MainWindow::select_locVeh(int typeVeh){
    ui->add_locVehicule->setEnabled(true);
    int idParc = ui->add_locParc->currentIndex();

    //std::cout << "select_parc IDPARC : " << idParc << std::endl;
    //std::cout << "select_parc TYPE VEH : " << typeVeh << std::endl;

    select_locVeh2(typeVeh, idParc);
}


void MainWindow::select_locVeh2(int id, int idParc){
    //std::cout << id <<std::flush;
    // id -2 : Voiture
    // id -3 : Bus
    // id -4 : Vélo

    //std::cout << "select_locVeh2 : " << id << " | " << idParc << std::endl;

    switch(id){
    case -2://Voiture
        refresh_ListVeh("Voiture", idParc);
        break;
    case -3://Bus
        refresh_ListVeh("Bus", idParc);
        break;
    case -4://Vélo
        refresh_ListVeh("Velo", idParc);
        break;
    }
}

void MainWindow::select_typeVeh(int id){
    // id -3 : voiture
    // id -2 : bus
    // id -4 : velo

    if(id==-3){
        //std::cout << "Voiture choisie\n" << std::flush;
        ui->add_vehModele->setEnabled(true);
        ui->add_vehImmat->setEnabled(true);
        ui->add_vehCT->setEnabled(true);
        ui->add_vehPrix->setEnabled(true);
        ui->add_vehPlaces->setEnabled(true);
        ui->add_vehDispo->setEnabled(true);
        ui->add_vehAssistElec->setEnabled(false);
        ui->valid_addVehicule->setEnabled(true);
    }
    if(id==-2){
        //std::cout << "Bus choisi\n" << std::flush;
        ui->add_vehModele->setEnabled(true);
        ui->add_vehImmat->setEnabled(true);
        ui->add_vehCT->setEnabled(true);
        ui->add_vehPrix->setEnabled(true);
        ui->add_vehPlaces->setEnabled(true);
        ui->add_vehDispo->setEnabled(true);
        ui->add_vehAssistElec->setEnabled(false);
        ui->valid_addVehicule->setEnabled(true);
    }
    if(id==-4){
        //std::cout << "Vélo choisi\n" << std::flush;
        ui->add_vehModele->setEnabled(true);
        ui->add_vehImmat->setEnabled(true);
        ui->add_vehCT->setEnabled(false);
        ui->add_vehPrix->setEnabled(true);
        ui->add_vehPlaces->setEnabled(false);
        ui->add_vehDispo->setEnabled(true);
        ui->add_vehAssistElec->setEnabled(true);
        ui->valid_addVehicule->setEnabled(true);
    }
    //std::cout << "c'est id : " << id << " qui a été cliqué\n" << std::flush;
}

//Appelée quand pendant la location, on a choisi la location
void MainWindow::select_parc(int idParc){
    ui->add_locVehicule->setEnabled(true);
    int typeVeh = ui->choixLocVeh->checkedId();

    //std::cout << "select_parc IDPARC : " << idParc << std::endl;
    //std::cout << "select_parc TYPE VEH : " << typeVeh << std::endl;

    select_locVeh2(typeVeh, idParc);
}


//----------- VALIDATION FORMULAIRE LOCATION ------------------------



void MainWindow::majPrixLoc(){
    QString immatVeh = ui->add_locVehicule->currentData().toString();
    std::string vehicule = immatVeh.toStdString();

    if(!vehicule.empty()){
        int idParc = ui->add_locParc->currentData().toInt();
        int duree = ui->add_locDuree->value();
        Vehicule* v = application.getParc(idParc)->getVehiculeByImmat(vehicule);
        int prix = v->getPrixJournee() * duree;
        std::ostringstream oss;
        oss << prix;
        std::string message = "<b>Prix : " + oss.str() + " euros</b>" ;
        ui->label_locPrix->setText(QString::fromStdString(message));
    }else{
        ui->label_locPrix->setText("Prix : 0 euros");
    }
}


void MainWindow::valid_addLocation(){
    //std::cout << "form addLocation\n\n" << std::flush;

    int idClient = ui->add_locClient->currentData().toInt()-1;
    QString refBanq = ui->add_locRefBanq->toPlainText();
    QDate dateDebut = ui->add_locDateDebut->date();
    int duree = ui->add_locDuree->value();
    //int typeVeh = ui->choixTypeVeh->checkedId();
    bool assist = ui->add_locAssist->isChecked();
    QString immatVeh = ui->add_locVehicule->currentData().toString();

    bool check = true;

    if(refBanq.trimmed().isEmpty()){
        check = false;
    }
    if(immatVeh.trimmed().isEmpty()){
        check = false;
    }
    if(idClient == 0){
        check = false;
    }
    if(duree == 0){
        check = false;
    }

    std::string strDate = dateDebut.toString("dd/MM/yyyy").toStdString();
    Date d(strDate);
    std::string refBanqstr = refBanq.toStdString();
    std::string immatVehstr = immatVeh.toStdString();
    application.addLocation(idClient, refBanqstr, d, duree, assist, immatVehstr);

    ui->add_locAssist->setChecked(false);
    ui->add_locBus->setChecked(false);
    ui->add_locVelo->setChecked(false);
    ui->add_locVoiture->setChecked(false);
    ui->add_locRefBanq->setText("");
    ui->add_locDuree->setValue(0);

}




//----------- LIENS ENTRE BOUTONS ET ONGLETS ------------------------





void MainWindow::form_addClient(){
    ui->tabWidget->setCurrentIndex(1);
}

void MainWindow::form_addVehicule(){

    ui->tabWidget->setCurrentIndex(2);
}

void MainWindow::form_addChauffeur(){

    ui->tabWidget->setCurrentIndex(3);
}

void MainWindow::form_addParc(){

    ui->tabWidget->setCurrentIndex(4);
}

void MainWindow::form_addLocation(){
    ui->tabWidget->setCurrentIndex(5);
}
