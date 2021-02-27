#pragma once
#include <math.h>
#include "Vector.h"
#include "Ray.h"
#include "Scene_Object.h"
using namespace  chromeball;

/*
* Stores Informaiton that define a plane.
*/
class Sphere :public Scene_Object {
public:
	Sphere(Vector position, float radius, Color& c):
		position(position), radius(radius), Scene_Object(c){}
	float intersect(const Ray& R)const;
	const Color get_color() const;
private:
	Vector position;
	float radius;
};

