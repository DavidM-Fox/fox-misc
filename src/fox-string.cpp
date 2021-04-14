#include <string>
#include <sstream>
#include <vector>
#include "fox-misc/fox-string.hpp"

namespace fox {
namespace misc {

std::vector<std::string> string::split(const std::string &str,
                                       const char &delimiter)
{
    std::vector<std::string> vec;
    size_t l_pos = 0;
    size_t pos = 0;

    while (pos != std::string::npos) {
        pos = str.find(delimiter, l_pos);
        vec.push_back(str.substr(l_pos, (pos - l_pos)));
        l_pos = pos + 1;
    }

    return vec;
}

void string::clean(std::string &str)
{
    str.erase(std::remove_if(str.begin(), str.end(), std::isspace), str.end());
}

} // namespace misc
} // namespace fox