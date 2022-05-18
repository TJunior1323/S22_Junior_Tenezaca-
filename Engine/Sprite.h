#pragma once

#include "SpriteImplementation.h"
#include "EngineUtil.h"

namespace Engine
{
	class ENGINE_API Sprite
	{
	public:
		Sprite(const std::string& filename);

		int GetWidth() const;
		int GetHeight() const;

		void Bind();

	private:
		SpriteImplementation* mImplementation;
	};
}