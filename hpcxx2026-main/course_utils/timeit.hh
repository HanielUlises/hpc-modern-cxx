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
#include <print>
#include <chrono>
#include <string>
#define COURSE_UTILS_EXPORT
#endif

namespace cxx_course {
    using std::size_t;

COURSE_UTILS_EXPORT
enum class TimeUnit { ns, us, ms, s };

COURSE_UTILS_EXPORT
template <class R, class P>
auto select_unit(std::chrono::duration<R, P> d) -> TimeUnit
{
    if (d > std::chrono::seconds {1}) return TimeUnit::s;
    else if (d > std::chrono::milliseconds {1}) return TimeUnit::ms;
    else if (d > std::chrono::microseconds {1}) return TimeUnit::us;

    return TimeUnit::ns;
}

COURSE_UTILS_EXPORT
template <class R, class P>
auto str(std::chrono::duration<R, P> d, TimeUnit U = TimeUnit::ns) -> std::string
{
    std::string ans;
    switch (U) {
        case TimeUnit::s: ans = std::format("{}", std::chrono::duration<double>(d)); break;
        case TimeUnit::ms: ans = std::format("{}", std::chrono::duration<double, std::milli>(d)); break;
        case TimeUnit::us: ans = std::format("{}", std::chrono::duration<double, std::micro>(d)); break;
        case TimeUnit::ns: 
        default: ans = std::format("{}", std::chrono::duration<double, std::nano>(d)); break;
    }
    return ans;
}

COURSE_UTILS_EXPORT
template <class Callable, class... Args>
void timeit(std::string_view testname, unsigned reps, Callable&& f, Args&&... args)
{
    using namespace std::chrono;
    using duration_type = duration<long long, std::nano>;
    duration_type tmin {}, tmax {}, ttot{};
    for (auto i = 0UL; i < reps; ++i) {
        auto start = high_resolution_clock::now();
        std::forward<Callable>(f)(std::forward<Args>(args)...);
        auto end = high_resolution_clock::now();
        auto intv = duration<long long, std::nano>(end - start);
        if (i == 0U) {
            tmin = tmax = intv;
        } else {
            tmax = std::max(tmax, intv);
            tmin = std::min(tmin, intv);
        }
        ttot += intv;
    }
    auto tmean = ttot / reps;
    auto unit = select_unit(tmin);
    std::print("Timing results for {} from {} repetitions...\n", testname, reps);
    std::print("Average = {}\n", str(tmean, unit));
    std::print("Minimum = {}\n", str(tmin, unit));
    std::print("Maximum = {}\n", str(tmax, unit));
}

}

