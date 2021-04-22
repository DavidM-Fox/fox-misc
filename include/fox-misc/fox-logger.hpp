#ifndef FOXMISC_LOGGER_H
#define FOXMISC_LOGGER_H
#include <fstream>
#include <string>

namespace fox {
namespace misc {

class Logger {
public:
    enum class level { NORMAL, WARNING, ERROR };
    Logger();
    Logger(const std::string &file_path);

    /// @brief Open an std::ofstream using file_path.
    void openFile(const std::string &file_path);

    /// @brief Append a log statement to the opened std::ofstream.
    void write(const std::string &str,
               const Logger::level &level = Logger::level::NORMAL);

    /// @brief Print a log statement to console.
    void print(const std::string &str,
               const Logger::level &level = Logger::level::NORMAL);

    /// @brief Set the log statement time prefix format string e.g. "%Y-%m-%d |
    /// %H:%M:%S". Set to "" if no time prefix is desired.
    void setTimeFormat(const std::string &str = "%Y-%m-%d | %H:%M:%S");

private:
    std::ofstream ofs;

    std::string time_format;
    std::string getTime();

    static const std::string Logger::levelStr(const Logger::level &level);
    static const std::string write_err;
    static const std::string open_err;
};

} // namespace misc
} // namespace fox
#endif // DMFMISC_LOGGER_H