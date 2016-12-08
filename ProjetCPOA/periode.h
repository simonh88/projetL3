#ifndef PERIODE_H
#define PERIODE_H
#include <date.h>

class Periode
{
private:
    Date dateDebut;
    Date dateFin;

public:
    Periode(Date db, Date df);
    Date getDateDebut();
    Date getDateFin();
    bool estDispo(Date d);
    void afficher();
};

#endif // PERIODE_H
