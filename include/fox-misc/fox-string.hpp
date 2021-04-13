#ifndef FOXMISC_STRING_H
#define FOXMISC_STRING_H
#include <string>
#include <vector>

namespace fox {
namespace misc {

class string {
public:
    /// @brief Split an std::string by a delimiter
    static std::vector<std::string> split(const std::string &str,
                                          const char &delimiter);

    /// @brief Join an std::vector<T> by a delimiter string
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

    /// @brief Remove all whitespace from an std::string
    static void clean(std::string &str);
};

} // namespace misc
} // namespace fox
#endif