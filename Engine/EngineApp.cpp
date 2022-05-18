#include "pch.h"


#include "EngineApp.h"
#include "GameWindow.h"

#include "glad/glad.h"
#include "Sprite.h"

namespace Engine
{
	void EngineApp::Run()
	{
		ENGINE_LOG("Game Engine is running");

		Engine::GameWindow::Init();

		Engine::GameWindow::GetWindow()->CreateWindow(800, 600, "Game Window");

		// SHADERS

		const char *vertexShader = R"(
			#version 330 core
			layout (location = 0) in vec2 rawCoords;
			layout (location = 1) in vec2 tCoordInput;

			out vec2 TexturePoints;

			void main()
			{
				gl_Position = vec4(rawCoords.x, rawCoords.y, 0.0f, 1.0f);
				TexturePoints = tCoordsInput;
			}
		)";
		const char *fragmentShader = R"(
			#version 330 core
			out vec4 FragColor;

			in vec2 TexturePoints;

			uniform sampler2D picture;

			void main()
			{
				FragColor = texture(picture, TexturePoints);
				//FragColor = vec4 (1.0f, 0.0f, 0.0f, 1.0f);
			}
		)";
		unsigned int vertexProg = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertexProg, 1, &vertexShader, NULL);
		glCompileShader(vertexProg); 
		// CHECK FOR SHADER COMPILE ERRORS
		int success;
		char infoLog[512];
		glGetShaderiv(vertexProg, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(vertexProg, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		}

		// FRAGMENT SHADER 
		unsigned int fragmentProg = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragmentProg, 1, &fragmentShader, NULL);
		glCompileShader(fragmentProg);
		// CHECK FOR SHADER COMPILE ERRORS
		glGetShaderiv(fragmentProg, GL_COMPILE_STATUS, &success);
		if (!success) 
		{
			glGetShaderInfoLog(fragmentProg, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
		}
		// LINK SHADERS
		unsigned int shaderProgram = glCreateProgram();
		glAttachShader(shaderProgram, vertexProg);
		glAttachShader(shaderProgram, fragmentProg);
		glLinkProgram(shaderProgram);
		// CHECK FOR LINKING ERRORS
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		}

		glDeleteShader(vertexProg);
		glDeleteShader(fragmentProg);
			
		Engine::Sprite star{"Engine/Assets/Star.png"};

		while (true)
		{
			OnUpdate();

			glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);

			glUseProgram(shaderProgram);
			star.Bind();
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);




			Engine::GameWindow::GetWindow()->SwapBuffers();
			Engine::GameWindow::GetWindow()->CollectEvents();



		}
	}
	void EngineApp::OnUpdate()
	{

	}


}