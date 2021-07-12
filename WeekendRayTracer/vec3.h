//
//  vec3.h
//  WeekendRayTracer
//
//  Created by Nikolaus Walton on 7/11/21.
//

#ifndef VEC3_H
#define VEC3_h

using std::sqrt;

class vec3 {
public:
	//store our 3 point vector into e
	
	//initializers
	vec3(): e{0,0,0} {}
	vec3(double e0, double e1, double e2): e{e0, e1, e2} {}
	
	//Getters
	double x() const {return e[0];}
	double y() const {return e[1];}
	double z() const {return e[2];}
	
	//overloading
	vec3 operator-() const {return vec3(-e[0], -e[1], -e[2]); }
	double operator[](int i) const {return e[i]; }
	double &operator[](int i) {return e[i];}
	
	//vector addition
	vec3& operator+=(const vec3 &v)
	{
		e[0] += v.e[0];
		e[1] += v.e[1];
		e[2] += v.e[2];
		return *this;
	}
	
	//division
	vec3& operator/=(const double t)
	{
		return *this *= 1/t;
	}
	
	//pythagorean theorem functions
	double length() const
	{
		return sqrt(length_squared());
	}
	
	double length_squared()
	{
		return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
	}
	
public:
	double e[3]
};

//type aliases for comfort
using point3 = vec3;
using color = vec3;

//utility functions
inline std::ostream& operator<<(std::ostream &out, const vec3 &v)
{
	return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vec3 operator+(const vec3 &u, const vec3 &v)
{
	return vec3(u.e[0]+v.e[0], u.e[1] + v.e[1], u.e[2] + v.[2]);
}

inline vec3 operator-(const vec3 &u, const vec3 &v)
{
	return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline vec3 operator*(const vec3 &u, const vec3 &v)
{
	return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline vec3 operator *(const vec3 &v, double t)
{
	return t * v;
}

inline vec3 operator/(vec3 v,double t)
{
	return (1/t) * v;
}

//dot product
inline double dot(const vec3 &u, const vec3 *v)
{
	return u.e[0] * v.e[0]
		+ u.e[1] * v.e[1]
		+ u.e[2] * v.e[2]
}

//cross product
inline vec3 cross(const vec3 &u, const vec3 &v)
{
	return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
				u.e[2] * v.e[0] - u.e[0] * v.e[2],
				u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

//unit vector
inline vec3 unit_vector(vec3 v)
{
	return v / v.length();
}

#endif /* vec3_h */
