#pragma once
#include "GameObject.h"
#include "Player.h"
#include "Spear.h"
#include "Enemy.h"
#include <vector>

class GameState
{
public:
	float spawnRate = 2.0f;
	//Set Base Constructor to make the pointer in GameObject gs point to this Class
	GameState()
	{
		GameObject::gs() = this;
	}

	Player dKnight;
	std::vector<Spear> spear;
	std::vector<Enemy> slime;

	void throwSpear(float px, float py, float vx, float vy, float life, int rotate);
	void spawnSlime();

	void update();
	void draw();
};