#include <iostream>
#include <chrono>
#include "dmfmisc/string.hpp"

using measure = std::chrono::high_resolution_clock;
using namespace std::chrono;

int main(int, char **)
{
    std::vector<int> test = {5, 32, 3, 4, 1};

    auto t1 = measure::now();
    auto str = dmfmisc::string::join(test, ", ");
    auto t2 = measure::now();

    std::cout << "\n\n\n\n";
    std::cout << duration_cast<microseconds>(t2 - t1).count() << std::endl;
    std::cout << str << std::endl;
    return 0;
}
