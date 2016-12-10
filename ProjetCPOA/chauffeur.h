#ifndef CHAUFFEUR_H
#define CHAUFFEUR_H
#include <string>
#include "vector"
#include <periode.h>

class Chauffeur
{
private:
    std::string noPermis;
    std::string nom;
    std::string prenom;
    bool estDispo;
    std::vector<Periode*> periodeIndispo;

public:
    Chauffeur(std::string &noPermis, std::string &nom, std::string &prenom, bool &estDispo);

    std::string getNom() const;
    std::string getPrenom() const;
    std::string getNoPermis() const;
    bool getDispo() const;
    Periode* getPeriode(int id) const;
    int getSizeIndispo();

    void setNom(const std::string &value);
    void setPrenom(const std::string &value);
    void setDispo(bool &value);
    void setPermis(std::string &value);
    void addIndispo(Periode* value);
    void afficherIndispo();
    void printChauffeur();
};

#endif // CHAUFFEUR_H
