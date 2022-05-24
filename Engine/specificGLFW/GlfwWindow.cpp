#include "pch.h"

//#include "GameWindow.h"
#include "GlfwWindow.h"
#include "EngineUtil.h"
#include "glad/glad.h"

namespace Engine
{

	GlfwWindow::GlfwWindow()
	{
		if (!glfwInit())
			ENGINE_LOG("ERROR: GLFW failed to initiualize!");


	}

	bool GlfwWindow::CreateWindow(int width, int height, const std::string& windowName)
	{
		mGlfwWindow = glfwCreateWindow(width, height, windowName.c_str(), NULL, NULL);

		if (mGlfwWindow == nullptr)
		{
			ENGINE_LOG("ERROR: window creation failed!");
			return false;
		}
		
		glfwMakeContextCurrent(mGlfwWindow);
		

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			ENGINE_LOG("Glad failed to initialize");

		return true;

	}

	void GlfwWindow::SwapBuffers()
	{
		glfwSwapBuffers(mGlfwWindow);
	}

	void GlfwWindow::CollectEvents()
	{
		glfwPollEvents();
	}

	int GlfwWindow::GetWidth() const
	{
		int width, height;
		glfwGetWindowSize(mGlfwWindow, &width, &height);
		return width;
	}
	int GlfwWindow::GetHeight() const
	{
		int width, height;
		glfwGetWindowSize(mGlfwWindow, &width, &height);
		return height;
	}

	GlfwWindow::~GlfwWindow()
	{
		if (mGlfwWindow != nullptr)
			glfwDestroyWindow(mGlfwWindow);

		glfwTerminate();
	}





}