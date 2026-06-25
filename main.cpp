#include "sim.h"
#include <iostream>
#include "constants.h"

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
		cout << i << "[ ";
		for (auto& d : delta) cout << d << " ";
		cout << "]" << endl;
		i++;
	}
	return 0;
}
