#include "leslocations.h"

LesLocations::LesLocations()
{

}

LesLocations::getLocation(int id){
    return listLocation.at(id);
}

LesLocations::getSize(){
    return listLocation.size();
}

LesLocations::addLocation(const Location &loc){
    int id = loc.getIdLocation();
    listLocation.at(id)=loc;
}
