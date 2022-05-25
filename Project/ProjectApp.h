#pragma once

#include "Engine.h"
#include "Entity.h"


class ProjectApp : public Engine::EngineApp
{
public:

	ProjectApp();

	virtual void OnUpdate() override;

	bool Collide(const Entity& one, const Entity& another);

private:
	Entity mHero{ {"Assets/Images/RightHero.png", "Assets/Images/LeftHero.png"} };
	std::vector<Entity> mDangers{ { {"Assets/Images/Dangers/Danger.png"}}};
	std::vector<Entity> mDangers2{ { {"Assets/Images/Dangers/Dangers2.png"}} };

	int mEnemyVSpeed{ -10 };


	int mHorizontalSpeed{ 0 }; // Speed measured in pixels per frame
	int mVerticalSpeed{ 0 };

};