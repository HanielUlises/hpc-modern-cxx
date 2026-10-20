// test_your_setup/test_import_std.cc

import std;

template <class T>
concept number = std::integral<T> or std::floating_point<T>;

template <class T>
concept not_number = not number<T>;

template <number T>
void check(T x) { std::print("{} is a number.\n", x); }
template <not_number T>
void check(T x) { std::print("'{}' is not a number.\n", x); }

auto main() -> int
{
    check(1);
    check("one");
    check(1.23);
    check(42UL);
    check(-99822);
    check(__func__);
}

