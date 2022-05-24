#pragma once

#include "Sprite.h"
#include "Shader.h"


namespace Engine
{
	class RendererImplementation
	{
	public:
		virtual void Draw(Engine::Sprite& picutre, int xPos, int yPos, int zPos, Engine::Shader shader) = 0;
	};
}