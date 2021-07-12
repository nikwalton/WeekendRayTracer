//
//  main.cpp
//  WeekendRayTracer
//
//  Created by Nikolaus Walton on 7/11/21.
//

#include <iostream>

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
			
			//rgb ranges from 0.0 to 1.0
			auto r = double(i) / (width - 1);
			auto g = double(j) / (height - 1);
			auto b = 0.25;
			
			int ir = static_cast<int>(255.999 * r);
			int ig = static_cast<int>(255.999 * g);
			int ib = static_cast<int>(255.999 * b);
			
			std::cout << ir << ' ' << ig << ' ' << ib << '\n';
		}
	}
	
	std::cerr << "\nDone\n";
}
