#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <string>
#include <sstream>

class Date
{
private:
    int jour;
    int mois;
    int annee;
    void split(std::string str, char delimiter);
public:
    Date(std::string dateStr);
    int getJour() const;
    int getMois() const;
    int getAnnee() const;
    void setAnnee(int value);
    void setMois(int value);
    void setJour(int value);
    int compare(Date d);
    Date();
    Date ajouter(int duree);
};

#endif // DATE_H
