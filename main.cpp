#include "sim.h"
#include "constants.h"
#include "cli.h"
#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main() {
	int n{};
	cin >> n;
	State state{};
	for (int i{}; i<n; i++) {
		double x{},y{},z{},mass{};
		cin >> x >> y >> z >> mass;
		state.add_body(x,y,z,mass);
	}
	Simulation sim{state};
	Cli cli{state};
	int i{};
	while (true) {
		auto positions = sim.step();
		cli.render(positions);
		this_thread::sleep_for(chrono::seconds(1));
	}
	return 0;
}
