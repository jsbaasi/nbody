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

Delta Simulation::step(double t=1.0) {
	auto& bodies = _state.bodies;
	int n = bodies.size();
	Delta accels(n);
	// calculate the delta
	for (int i{}; i<n-1; i++) {
		for (int j{i+1}; j<n; j++) {
			auto& b1 = bodies[i];
			auto& b2 = bodies[j];
			auto direction = b2.pos - b1.pos;
			double force = (g*b1.mass*b2.mass)/b1.distance_to(b2);
			accels[i] += force/b1.mass;
			accels[j] += -force/b2.mass;
		}
	}

	// go through and update the positions
	
	// update the time
	_state.time += t;

	//return the delta
	return {};
}
