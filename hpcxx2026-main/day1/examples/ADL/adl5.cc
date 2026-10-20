#include <iostream>

namespace A::B {
    struct A1 {};
    void f(A1);
    void f(double, A1);
}
void useit(A::B::A1);

auto main() -> int
{
    A::B::A1 a1;
    useit(a1);
    // We are calling function useit here, and
    // a declaration is visible. No definition
    // up to this point, but that is OK.
}

namespace A::B {
    void f(A1 a) {
        std::cout << "Call to B::f()\n";
    }
    void f(double x, B::A1 a) {
        std::cout << "Call to A::f()\n";
    }
}

void useit(A::B::A1 a)
{
    f(5.2, a);
    // We are calling f here, and the top-down
    // processing of the source file has enough
    // information to know that there is a function
    // f(double, A1) in the namespace where the
    // class A1 is defined.
}

