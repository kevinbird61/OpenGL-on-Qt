#-------------------------------------------------
#
# Project created by QtCreator 2016-05-04T14:17:49
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = testOpenGL
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    myopengl.cpp \
    tiny_object/tiny_obj_loader.cc \
    mycombobox.cpp

HEADERS  += mainwindow.h \
    myopengl.h \
    tiny_object/tiny_obj_loader.h \
    mycombobox.h

FORMS    += mainwindow.ui
