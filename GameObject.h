#pragma once
#include <string>
#include "sfwdraw.h"
#include "AssetManager.h"

// Forward declaration
// Hint to the compiler that this object WILL EXIST AT SOME POINT.
// Okay to make pointers, but not actual instances.
class GameState;

class GameObject
{
public:
	// Static functions DON'T need a gameObject to be called,
	// they are kinda like global functions (normal ones).
	// The difference is that the 'class' is now a namespace.
	// e.g. GameObject::gs()
	static GameState *&gs()   // return type is a reference to a pointer.
	{
		static GameState *game;
		return game;
	}

	//Variables for Drawing Objects
	std::string textureName;
	float x, y, width, height, angle;
	bool isActive;

	//Variables for Animating Objects
	std::string animName;
	float animTimer;
	unsigned currentFrame;

	GameObject() : x(400), y(300), width(60), height(60), angle(0),
		currentFrame(0), animTimer(0), isActive(true) {}

	//Draws an object to screen from the GameObject, modifiable for any inheriting classes
	virtual void draw()
	{
		sfw::drawTexture(getTexture(textureName), x, y, width, height, angle, true, currentFrame);
	}

	//Updates the Animation of the Object, should also update position (Maybe detect collision?)
	virtual void update()
	{
		animTimer += sfw::getDeltaTime();
		currentFrame = sampleAnimation(textureName, animName, animTimer);
	}

	//Do something when collision happens
	virtual void onCollsion(GameObject &object, float distance) {}
};

//Checks for collision between two objects
float doCollision(GameObject &object1, GameObject &object2);