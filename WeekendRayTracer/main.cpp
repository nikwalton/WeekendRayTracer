//
//  main.cpp
//  WeekendRayTracer
//
//  Created by Nikolaus Walton on 7/11/21.
//
#include "color.h"
#include "ray.h"
#include "vec3.h"

#include <iostream>

//essentially our sky color
color ray_color(const ray& r) {
	vec3 unit_dir = unit_vector(r.direction());
	auto t = 0.5*(unit_dir.y() + 1.0);
	return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
}

int main() {

	// Image
	const auto aspect_ratio = 16.0 / 9.0;
	const int width = 400;
	const int height = static_cast<int>(width / aspect_ratio);
	
	//Camera
	
	auto viewport_height = 2.0;
	auto viewport_width = aspect_ratio + viewport_height;
	auto focal_len = 1.0;
	
	auto origin = point3(0,0,0);
	auto horiz = vec3(viewport_width, 0, 0);
	auto vert = vec3(0, viewport_height, 0);
	auto lower_left_corner = origin - horiz/2 - vert/2 - vec3(0, 0, focal_len);
	
	// Render
	std::cout << "P3\n" << width << ' ' << height << "\n255\n";
	
	//pixels are written in rows from left to right
	//rows are written top to bottom
	
	for (int j = height - 1; j>= 0; --j) {
		std::cerr << "\rScanlines Remaining: " << j << ' ' << std::flush;
		for (int i = 0; i < width; ++ i) {
			auto u = double(i) / (width - 1);
			auto v = double(j) / (height - 1);
			ray r(origin, lower_left_corner + u*horiz + v*vert - origin);
			
			color pixel_color = ray_color(r);
			write_color(std::cout, pixel_color);
	
		}
	}
	
	std::cerr << "\nDone\n";
}
