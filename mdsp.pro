QT += core gui widgets

CONFIG += c++17 dll

TARGET = ComplexPlotLib
TEMPLATE = lib

DEFINES += COMPLEXPLOTLIB_LIBRARY

SOURCES += \
    src/complexplot.cpp \
    src/mainwindow.cpp \
    src/qcustomplot.cpp

HEADERS += \
    src/complexplot.h \
    src/mainwindow.h \
    src/qcustomplot.h


