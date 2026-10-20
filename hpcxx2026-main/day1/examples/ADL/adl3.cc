#include <iostream>

namespace A::B {
    struct A1 {};
    void f(A1 a) {
        std::cout << "Call to B::f()\n";
    }
}
namespace A::B {
    void f(double x, B::A1 a) {
        std::cout << "Call to A::f()\n";
    }
}

auto main() -> int
{
    A::B::A1 a1;
    f(5.2, a1);
  // This is fine! Now we have defined f matching
  // function f in the same namespace A::B as the
  // one containing the class A1. So, that function
  // can be discovered.
}

