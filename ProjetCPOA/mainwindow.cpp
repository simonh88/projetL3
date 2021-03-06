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
    connect(ui->btn_showLocations, SIGNAL(clicked()), this, SLOT(tab_showLocations()));
    connect(ui->btn_showVehicules, SIGNAL(clicked()), this, SLOT(tab_showVehicules()));
    connect(ui->btn_showChauffeurs, SIGNAL(clicked()), this, SLOT(tab_showChauffeurs()));

    connect(ui->valid_addClient, SIGNAL(clicked()), this, SLOT(valid_addClient()));

    connect(ui->valid_addVehicule, SIGNAL(clicked()), this, SLOT(valid_addVehicule()));
    //---------Attachement des fonctions aux groupes de boutons---------/
    connect(ui->choixTypeVeh, SIGNAL(buttonClicked(int)), this, SLOT(select_typeVeh(int))) ;
    connect(ui->choixLocVeh, SIGNAL(buttonClicked(int)), this, SLOT(select_locVeh(int)));

    //----------------MAJ PRIX DANS LOCATIONS----------------------------------//
    connect(ui->add_locDuree, SIGNAL(valueChanged(int)), this, SLOT(majPrixLoc()));
    connect(ui->add_locDateDebut, SIGNAL(dateChanged(QDate)),this,SLOT(refreshVehiculeLoc()));
    connect(ui->add_locDuree, SIGNAL(valueChanged(int)),this,SLOT(refreshVehiculeLoc()));
    connect(ui->add_locVehicule, SIGNAL(currentIndexChanged(int)), this, SLOT(majPrixLoc()));
    connect(ui->add_locAssist, SIGNAL(clicked()), this, SLOT(majPrixLoc()));


    connect(ui->show_locLocation, SIGNAL(currentIndexChanged(int)), this, SLOT(refresh_ShowLocations()));

    connect(ui->validAddControleVeh, SIGNAL(clicked(bool)),this,SLOT(valid_addControleVehic()));
    connect(ui->valid_addControleChauff, SIGNAL(clicked(bool)),this,SLOT(valid_addControleChauff()));

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
    this->refresh_ListLocations();
    this->refresh_showVeh();
    this->refresh_showChau();
}

void MainWindow::refresh_ListLocations(){
    QComboBox *listLocation = ui->show_locLocation;

    //std::cout << "getLocationsSize : " << application.getLocationsSize() << std::endl;

    //listLocation->clear();
    disconnect(ui->show_locLocation, SIGNAL(currentIndexChanged(int)), this, SLOT(refresh_ShowLocations()));
    listLocation->clear();
    for(int i=0; i<application.getLocationsSize();i++){
        Location* loc = application.getLocation(i);

        QString client = QString::fromStdString(loc->getCli()->getNom()) +" "+ QString::fromStdString(loc->getCli()->getPrenom());

        listLocation->addItem(client);

    }
    connect(ui->show_locLocation, SIGNAL(currentIndexChanged(int)), this, SLOT(refresh_ShowLocations()));
    this->refresh_ShowLocations();
}

void MainWindow::refresh_ShowLocations(){
    QComboBox *listLocation = ui->show_locLocation;

    int idLocation = listLocation->currentIndex();

    Location* l = application.getLocation(idLocation);
    Client* c = l->getCli();
    Vehicule* v = l->getVehic();

    QString client = QString::fromStdString(l->getCli()->getNom()) +" "+ QString::fromStdString(l->getCli()->getPrenom());

    ui->show_locClient->setText(client);
    ui->show_locRefBanq->setText(QString::fromStdString(l->getModePaiement()));
    ui->show_locDateDebut->setText(QString::fromStdString(l->getDateDebut().toString()));
    ui->show_locDateFin->setText(QString::fromStdString(l->getDateFin().toString()));
    ui->show_locTypeVeh->setText(QString::fromStdString(v->getType()));
    ui->show_locAssist->setText(QString::number(l->getAssistance()));

    std::stringstream oss;
    oss << "<p align='center'><span style='font-size:11pt; font-weight:600;'>Prix : " << l->getPrix() << " euros</p>";
    std::string prix = oss.str();

    ui->show_locPrix->setText(QString::fromStdString(prix));
    ui->show_locVeh->setText(QString::fromStdString(v->getModele()));

    ui->show_locParc->setText(QString::fromStdString(application.getParcByVeh(v->getImmatriculation())->getNom()));

    //std::cout << "idLocation : " << idLocation << std::endl;
}

