#pragma once
#include <string>
#include <vector>


//Loads in a texture and gives it an easy to use name
void loadTexture(const std::string &name,
				 const char *path, 
				 unsigned r, 
				 unsigned c);

//Grabs a Texture brought in by LoadTexture
unsigned getTexture(const std::string &name);

//Creates an animation from LoadTexture and gives it an easy to use name
void addAnimation(const std::string &tname,
				  const std::string &aname,
				  const std::vector<unsigned> &frames,
				  float frameRate = 12.f);

//???
unsigned getFrame(const std::string &tname,
				  const std::string &aname,
				  unsigned frame);

//Gets the length of an animation
unsigned getAnimationLength(const std::string &tname,
							const std::string &aname);

//???
float getAnimationDuration(const std::string &tname,
						   const std::string &aname);

//???
unsigned sampleAnimation(const std::string &tname,
						 const std::string &aname,
						 float timePassed, float speed = 1.f, bool loop = true);