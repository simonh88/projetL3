#include "lesclients.h"
#include <vector>
#include <string>


LesClients::LesClients()
{

}

Client LesClients::getClient(int id) const
{
    return this->listClients.at(id);
}

void LesClients::setClient(const Client c)
{
    this->listClients.push_back(c);
}

int LesClients::getSize() const
{
    return this->listClients.size();
}

