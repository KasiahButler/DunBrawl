#include "GameObject.h"
#include "GameState.h"
#include "AssetManager.h"
#include "Player.h"
#include "sfwdraw.h"

int main()
{
	sfw::initContext(800, 800, "Basic");
	loadTexture("Background", "./Textures/Dungeon.png", 1, 1);
	loadTexture("dKnight", "./Textures/dKnight.png", 4, 4);
	GameState game;
	
	while (sfw::stepContext())
	{
		game.update();
		game.draw();
	}
	sfw::termContext();
	return 0;
}