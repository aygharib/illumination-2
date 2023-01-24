#pragma once

#include <string>

class WorkingDirectory {
public:
    WorkingDirectory();

    inline auto get() -> std::string& {
        return path;
    }
private:
    std::string path;
};