#include "controlechauffeur.h"

int ControleChauffeur::getIdChauffeur() const
{
    return idChauffeur;
}

Periode *ControleChauffeur::getInactivite() const
{
    return inactivite;
}

void ControleChauffeur::setIdChauffeur(const int &value)
{
    idChauffeur = value;
}

void ControleChauffeur::setInactivite(Periode *value)
{
    inactivite = value;
}

ControleChauffeur::ControleChauffeur(int id, Periode* p)
{
    this->idChauffeur = id;
    this->inactivite = p;
}

void ControleChauffeur::afficherControle(){
    std::cout << "Controle chauffeur du " << std::endl;
    inactivite->afficher();
    std::cout << "Pour le chauffeur " << idChauffeur << std::endl << std::endl;
}
