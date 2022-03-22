#pragma once

#include "pch.h"

#ifdef ENGINE_WINDOWS
	#ifdef ENGINE_LIB
		#define ENGINE_API __declspec(dllexport)
	#else
		#define	ENGINE_API __declspec(dllexport)
	#endif
#else
	#define ENGINE_API
#endif

#ifdef ENGINE_DEBUG
	#define ENGINE_LOG(x) std::cout<<x<<std::endl;
#else
	#define ENGINE_LOG(x)
#endif

