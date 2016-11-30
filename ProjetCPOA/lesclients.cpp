#include "lesclients.h"
#include <vector>
#include <string>


LesClients::LesClients()
{
    //listClients.push_back("blabla");
}

Client LesClients::getClient(int id) const
{
    return this->listClients.at(id);//-1 car quand on set l'id c'est taille +1
}

void LesClients::setClient(const Client c)
{
    this->listClients.push_back(c);
}

int LesClients::getSize() const
{
    return this->listClients.size();
}

