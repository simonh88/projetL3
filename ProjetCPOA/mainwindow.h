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

    void refresh();
    void refresh_ListVeh(std::string typeVehicule, int idParc);
    void refresh_ListClient();
    void refresh_ListParc();
    void refreshVehiculeLoc();
    void refresh_ListLocations();
    void refresh_ShowLocations();

    void valid_addClient();
    void valid_addParc();
    void valid_addChauffeur();

    void valid_addVehicule();
    void select_typeVeh(int id);
    void select_locVeh(int id);

    void valid_addLocation();
    void select_parc(int idParc);

    void majPrixLoc();
    void refresh_ListVehAfterValid();
};

#endif // MAINWINDOW_H
