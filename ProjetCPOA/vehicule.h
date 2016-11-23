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

public:
    Vehicule();
    std::string getUrlImage() const;
    double getPrixJournee() const;
    std::string getImmatriculation() const;
    bool getEstDispo() const;

    void setUrlImage(const std::string &value);
    void setPrixJournee(double value);
    void setImmatriculation(const std::string &value);
    void setEstDispo(bool value);
};

#endif // VEHICULE_H
