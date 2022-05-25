#include "pch.h"


#include "EngineApp.h"
#include "GameWindow.h"
#include "KeyCodes.h"

#include "Sprite.h"
#include "Shader.h"
#include "Renderer.h"
#include "Events.h"


namespace Engine
{
	EngineApp::EngineApp()
	{
		ENGINE_LOG("Game Engine is running");

		Engine::GameWindow::Init();

		Engine::GameWindow::GetWindow()->CreateWindow(1440, 1080, "Game Window");

		Renderer::Init();
	}

	void EngineApp::Run()
	{

		mNextFrameTime = std::chrono::steady_clock::now() + mFrameDuration;

		while (true)
		{
			Renderer::ClearScreen();

			OnUpdate();



			std::this_thread::sleep_until(mNextFrameTime);

			Engine::GameWindow::GetWindow()->SwapBuffers();
			Engine::GameWindow::GetWindow()->CollectEvents();

			mNextFrameTime += mFrameDuration;



		}
	}
	void EngineApp::OnUpdate()
	{

	}

	void EngineApp::SetKeyPressedCallback(std::function<void(const KeyPressedEvents&)> keyPressedCallback)
	{
		GameWindow::GetWindow()->SetKeyPressedCallback(keyPressedCallback);
	}

	void EngineApp::SetKeyReleasedCallback(std::function<void(const KeyReleasedEvents&)> keyReleasedCallback)
	{
		GameWindow::GetWindow()->SetKeyReleasedCallback(keyReleasedCallback);
	}


}