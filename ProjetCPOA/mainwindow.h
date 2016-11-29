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

private slots :
    void form_addClient();
    void form_addVehicule();
    void form_addChauffeur();
    void form_addParc();
    void form_addLocation();

    void refresh();
    void refresh_ListVeh();
    void refresh_ListClient();

    void valid_addClient();

    void valid_addVehicule();
    void select_typeVeh(int id);

    void valid_addLocation();
};

#endif // MAINWINDOW_H
