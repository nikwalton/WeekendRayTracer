//
//  main.cpp
//  WeekendRayTracer
//
//  Created by Nikolaus Walton on 7/11/21.
//


#include <iostream>
#include "color.h"
#include "vec3.h"

int main() {

	// Image
	const int width = 256;
	const int height = 256;
	
	// Render
	std::cout << "P3\n" << width << ' ' << height << "\n255\n";
	
	//pixels are written in rows from left to right
	//rows are written top to bottom
	
	for (int j = height - 1; j>= 0; --j) {
		std::cerr << "\rScanlines Remaining: " << j << ' ' << std::flush;
		for (int i = 0; i < width; ++ i) {
			color pixel_color(double(i)/(width-1), double(j)/(height - 1), 0.25);
			write_color(std::cout, pixel_color);
	
		}
	}
	
	std::cerr << "\nDone\n";
}
