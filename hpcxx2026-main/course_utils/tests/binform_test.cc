#ifdef WITH_MODULES
import course_utils;
#else
#include "binform.hh"
#endif

auto main() -> int
{
    for (auto i : {1, 2, 5, 9, 11, 17, 23, 81, 143}) {
        cxx_course::showbits(i);
    }
    for (auto i : {1., 2., 5., .9, 1.1, 1.7, 23., 8.1, 1.43}) {
        cxx_course::showbits(i);
    }
}

