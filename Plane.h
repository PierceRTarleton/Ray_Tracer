#pragma once
#include "Ray.h"
#include "Vector.h"
#include "Scene_Object.h"
using namespace  chromeball;

/*
* Stores Informaiton that define a plane.
*/
class Plane : public Scene_Object {
public:
	Plane(Vector pos, Vector normal_direc, Color& c) :
		position(pos), normal_direction(normal_direc), Scene_Object(c) {};
	float intersect(const Ray& r)const;
	const Color get_color() const;
private:

	/*Use to store the Vector infromaiotn, that defines the Plane.*/
	Vector position;
	Vector normal_direction;
};