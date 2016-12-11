#-------------------------------------------------
#
# Project created by QtCreator 2016-11-16T10:16:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ProjetCPOA
TEMPLATE = app


SOURCES += main.cpp\
    mainwindow.cpp \
    lesclients.cpp \
    client.cpp \
    lesvehicules.cpp \
    vehicule.cpp \
    location.cpp \
    leslocations.cpp \
    date.cpp \
    bus.cpp \
    voiture.cpp \
    velo.cpp \
    application.cpp \
    lesparcs.cpp \
    parc.cpp \
    leschauffeurs.cpp \
    chauffeur.cpp \
    periode.cpp \
    lescontroleschauffeurs.cpp \
    controlechauffeur.cpp \
    lescontrolesvehicules.cpp \
    controlevehicule.cpp


HEADERS  += mainwindow.h \
    lesclients.h \
    client.h \
    location.h \
    leslocations.h \
    vehicule.h \
    lesvehicules.h \
    date.h \
    bus.h \
    voiture.h \
    velo.h \
    application.h \
    lesparcs.h \
    parc.h \
    leschauffeurs.h \
    chauffeur.h \
    periode.h \
    lescontroleschauffeurs.h \
    controlechauffeur.h \
    lescontrolesvehicules.h \
    controlevehicule.h

FORMS    += mainwindow.ui
