#include "lesclients.h"
#include <vector>
#include <string>


LesClients::LesClients()
{

    //listClients.push_back("blabla");
}

Client LesClients::getClient(int id) const
{
    return this->LesClients.at(i);
}

void LesClients::setClient(const Client &c)
{
    this->LesClients.push_back(c);
}

int LesClients::getSize() const
{
    return this->LesClients.size();
}

