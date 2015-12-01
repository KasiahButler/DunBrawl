#pragma once
#include "GameObject.h"

class Spear : public GameObject
{
private:
	//Spear Base Stats
	float velx, vely;
	float duration;
	int rotation;

public:
	//Set Constructor for Spear to be used when Player spawns new one
	Spear(float px, float py, float vx, float vy, float life, int rotate)
	{
		x = px;
		y = py;
		rotation = rotate;

		velx = vx;
		vely = vy;

		duration = life;

		textureName = "spear";
		isActive = true;
	}

	//Spear Functions
	void update();
	void draw();
	void onCollision(GameObject& object, float distance);
};