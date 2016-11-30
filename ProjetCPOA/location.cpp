#include "location.h"
#include <string>
#include "date.h"

Location::Location(int &id, int &loc_idClient, std::string &loc_refBanq, Date &loc_DateDebut, int &loc_Duree, bool &loc_assist, std::string &loc_immatVeh)
{
    idLocation = id;
    modePaiement = loc_refBanq;

    //TODO
    //str Date to QDate
    // dateFin QDate (datedebut + duree)
    // prix a calculer et reucprer dans application
    // vehic recup veh by immat
    // cli recup by id

    /*dateDebut = loc_DateDebut;
    dateFin = loc_DateDebut + loc_Duree;
    prix = 0;
    vehic = loc_immatVeh;
    cli = loc_idClient;*/

}

Vehicule Location::getVehic() const
{
    return vehic;
}

void Location::setVehic(const Vehicule &value)
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

Client Location::getCli() const
{
    return cli;
}

void Location::setCli(const Client &value)
{
    cli = value;
}



