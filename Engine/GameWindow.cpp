#include "pch.h"
#include "GameWindow.h"
#include "specificGLFW/Glfwwindow.h"

namespace Engine
{
	void GameWindow::Init()
	{
		if (mInstance == nullptr)
			mInstance = new GameWindow;
	}
	GameWindow* GameWindow::GetWindow()
	{
		assert(mInstance);
		return mInstance;
	}

	bool GameWindow::CreateWindow(int width, int height, const std::string& windowName)
	{
		return mWindow->CreateWindow(800, 600, "Project 2022");
	}

	void GameWindow::SwapBuffers()
	{
		mWindow->SwapBuffers();
	}

	void GameWindow::CollectEvents()
	{
		mWindow->CollectEvents();
	}

	int GameWindow::GetWidth() const
	{
		return mWindow->GetWidth();
	}

	int GameWindow::GetHeight() const
	{
		return mWindow->GetHeight();
	}

	GameWindow::GameWindow()
	{
#ifdef ENGINE_WINDOWS
	mWindow = new GlfwWindow;
#elif defined ENGINE_MACOS
	mWindow = new GlfwWindow;
#elif defined ENGINE_LINUX
	mWindow = new GlfwWindow;
#else
	#Unsupported_platform
#endif

	}

}