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
		glfwSwapInterval(1);
		

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			ENGINE_LOG("Glad failed to initialize");

		glfwSetWindowUserPointer(mGlfwWindow, &mCallbacks);

		glfwSetKeyCallback(mGlfwWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				if (action == GLFW_PRESS || action == GLFW_REPEAT)
				{
					Callbacks* userPointer{ (Callbacks*)glfwGetWindowUserPointer(window) };

					KeyPressedEvents event{ key };
					userPointer->keyPressedCallback(event);
				}
				else if (action == GLFW_RELEASE)
				{
					Callbacks* userPointer{ (Callbacks*)glfwGetWindowUserPointer(window) };

					KeyReleasedEvents event{ key };
					userPointer->keyReleasedCallback(event);
				}

			}
		);


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

	void GlfwWindow::SetKeyPressedCallback(std::function<void(const KeyPressedEvents&)> keyPressedCallback)
	{
		mCallbacks.keyPressedCallback = keyPressedCallback;
	}

	void GlfwWindow::SetKeyReleasedCallback(std::function<void(const KeyReleasedEvents&)> keyReleasedCallback)
	{
		mCallbacks.keyReleasedCallback = keyReleasedCallback;
	}


}