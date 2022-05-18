#pragma once

#include "SpriteImplementation.h"

namespace Engine
{

	class OpenGLSprite : public SpriteImplementation
	{
	public:
		OpenGLSprite(const std::string& fileName);

		virtual int GetWidth() const override;
		virtual int GetHeight() const override;
		virtual void Bind() override;
		virtual bool IsBound() override;

	private:

		unsigned int mVBO;
		unsigned int mVAO;
		unsigned int mEBO;
		unsigned int mTex;
		int mWidth{ 0 };
		int mHeight{ 0 };

	};
}
