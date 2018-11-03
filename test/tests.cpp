#define CATCH_CONFIG_MAIN

#include "lib.hpp"

#include <catch2/catch.hpp>

TEST_CASE("Test `constexpr_func`")
{
	REQUIRE(lib::constexpr_func(1) == 1);
	REQUIRE(lib::constexpr_func(2) == 4);
}

TEST_CASE("Test `tested_func`")
{
	REQUIRE(lib::tested_func(1, 0) == 1);
	REQUIRE(lib::tested_func(4, 0) == 2);
}
