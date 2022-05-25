#pragma once

#include "Sprite.h"
#include "Shader.h"
#include "RendererImplementation.h"
#include "EngineUtil.h"

namespace Engine
{


	class ENGINE_API Renderer
	{
	public:
		static void Init();
		static void Draw(Engine::Sprite& picture, int xPos, int yPos, int zPos);
		static void ClearScreen();


	private:
		inline static Renderer* mInstance{ nullptr };
		RendererImplementation* mImplementation{ nullptr };

		Renderer();

		Engine::Shader mShader;
	};

}
