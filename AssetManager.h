#pragma once
#include <string>
#include <vector>

void loadTexture(const std::string &name, 
				 const char *path, 
				 unsigned r, 
				 unsigned c);

unsigned getTexture(const std::string &name);

void addAnimation(const std::string &tname,
				  const std::string &aname,
				  const std::vector<unsigned> &frames,
				  float frameRate = 12.f);

unsigned getFrame(const std::string &tname,
				  const std::string &aname,
				  unsigned frame);

unsigned getAnimationLength(const std::string &tname,
							const std::string &aname);

float getAnimationDuration(const std::string &tname,
						   const std::string &aname);

unsigned sampleAnimation(const std::string &tname,
						 const std::string &aname,
						 float timePassed, float speed = 1.f, bool loop = true);