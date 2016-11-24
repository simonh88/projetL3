#include "leslocations.h"

LesLocations::LesLocations()
{

}

Location LesLocations::getLocation(int id){
    return this->listLocation.at(id);
}

int LesLocations::getSize(){
    return this->listLocation.size();
}

void LesLocations::addLocation(const Location &loc){
    this->listLocation.push_back(loc);
}
