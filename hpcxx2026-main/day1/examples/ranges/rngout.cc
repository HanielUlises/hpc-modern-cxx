#include <print>
#include <ranges>
#include <algorithm>
#include <vector>
#include <string>

auto main() -> int
{
    using namespace std::literals;
    namespace sr = std::ranges;
    namespace sv = sr::views;

    std::vector v{"One"s, "Two"s, "Three"s, "Four"s};
    std::print("v = {}\n", v);

    std::print("vr = {}\n", v | sv::reverse);
    std::print("[(v_i, vr_i)...] = {}\n", sv::zip(v | sv::reverse, v));

    std::print("{}\n", sv::zip(sv::iota(1UL), v));
    std::print("{}\n", sv::enumerate(v));
    std::print("{::}\n", v);
}

