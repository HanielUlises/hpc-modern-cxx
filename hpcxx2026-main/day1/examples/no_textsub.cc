template <unsigned N> constexpr unsigned fact = N * fact<N-1>;
template <> constexpr unsigned fact<0> = 1U;
static_assert(fact<7> == 5040);
template <class A, class B>
constexpr auto are_same = false;
template <class A>
constexpr auto are_same<A, A> = true;
//static_assert(are_same<int, unsigned int>);
using Integer = int;
static_assert(are_same<int, Integer>);
auto main() -> int {}

