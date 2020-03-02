#include "lib.hpp"

#include <cmath>

int lib::tested_func(double param1, unsigned unused)
{
	(void)unused;

	return static_cast<int>(std::round(std::sqrt(param1)));
};

int lib::untested_func(double param1, unsigned unused)
{
	(void)unused;

	return static_cast<int>(std::round(std::sqrt(param1)));
};