/*------------------------------Refresh page show voitures -----------------------*/
void MainWindow::refresh_showVeh(){
    QComboBox *listVehicules = ui->show_vehVehicule;

    //std::cout << "getLocationsSize : " << application.getLocationsSize() << std::endl;

    //listLocation->clear();
    disconnect(ui->show_vehVehicule, SIGNAL(currentIndexChanged(int)), this, SLOT(refresh_ShowInfosVeh()));
    listVehicules->clear();
    for(int i=0; i<application.getParcsSize(); i++){
        Parc* parc = application.getParc(i);
        for(int j=0; j<parc->getVehiculesSize(); j++){
            Vehicule* v = parc->getVehicule(j);

            QString vehicule = QString::fromStdString(v->getImmatriculation()) + " -- " + QString::fromStdString(parc->getNom()) + " -- " + QString::fromStdString(v->getModele());
            listVehicules->addItem(vehicule);
        }
    }
    connect(ui->show_vehVehicule, SIGNAL(currentIndexChanged(int)), this, SLOT(refresh_ShowInfosVeh()));
    this->refresh_ShowInfosVeh();
}

void MainWindow::refresh_ShowInfosVeh(){

    //On split le resultat pour avoir que l'immat du vehicule
    QString infosVeh = ui->show_vehVehicule->currentText();
    std::string vehicule = infosVeh.toStdString();
    std::istringstream iss(vehicule);
    std::string immat;
    getline(iss, immat, ' ');
    //std::cout << "IMMAT : " << immat << std::endl;



    Vehicule* v = application.getVehiculeByImmat(immat);

    std::stringstream ss;
    ss << v->getPrixJournee();

    ui->show_vehAssist->setText(QString::fromStdString(v->getAssist()));
    ui->show_vehImmat->setText(QString::fromStdString(immat));
    ui->show_vehModele->setText(QString::fromStdString(v->getModele()));
    ui->show_vehPrix->setText(QString::fromStdString(ss.str()));
    ui->show_vehType->setText(QString::fromStdString(v->getType()));



    //ui->show_vehNbPlaces->setText(QString::fromStdString(v->getNbPlaces()));

    //std::cout << "idLocation : " << idLocation << std::endl;
}

/*------------------------------Refresh page show Chauffeurs -----------------------*/
void MainWindow::refresh_showChau(){
    QComboBox *listChauffeurs = ui->show_chauChauffeur;
    //std::cout << "getLocationsSize : " << application.getLocationsSize() << std::endl;


    disconnect(ui->show_chauChauffeur, SIGNAL(currentIndexChanged(int)), this, SLOT(refresh_ShowInfosChau()));
    listChauffeurs->clear();
    for(int i=0; i<application.getChauffeursSize();i++){
        Chauffeur* chauffeur = application.getChauffeur(i);

        QString strchauffeur = QString::fromStdString(chauffeur->getNom()) +" "+ QString::fromStdString(chauffeur->getPrenom());

        listChauffeurs->addItem(strchauffeur);

    }
    connect(ui->show_chauChauffeur, SIGNAL(currentIndexChanged(int)), this, SLOT(refresh_ShowInfosChau()));
    this->refresh_ShowInfosChau();
}

void MainWindow::refresh_ShowInfosChau(){

    int idChauffeur = ui->show_chauChauffeur->currentIndex();
    Chauffeur* chauffeur = application.getChauffeur(idChauffeur);
    ui->show_chauNom->setText(QString::fromStdString(chauffeur->getNom()));
    ui->show_chauPrenom->setText(QString::fromStdString(chauffeur->getPrenom()));
    ui->show_chauPermis->setText(QString::fromStdString(chauffeur->getNoPermis()));

}


