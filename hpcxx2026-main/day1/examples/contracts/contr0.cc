#include <contracts>
#include <iostream>
#include <algorithm>
#include <ranges>
namespace sr = std::ranges;
namespace sv = sr::views;

constexpr auto are_digits(std::string_view R) -> bool
{
    return sr::all_of(R,
            [](char c) { return std::isdigit(c); });
}

auto func(const std::string& s) -> int
    pre(not s.empty())
    pre(are_digits(s) or
            (s.size() > 1UL 
             && s[0] == '-' 
             && are_digits(s.substr(1UL)))) 
{
    return std::stoi(s);
}

auto main(int argc, char *argv[]) -> int
{
    while (1) {
        std::string inp;
        std::cout << "String to convert: ";
        std::cin >> inp;
        auto i = func(inp);
        std::cout << "Square = "
            << i * i << "\n";
    }
}

