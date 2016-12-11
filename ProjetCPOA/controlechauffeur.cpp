#include "controlechauffeur.h"

std::string ControleChauffeur::getNomChauffeur() const
{
    return nomChauffeur;
}

Periode *ControleChauffeur::getInactivite() const
{
    return inactivite;
}

void ControleChauffeur::setNomChauffeur(const std::string &value)
{
    nomChauffeur = value;
}

void ControleChauffeur::setInactivite(Periode *value)
{
    inactivite = value;
}

ControleChauffeur::ControleChauffeur()
{

}
