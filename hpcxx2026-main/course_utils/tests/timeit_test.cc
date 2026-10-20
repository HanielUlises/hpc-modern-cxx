#include "timeit.hh"

void waste(unsigned long N)
{
    volatile unsigned long total{0UL};
    for (auto i = 0UL; i < N; ++i) total += i;
    std::print("Total = {}\n", static_cast<unsigned long>(total));
}

auto main() -> int
{
    cxx_course::timeit("timit tester", 4U, waste, 1000000UL);
}
