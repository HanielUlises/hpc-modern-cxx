#include <algorithm>
#include <contracts>
#include <print>
#include <ranges>

namespace sr = std::ranges;

auto func(double x) -> double pre(x >= 0.)
    post(r : r >= 0.)
{
    return x * x - 0.001;
}
auto input_filter(std::string s) -> std::optional<double>
    pre(not s.empty())
    pre(s[0] == '.' or s[0] == '-' or std::isdigit(s[0]))
    pre(sr::all_of(s.substr(1UL), [](char c) { return std::isdigit(c) or c == '.'; }))
    pre(sr::count(s, '.') <= 1)
    post(r : r.has_value())
{
    std::optional<double> ans{};
    try {
        ans = std::stod(s);
    } catch (...) {
    }
    return ans;
}

auto main(int argc, char* argv[]) -> int pre(argc > 1)
{
    std::string input { argv[1] };
    std::print("Result = {}\n", func(input_filter(input).value()));
}

