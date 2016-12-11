#include "location.h"
#include <string>
#include "date.h"

Location::Location(int &id, Client* &client, std::string &loc_refBanq, Date &loc_DateDebut, int &loc_Duree, bool &loc_assist, Vehicule* &vehicule)
{
    idLocation = id;
    modePaiement = loc_refBanq;
    dateDebut = loc_DateDebut;
    dateFin = dateDebut.ajouter(loc_Duree);
    vehic = vehicule;
    cli = client;
    prix = vehicule->getPrixJournee()*loc_Duree;
    assistance = loc_assist;

    //TODO
    // prix a calculer et reucprer dans application
    // cli recup by id

    /*dateDebut = loc_DateDebut;
    dateFin = loc_DateDebut + loc_Duree;
    prix = 0;
    vehic = loc_immatVeh;
    cli = loc_idClient;*/

}

Vehicule* Location::getVehic()
{
    return vehic;
}

void Location::setVehic(Vehicule* value)
{
    vehic = value;
}

int Location::getIdLocation() const
{
    return idLocation;
}

void Location::setPrix(double value)
{
    prix = value;
}

std::string Location::getModePaiement() const
{
    return modePaiement;
}

void Location::setModePaiement(const std::string &value)
{
    modePaiement = value;
}

bool Location::getAssistance() const
{
    return assistance;
}

void Location::setAssistance(const bool &value)
{
    assistance = value;
}

Date Location::getDateDebut() const
{
    return dateDebut;
}

void Location::setDateDebut(const Date &value)
{
    dateDebut = value;
}

Date Location::getDateFin() const
{
    return dateFin;
}

void Location::setDateFin(const Date &value)
{
    dateFin = value;
}

Client* Location::getCli()
{
    return cli;
}

void Location::setCli(Client* &value)
{
    cli = value;
}

double Location::getPrix()
{
    return prix;
}

void Location::setPrix(double &value)
{
    prix = value;
}

void Location::printLocation(){
    std::cout << "LOCATION : " << idLocation <<  "\n" << std::flush;
    std::cout << "idCLient : " << cli->getNom() << "\n" << std::flush;
    std::cout << "refBanq : " << modePaiement << "\n" << std::flush;
    //std::cout << "dateDebut : " <<  << "\n" << std::flush;
    //std::cout << "duree : " << duree << "\n" << std::flush;
    //std::cout << "typeVeh : " << typeVeh << "\n" << std::flush;
    std::cout << "assist ? : " << assistance << "\n" << std::flush;
    std::cout << "immateVeh : " << vehic->getModele() << "\n" << std::flush;
    std::cout << "Prix total : " << prix << std::endl << std::flush;
}



