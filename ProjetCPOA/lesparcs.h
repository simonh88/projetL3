#ifndef LESPARCS_H
#define LESPARCS_H
#include <vector>
#include "parc.h"

class LesParcs
{

private:
    std::vector<Parc> listParc;

public:
    LesParcs();
    Parc& getParc(int id);
    int getSize();
    void addParc(Parc* P);

};

#endif // LESPARCS_H
