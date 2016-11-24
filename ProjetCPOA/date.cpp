#include "date.h"

int Date::getJour() const
{
    return jour;
}

int Date::getMois() const
{
    return mois;
}

int Date::getAnnee() const
{
    return annee;
}

void Date::setAnnee(int value)
{
    annee = value;
}

void Date::setMois(int value)
{
    mois = value;
}

void Date::setJour(int value)
{
    jour = value;
}
/// @brief 1 si this est plus petit que d
/// 0 sinon et -1 si this == d
int Date::compare(Date d)
{
    int res = -1;
    if(this->getAnnee() < d.getAnnee()){
        res = 1;
    }else if(this->getAnnee() > d.getAnnee()){
        res = 0;
    }else{
        if(this->getMois() < d.getMois()){
            res = 1;
        }else if(this->getMois() > d.getMois()){
            res = 0;
        }else{
            if(this->getJour() < d.getJour()){
                res = 1;
            }else if(this->getJour() > d.getJour()){
                res = 0;
            }else{//Si on entre ici, les deux dates sont égales
                res = -1;
            }
        }
    }
    return res;
}

Date::Date()
{

}

