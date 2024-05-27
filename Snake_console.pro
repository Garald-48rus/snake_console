TEMPLATE = app
CONFIG += console c++17
LIBS += -lpthread
CONFIG -= app_bundle
CONFIG -= qt


SOURCES += \
        field.cpp \
        game.cpp \
        main.cpp \
        snake.cpp

HEADERS += \
    field.h \
    game.h \
    snake.h
