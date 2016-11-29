#ifndef VEHICULE_H
#define VEHICULE_H
#include <string>


class Vehicule
{
protected:
    std::string type;
    bool estDispo;
    std::string immatriculation;
    double prixJournee;
    std::string urlImage;
    std::string modele;

public:
    Vehicule();
    Vehicule(std::string immatriculation, std::string modele, bool estDispo, double prixJournee);
    virtual ~Vehicule();
    std::string getUrlImage() const;
    double getPrixJournee() const;
    std::string getImmatriculation() const;
    bool getEstDispo() const;
    std::string getModele() const;
    std::string getType() const;
    //virtual int getNbPlaces() const = 0;

    void setUrlImage(const std::string &value);
    void setPrixJournee(double value);
    void setImmatriculation(const std::string &value);
    void setEstDispo(bool value);
    void setType(const std::string &value);
    void setModele(const std::string &value);
    void printVehicule();
};

#endif // VEHICULE_H
