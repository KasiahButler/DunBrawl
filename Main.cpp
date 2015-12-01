#include "GameObject.h"
#include "GameState.h"
#include "AssetManager.h"
#include "Player.h"
#include "sfwdraw.h"
#include "Menus.h"
#include <Windows.h>

int main()
{
	//Render Game Window
	sfw::initContext(800, 800, "Basic");

	//Load Textures from File
	loadTexture("Background", "./Textures/Dungeon.png", 1, 1);
	loadTexture("dKnight",    "./Textures/dKnight.png", 4, 4);
	loadTexture("spear",      "./Textures/spear.PNG",   8, 8);
	loadTexture("slime",      "./Textures/Slime.png",   6, 4);

	//Set Animations
	addAnimation("dKnight",   "walkLeft",  { 4, 5, 6, 7 });
	addAnimation("dKnight",   "walkRight", { 8, 9, 10, 11 });
	addAnimation("dKnight",   "walkUp",    { 12, 13, 14, 15 });
	addAnimation("dKnight",   "walkDown",  { 0, 1, 2, 3 });
	addAnimation("slime",     "slideUp",   { 0, 1, 2, 3 });

	//Instantiate necessary Classes
	GameState game;
	STATE state;
	
	//Set Main Game States and continue looping until exited
	while (sfw::stepContext())
	{
	//	switch (state = Game)
	//	{
	//	case Game :
			/*state =*/ game.update();
			/*state =*/ game.draw();
		//case Main :
		//    return Exit;
		//case Splash:
	 //    	return Exit;
		//case Exit:
		//	break;
	}
	sfw::termContext();
	return 0;
}