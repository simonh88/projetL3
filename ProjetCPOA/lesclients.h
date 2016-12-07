#ifndef LESCLIENTS_H
#define LESCLIENTS_H
#include <vector>
#include <string>
#include "client.h"


class LesClients
{
private:
    std::vector<Client*> listClients;

public:
    LesClients();
    Client* getClient(int id);
    void setClient(Client* c);
    int getSize() const;
};

#endif // LESCLIENTS_H
