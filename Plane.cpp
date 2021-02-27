#include "Plane.h"
using namespace  chromeball;

/*
* Returns the Distance from the the ray position to where it intersects with the plane. If there is no intersection it returns -1.
* Inputs: Ray to check for an intersections with.
* 
* Output: float t - distance from the ray start position.
*		  or -1 if there is no intersection.
*/
float Plane::intersect(const Ray& r)const {
	const Vector Ray_direction = r.get_direction();
	const Vector Ray_position = r.get_position();
	float denominator = r.get_direction() * normal_direction;
	if (denominator == 0) {
		return -1;
	}
	
	float numerator = (r.get_position() - position) * normal_direction;
	float t = -1 * (numerator / denominator);
	if (t < 0) {
		return -1;
	}

	return t;
}

/*
* 
*/
const Color Plane::get_color() const {
	return C;
}