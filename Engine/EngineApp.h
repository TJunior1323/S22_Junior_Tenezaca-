#pragma once

#include "EngineUtil.h"

namespace Engine
{

	class ENGINE_API EngineApp
	{
	public:
		void Run();
		virtual void OnUpdate();
	};

}

