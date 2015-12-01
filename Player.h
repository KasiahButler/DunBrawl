#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:
	//Player Stats
	float speed;
	float rateOfFire;
	int health;
	float invinFrames;
	int pScore;

	//Base Player Constructor sets "Stats" to reasonable Defaults
	Player() : speed(150), rateOfFire(0.5f), health(5)
	{
		width = 64; height = 64; x = 400; y = 400;
		textureName = "dKnight";
		animName = "walkDown";
	}

	//Player Functions
	virtual void update();
	virtual void draw();
	void onCollision(GameObject &object, float distance);
};
