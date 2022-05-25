#include "Entity.h"
#include "Engine.h"

Entity::Entity(const std::vector<std::string>& filenames): 
	mImages(filenames.begin(), filenames.end())
{
}

int Entity::GetX() const
{
	return mXPos;
}

int Entity::GetY() const
{
	return mYPos;
}

int Entity::GetZ() const
{
	return mZPos;
}

bool Entity::GetSolid() const
{
	return mSolid;
}

int Entity::GetActiveImage() const
{
	return mActiveImage;
}

int Entity::GetWidth() const
{
	return mImages[mActiveImage].GetWidth();
}

int Entity::GetHeight() const
{
	return mImages[mActiveImage].GetHeight();
}

void Entity::SetX(int newX)
{
	mXPos = newX;
}

void Entity::SetY(int newY)
{
	mYPos = newY;
}

void Entity::SetZ(int newZ)
{
	mZPos = newZ;
}

void Entity::SetSolid(bool newSolid)
{
	mSolid = newSolid;
}

void Entity::SetActiveImage(int newActiveImage)
{
	mActiveImage = newActiveImage;
}

void Entity::Draw()
{
	Engine::Renderer::Draw(mImages[mActiveImage], mXPos, mYPos, mZPos);
}
