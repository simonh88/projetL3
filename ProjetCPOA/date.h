#ifndef DATE_H
#define DATE_H


class Date
{
private:
    int jour;
    int mois;
    int annee;
public:
    Date();
    int getJour() const;
    int getMois() const;
    int getAnnee() const;
    void setAnnee(int value);
    void setMois(int value);
    void setJour(int value);
    int compare(Date d);
};

#endif // DATE_H
