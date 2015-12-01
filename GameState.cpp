#include "GameState.h"
#include "Spear.h"
#include "Enemy.h"
#include <vector>
#include <iostream>

//Generate a spear and add it to vector
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

//Add an Enemy instance to the slime Vector
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

STATE GameState::splashScreen()
{
	sfw::drawTexture(getTexture("Title"), 400, 650, 400, 200, 0, true, 0);
	sfw::drawTexture(getTexture("press"), 400, 100, 300, 100, 0, true, 0);
	sfw::drawTexture(getTexture("move"), 400, 350, 300, 100, 0, true, 0);
	sfw::drawTexture(getTexture("fire"), 400, 250, 300, 100, 0, true, 0);
	if (sfw::getKey('F'))
	{
		return Game;
	}
	else return Splash;
}

STATE GameState::mainMenu()
{
	return Game;
}

//Update all the things
void GameState::update()
{
	//Update the Player's position and check for other things
	dKnight.update();

	//Check if player has invinFrames
	if (dKnight.invinFrames >= 0)
	{
		dKnight.invinFrames -= 12 * sfw::getDeltaTime();
	}

	//spawnRate decrease so Slime's won't explode onto screen
	spawnRate -= sfw::getDeltaTime();
	
	//When spawRate hits zero spawn a slime and reset spawnRate
	if (spawnRate <= 0)
	{
		spawnSlime();
		spawnRate = 2.0f;
	}
	
	//Update and Generate slimes if needed
	for (int i = 0; i < slime.size(); ++i)
	{
		if (slime[i].isActive)
		{
			slime[i].update(dKnight);
			doCollision(slime[i], dKnight);
			if (slime[i].health <= 0)
			{
				++dKnight.score;
				slime[i].isActive = false;
				if (!slime[i].isActive)
				{
					slime.erase(slime.begin() + i);
				}
			}
		}
	}

	//Update and Generate Spears if needed
	for (int i = 0; i < spear.size(); ++i)
	{
		if (spear[i].isActive)
		{
			spear[i].update();
			for (int j = 0; j < slime.size(); ++j)
			{
				doCollision(spear[i], slime[j]);
			}
		}
	}
}

//Draw all the things
STATE GameState::draw()
{
	//Draw the Background first every draw phase
	sfw::drawTexture(getTexture("Background"), 400, 400, 800, 800, 0, true, 0);
	sfw::drawString(getTexture("font"), "score", 50, 750, 25, 10, 0, ' ');

	//Check for Active Spears and draw them
	for (int i = 0; i < spear.size(); ++i)
	{
		if (spear[i].isActive)
		{
			spear[i].draw();
		}
	}

	//Check for Active Slimes and draw them if needed
	for (int i = 0; i < slime.size(); ++i)
	{
		if (slime[i].isActive)
		{
			slime[i].draw();
		}
	}

	//Draw the Player last so it's drawn on top of everything
	dKnight.draw();

	if (dKnight.pScore >= 10)
	{
		dKnight.pScore = 0;
		dKnight.health = 5;
		return Win; //Replace this with win game function
	}

	if (dKnight.health <= 0)
	{
		dKnight.pScore = 0;
		dKnight.health = 5;
		return Lose; //Replace with death function
	}

	return Game;
}

STATE GameState::win()
{
	sfw::drawTexture(getTexture("win"), 400, 400, 400, 200, 0, true, 0);
	sfw::drawTexture(getTexture("pressA"), 400, 100, 300, 100, 0, true, 0);
	if (sfw::getKey('A'))
	{
		return Splash;
	}
	return Win;
}

STATE GameState::lose()
{
	sfw::drawTexture(getTexture("lose"), 400, 400, 400, 200, 0, true, 0);
	sfw::drawTexture(getTexture("pressA"), 400, 100, 300, 100, 0, true, 0);
	if (sfw::getKey('A'))
	{
		return Splash;
	}
	return Lose;
}