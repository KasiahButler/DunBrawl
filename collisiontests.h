#pragma once

//Test for Circle Collision
float itest_Circle(float x1, float y1, float r1,
				   float x2, float y2, float r2);

//Test for Axis Aligned Bounding Box Collision
float itest_AABB(float x1, float y1, float hw1, float hh1,
				 float x2, float y2, float hw2, float hh2);

//Test for Circle vs AABB collision
float itest_CircleAABB(float x1, float y1, float r1,
					   float x2, float y2, float hw2, float hh2);
