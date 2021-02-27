#include "Sphere.h"
using namespace  chromeball;

/*
* Returns the Distance from the the ray position to where it intersects with the sphere. If there is no intersection it returns -1.
* Inputs: Ray to check for an intersections with.
*
* Output: float t - the distance of the closest intersection from the ray start position.
*		  or -1 if there is no intersection.
*/
float Sphere::intersect(const Ray& R)const {
	const Vector a = R.get_position() - position;
	float b = (R.get_direction() * a);
	float f = pow(R.get_direction() * a, 2) + pow(radius, 2) - pow(a.magnitude(), 2);

	if (f < 0) {
		return -1;
	}

	/*
	* t_neg: intersections with the negative side of the Sphere
	* t_plus: intersections with the positive side of the Sphere
	*/
	float t_neg = (-1 * b - sqrt(f));
	float t_plus = (-1 * b + sqrt(f));

	if (t_neg > 0 && (t_plus > t_neg || t_plus < 0)) {
		return t_neg;
	}
	else if (t_plus > 0 && (t_plus < t_neg || t_neg < 0)) {
		return t_plus;
	}
	else {
		return -1;
	}
}


const Color Sphere::get_color() const {
	return C;
}