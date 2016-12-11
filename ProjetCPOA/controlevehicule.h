#ifndef CONTROLEVEHICULE_H
#define CONTROLEVEHICULE_H
#include <string>
#include "periode.h"

class ControleVehicule
{
private:
    std::string immatVehicule;
    Periode* inactivite;
public:
    ControleVehicule(std::string immat, Periode* p);


    std::string getImmatVehicule() const;
    Periode* getInactivite() const;

    void setImmatVehicule(const std::string &value);
    void setInactivite(Periode* value);

    void afficherControle();
};

#endif // CONTROLEVEHICULE_H
