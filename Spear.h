#pragma once
#include "GameObject.h"

class Spear : public GameObject
{
private:
	float velx, vely;
	float duration;
	int rotation;
public:
	Spear(float px, float py, float vx, float vy, float life, int rotate)
	{
		x = px;
		y = py;
		rotation = rotate;

		velx = vx;
		vely = vy;

		duration = life;

		isActive = true;
	}

	void update();
	void draw();
};