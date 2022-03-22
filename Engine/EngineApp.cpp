#include "pch.h"

#include "EngineApp.h"
#include "GameWindow.h"

namespace Engine
{
	void EngineApp::Run()
	{
		ENGINE_LOG("Game Engine is running");

		Engine::GameWindow::Init();
		

		Engine::GameWindow::GetWindow()->CreateWindow(800, 600, "Game Window");

		while (true)
		{
			OnUpdate();

			Engine::GameWindow::GetWindow()->SwapBuffers();
			Engine::GameWindow::GetWindow()->CollectEvents();



		}
	}
	void EngineApp::OnUpdate()
	{

	}


}