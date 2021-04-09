#ifndef DMFMISC_STRING_H
#define DMFMISC_STRING_H
#pragma once
#include <string>
#include <sstream>
#include <vector>

namespace dmfmisc {

class string {
public:
    /// @brief Splits an std::string by a delimiter
    static std::vector<std::string> split(const std::string &str,
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

    /// @brief joins a vector<T> by a delimiter string
    template <typename T>
    static std::string join(const std::vector<T> &vec,
                            const char *const delimiter)
    {
        std::ostringstream os;
        auto begin = vec.begin();
        auto end = vec.end();

        if (begin != end) {
            std::copy(begin, std::prev(end),
                      std::ostream_iterator<T>(os, delimiter));
            begin = std::prev(end);
        }
        if (begin != end) {
            os << *begin;
        }
        return os.str();
    }

    /// @brief Removes all whitespace from a std::string
    static void clean(std::string &str)
    {
        str.erase(std::remove_if(str.begin(), str.end(), std::isspace),
                  str.end());
    }
};

} // namespace dmfmisc
#endif