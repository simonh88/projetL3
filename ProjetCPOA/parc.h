#ifndef PARC_H
#define PARC_H
#include <string>

class Parc
{

private:
    std::string nom;
    std::string adresse;
    int nbPlaces;

public:
    Parc();

    std::string getNom() const;
    std::string getAdresse() const;
    int getNbPlaces() const;

    void setNom(const std::string &value);
    void setAdresse(const std::string &value);
    void setNbPlaces(int value);

    void printParc();
};

#endif // PARC_H
