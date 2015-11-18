#pragma once
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>

class GameState
{
	GameState()
	{
		GameObject::gs() = this;
	}

	Player deer;
	std::vector<Enemy> enemies;

public:
	void update();
	void draw();

	void enemyDeath(Enemy &enemy);
	void gameOver(Player &player);
};