#include "pch.h"
#include "Events.h"

namespace Engine
{


	KeyPressedEvents::KeyPressedEvents(int codeofKey): mKeyCode(codeofKey)
	{
	}
	int KeyPressedEvents::GetKeyCode() const
	{
		return mKeyCode;
	}
	KeyReleasedEvents::KeyReleasedEvents(int codeofKey): mKeyCode(codeofKey)
	{

	}

	int KeyReleasedEvents::GetKeyCode() const
	{
		return mKeyCode;
	}

}