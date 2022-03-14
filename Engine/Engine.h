#pragma once

#include "EngineApp.h"
#define ENGINE_APPLICATION_START(classname) \
\
int main()\
{\
	classname game;\
	game.Run();\
}