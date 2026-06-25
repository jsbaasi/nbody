#ifndef CLI_H
#define CLI_H

struct Cli {
	Simulation _sim{};
	Cli(Simulation sim) : _sim{sim} {}
};

#endif
