#pragma once
#include "GameObject.h"
#include "Player.h"
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
	std::vector<Enemy> enemies;

	void update()
	{
		dKnight.update();
	}
	void draw()
	{
		sfw::drawTexture(getTexture("Background"), 400, 400, 800, 800, 0, true, 0);
		dKnight.draw();a
	}
};