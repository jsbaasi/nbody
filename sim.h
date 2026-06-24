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

struct Vec3;
struct Body;
struct State;
struct Delta;
struct Simulation;

using namespace std;
using Bodies = vector<Body>;

struct Vec3 {
	double x{}, y{}, z{};
};

struct Body {
	Vec3 pos{};
	double mass{};
};

struct State {
	double time{};
	Bodies bodies{};
};

struct Delta {
	vector<Vec3> deltas{};
};

struct Simulation {
	State _state{};
	Simulation(State initial) : _state{initial} {}
	Delta step(double t);
};

#endif
