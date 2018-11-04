#pragma once

namespace lib
{
	constexpr int constexpr_func(int x)
	{
		return x * x;
	};

	int tested_func(double param1, unsigned unused);
	int untested_func(double param1, unsigned unused);
}