/*------------------------Autres refresh----------------------------------*/


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
                    int duree = ui->add_locDuree->value();
                    int j = 0;
                    bool dispo = true;
                    while(j<veh->getSizeIndispo()){
                        if(duree == 0){
                            if(!veh->getPeriode(j)->estDispo(d)){
                                dispo = false;
                            }
                        }else{
                            for(int k = 0 ; k < duree ; k++){
                                if(!veh->getPeriode(j)->estDispo(d)){
                                    dispo = false;
                                }
                                d = d.ajouter(1);
                            }
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

void MainWindow::refreshVehiculeLoc(){
    int idParc = ui->add_locParc->currentIndex();
    int id = ui->choixLocVeh->checkedId();
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
    this->refresh();

}

//-------------------Ajout d'un controle vehicule----------------

void MainWindow::valid_addControleVehic(){

    QDate dateDeb = ui->addControleVehDateDeb->date();
    QDate dateF = ui->addControleVehDateFin->date();
    std::string strDateDeb = dateDeb.toString("dd/MM/yyyy").toStdString();
    std::string strDateFin = dateF.toString("dd/MM/yyyy").toStdString();
    Date dDeb(strDateDeb);
    Date dFin(strDateFin);


    QString infosVeh = ui->show_vehVehicule->currentText();
    std::string vehicule = infosVeh.toStdString();
    std::istringstream iss(vehicule);
    std::string immat;
    getline(iss, immat, ' ');
    //---AFFICHAGE std::cout << "Vehicule : " << immat << std::flush;

    int i = 0;
    bool trouve = false;
    Vehicule* v;
    while(i<application.getParcsSize() && trouve == false){
        Parc* p = application.getParc(i);
        v = p->getVehiculeByImmat(immat);
        if(v != 0){
            trouve = true;
        }
    }
    v->printVehicule();
    application.addControleVehic(dDeb,dFin,v);
}

void MainWindow::valid_addControleChauff(){

    QDate dateDeb = ui->add_controleChauffDateDeb->date();
    QDate dateF = ui->add_controleChauffDateFin->date();
    std::string strDateDeb = dateDeb.toString("dd/MM/yyyy").toStdString();
    std::string strDateFin = dateF.toString("dd/MM/yyyy").toStdString();
    Date dDeb(strDateDeb);
    Date dFin(strDateFin);


    int i = 0;
    bool trouve = false;
    Chauffeur* c;
    while(i<application.getChauffeursSize() && trouve == false){
        c = application.getChauffeur(i);

        if(c != 0){
            trouve = true;
        }
        else{
            i++;
        }
    }

    c->printChauffeur();

    application.addControleChauff(dDeb,dFin,c, i);
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

        bool assist = ui->add_locAssist->isChecked();

        if(assist){
            prix = prix*2;
        }

        std::ostringstream oss;
        oss << prix;
        std::string message = "<p align='center'><span style='font-size:11pt; font-weight:600;'>Prix : " + oss.str() + " euros</p>" ;
        ui->label_locPrix->setText(QString::fromStdString(message));
    }else{
        ui->label_locPrix->setText("<p align='center'><span style='font-size:11pt; font-weight:600;'>Prix : 0 euros</p>");
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
    QString prix = ui->label_locPrix->text();

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
    std::string prixstr = prix.toStdString();
    application.addLocation(idClient, refBanqstr, d, duree, assist, immatVehstr, prixstr);

    ui->add_locAssist->setChecked(false);
    ui->add_locBus->setChecked(false);
    ui->add_locVelo->setChecked(false);
    ui->add_locVoiture->setChecked(false);
    ui->add_locRefBanq->setText("");
    ui->add_locDuree->setValue(0);

    this->refresh();

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

void MainWindow::tab_showLocations(){
    ui->tabWidget->setCurrentIndex(6);
}

void MainWindow::tab_showVehicules(){
    ui->tabWidget->setCurrentIndex(7);
}

void MainWindow::tab_showChauffeurs(){
    ui->tabWidget->setCurrentIndex(8);
    this->refresh_showChau();
}
