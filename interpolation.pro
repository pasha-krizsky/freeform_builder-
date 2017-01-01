#-------------------------------------------------
#
# Project created by QtCreator 2016-11-24T20:14:14
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = interpolation
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcustomplot.cpp \
    bezier_curves.cpp \
    lagrange_polynomial.cpp \
    input_data.cpp \
    linear_interpolation.cpp \
    quadratic_interpolation.cpp \
    matrix.cpp \
    approximation.cpp \
    calculation.cpp

HEADERS  += mainwindow.h \
    qcustomplot.h \
    lagrange_polynomial.h \
    bezier_curves.h \
    input_data.h \
    linear_interpolation.h \
    quadratic_interpolation.h \
    matrix.h \
    approximation.h \
    calculation.h

FORMS    += mainwindow.ui
