#include <iostream>

namespace A::B {
    struct A1 {};
    void f(A1 a) {
        std::cout << "Call to B::f()\n";
    }
}
void useit(A::B::A1 a)
{
    f(5.2, a);
    // We are calling f here, and the top-down
    // processing of the source file does not
    // know at this point that there will be
    // a matching function defined later in the
    // namespace A::B. At the point of usage a
    // matching declaration must be visible!
}
namespace A::B {
    void f(double x, B::A1 a) {
        std::cout << "Call to A::f()\n";
    }
}

auto main() -> int
{
    A::B::A1 a1;
    useit(a1);
    // We are calling function useit here, and
    // a declaration is visible. No problems at
    // this point.
}

