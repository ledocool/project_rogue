#ifndef STDAFX_H
#define STDAFX_H
//Precompided header

//Global constants
const float PI = 3.14159265;

//Type defines
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char uchar;

//typedef unsigned int uint16_t;

//SDL
#include <SDL.h>
#include <SDL_opengl.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

//libconfig
#include <libconfig.h>

//OpenGL
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glaux.h>

//For computation
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <ctime>
#include <string>
#include <list>

//My classes
#include "etc/singleton.h"
#include "etc/camera.h"

#include "graphics/sprite.h"
#include "audio/music.h"
#include "audio/sound.h"

#include "audio/audiomanager.h"
#include "audio/audiomixer.h"

#include "graphics/graphicmanager.h"
#include "graphics/spritemanager.h"

#include "input/inputmanager.h"
#include "input/controlmappingsmanager.h"
#include "core/processManager/processmanager.h"
#include "core/stateManager/statemanager.h"

#endif // STDAFX_H
