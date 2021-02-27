#pragma once
#include "Vector.h"
#include "Scene_Object.h"
using namespace  chromeball;

/*
* Abstract class for any object that will be put in the Scene.
*/
class Scene_Object {
public:
	Scene_Object(Color& c) :C(c) {};
	virtual float intersect(const Ray& R)const = 0;
	virtual const Color get_color()const = 0;
protected:
	Color C;
};