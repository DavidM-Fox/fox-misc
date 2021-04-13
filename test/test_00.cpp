#include <vector>
#include <string>
#include <fox-misc/fox-string.hpp>
#include "catch.hpp"

TEST_CASE("string::join()", "[fox::misc::string]")
{
    std::vector<int> vec_0({1, 2, 3, 4, 5});
    std::vector<double> vec_1({1.032, 2.321, 0.342, .42342});
    std::vector<double> vec_2({1.032});

    std::string str_0 = fox::misc::string::join(vec_0, ".");
    std::string str_1 = fox::misc::string::join(vec_1, "|");
    std::string str_2 = fox::misc::string::join(vec_2, "|");

    REQUIRE(str_0 == "1.2.3.4.5");
    REQUIRE(str_1 == "1.032|2.321|0.342|0.42342");
    REQUIRE(str_2 == "1.032");
}

TEST_CASE("string::split()", "[fox::misc::string]")
{
    std::string str_0 = "THIS.IS.A.TEST.STRING";
    std::string str_1 = "THIS.IS.ANOTHER.TEST.STRING.";

    auto vec_0 = fox::misc::string::split(str_0, '.');
    auto vec_1 = fox::misc::string::split(str_1, '.');

    REQUIRE(vec_0[0] == "THIS");
    REQUIRE(vec_0[1] == "IS");
    REQUIRE(vec_0[2] == "A");
    REQUIRE(vec_0[3] == "TEST");
    REQUIRE(vec_0[4] == "STRING");
    REQUIRE(vec_1.back() == "");
}