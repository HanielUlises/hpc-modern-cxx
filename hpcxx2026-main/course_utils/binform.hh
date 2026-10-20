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
#include <string>
#include <array>
#include <bit>
#include <bitset>
#include <cstddef>
#include <concepts>
#include <iomanip>
#include <print>
#define COURSE_UTILS_EXPORT
#endif



namespace cxx_course {
    COURSE_UTILS_EXPORT
template <class T>
concept Number = std::floating_point<T> || std::integral<T>;

    COURSE_UTILS_EXPORT
template <Number T>
auto bits(const T& var)
{
    auto bytes = std::bit_cast<std::array<unsigned char, sizeof(T)>>(var);
    std::bitset<sizeof(T) * 8UL> ans{};
    for (unsigned i = 0U; i < bytes.size(); ++i) {
        auto b = bytes[i];
	for (unsigned j = 0U; j < 8U; ++j) {
            if (b & (static_cast<unsigned char>(1) << j)) ans.set(8U * i + j);
	}
    }
    return ans;
}

COURSE_UTILS_EXPORT
void showbits(double var)
{
    std::print("bits for double value {}\n", var);
    auto b = bits(var).to_string();
    std::print("raw = {}\n", b);
    std::print("sign  exponent          mantissa\n");
    std::print("{: <6}{: <16}  {}\n\n",  b[0], b.substr(1UL, 11), b.substr(12));
}

COURSE_UTILS_EXPORT
void showbits(float var)
{
    std::print("bits for float value {}\n", var);
    auto b = bits(var).to_string();
    std::print("raw = {}\n", b);
    std::print("sign  exponent          mantissa\n");
    std::print("{: <6}{: <16}  {}\n\n",  b[0], b.substr(1UL, 8), b.substr(9));
}

COURSE_UTILS_EXPORT
void showbits(auto var)
{
    std::print("bits for {} with non-floating point type : {}\n", var, bits(var).to_string());
}

}

