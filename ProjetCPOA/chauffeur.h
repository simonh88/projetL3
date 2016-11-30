#ifndef CHAUFFEUR_H
#define CHAUFFEUR_H
#include <string>

class Chauffeur
{
private:
    std::string noPermis;
    std::string nom;
    std::string prenom;
    bool estDispo;

public:
    Chauffeur(std::string &noPermis, std::string &nom, std::string &prenom, bool &estDispo);

    std::string getNom() const;
    std::string getPrenom() const;
    std::string getNoPermis() const;
    bool getDispo() const;

    void setNom(const std::string &value);
    void setPrenom(const std::string &value);
    void setDispo(bool &value);
    void setPermis(std::string &value);

    void printChauffeur();
};

#endif // CHAUFFEUR_H
