#pragma once
#include <math.h>
#include "Vector.h"
using namespace  chromeball;
/*
* Holds the information that make up the camera.
*	-information needed to calculate the ray direction
*/
class Camera {
public:
	Camera(Vector eye, Vector view, Vector up, float hfov, float aspect) :
		position(eye), view_direction(view), 
		up_direction(up), hfov(hfov), aspect(aspect) {};
	Vector Veiw(float x, float y) const;

private:
	Vector position, view_direction, up_direction;
	float hfov, aspect;

};
