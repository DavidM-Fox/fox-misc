#include <vector>
#include <string>
#include "catch.hpp"
#include <fox-misc/fox-string.hpp>

TEST_CASE("string::join()", "[fox::misc::string]")
{
    std::vector<int> vec_0({1, 2, 3, 4, 5});
    std::vector<double> vec_1({1.032, 2.321, 0.342, .42342});

    std::string str_1 = fox::misc::string::join(vec_0, ".");
    std::string str_2 = fox::misc::string::join(vec_1, "|");

    REQUIRE(str_1 == "1.2.3.4.5");
    REQUIRE(str_2 == "1.032|2.321|0.342|0.42342");
}