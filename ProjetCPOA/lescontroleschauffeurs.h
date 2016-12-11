#ifndef LESCONTROLESCHAUFFEURS_H
#define LESCONTROLESCHAUFFEURS_H
#include <vector>
#include "controlechauffeur.h"


class LesControlesChauffeurs
{
private:
    std::vector<ControleChauffeur*> listControleChauffeur;
public:
    LesControlesChauffeurs();
    ControleChauffeur* getControleChauffeur(int id);
    int getSize();
    void addControleChauffeur(ControleChauffeur* cChau);
};

#endif // LESCONTROLESCHAUFFEURS_H
