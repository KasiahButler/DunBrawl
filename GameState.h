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
	Enemy slime;

	void throwSpear(float px, float py, float vx, float vy, float life, int rotate);

	void update();

	void draw();
};