//
//  ray.h
//  WeekendRayTracer
//
//  Created by Nikolaus Walton on 7/12/21.
//

#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray
{
	
public:
	ray() {}
	ray(const point3& origin, const vec3& direction)
	: orig(origin), dir(direction) {}
	
	point3 origin() const { return orig; }
	vec3 direction() const { return dir; }
	
public:
	point3 orig;
	vec3 dir;
};

#endif /* ray_h */
