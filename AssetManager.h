#pragma once
#include <string>
#include <vector>

//Loads a Texture gives it an easy to grab name
void loadTexture(const std::string &name,
				 const char *path, 
				 unsigned r, 
				 unsigned c);

//Gets the sprite from a SpriteSheet loaded in
unsigned getTexture(const std::string &name);

//Adds an animation to the Animation Map
void addAnimation(const std::string &tname,
				  const std::string &aname,
				  const std::vector<unsigned> &frames,
				  float frameRate = 12.f);

//Grabs the frame from an Animation map
unsigned getFrame(const std::string &tname,
				  const std::string &aname,
				  unsigned frame);

//Gets the size of an Animation map
unsigned getAnimationLength(const std::string &tname,
							const std::string &aname);

//Gets the duration of an Animation by dividing the AnimationLength by the FrameRate
float getAnimationDuration(const std::string &tname,
						   const std::string &aname);

//Gets the frame we are on for the animation based on the animTimer in GameObject
unsigned sampleAnimation(const std::string &tname,
						 const std::string &aname,
						 float timePassed, float speed = 1.f, bool loop = true);