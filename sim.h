#ifndef SIM_H
#define SIM_H
/*
 * we init the simulation with a state we fill in our selves then the sim object
 * just returns a delta object
 * we have a start state, where the simulation sends all the registered bodies
 * each step() function call it sends the delta of all bodies registered
 * (+x, +y, +z) etc for all of them
 */

#include <vector>
#include <iostream>

struct Vec3;
struct Body;
struct State;
struct Simulation;

using namespace std;
using Bodies = vector<Body>;
using Positions = vector<Vec3>;


struct Vec3 {
	double x{}, y{}, z{};
	Vec3& operator+=(Vec3 other) {
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}
	Vec3 operator-(Vec3 other) {
		return {this->x-other.x, this->y-other.y, this->z-other.z};
	}

	Vec3 operator+(Vec3 other) {
		return {this->x+other.x, this->y+other.y, this->z+other.z};
	}

	Vec3 operator*(double scalar) {
		return {this->x*scalar, this->y*scalar, this->z*scalar};
	}


	double distance_to(Vec3 a);
	void unit_vector();
	double magnitude();
};

inline ostream& operator<<(ostream& os, Vec3& v) {
	os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
	return os;
}

struct Body {
	Body(double x, double y, double z, double _mass) :
		pos{x,y,z},
		mass{_mass}
	{};
	Vec3 pos{};
	Vec3 vel{};
	double mass{};
};

struct State {
	double time{};
	Bodies bodies{};
	void add_body(double x, double y, double z, double mass);
};

struct Simulation {
	State _state{};
	Simulation(State initial) : _state{initial} {}
	Positions step(double t=1.0);
};

#endif
