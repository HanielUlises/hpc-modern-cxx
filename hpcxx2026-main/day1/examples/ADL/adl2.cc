#include <iostream>

namespace A::B {
    struct A1 {};
    void f(A1 a) {
        std::cout << "Call to B::f()\n";
    }
}
namespace A {
    void f(double x, B::A1 a) {
        std::cout << "Call to A::f()\n";
    }
}

auto main() -> int
{
    A::B::A1 a1;
    f(5.2, a1);
   // In contrast to adl1.cc, there is now a function
   // A::B::f. This is discovered by ADL, and is
   // considered as a possible meaning for what we
   // wrote above. The other function A::f defined
   // later does not matter. So, the compiler reports
   // an error that there is no way to convert 5.2 to
   // an object of type A1 or that there is no matching
   // function.
}

