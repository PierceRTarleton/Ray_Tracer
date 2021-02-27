#pragma once
#include "Vector.h"
using namespace  chromeball;

/*
* Stores the information about the ray.
*/
class Ray {
public:
	Ray(Vector position, Vector direction): 
		position(position), direction(direction){}
	const Vector& get_position() const;
	const Vector get_direction() const;
private:
	Vector position;
	Vector direction;
};