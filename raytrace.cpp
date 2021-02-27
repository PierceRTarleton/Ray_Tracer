#include <fstream>
#include <iostream>
#include <vector>
#include "Vector.h"
#include "Image_Plane.h"
#include "Plane.h"
#include "Sphere.h"
#include "Ray.h"
#include "Camera.h"
#include "Scene_Object.h"
using namespace  chromeball;

/*
* Checks intersections with scene objects
* Returns: Color of the closest object
*/
Color Trace(const Ray& r, const std::vector<Scene_Object*> Scene);

int main() {
	/*Inisalize the Image Dementions*/
	const int nx = 1024;
	const int ny = 768;
	const int Image_plane_size = nx * ny;

	/*Inisalize the Camera*/
	std::vector<Scene_Object*> Scene;
	Vector Cam_pos(0, 0, 0);
	Vector Cam_view(0, 0, 1);
	Vector Cam_up_direc(0, 1, 0);
	float Cam_hfov = 90;
	float Cam_aspect = 1.3333;
	Camera Camera_1(Cam_pos, Cam_view, Cam_up_direc, Cam_hfov, Cam_aspect);

	/*Inisalize the Plane*/
	Vector Obj_position(0, 2, 0);
	Vector Obj_normal(0, 1, 0);
	Color Obj_color;
	Obj_color.r = 0;
	Obj_color.g = 0.5;
	Obj_color.b = 1;
	Scene.push_back(new Plane(Obj_position, Obj_normal, Obj_color));

	/*Inisalize the Sphere*/
	Obj_position.set(1, 2, 15);
	float Obj_radius = 3;
	Obj_color.r = 0.5;
	Obj_color.g = 1;
	Obj_color.b = 0;
	Scene.push_back(new Sphere(Obj_position, Obj_radius, Obj_color));

	Image_Plane Image(nx, ny);


	/*
	* Loops through image pixels setting pixel color
	* based what scene object is has the closest intersection.
	*/
	for (int x = 0; x < nx; x++) {
		for (int y = 0; y < ny; y++) {
			float u = 2.0 * (float)x / (float)nx - 1.0;
			float v = 2.0 * (float)y / (float)ny - 1.0;
			Ray Ray_trace(Cam_pos, Camera_1.Veiw(u, v));
			Image.set(x, y, Trace(Ray_trace, Scene));
		}
	}

	/*
	* Print image to output file
	*/
	Color Pixel;
	std::ofstream output;
	output.open("output.ppm");
	output << "P3\n" << nx << " " << ny << "\n" << "255\n";
	for (int y = 0; y < ny; y++) {
		for (int x = 0; x < nx; x++) {
			Pixel = Image.get(x, y);
			output << (int)(Pixel.r * 255) << " " << (int)(Pixel.g * 255) << " " << (int)(Pixel.b * 255) << "\n";
		}
	}
	output.close();
	return 0;
}



/*
* Checks intersections with scene objects.
* Returns: Color of the object with the closest intersection
*/
Color Trace(const Ray& r, const std::vector<Scene_Object*> Scene) {

	Color Pixel_color;
	Pixel_color.r = 0;
	Pixel_color.g = 0;
	Pixel_color.b = 0;

	float t = -1;
	float t_intersect;


	for (int i = 0; i < Scene.size(); i++) {
		t_intersect = Scene[i]->intersect(r);
		if (t_intersect > 0) {
			if (t_intersect < t) {
				Pixel_color = Scene[i]->get_color();
				t = t_intersect;
			}
			else if (t < 0) {
				Pixel_color = Scene[i]->get_color();
				t = t_intersect;
			}
		}
	}

	return Pixel_color;
}