#include "GameObject.h"
#include "GameState.h"
#include "AssetManager.h"
#include "Player.h"
#include "sfwdraw.h"
#include <Windows.h>

int main()
{
	FreeConsole();
	sfw::initContext(800, 800, "Basic");
	loadTexture("Background", "./Textures/Dungeon.png", 1, 1);
	loadTexture("dKnight", "./Textures/dKnight.png", 4, 4);
	loadTexture("spear", "./Textures/spear.PNG", 8, 8);
	loadTexture("slime", "./Textures/Slime.png", 6, 4);
	addAnimation("dKnight", "walkLeft", { 5, 6, 7, 8 });
	addAnimation("dKnight", "walkRight", { 9, 10, 11, 12 });
	addAnimation("dKnight", "walkUp", { 13, 14, 15, 16 });
	addAnimation("dKnight", "walkDown", { 1, 2, 3, 4 });

	GameState game;
	
	while (sfw::stepContext())
	{
		game.update();
		game.draw();
	}
	sfw::termContext();
	return 0;
}