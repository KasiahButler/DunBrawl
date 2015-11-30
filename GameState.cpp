#include "GameState.h"
#include "Spear.h"
#include "Enemy.h"
#include <vector>
#include <iostream>

void GameState::throwSpear(float px, float py, float vx, float vy, float life, int rotate)
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

void GameState::spawnSlime()
{
	for (int i = 0; i < slime.size(); ++i)
	{
		if (!slime[i].isActive)
		{
			slime[i] = Enemy();
		}
	}
	slime.push_back(Enemy());
}

void GameState::update()
{
	dKnight.update();

	spawnSlime();

	for (int i = 0; i < slime.size(); ++i)
	{
		if (slime[i].isActive)
		{
			slime[i].update(dKnight);
			doCollision(slime[i], dKnight);
			if (slime[i].health == 0)
			{
				slime[i].isActive = false;
			}
		}
		else slime.erase(slime.begin() + (i - 1));
	}

	for (int i = 0; i < spear.size(); ++i)
	{
		if (spear[i].isActive)
		{
			spear[i].update();
			for (int j = 0; j > slime.size(); ++j)
			{
				doCollision(spear[i], slime[j]);
			}
		}
	}

	if (dKnight.health == 0) { std::cout << "you've died" << std::endl; }
}

void GameState::draw()
{
	sfw::drawTexture(getTexture("Background"), 400, 400, 800, 800, 0, true, 0);

	for (int i = 0; i < spear.size(); ++i)
	{
		if (spear[i].isActive)
		{
			spear[i].draw();
		}
	}

	for (int i = 0; i < slime.size(); ++i)
	{
		if (slime[i].isActive)
		{
			slime[i].draw();
		}
	}

	dKnight.draw();

}