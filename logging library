#pragma once

#include <iostream>
#include <chrono>
#include <iomanip>
#include <utility>

class log {
public:
    enum class level { info, warning, error, debug, critical };

private:
    static const char* to_string(level lvl) {
        switch (lvl) {
        case level::info:     return "INFO";  case level::warning:  return "WARN";
        case level::error:    return "ERROR"; 
        case level::debug:    return "DEBUG"; case level::critical: return "CRIT";
        }
        return "UNKNOWN";
    }

    static std::ostream& stream(level lvl) {
        return (lvl == level::info) ? std::cout : std::cerr;
    }

    static void prefix(level lvl) {
        auto now = std::chrono::system_clock::to_time_t(
            std::chrono::system_clock::now()
        );

        std::cout << std::put_time(std::localtime(&now), "%F %T")
            << " [" << to_string(lvl) << "] ";
    }

    template<typename... Args>
    static void emit(level lvl, Args&&... args) {
        prefix(lvl);
        auto& os = stream(lvl);
        (os << ... << std::forward<Args>(args)) << '\n';
    }

public:
    template<typename... Args>
    static void info(Args&&... args) { emit(level::info, std::forward<Args>(args)...); }

    template<typename... Args>
    static void error(Args&&... args) { emit(level::error, std::forward<Args>(args)...); }

    template<typename... Args>
    static void warning(Args&&... args) { emit(level::warning, std::forward<Args>(args)...); }

    template<typename... Args>
    static void debug(Args&&... args) { emit(level::debug, std::forward<Args>(args)...); }

    template<typename... Args>
    static void critical(Args&&... args) { emit(level::critical, std::forward<Args>(args)...); }
};
