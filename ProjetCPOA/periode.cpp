#include "periode.h"

Periode::Periode(Date db, Date df)
{
    this->dateDebut = db;
    this->dateFin = df;
}

bool Periode::estDispo(Date d){
    bool dispo;
    if(this->dateDebut.compare(d) == 0 || this->dateFin.compare(d) == 1){
        dispo = true;
    }else{
        dispo = false;
    }
    return dispo;
}

Date Periode::getDateDebut(){
    return this->dateDebut;
}

Date Periode::getDateFin(){
    return this->dateFin;
}


void Periode::afficher(){
    std::cout << "Date debut : \n" << std::flush;
    this->dateDebut.afficher();
    std::cout << "Date fin : \n" << std::flush;
    this->dateFin.afficher();
}
