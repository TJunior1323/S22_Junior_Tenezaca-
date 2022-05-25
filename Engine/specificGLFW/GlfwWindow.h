#pragma once

#include "../WindowImplementation.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Events.h"

namespace Engine
{
	class GlfwWindow : public WindowImplementation
	{
	public:
		GlfwWindow();
		virtual bool CreateWindow(int width, int height, const std::string& windowName) override;
		virtual void SwapBuffers() override;
		virtual void CollectEvents() override;
		virtual int GetWidth() const override;
		virtual int GetHeight() const override;
		~GlfwWindow();

		virtual void SetKeyPressedCallback(std::function<void(const KeyPressedEvents&)> keyPressedCallback) override;
		virtual void SetKeyReleasedCallback(std::function<void(const KeyReleasedEvents&)> keyReleasedCallback) override;

	private:

		struct Callbacks
		{
			std::function<void(const KeyPressedEvents&)> keyPressedCallback{ [](const KeyPressedEvents&) {} };
			std::function<void(const KeyReleasedEvents&)> keyReleasedCallback{ [](const KeyReleasedEvents&) {} };
		} mCallbacks;

		GLFWwindow* mGlfwWindow{ nullptr };


	};



}