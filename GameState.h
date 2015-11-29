#pragma once
#include "GameObject.h"
#include "Player.h"
#include "Spear.h"
#include "Enemy.h"
#include <vector>

class GameState
{
public:
	//Set Base Constructor to make the pointer in GameObject to gs point to this Class
	GameState()
	{
		GameObject::gs() = this;
	}

	Player dKnight;
	std::vector<Spear> spear;
	std::vector<Enemy> enemies;

	void throwSpear(float px, float py, float vx, float vy, float life, int rotate)
	{
		for (int i = 0; i < spear.size(); ++i)
		{
			if (!spear[i].isActive)
			{
				spear[i] = Spear(px, py, vx, vy, life, rotate);
			}
		}
		spear.push_back(Spear(px, py, vx, vy, life, rotate));
	}

	void update()
	{
		dKnight.update();

		for (int i = 0; i < spear.size(); ++i)
		{
			if (spear[i].isActive)
			{
				spear[i].update();
			}
		}
	}
	void draw()
	{
		sfw::drawTexture(getTexture("Background"), 400, 400, 800, 800, 0, true, 0);
		
		for (int i = 0; i < spear.size(); ++i)
		{
			if (spear[i].isActive)
			{
				spear[i].draw();
			}
		}

		dKnight.draw();
	}
};