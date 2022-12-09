CONFIG += c++17 console
CONFIG -= app_bundle

INCLUDEPATH *= $$clean_path($$PWD/../)
INCLUDEPATH += $$clean_path(/usr/include/)
include($$PWD/BallCollision.pri)

SOURCES += \
        $$PWD/main.cpp \

