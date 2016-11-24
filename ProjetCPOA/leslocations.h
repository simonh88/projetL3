#ifndef LESLOCATIONS_H
#define LESLOCATIONS_H
#include <vector>
#include "location.h"

class LesLocations
{
private:
    std::vector<Location> listLocation;

public:
    LesLocations();
    Location getLocation(int id);
    int getSize();
    void addLocation(const Location &loc);
};


#endif // LESLOCATIONS_H
