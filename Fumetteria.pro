TEMPLATE = app
TARGET = Fumetteria
INCLUDEPATH += .
QT+= widgets
QT += gui
QMAKE_CXXFLAGS += -std=c++11

# Input
HEADERS += \
           model/admin.h \
           view/v_login.h \
    model/nerd_stuff.h \
    controller/c_nerd_stuff.h \
    model/database_stuff.h \
    model/comic_book.h \
    model/dvd.h \
    model/action_figure.h \
    controller/c_main_window.h \
    controller/c_user.h \
    model/database_user.h \
    model/base_user.h \
    model/gold_user.h \
    model/user.h \
    view/v_manage_stuff.h \
    view/v_manage_user.h \
    view/v_starred.h \
    view/v_starred_ask.h \
    view/v_search_list.h \
    view/v_search_window.h \
    view/v_main_window.h

SOURCES += main.cpp \
           model/admin.cpp \
           view/v_login.cpp \
    model/database_stuff.cpp \
    model/nerd_stuff.cpp \
    model/comic_book.cpp \
    model/dvd.cpp \
    model/action_figure.cpp \
    controller/c_nerd_stuff.cpp \
    controller/c_main_window.cpp \
    controller/c_user.cpp \
    model/database_user.cpp \
    model/base_user.cpp \
    model/gold_user.cpp \
    model/user.cpp \
    view/v_manage_stuff.cpp \
    view/v_manage_user.cpp \
    view/v_starred.cpp \
    view/v_starred_ask.cpp \
    view/v_search_list.cpp \
    view/v_search_window.cpp \
    view/v_main_window.cpp

