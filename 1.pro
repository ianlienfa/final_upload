QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    add1.cpp \
    building.cpp \
    closest_path.cpp \
    data.cpp \
    easycity1.cpp \
    escape.cpp \
    factorial.cpp \
    fib.cpp \
    floor.cpp \
    judge.cpp \
    largestroot.cpp \
    longest_path.cpp \
    main.cpp \
    mainwindow.cpp \
    minesweeper.cpp \
    mydatabase.cpp \
    mymath.cpp \
    myother.cpp \
    mytree.cpp \
    paperpassing.cpp \
    people.cpp \
    prime.cpp \
    problemset.cpp \
    scheduler.cpp \
    shygame.cpp \
    treewalk.cpp

HEADERS += \
    add1.h \
    building.h \
    closest_path.h \
    data.h \
    easycity1.h \
    escape.h \
    factorial.h \
    fib.h \
    floor.h \
    judge.h \
    largestroot.h \
    longest_path.h \
    mainwindow.h \
    minesweeper.h \
    mydatabase.h \
    mymath.h \
    myother.h \
    mytree.h \
    paperpassing.h \
    people.h \
    prime.h \
    problemset.h \
    scheduler.h \
    shygame.h \
    treewalk.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
