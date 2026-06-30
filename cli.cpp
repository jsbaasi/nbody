#include "cli.h"
#include "sim.h"
#include <iostream>

void Cli::render(Positions positions) {
	cout << tick << " ==========================" << endl;
	for (int i{}; i<rows; i++) {
		for (int j{}; j<cols; j++) {
			cout << ".";
		}
		cout << endl;
	}
	cout << "============================" << endl;
	tick++;
}
