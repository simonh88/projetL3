#include "date.h"
#include <stdlib.h>

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

Date Date::ajouter(int duree){
    int jours = this->getJour()+duree;
    int nbJoursMois = 0;
    bool bissextile = false;
    if(getAnnee() % 4 == 0 && getAnnee() % 100 != 0 || getAnnee() % 400 == 0){
        bissextile = true;
    }
    Date d("0/00/0000");
    switch(getMois()){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            nbJoursMois = 31;
        break;
        case 4: case 6: case 9: case 11:
            nbJoursMois = 30;
        break;
        case 2:
            if(bissextile) nbJoursMois = 29;
            else nbJoursMois = 28;
        break;
    }
    if(jours > nbJoursMois){
        d.setMois(getMois()+1);
        d.setJour(jours - nbJoursMois);
        if(d.getMois() > 12){
            d.setAnnee(getAnnee()+1);
            d.setMois(1);
        }else{
            d.setAnnee(getAnnee());
        }
    }
    return d;
}

void Date::split(std::string str, char delimiter) {
  std::stringstream ss(str); // Turn the string into a stream.
  std::string tok;
  getline(ss, tok, delimiter);
  jour = atoi(tok.c_str());
  getline(ss, tok, delimiter);
  mois = atoi(tok.c_str());
  getline(ss, tok, delimiter);
  annee = atoi(tok.c_str());
}

Date::Date()
{
}

Date::Date(std::string dateStr)
{
    split(dateStr, '/');
}

