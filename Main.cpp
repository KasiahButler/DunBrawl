#include "GameObject.h"
#include "GameState.h"
#include "AssetManager.h"
#include "Player.h"
#include "sfwdraw.h"
#include <Windows.h>

int main()
{
	//Render Game Window
	sfw::initContext(800, 800, "Basic");

	//Load Textures from File
	loadTexture("Background", "./Textures/Dungeon.png", 1, 1);
	loadTexture("Title",      "./Textures/title.png",   1, 1);
	loadTexture("dKnight",    "./Textures/dKnight.png", 4, 4);
	loadTexture("spear",      "./Textures/spear.PNG",   8, 8);
	loadTexture("slime",      "./Textures/Slime.png",   6, 4);
	loadTexture("press",      "./Textures/pressF.png",  1, 1);
	loadTexture("pressA",     "./Textures/pressA.png",  1, 1);
	loadTexture("win",        "./Textures/win.png",     1, 1);
	loadTexture("lose",       "./Textures/lose.png",    1, 1);
	loadTexture("move",       "./Textures/moveText.png",1, 1);
	loadTexture("fire",       "./Textures/fireText.png",1, 1);
	loadTexture("font",       "./Textures/fontmap.png", 16, 16);

	//Set Animations
	addAnimation("dKnight",   "walkLeft",  { 4, 5, 6, 7 });
	addAnimation("dKnight",   "walkRight", { 8, 9, 10, 11 });
	addAnimation("dKnight",   "walkUp",    { 12, 13, 14, 15 });
	addAnimation("dKnight",   "walkDown",  { 0, 1, 2, 3 });
	addAnimation("slime",     "slideUp",   { 0, 1, 2, 3 });

	//Instantiate necessary Classes
	GameState game;
	STATE state = Splash;
	
	//Set Main Game States and continue looping until exited
	while (sfw::stepContext())
	{
		switch (state)
		{
		case Splash:
			state = game.splashScreen(); break;
		case Main:
			return Game;
		case Game:
			game.update();
			state = game.draw(); break;
		case Win:
			state = game.win(); break;
		case Lose:
			state = game.lose(); break;
		}
	}
	sfw::termContext();
	return 0;
}