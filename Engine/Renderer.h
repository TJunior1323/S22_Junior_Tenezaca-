#pragma once

#include "Sprite.h"
#include "Shader.h"
#include "RendererImplementation.h"

namespace Engine
{


	class Renderer
	{
	public:
		static void Init();
		static void Draw(Engine::Sprite& picture, int xPos, int yPos, int zPos);


	private:
		inline static Renderer* mInstance{ nullptr };
		RendererImplementation* mImplementation{ nullptr };

		Renderer();

		Engine::Shader mShader;
	};

}
