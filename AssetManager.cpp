#include "AssetManager.h"
#include <map>
#include <iostream>
#include "sfwdraw.h"

//Connects loaded texture to a name
static std::map<std::string, unsigned> textures;

//Loads texture by name
void loadTexture(const std::string &name, const char *path, unsigned r, unsigned c)
{
	textures[name] = sfw::loadTextureMap(path, r, c);
}


unsigned getTexture(const std::string &name)
{
	if (name == "")
	{
		std::cerr << "There's nothing here Jim" << std::endl;
		return 0;
	}
	if (textures[name] == 0)
	{
		std::cerr << name << " was not loaded!" << std::endl;
		return 0;
	}
	return textures[name];
}

static std::map<std::string, std::map<std::string, std::vector<unsigned>>> animations;

static std::map<std::string, std::map<std::string, float> > frameRates;

unsigned getFrame(const std::string &tname, const std::string &aname, unsigned frame)
{
	return animations[tname][aname][frame];
}

unsigned getAnimationLength(const std::string &tname, const std::string &aname)
{
	return animations[tname][aname].size();
}

float getAnimationDuration(const std::string &tname, const std::string &aname)
{
	return getAnimationLength(tname, aname) / frameRates[tname][aname];
}


void addAnimation(const std::string &tname, const std::string &aname, const std::vector<unsigned> &frames, float frameRate)
{
	animations[tname][aname] = frames;

	frameRates[tname][aname] = frameRate;
}

unsigned sampleAnimation(const std::string &tname, const std::string &aname, float timePassed, float speed, bool loop)
{
	unsigned index = (timePassed / getAnimationDuration(tname, aname)) * (getAnimationLength(tname, aname));

	if (loop) index %= getAnimationLength(tname, aname);

	else if (index == getAnimationLength(tname, aname)) index--;

	return getFrame(tname, aname, index);
}