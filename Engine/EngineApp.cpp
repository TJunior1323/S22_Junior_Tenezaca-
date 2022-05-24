#include "pch.h"


#include "EngineApp.h"
#include "GameWindow.h"

#include "glad/glad.h"
#include "Sprite.h"
#include "Shader.h"
#include "Renderer.h"


namespace Engine
{
	void EngineApp::Run()
	{
		ENGINE_LOG("Game Engine is running");

		Engine::GameWindow::Init();

		Engine::GameWindow::GetWindow()->CreateWindow(800, 600, "Game Window");

		Renderer::Init();

		Engine::Sprite star{"../Engine/Assets/Images/Star.png"};

		while (true)
		{
			OnUpdate();

			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			Renderer::Draw(star, 50, 20, 1);

			Engine::GameWindow::GetWindow()->SwapBuffers();
			Engine::GameWindow::GetWindow()->CollectEvents();



		}
	}
	void EngineApp::OnUpdate()
	{

	}


}