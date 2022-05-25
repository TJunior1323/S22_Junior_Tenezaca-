#pragma once

#include "RendererImplementation.h"

namespace Engine
{
	class OpenGLRenderer : public RendererImplementation
	{
	public:
		virtual void Draw(Engine::Sprite& picture, int xPos, int yPos, int zPos, Engine::Shader shader) override;
		virtual void ClearScreen() override;
	};
}