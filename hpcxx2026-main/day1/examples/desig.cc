#include <print>

struct pars { int offset, size; };
auto example_func(pars p)
{
    for (int i = 0; i < p.size; ++i)
        std::print("{}\n", p.offset + i);
    return p.size;
}

auto main() -> int
{
    example_func({.offset = 5, .size = 10});
}


