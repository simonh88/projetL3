#include "location.h"
#include <string>


Location::Location(int idLoc)
{
    idLocation = idLoc;
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



