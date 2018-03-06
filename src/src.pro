#-------------------------------------------------
#
# Project created by QtCreator 2018-03-04T12:48:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = src
TEMPLATE = app


SOURCES += main.cpp\
        youtubedownloader.cpp \
    helpdialog.cpp \
    videosettings.cpp \
    playlistsettings.cpp

HEADERS  += youtubedownloader.hpp \
    helpdialog.hpp \
    videosettings.hpp \
    playlistsettings.hpp

FORMS    += youtubedownloader.ui \
    helpdialog.ui \
    videosettings.ui \
    playlistsettings.ui
