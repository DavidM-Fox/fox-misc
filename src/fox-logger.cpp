#include <fstream>
#include <exception>
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>
#include "fox-misc/fox-logger.hpp"

namespace fox {
namespace misc {

Logger::Logger() : file_path("") {}
Logger::Logger(const std::string &file_path) : file_path(file_path)
{
    ofs.open(file_path.c_str(), std::ios_base::app);
    if (!ofs.is_open()) {
        std::cerr << "'dmfmisc/logger.hpp'.hpp: Warning: "
                     "dmfmisc::logger(): Cannot open file_path '" +
                         file_path + "'\n";
    }
}

/// @brief Open an ofstream using file_path.
void Logger::open_ofstream(const std::string &file_path)
{
    if (ofs.is_open())
        ofs.close();
    ofs.open(file_path, std::ios_base::app);
}

/// @brief Append a Log statement to the ofstream file_path.
void Logger::write(const std::string &str, const Logger::level &level)
{
    if (!ofs.is_open()) {
        std::cerr << "'dmfmisc/logger.hpp'.hpp: Warning: "
                     "dmfmisc::logger::write(): Cannot log statement to file. "
                     "ofstream is not open.\n";
    }
    else {
        ofs << prepend_str() + str + '\n';
    }
}

/// @brief Print a Log statement to console.
void Logger::print(const std::string &str, const Logger::level &level)
{
    std::cout << prepend_str() + str + '\n';
}

/// @brief Static string return for header-only library.
std::string Logger::prepend_str(const Logger::level &level)
{
    static const std::string a[3] = {" >> ", " >> WARNING: ", " >> ERROR: "};

    std::time_t time =
        std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    auto time_info = std::localtime(&time);
    std::ostringstream oss;
    oss << std::put_time(time_info, "%Y-%m-%d | %H:%M:%S");
    return oss.str() + a[static_cast<int>(level)];
}

} // namespace misc
} // namespace fox