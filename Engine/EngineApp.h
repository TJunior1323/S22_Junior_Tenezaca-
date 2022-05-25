#pragma once

#include "EngineUtil.h"
#include "pch.h"
#include "Events.h"

#define ENGINE_FRAMERATE 60

namespace Engine
{

	class ENGINE_API EngineApp
	{
	public:
		EngineApp();
		void Run();
		virtual void OnUpdate();
		void SetKeyPressedCallback(std::function<void(const KeyPressedEvents &)>  keyPressedCallback);
		void SetKeyReleasedCallback(std::function<void(const KeyReleasedEvents&)>  keyReleasedCallback);

	private:
		std::chrono::milliseconds mFrameDuration{ 1000 / ENGINE_FRAMERATE };
		std::chrono::steady_clock::time_point mNextFrameTime;
	};

}

