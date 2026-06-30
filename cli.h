#ifndef CLI_H
#define CLI_H

#include "sim.h"

struct Cli {
	State _state{};
	double zoom{1};
	int rows{15}, cols{51}, tick{};
	Cli(State initial) : _state{initial}{}
	void render(Positions positions);
};

#endif
