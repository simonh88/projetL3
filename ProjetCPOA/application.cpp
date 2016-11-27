#include "application.h"
#include "lesclients.h"
#include <iostream>


Application::Application()
{

}

void Application::addVehicule(Vehicule veh)
{
    lesVehicules.setVehicule(veh);
}

void Application::addClient(std::string &client_Nom, std::string &client_Prenom, std::string &client_Adresse)
{
    int id = lesClients.getSize();
    Client c(id, client_Nom, client_Prenom, client_Adresse);
    lesClients.setClient(c);

}

void Application::addLocation(Location loc)
{

}

void Application::afficherClients(){
    for(int i = 0; i<lesClients.getSize(); i++){
        lesClients.getClient(i).printClient();
    }
}

void Application::afficherVehicules(){
    std::cout << lesVehicules.getSize() << std::flush;
    for(int i = 0; i<lesVehicules.getSize(); i++){
        lesVehicules.getVehicule(i).printVehicule();
    }
}

