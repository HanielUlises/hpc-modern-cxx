#include <print>
#include <algorithm>
#include <array>
#include <ranges>

namespace sr = std::ranges;
namespace sv = sr::views;

constexpr auto poly(double x) { return 3. * x * x * x - 2. * x * x + 0.877 * x - 1.0; }

constexpr auto bounds = []{
     std::array pre{ 1.2, 3.0, 0.99, 0.05, 1.44, 0.71, 0.881 };
     return sr::minmax( pre | sv::transform(poly) );
}();

auto main() -> int
{
    std::print("{}\t{}\n", bounds.min, bounds.max);
    static_assert(bounds.min > -1. and bounds.min < -0.94);
}

