#include <meta>
#include <concepts>
#include <print>

auto main() -> int
{
    constexpr auto r = ^^const int;
    using T = const [: r :] &;
    T x = 4;
    static_assert(std::same_as<const int&, T>);
}

