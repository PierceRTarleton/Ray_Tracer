#include "Image_Plane.h""
using namespace  chromeball;


Color Image_Plane::get(int i, int j) const {
	return data[i + Nx * j];
}

void Image_Plane::set(int i, int j, const Color& C) {
	data[i + Nx * j] = C;
}