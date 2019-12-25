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
    Add_10.cpp \
    building.cpp \
    closest_path.cpp \
    data.cpp \
    easycity2_25.cpp \
    escape_13.cpp \
    factorial_8.cpp \
    fib_5.cpp \
    findperiodstring_15.cpp \
    floor.cpp \
    getsolution_19.cpp \
    judge.cpp \
    judgewindow.cpp \
    largefactorial_16.cpp \
    largestroot_6.cpp \
    longest_path.cpp \
    longestcommonsubstring_18.cpp \
    longestpeekpalindrome_20.cpp \
    main.cpp \
    mainwindow.cpp \
    mario_12.cpp \
    maze_21.cpp \
    minesweeper_2.cpp \
    mydatabase.cpp \
    mymath.cpp \
    myother.cpp \
    mystring.cpp \
    mytree.cpp \
    paperpassing_3.cpp \
    people.cpp \
    prime.cpp \
    primedistance_11.cpp \
    problemset.cpp \
    scheduler.cpp \
    shortest_longest_1.cpp \
    shortest_summation_9.cpp \
    shygame_4.cpp \
    sub_14.cpp \
    sumoflarge_17.cpp \
    treewalk_7.cpp

HEADERS += \
    Add_10.h \
    building.h \
    closest_path.h \
    data.h \
    easycity2_25.h \
    escape_13.h \
    factorial_8.h \
    fib_5.h \
    findperiodstring_15.h \
    floor.h \
    getsolution_19.h \
    judge.h \
    judgewindow.h \
    largefactorial_16.h \
    largestroot_6.h \
    longest_path.h \
    longestcommonsubstring_18.h \
    longestpeekpalindrome_20.h \
    mainwindow.h \
    mario_12.h \
    maze_21.h \
    minesweeper_2.h \
    mydatabase.h \
    mymath.h \
    myother.h \
    mystring.h \
    mytree.h \
    paperpassing_3.h \
    people.h \
    prime.h \
    primedistance_11.h \
    problemset.h \
    scheduler.h \
    shortest_longest_1.h \
    shortest_summation_9.h \
    shygame_4.h \
    sub_14.h \
    sumoflarge_17.h \
    treewalk_7.h

FORMS += \
    judgewindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
