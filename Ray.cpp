#include "Ray.h"
using namespace  chromeball;


const Vector& Ray::get_position() const{
	return position;
}

const Vector Ray::get_direction() const{
	return direction;
}