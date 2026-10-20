#include <print>
#include <iostream>
#include <vector>

auto main(int argc, char* argv[]) -> int
{
    std::vector v(10UL, 1.);
    unsigned long index{};
    while (1) {
        std::print("access index: ");
        std::cin >> index;
        std::print("v[{}] = {}\n", index, v[index]);
    }
}

