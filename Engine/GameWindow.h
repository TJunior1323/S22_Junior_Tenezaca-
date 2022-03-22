#pragma once

#include "WindowImplementation.h"
#include "EngineUtil.h"

namespace Engine
{
	class ENGINE_API GameWindow
	{
	public:
		static void Init();
		static GameWindow* GetWindow();

		bool CreateWindow(int width, int height, const std::string& windowName);
		void SwapBuffers();
		void CollectEvents();
		int GetWidth() const;
		int GetHeight() const;


	private:
		inline static GameWindow* mInstance{ nullptr };

		GameWindow();

		WindowImplementation* mWindow{ nullptr };
	};
}

//		GameWindow::GetWindow()->GetWidth();