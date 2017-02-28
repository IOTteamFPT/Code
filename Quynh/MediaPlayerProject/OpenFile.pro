#-------------------------------------------------
#
# Project created by QtCreator 2017-02-24T14:36:21
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets quickwidgets multimedia

TARGET = OpenFile
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    music.cpp \
    musicqlistwidgetitem.cpp \
    slist.cpp \
    dialog.cpp

HEADERS  += mainwindow.h \
    music.h \
    musicqlistwidgetitem.h \
    slist.h \
    dialog.h

FORMS    += mainwindow.ui \
    dialog.ui

unix:!macx: LIBS += -L$$PWD/../../../ID3tag/lib/ -lid3

INCLUDEPATH += $$PWD/../../../ID3tag/include
DEPENDPATH += $$PWD/../../../ID3tag/include

DISTFILES += \
    Transition.qml

RESOURCES += \
    resources.qrc
