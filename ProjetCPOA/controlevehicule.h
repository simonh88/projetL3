#ifndef CONTROLEVEHICULE_H
#define CONTROLEVEHICULE_H
#include <string>
#include "periode.h"

class ControleVehicule
{
private:
    std::string nomVehicule;
    Periode* inactivite;
public:
    ControleVehicule(std::string nom, Periode* p);


    std::string getNomVehicule() const;
    Periode* getInactivite() const;

    void setNomVehicule(const std::string &value);
    void setInactivite(Periode* value);

    void afficherControle();
};

#endif // CONTROLEVEHICULE_H
