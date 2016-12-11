#ifndef CONTROLECHAUFFEUR_H
#define CONTROLECHAUFFEUR_H
#include <string>
#include <periode.h>

class ControleChauffeur
{
private:
    std::string nomChauffeur;
    Periode* inactivite;
public:
    ControleChauffeur();


    std::string getNomChauffeur() const;
    Periode *getInactivite() const;

    void setNomChauffeur(const std::string &value);
    void setInactivite(Periode *value);
};

#endif // CONTROLECHAUFFEUR_H
