#pragma once

#include "EngineApp.h"
#include "GameWindow.h"
#define ENGINE_APPLICATION_START(classname) \
\
int main()\
{\
	classname game;\
	game.Run();\
}