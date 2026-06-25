#include "sim.h"
#include <vector>
#include <iostream>
#include <cmath>
#include "constants.h"
#define g constants::gravity

using namespace std;

double Vec3::distance_to(Vec3 a) {
	return sqrt(
		pow(this->x-a.x, 2)+
		pow(this->y-a.y, 2)+
		pow(this->z-a.z, 2)
	);
}

double Vec3::magnitude() {
	return sqrt(
		pow(this->x,2)+
		pow(this->y,2)+
		pow(this->z,2)
	);
}

void Vec3::unit_vector() {
	auto mag = this->magnitude();
	this->x/=mag;
	this->y/=mag;
	this->z/=mag;
}

void State::add_body(double x, double y, double z, double mass) {
	bodies.push_back({x,y,z,mass});
}


Delta Simulation::step(double t) {
	auto& bodies = _state.bodies;
	int n = bodies.size();
	Delta accels(n);
	Delta displacement(n);

	// calculate the displacement
	for (int i{}; i<n-1; i++) {
		for (int j{i+1}; j<n; j++) {
			auto& b1 = bodies[i];
			auto& b2 = bodies[j];
			auto direction = b2.pos - b1.pos;
			direction.unit_vector();
			double force = (g*b1.mass*b2.mass)/b1.pos.distance_to(b2.pos);
			accels[i] += direction*(force/b1.mass);
			accels[j] += direction*(-force/b2.mass);
		}
	}
	for (int i{}; i<n; i++) {
		displacement[i] = bodies[i].vel*t + accels[i]*0.5*pow(t,2);
	}

	// go through and update the positions and speed
	for (int i{}; i<n; i++) {
		bodies[i].pos+=displacement[i];
		bodies[i].vel+=accels[i]*t;
	}

	// update the time
	_state.time += t;

	//return the delta
	return displacement;
}
