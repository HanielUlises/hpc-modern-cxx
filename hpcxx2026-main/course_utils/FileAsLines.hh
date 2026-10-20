/**************************************************************************
 ** This library contains utilities  developed over the years for C++ courses
 ** at the Juelich Supercomputing Centre, Research Centre Juelich, Germany.
 ** They are needed to build some of the examples in the courses
 ** "Programming in C++", an introductory course keeping up with the latest
 ** official C++ standard, and "High Performance Scientific Computing in C++",
 ** an advanced course, also using the latest official C++ standard, but
 ** but targetting more experienced programmers and more performance related
 ** topics.
 **
 ** Copyright (C) (2025-) Sandipan Mohanty <s.mohanty@fz-juelich.de>
 ** Email: s.mohanty@fz-juelich.de
 ** This library is free software; you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License
 **
 ** This package is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 **************************************************************************/

#pragma once

#ifdef COURSE_UTILS_IN_A_MODULE
#define COURSE_UTILS_EXPORT export
#else
#include <filesystem>
#include <fstream>
#include <string>
#include <vector>
#define COURSE_UTILS_EXPORT
#endif

namespace cxx_course {
using std::size_t;
COURSE_UTILS_EXPORT
class FileAsLines {
public:
    using iterator = std::vector<std::string>::iterator;
    void read(std::filesystem::path nm)
    {
        std::ifstream fin { nm };
        std::string line;
        while (getline(fin, line))
            mylines.push_back(line);
    }
    FileAsLines(std::filesystem::path nm) { read(nm); }
    FileAsLines() = default;
    FileAsLines(const FileAsLines&) = default;
    FileAsLines(FileAsLines&&) = default;
    FileAsLines& operator=(const FileAsLines&) = default;
    FileAsLines& operator=(FileAsLines&&) = default;
    ~FileAsLines() = default;
    inline auto size() const -> size_t { return mylines.size(); }
    inline auto empty() const -> bool { return mylines.empty(); }
    inline auto operator[](size_t i) const -> const std::string& { return mylines[i]; }
    inline auto operator[](size_t i) -> std::string& { return mylines[i]; }
    inline auto front() const -> const std::string& { return mylines.front(); }
    inline auto front() -> std::string& { return mylines.front(); }
    inline auto back() const -> const std::string& { return mylines.back(); }
    inline auto back() -> std::string& { return mylines.back(); }
    inline decltype(auto) begin() { return mylines.begin(); }
    inline decltype(auto) end() { return mylines.end(); }
    inline decltype(auto) begin() const { return mylines.cbegin(); }
    inline decltype(auto) end() const { return mylines.cend(); }

private:
    std::vector<std::string> mylines;
};

COURSE_UTILS_EXPORT
auto operator<<(std::ostream& os, const FileAsLines& lines) -> std::ostream& 
{
    for (auto&& line : lines) os << line;
    return os;
}

}

