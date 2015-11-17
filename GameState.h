#pragma once
#include "GameObject.h"

class GameState
{
	GameState()
	{
		GameObject::gs() = this;
	}


};