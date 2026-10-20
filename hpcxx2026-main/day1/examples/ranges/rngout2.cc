#include <print>
#include <vector>
#include <string>

auto main() -> int
{
    using namespace std::literals;

    std::vector v{"One"s, "Two"s, "Three"s, "Four"s};
    std::print("v = {}\n", v);
    std::print("{:n}\n", v);
    std::print("{:_>50n}\n", v);
    std::print("{:n:.^8}\n", v);
    std::vector name_ind{ std::pair("One"s, 1), std::pair("Two"s, 2), std::pair("Three"s, 3) };
    std::print("{:m}\n", name_ind);
    std::print("{}\n", name_ind);
}

