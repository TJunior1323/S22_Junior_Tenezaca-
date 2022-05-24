#include "pch.h"
#include "OpenGLRenderer.h"
#include "GameWindow.h"
#include "glad/glad.h"

namespace Engine
{
	void OpenGLRenderer::Draw(Engine::Sprite& picture, int xPos, int yPos, int zPos, Engine::Shader shader)
	{
		int winWidth{GameWindow::GetWindow()->GetWidth()};
		int winHeight{ GameWindow::GetWindow()->GetHeight() };

		shader.Bind();
		picture.Bind();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);


		shader.SetUniform2Ints("windowSize", winWidth, winHeight);
		shader.SetUniform3Ints("spriteCoord", xPos, yPos, zPos);

		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

	}

}