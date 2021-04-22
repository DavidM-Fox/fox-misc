#include <fstream>
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>
#include "fox-misc/fox-logger.hpp"

namespace fox {
namespace misc {

Logger::Logger() : time_format("%Y-%m-%d | %H:%M:%S") {}
Logger::Logger(const std::string &file_path)
    : time_format("%Y-%m-%d | %H:%M:%S")
{
    ofs.open(file_path.c_str(), std::ios_base::app);
    if (!ofs.is_open())
        std::cerr << open_err << file_path << '\n';
}

void Logger::openFile(const std::string &file_path)
{
    if (ofs.is_open())
        ofs.close();
    ofs.open(file_path, std::ios_base::app);
    if (!ofs.is_open())
        std::cerr << open_err << file_path << '\n';
}

void Logger::write(const std::string &str, const Logger::level &level)
{
    if (!ofs.is_open())
        std::cerr << write_err;
    else
        ofs << getTime() + levelStr(level) + str + '\n';
}

void Logger::print(const std::string &str, const Logger::level &level)
{
    std::cout << getTime() + levelStr(level) + str + '\n';
}

void Logger::setTimeFormat(const std::string &str) { time_format = str; }

std::string Logger::getTime()
{
    if (time_format == "")
        return "";
    std::time_t time =
        std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    auto time_info = std::localtime(&time);
    std::ostringstream oss;
    oss << std::put_time(time_info, time_format.c_str());
    return oss.str();
}

const std::string Logger::levelStr(const Logger::level &level)
{
    static const std::string a[] = {" >> ", " >> WARNING: ", " >> ERROR: "};
    return a[static_cast<int>(level)];
}

const std::string Logger::write_err =
    "'fox-misc/fox-logger.hpp': Warning: "
    "fox::misc::logger::write(): Cannot log statement to file. "
    "ofstream is not open.\n";

const std::string Logger::open_err =
    "'fox-misc/fox-logger.hpp': Warning: "
    "fox-misc::logger(): Cannot open file_path '";

} // namespace misc
} // namespace fox