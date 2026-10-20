// examples/overload_w_concepts.cc
#include <print>
#include <concepts>
#include <string>
#include <typeinfo>

template <class N> concept Number = std::is_floating_point_v<N> || std::is_integral_v<N>;
template <class N> concept NotNumber = not Number<N>; 

void proc(Number auto&& x) 
{
    std::print("Called proc for numbers with {} of typeid {}\n", x, typeid(x).name());
}
void proc(NotNumber auto&& x) 
{
    std::print("Called proc for non-numbers with {} of typeid {}\n", x, typeid(x).name());
}

auto main() -> int
{
    using namespace std::string_literals;
    proc(-1);
    proc(88UL);
    proc("0118 999 88191 9119725 3");
    proc(3.141);
    proc("eighty"s);
}

