TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle

#gl subsystem
CONFIG += qt
QT += opengl

#SDL
LIBS += -LC:/Qt/Library/Frameworks/SDL2-2.0.3/lib/x86 -lSDL2main -lSDL2
INCLUDEPATH += C:/Qt/Library/Frameworks/SDL2-2.0.3/include
#SDL_image
LIBS += -LC:/Qt/Library/Frameworks/SDL2_image-2.0.0/lib/x86 -lSDL2_image
INCLUDEPATH += C:/Qt/Library/Frameworks/SDL2_image-2.0.0/include
#SDL_mixer
LIBS += -LC:/Qt/Library/Frameworks/SDL2_mixer-2.0.0/lib/x86 -lSDL2_mixer
INCLUDEPATH += C:/Qt/Library/Frameworks/SDL2_mixer-2.0.0/include

#PRE_TARGETDEPS +=

PRECOMPILED_HEADER = stdafx.h

SOURCES += main.cpp \
    core/appcore.cpp \
    core/stateManager/state.cpp \
    core/stateManager/statemanager.cpp \
    core/processManager/processmanager.cpp \
    core/processManager/process.cpp \
    input/inputmanager.cpp \
    graphics/graphicmanager.cpp \
    graphics/renderGL.cpp \
    graphics/spritemanager.cpp \
    etc/camera.cpp \
    audio/audiomanager.cpp \
    audio/sound.cpp \
    audio/audiomixer.cpp \
    graphics/sprite.cpp \
    audio/music.cpp \
    game/logic.cpp \
    game/map.cpp \
    game/tile.cpp \
    core/console.cpp

HEADERS += \
    core/appcore.h \
    stdafx.h \
    core/stateManager/state.h \
    etc/singleton.h \
    core/stateManager/statemanager.h \
    core/processManager/processmanager.h \
    core/processManager/process.h \
    input/inputmanager.h \
    input/keystroke.h \
    graphics/graphicmanager.h \
    graphics/spritemanager.h \
    etc/camera.h \
    audio/audiomanager.h \
    audio/sound.h \
    audio/audiomixer.h \
    graphics/sprite.h \
    audio/music.h \
    game/logic.h \
    game/map.h \
    game/tile.h \
    core/console.h

OTHER_FILES += \
    todo.txt

