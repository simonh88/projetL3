#ifndef LESCHAUFFEURS_H
#define LESCHAUFFEURS_H
#include <vector>
#include "chauffeur.h"

class LesChauffeurs
{
private:
    std::vector<Chauffeur*> listChauffeurs;

public:
    LesChauffeurs();

    Chauffeur* getChauffeur(int id);
    int getSize();
    void addChauffeur(Chauffeur* &chau);
};
#endif // LESCHAUFFEURS_H
