#include <loop_manager.h>
#include <iostream>

using std::cout;

Loop::Loop(int TPS) : tps(TPS) {
	tick = 1.0 / tps;
}

void Loop::runTicks(double dt) {
	ft = dt;
	accumulator += ft;

	while (accumulator >= dt) {
		accumulator -= tick;
		
		// Run Physics
	}
}