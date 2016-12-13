#-------------------------------------------------
#
# Project created by QtCreator 2016-11-29T18:07:49
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = yueer1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    singing.cpp \
    song.cpp \
    songmanage.cpp \
    singerbutton.cpp \
    dialogsinger.cpp

HEADERS  += mainwindow.h \
    singing.h \
    song.h \
    songmanage.h \
    songstatus.h \
    singerbutton.h \
    dialogsinger.h

FORMS    += mainwindow.ui \
    singing.ui \
    dialogsinger.ui


QT += multimedia

QT += multimediawidgets

RESOURCES += \
    resource1.qrc


