QT += testlib core widgets
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app


DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    ControllerScreen.cpp \
    StartScreen.cpp \
    tst_testcontroller.cpp

HEADERS += \
    ControllerScreen.h \
    StartScreen.h

FORMS += \
    controller_dialog.ui \
    widget.ui
