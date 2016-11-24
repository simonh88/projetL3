#ifndef VEHICULE_H
#define VEHICULE_H
#include <string>


class Vehicule
{
private:
    bool estDispo;
    std::string immatriculation;
    double prixJournee;
    std::string urlImage;
    std::string modele;

public:
    Vehicule();
    virtual ~Vehicule();
    std::string getUrlImage() const;
    double getPrixJournee() const;
    std::string getImmatriculation() const;
    bool getEstDispo() const;
    std::string getModele() const;
    //virtual int getNbPlaces() const = 0;

    void setUrlImage(const std::string &value);
    void setPrixJournee(double value);
    void setImmatriculation(const std::string &value);
    void setEstDispo(bool value);
    void setModele(const std::string &value);
    //virtual void setNbPlaces(int value) = 0;
};

#endif // VEHICULE_H
