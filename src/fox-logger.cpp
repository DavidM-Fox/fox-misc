#include <fstream>
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>
#include "fox-misc/fox-logger.hpp"

namespace fox {
namespace misc {

Logger::Logger() {}
Logger::Logger(const std::string &file_path)
{
    ofs.open(file_path.c_str(), std::ios_base::app);
    if (!ofs.is_open())
        openFileCerr(file_path);
}

void Logger::openFile(const std::string &file_path)
{
    if (ofs.is_open())
        ofs.close();
    ofs.open(file_path, std::ios_base::app);
}

void Logger::write(const std::string &str, const Logger::level &level)
{
    if (!ofs.is_open())
        writeCerr();
    else
        ofs << levelStr(level) + getTime() + str + '\n';
}

void Logger::print(const std::string &str, const Logger::level &level)
{
    std::cout << levelStr(level) + getTime() + str + '\n';
}

std::string Logger::getTime()
{

    std::time_t time =
        std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    auto time_info = std::localtime(&time);
    std::ostringstream oss;
    oss << std::put_time(time_info, "%Y-%m-%d | %H:%M:%S");
    return oss.str();
}

const std::string Logger::levelStr(const Logger::level &level)
{
    static const std::string a[] = {" >> ", " >> WARNING: ", " >> ERROR: "};
    return a[static_cast<int>(level)];
}

void writeCerr()
{
    static const std::string error =
        "'dmfmisc/logger.hpp'.hpp: Warning: "
        "dmfmisc::logger::write(): Cannot log statement to file. "
        "ofstream is not open.\n";
    std::cerr << error;
}

void openFileCerr(const std::string &file_path)
{
    static const std::string error =
        "'fox-misc/fox-logger.hpp'.hpp: Warning: "
        "fox-misc::logger(): Cannot open file_path '";
    std::cerr << error + file_path + "'\n";
}

} // namespace misc
} // namespace fox