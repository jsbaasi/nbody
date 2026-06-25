#include "sim.h"
#include <iostream>
#include "constants.h"
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
	int i{};
	while (true) {
		auto delta = sim.step();
		cout << "[" << i << "] " << " [ ";
		for (auto& d : delta) cout << d << " ";
		cout << "]" << endl;
		i++;
		this_thread::sleep_for(chrono::seconds(1));
	}
	return 0;
}
