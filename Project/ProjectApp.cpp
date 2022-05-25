#include "ProjectApp.h"

ProjectApp::ProjectApp()
{
	SetKeyPressedCallback([this](const Engine::KeyPressedEvents& e) {
		switch (e.GetKeyCode())
		{
		case ENGINE_KEY_LEFT:
			mHorizontalSpeed = -10;
			mHero.SetActiveImage(1);
			break;
		case ENGINE_KEY_RIGHT:
			mHorizontalSpeed = 10;
			mHero.SetActiveImage(0);
			break;
		case ENGINE_KEY_UP:
			mVerticalSpeed = 10;
			mHero.SetActiveImage(0);
			break;
		case ENGINE_KEY_DOWN:
			mVerticalSpeed = -10;
			mHero.SetActiveImage(0);
			break;
		case ENGINE_KEY_ESCAPE:
			exit(0);
			break;
		}
		});

	SetKeyReleasedCallback([this](const Engine::KeyReleasedEvents& e) {
		mHorizontalSpeed = 0;
		mVerticalSpeed = 0;
		});


	mDangers[0].SetX(300);
	mDangers[0].SetY(300);

	///////////////////////////////

	mDangers2[0].SetX(900);
	mDangers2[0].SetY(300);

}

void ProjectApp::OnUpdate()
{
	mHero.SetX(mHero.GetX() + mHorizontalSpeed);
	mHero.SetY(mHero.GetY() + mVerticalSpeed);

	if (mDangers[0].GetY() < 0)
		mEnemyVSpeed *= -1;
	else if (mDangers[0].GetY() > Engine::GameWindow::GetWindow()->GetHeight() - mDangers[0].GetHeight())
		mEnemyVSpeed *= -1;

	mDangers[0].SetY(mDangers[0].GetY() + mEnemyVSpeed);

	if (Collide(mHero, mDangers[0]))
	{
		exit(0);
	}


	mDangers2[0].SetY(mDangers2[0].GetY() + mEnemyVSpeed);

	if (Collide(mHero, mDangers2[0]))
	{
		exit(0);
	}

	mHero.Draw();
	mDangers[0].Draw();
	mDangers2[0].Draw();

}

bool ProjectApp::Collide(const Entity& one, const Entity& another)
{
	int oneLeft{ one.GetX() };
	int oneRight{ one.GetX() + one.GetWidth() };
	int anotherLeft{ another.GetX() };
	int anotherRight{ another.GetX() + another.GetWidth() };

	int oneBottom{ one.GetY() };
	int oneTop{ one.GetY() + one.GetHeight() };
	int anotherBottom{ another.GetY() };
	int anotherTop{ another.GetY() + another.GetHeight() };

	bool collideX{ false };
	if ((oneLeft <= anotherLeft && anotherLeft <= oneRight) ||
		(anotherLeft <= oneLeft && oneLeft <= anotherRight))
		collideX = true;

	bool collideY{ false };
	if ((oneBottom <= anotherBottom && anotherBottom <= oneTop) ||
		(anotherBottom <= oneBottom && oneBottom <= anotherTop))
		collideY = true;

	return collideX && collideY;

}
