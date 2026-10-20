#include <cmath>
#include <print>

auto main() -> int
{
    for (auto i = 0UL; i < 110UL; ++i) {
        std::print("i = {0:010d}, E_tot = {2:16.12f}, E_hb = {1:8.4f}\n",
            i, std::exp(std::cos(1.0 * i)), std::exp(std::sin(1.0 * i)));
    }
}
