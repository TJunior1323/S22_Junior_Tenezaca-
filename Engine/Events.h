#pragma once

#include "EngineUtil.h"
namespace Engine
{


	class ENGINE_API KeyPressedEvents
	{
	public:
		KeyPressedEvents(int codeofKey);
		KeyPressedEvents() = delete;

		int GetKeyCode() const;

	private:
		int mKeyCode;

	};

	class ENGINE_API KeyReleasedEvents
	{
	public:
		KeyReleasedEvents(int codeofKey);
		KeyReleasedEvents() = delete;

		int GetKeyCode() const;

	private:
		int mKeyCode;

	};
}
