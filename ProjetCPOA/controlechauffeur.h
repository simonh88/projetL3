#ifndef CONTROLECHAUFFEUR_H
#define CONTROLECHAUFFEUR_H
#include <string>
#include <periode.h>

class ControleChauffeur
{
private:
    int idChauffeur;
    Periode* inactivite;
public:
    ControleChauffeur(int id, Periode* p);


    int getIdChauffeur() const;
    Periode *getInactivite() const;

    void setIdChauffeur(const int &value);
    void setInactivite(Periode *value);
    void afficherControle();
};

#endif // CONTROLECHAUFFEUR_H
