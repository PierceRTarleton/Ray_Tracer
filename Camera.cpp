#include "Camera.h"
using namespace  chromeball;

/*
* Creates a vector directions for the pixle at (x, y) on the image plane.
* 
* x = 2.0 * (x pixle position) / (image plane width) - 1.0
* y = 2.0 * (y pixle position) / (image plane hight) - 1.0
*/
Vector Camera::Veiw(float x, float y) const {
	Vector right_direction = up_direction ^ view_direction;

	float a = tan((hfov * 3.14159265359 / 180) / 2);
	float u = x * a;
	float v = y * a / aspect;

	Vector x_position = (u * right_direction + v * up_direction);

	Vector Pixel_direction = (x_position + view_direction).normal();

	return Pixel_direction;
}