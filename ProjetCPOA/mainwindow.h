#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "application.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Application application;
    std::vector<std::string> split(std::string, char delimiter);
    void select_locVeh2(int id, int idParc);


private slots :
    void form_addClient();
    void form_addVehicule();
    void form_addChauffeur();
    void form_addParc();
    void form_addLocation();
    void tab_showLocations();
    void tab_showVehicules();
    void tab_showChauffeurs();

    void refresh();
    void refresh_ListVeh(std::string typeVehicule, int idParc);
    void refresh_ListClient();
    void refresh_ListParc();
    void refreshVehiculeLoc();
    void refresh_ListLocations();
    void refresh_ShowLocations();
    void refresh_ListVehAfterValid();
    void refresh_showVeh();
    void refresh_ShowInfosVeh();
    void refresh_showChau();
    void refresh_ShowInfosChau();


    void valid_addClient();
    void valid_addParc();
    void valid_addChauffeur();
    void valid_addVehicule();
    void valid_addLocation();

    void select_typeVeh(int id);
    void select_locVeh(int id);
    void select_parc(int idParc);

    void majPrixLoc();

};

#endif // MAINWINDOW_H
