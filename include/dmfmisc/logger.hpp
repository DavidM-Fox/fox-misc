#ifndef DMFMISC_LOGGER_H
#define DMFMISC_LOGGER_H
#pragma once
#include <fstream>
#include <exception>
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>

namespace dmfmisc {

class Logger {
public:
    enum class level { NORMAL, WARNING, ERROR };
    Logger() : file_path("") {}
    Logger(const std::string &file_path) : file_path(file_path)
    {
        ofs.open(file_path.c_str(), std::ios_base::app);
        if (!ofs.is_open()) {
            std::cerr << "'dmfmisc/logger.hpp'.hpp: Warning: "
                         "dmfmisc::logger(): Cannot open file_path '" +
                             file_path + "'\n";
        }
    }

    void open_ofstream(const std::string &file_path)
    {
        if (ofs.is_open())
            ofs.close();
        ofs.open(file_path, std::ios_base::app);
    }

    void write(const std::string &str,
               const Logger::level &level = Logger::level::NORMAL)
    {
        if (!ofs.is_open()) {
            std::cerr
                << "'dmfmisc/logger.hpp'.hpp: Warning: "
                   "dmfmisc::logger::write(): Cannot log statement to file. "
                   "ofstream is not open.\n";
        }
        else {
            ofs << prepend_str() + str + '\n';
        }
    }

    void print(const std::string &str,
               const Logger::level &level = Logger::level::NORMAL)
    {
        std::cout << prepend_str() + str + '\n';
    }

private:
    static std::string
    prepend_str(const Logger::level &level = Logger::level::NORMAL)
    {
        static const std::string a[3] = {" >> ",
                                         " >> WARNING: ", " >> ERROR: "};

        std::time_t time = std::chrono::system_clock::to_time_t(
            std::chrono::system_clock::now());
        auto time_info = std::localtime(&time);
        std::ostringstream oss;
        oss << std::put_time(time_info, "%Y-%m-%d | %H:%M:%S");
        return oss.str() + a[static_cast<int>(level)];
    }

    std::string file_path;
    std::ofstream ofs;
};

} // namespace dmfmisc
#endif // DMFMISC_LOGGER_H