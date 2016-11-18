TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle

#gl subsystem
CONFIG += qt
QT += opengl

#SDL
LIBS += -LC:/Library/Frameworks/SDL2-2.0.3/lib/x86 -lSDL2main -lSDL2
INCLUDEPATH += C:/Library/Frameworks/SDL2-2.0.3/include
#SDL_image
LIBS += -LC:/Library/Frameworks/SDL2_image-2.0.0/lib/x86 -lSDL2_image
INCLUDEPATH += C:/Library/Frameworks/SDL2_image-2.0.0/include
#SDL_mixer
LIBS += -LC:/Library/Frameworks/SDL2_mixer-2.0.0/lib/x86 -lSDL2_mixer
INCLUDEPATH += C:/Library/Frameworks/SDL2_mixer-2.0.0/include
#SDL2 ttf
LIBS += -LC:/Library/Frameworks/SDL2_ttf-2.0.14/lib/x86 -lSDL2_ttf
INCLUDEPATH += C:/Library/Frameworks/SDL2_ttf-2.0.14/include/

#ftgl
LIBS += -LC:/Library/Frameworks/ftgl/bin -lftgl
INCLUDEPATH += C:/Library/Frameworks/ftgl/include
LIBS += -LC:/Library/Frameworks/freetype2/lib -lfreetype
INCLUDEPATH += C:/Library/Frameworks/freetype2/include
INCLUDEPATH += C:/Library/Frameworks/freetype2/include/freetype2

#libconfig
LIBS += -LC:/Library/Frameworks/libconfig/bin -llibconfig
INCLUDEPATH += C:/Library/Frameworks/libconfig/include

PRECOMPILED_HEADER = stdafx.h

SOURCES += main.cpp \
    core/appcore.cpp \
    core/stateManager/state.cpp \
    core/stateManager/statemanager.cpp \
    core/processManager/processmanager.cpp \
    input/inputmanager.cpp \
    graphics/graphicmanager.cpp \
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
    core/console.cpp \
    core/processManager/processes/drawprocess.cpp \
    core/processManager/processes/keyboardenquiryprocess.cpp \
    input/controlmappingsmanager.cpp \
    input/keycombination.cpp \
    core/stateManager/menustate.cpp \
    core/exception.cpp \
    core/stateManager/gamestate.cpp

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
    core/console.h \
    core/processManager/event.h \
    core/processManager/processes/drawprocess.h \
    core/processManager/processes/keyboardenquiryprocess.h \
    input/controlmappingsmanager.h \
    input/keycombination.h \
    core/stateManager/menustate.h \
    core/exception.h \
    core/stateManager/gamestate.h

OTHER_FILES += \
    todo.txt

DISTFILES += \
    README \
    resources/config.ini \
    resources/strings.ini \
    resources/courier.ttf
