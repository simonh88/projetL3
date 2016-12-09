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
    Vehicule* vehic;
    Client* cli;
    bool assistance;

public:
    Location(int &id, Client* &client, std::string &loc_refBanq, Date &loc_DateDebut, int &loc_Duree, bool &loc_assist, Vehicule* &vehicule);
    Vehicule* getVehic();
    void setVehic(Vehicule* value);
    int getIdLocation() const;
    void setPrix(double value);
    std::string getModePaiement() const;
    void setModePaiement(const std::string &value);
    bool getAssistance() const;
    void setAssistance(const bool &value);
    Date getDateDebut() const;
    void setDateDebut(const Date &value);
    Date getDateFin() const;
    void setDateFin(const Date &value);
    Client* getCli();
    void setCli(Client* &value);
    void printLocation();
};

#endif // LOCATION_H
