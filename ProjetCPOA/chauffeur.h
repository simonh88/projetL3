#ifndef CHAUFFEUR_H
#define CHAUFFEUR_H
#include <string>

class Chauffeur
{
private:
    int noPermis;
    std::string nom;
    std::string prenom;
    bool estDispo;

public:
    Chauffeur();

    std::string getNom() const;
    std::string getPrenom() const;
    int getNoPermis() const;
    bool getDispo() const;

    void setNom(const std::string &value);
    void setPrenom(const std::string &value);
    void setDispo(bool value);
    void setPermis(int value);

    void printChauffeur();
};

#endif // CHAUFFEUR_H
