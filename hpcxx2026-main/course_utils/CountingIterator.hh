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
#include <concepts>
#include <compare>
#include <iterator>
#define COURSE_UTILS_EXPORT
#endif

namespace cxx_course {
    using std::size_t;
    COURSE_UTILS_EXPORT
    template <class T> concept Integer = std::is_integral_v<T>;
    template <Integer T>
    struct CountingIterator {
        using difference_type = std::make_signed_t<T>;
        using value_type = T;
        using pointer = T*;
        using reference = T&;
        using iterator_category = std::random_access_iterator_tag;

        constexpr auto operator++(int) noexcept -> CountingIterator { return { val++ }; }
        constexpr auto operator++() noexcept -> CountingIterator&
        {
            ++val;
            return *this;
        }
        constexpr auto operator--(int) noexcept -> CountingIterator { return { val-- }; }
        constexpr auto operator--() noexcept -> CountingIterator&
        {
            --val;
            return *this;
        }
        constexpr auto operator+=(difference_type d) -> CountingIterator&
        {
            val += d;
            return *this;
        }
        constexpr auto operator-=(difference_type d) -> CountingIterator&
        {
            val -= d;
            return *this;
        }
        constexpr auto operator<=>(const CountingIterator& other) const noexcept = default;
        constexpr auto operator*() noexcept -> T& { return val; }
        constexpr auto operator*() const noexcept -> T { return val; }
        constexpr auto operator->() noexcept { return &val; }
        constexpr auto operator->() const noexcept { return &val; }
        constexpr auto operator-(CountingIterator other) const noexcept -> difference_type { return val - other.val; }
        constexpr auto operator+(difference_type d) const noexcept -> CountingIterator { return { val + d }; }
        constexpr auto operator[](size_t d) const noexcept { return val + d; }
        T val {};
    };
    COURSE_UTILS_EXPORT
    template <Integer T>
    CountingIterator(T) -> CountingIterator<T>;

    COURSE_UTILS_EXPORT
    template <Integer T>
    auto algo_counter(T&& i) -> CountingIterator<T> { return { i }; }
}
