#ifndef LOCATION_H
#define LOCATION_H
#include <string>
#include "date.h"
#include "vehicule.h"
#include "client.h"

class Location
{

private:
    int idLocation;
    double prix;
    std::string modePaiement;
    Date dateDebut;
    Date dateFin;
    Vehicule vehic;
    Client cli;

public:
    Location(int &id, int &loc_idClient, std::string &loc_refBanq, std::string &loc_DateDebut, int &loc_Duree, bool &loc_assist, std::string &loc_immatVeh);
    Vehicule getVehic() const;
    void setVehic(const Vehicule &value);
    int getIdLocation() const;
    void setPrix(double value);
    std::string getModePaiement() const;
    void setModePaiement(const std::string &value);
    Date getDateDebut() const;
    void setDateDebut(const Date &value);
    Date getDateFin() const;
    void setDateFin(const Date &value);
    Client getCli() const;
    void setCli(const Client &value);
};

#endif // LOCATION_H
