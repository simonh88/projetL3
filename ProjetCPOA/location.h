#include <string>
#ifndef LOCATION_H
#define LOCATION_H


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
    Location(int idLoc);
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
