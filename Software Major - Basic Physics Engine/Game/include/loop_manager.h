#pragma once

class Loop
{
	public:
		Loop(int TPS);

		void runTicks(double dt);

	private:
		int tps{};
		double tick{}, accumulator{}, ft{}, dt{};
};