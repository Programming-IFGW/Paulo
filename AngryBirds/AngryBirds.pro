####################################################
DEFINES     += QT_DISABLE_DEPRECATED_BEFORE=0x060000    
TEMPLATE     = app
TARGET       = AngryBirds
INCLUDEPATH += .
HEADERS     += Headers/entity.h \
               Headers/game.h \
               Headers/includes.hpp \
               Headers/vector.h \
               Headers/window.h
SOURCES     += Sources/entity.cpp \
               Sources/game.cpp \
               Sources/main.cpp \
               Sources/vector.cpp \
               Sources/window.cpp
QT          += widgets
####################################################
