#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "test.h"
#include <iostream>
#include "client.h"
#include "vehicule.h"
#include "voiture.h"
#include "velo.h"
#include "bus.h"
#include "application.h"



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
    connect(ui->choixTypeVeh, SIGNAL(buttonClicked(int)), this, SLOT(select_typeVeh(int))) ;

    connect(ui->valid_addLocation, SIGNAL(clicked()), this, SLOT(valid_addLocation()));

}

MainWindow::~MainWindow()
{
    delete ui;
}



//----------------------- REFRESH --------------------------------


void MainWindow::refresh(){
    this->refresh_ListVeh();
    this->refresh_ListClient();
}

void MainWindow::refresh_ListVeh(){
    QComboBox *listVeh = ui->add_locVehicule;

    listVeh->clear();

    for(int i=0; i<application.getVehiculesSize();i++){
        Vehicule veh = application.getVehiculeById(i);
        if(veh.getEstDispo()){
            listVeh->addItem(QString::fromStdString(veh.getModele()), QString::fromStdString(veh.getImmatriculation()));
        }
    }
}

void MainWindow::refresh_ListClient(){
    QComboBox *listClient = ui->add_locClient;

    listClient->clear();

    for(int i=0; i<application.getClientsSize();i++){
        Client client = application.getClientById(i);

        listClient->addItem(QString::fromStdString(client.getNom()+" "+client.getPrenom()), QString::number(client.getIdClient()));
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
        std::cout << "form addClient OK\n\n" << std::flush;

        std::string client_Nom = nom.toStdString();
        std::string client_Prenom = prenom.toStdString();
        std::string client_Adresse = adresse.toStdString();
        /*Client c(client_Nom, client_Prenom, client_Adresse);*/

        //c.printClient();
        application.addClient(client_Nom, client_Prenom, client_Adresse);
        application.afficherClients();

        //Redirection sur l'index acceuil a voir si on rajoute message ou non
        ui->tabWidget->setCurrentIndex(0);
        this->refresh();
;    }

    //std::cout << naissance.toStdString() << std::flush;
}




//----------- VALIDATION FORMULAIRE VEHICULE ------------------------




void MainWindow::valid_addVehicule(){
    std::cout << "form addVeh\n\n" << std::flush;

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
            std::cout << "form addVeh voiture ok\n\n" << std::flush;

            Voiture v(strImmatriculation, strModele, nbPlaces, estDispo, prixJournee);
            application.addVehicule(v);
            //Instanciation nouvelle voiture
        }
        break;
        case -2: //BUS
        {
            std::cout << "form addVeh bus ok\n\n" << std::flush;
            Bus b(strImmatriculation, strModele, nbPlaces, estDispo, prixJournee);
            application.addVehicule(b);
        }
        break;
        case -4: //VELO
        {
            std::cout << "form addVeh velo ok\n\n" << std::flush;
            Velo v(strImmatriculation, strModele, estDispo, prixJournee);
            application.addVehicule(v);
        }
        break;
        default:
        {
            std::cout << "form addVeh choix veh a faire\n\n" << std::flush;
            check = false;
        }
        break;
    }

   application.afficherVehicules();
   this->refresh();

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




//----------- VALIDATION FORMULAIRE LOCATION ------------------------




void MainWindow::valid_addLocation(){
    std::cout << "form addLocation\n\n" << std::flush;

    int idClient = ui->add_locClient->currentData().toInt();
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

    std::cout << "LOCATION\n" << std::flush;
    std::cout << "idCLient : " << idClient << "\n" << std::flush;
    std::cout << "refBanq : " << refBanq.toStdString() << "\n" << std::flush;
    std::cout << "dateDebut : " << strDate << "\n" << std::flush;
    std::cout << "duree : " << duree << "\n" << std::flush;
    //std::cout << "typeVeh : " << typeVeh << "\n" << std::flush;
    std::cout << "assist ? : " << assist << "\n" << std::flush;
    std::cout << "immateVeh : " << immatVeh.toStdString() << "\n" << std::flush;
}




//----------- LIENS ENTRE BOUTONS ET ONGLETS ------------------------





void MainWindow::form_addClient(){
    test t;
    t.print();

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
