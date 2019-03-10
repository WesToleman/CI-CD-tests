#pragma once

/**
 * @brief      A namespace containing some basic functions
 */
namespace lib
{
	/**
	 * @brief      A constant expression function
	 *
	 * @param[in]  x     An integer
	 *
	 * @return     `x` squared
	 */
	constexpr int constexpr_func(int x)
	{
		return x * x;
	};

	/**
	 * @brief      This function is covered by the unit tests and will show up
	 *             in the coverage report
	 *
	 * @param[in]  param1  The first parameter
	 * @param[in]  unused  An unused parameter
	 *
	 * @return     The integral square root of `param1`
	 */
	int tested_func(double param1, unsigned unused);

	/**
	 * @brief      This function is not covered by the unit tests and will be
	 *             highlighted as untested in the coverage report
	 *
	 * @param[in]  param1  The first parameter
	 * @param[in]  unused  An unused parameter
	 *
	 * @return     The integral square root of `param1`
	 */
	int untested_func(double param1, unsigned unused);
}
