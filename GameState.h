#pragma once
#include "GameObject.h"
#include "Player.h"
#include "Spear.h"
#include "Enemy.h"
#include <time.h>
#include <vector>
#include <stdlib.h>

enum STATE { Splash, Main, Game, Win, Lose };

class GameState
{
public:
	float spawnRate = 2.0f;

	//Set Base Constructor to make the pointer in GameObject gs point to this Class
	GameState()
	{
		GameObject::gs() = this;
	}

	//Instantiate Classes needed for Main Game Loop
	Player dKnight;
	std::vector<Spear> spear;
	std::vector<Enemy> slime;

	//Spawn new Enemies/Projectiles
	void throwSpear(float px, float py, float vx, float vy, float life, int rotate);
	void spawnSlime();

	//Main Game Functionality
	STATE splashScreen();
	STATE mainMenu();
	void update();
	STATE draw();
	STATE win();
	STATE lose();
};