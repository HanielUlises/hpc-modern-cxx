#include <print>
#include <algorithm>
#include "CountingIterator.hh"
#include "timeit.hh"

auto waste(unsigned long N)
{
    volatile unsigned long total{0UL};
    for (auto i = 0UL; i < N; ++i) total += i;
    return static_cast<unsigned long>(total);
}

auto main() -> int
{
    using namespace cxx_course;
    std::for_each(algo_counter(10'000'000UL), algo_counter(10'000'010UL), [](auto i) {
        timeit(std::format("timit tester for size {}", i), 4U, waste, i);
    });
}

