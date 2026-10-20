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
#include <iomanip>
#include <iostream>
#include <string>
#define COURSE_UTILS_EXPORT
#endif

namespace cxx_course {
using std::size_t;

COURSE_UTILS_EXPORT
class Vbose {
public:
    Vbose()
    {
        std::cout << "Default constructor of object at " << ((size_t)this) << "\n";
    }
    inline auto getval() const { return nm; }
    inline void setval(const std::string& nw) { nm = nw; }

    Vbose(const Vbose& v)
        : nm(v.nm)
    {
        std::cout << "Copy constructor of object at " << ((size_t)this) << ". ";
        std::cout << "Source for copy is at " << ((size_t)&v) << "\n";
    }
    Vbose(Vbose&& v) noexcept
        : nm(std::move(v.nm))
    {
        std::cout << "Move constructor of object at " << ((size_t)this) << ". ";
        std::cout << "Source for move is at " << ((size_t)&v) << "\n";
    }

    Vbose(std::string gs) noexcept
        : nm(gs)
    {
        std::cout << "Constructor of object at " << ((size_t)this) << ",";
        std::cout << " using string " << std::quoted(gs) << "\n";
    }

    auto operator=(const Vbose& v) -> Vbose&
    {
        std::cout << "Assignment operator: LHS @ " << ((size_t)this) << "(" << nm << "), ";
        std::cout << "RHS @ " << ((size_t)&v) << "(" << std::quoted(v.nm) << ")\n";
        if (this != &v) {
            nm = v.nm;
        }
        return *this;
    }

    auto operator=(Vbose&& v) -> Vbose&
    {
        std::cout << "Move assignment operator: LHS @ " << ((size_t)this) << "(" << std::quoted(nm) << "), ";
        std::cout << "RHS @ " << ((size_t)&v) << "(" << std::quoted(v.nm) << ")\n";
        std::swap(nm, v.nm);
        return *this;
    }

    ~Vbose()
    {
        std::cout << "Destructor of object at " << ((size_t)this) << " with data " << std::quoted(nm) << "\n";
    }

    auto operator+(const Vbose& v) -> Vbose
    {
        std::cout << "Inside operator + ()\n";
        return {nm + "+" + v.nm};
    }
    auto value() const noexcept -> std::string
    {
	return nm;
    }
    void value(const std::string& vl)
    {
	std::cout << "Changing internal value of object at " << ((size_t)this) << " from " << nm << " to " << vl << "\n";
	nm = vl;
    }

private:
    std::string nm { "Uninitialized" };
};

}

