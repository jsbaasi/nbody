#include "sim.h"
#include <vector>
#include <iostream>

using namespace std;

Delta Simulation::step(double t=1.0) {
	int n = _state.bodies.size();
	vector<Vec3> accels(n);
	// calculate the delta
	for (int i{}; i<n-1; i++) {
		for (int j{i+1}; j<n; j++) {
			accels[i] +=	
		}
	}

	// go through and update the positions
	
	// update the time
	_state.time += t;

	//return the delta
	return {};
}
