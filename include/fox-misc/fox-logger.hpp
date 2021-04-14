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

    /// @brief Open an ofstream using file_path.
    void openFile(const std::string &file_path);

    /// @brief Append a Log statement to the ofstream file_path.
    void write(const std::string &str,
               const Logger::level &level = Logger::level::NORMAL);

    /// @brief Print a Log statement to console.
    static void print(const std::string &str,
                      const Logger::level &level = Logger::level::NORMAL);

private:
    std::ofstream ofs;

    static std::string getTime();
    static const std::string Logger::levelStr(const Logger::level &level);
    static void writeCerr();
    static void openFileCerr(const std::string &file_path);
};

} // namespace misc
} // namespace fox
#endif // DMFMISC_LOGGER_H