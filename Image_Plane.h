#pragma once
#include <vector>
#include "Vector.h"
using namespace  chromeball;

/*
* Stores the color information for the pixels that make the image plane in a vector.
*/
class Image_Plane {
public:
	Image_Plane(int nx, int ny) :Nx(nx), Ny(ny) { data.resize(Nx * Ny); };
	Color get(int i, int j) const;
	void set(int i, int j, const Color& C);

private:
	/*x and y dementions of the image*/
	int Nx, Ny;

	/*vector storing pixel color data*/
	std::vector<Color> data;
};