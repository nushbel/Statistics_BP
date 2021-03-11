QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Math/ChiSquare.cpp \
    Math/PROBDIST.cpp \
    Math/Sample.cpp \
    Math/SampleBernoulli.cpp \
    Math/SampleInverseTransform.cpp \
    Math/modeling.cpp \
    Math/theoreticalDistribution.cpp \
    histogram.cpp \
    main.cpp \
    mainwindow.cpp \
    plot.cpp

HEADERS += \
    Math/ChiSquare.h \
    Math/PROBDIST.h \
    Math/Sample.h \
    Math/SampleBernoulli.h \
    Math/SampleInverseTransform.h \
    Math/modeling.h \
    Math/theoreticalDistribution.h \
    histogram.h \
    mainwindow.h \
    plot.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
