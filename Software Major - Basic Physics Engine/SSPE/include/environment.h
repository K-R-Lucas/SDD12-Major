#pragma once
#include <vectors.h>

using sspe::Vec2;

namespace sspe
{
	class Environment
	{
		public:
			Environment();

		private:
			Vec2* a, * v, * s, * f;
			double* Aa, * Av, * As, * t, * m;

			int n;
			double dt;
	};
}