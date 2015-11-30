#include "GameState.h"
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

void GameState::update()
{
	dKnight.update();
	slime.update(dKnight);

	for (int i = 0; i < spear.size(); ++i)
	{
		if (spear[i].isActive)
		{
			spear[i].update();
			doCollision(spear[i], slime);
		}
	}

	doCollision(dKnight, slime);

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

	dKnight.draw();
	slime.draw();

}