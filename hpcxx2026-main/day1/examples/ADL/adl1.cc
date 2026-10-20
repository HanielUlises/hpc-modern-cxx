#include <iostream>

namespace A::B {
    struct A1 {};
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
    // This does not work! There is no function
    // name f visible in this context. There is
    // no global function f. There is no such name
    // imported into this context via a
    // "using namespace ___" declaration. So direct
    // lookup fails. The first argument is a double,
    // which does not expand the search space for
    // the function f. But the second is a class!
    // So, ADL kicks in. We look in the namespace
    // where the class A1 was defined, i.e., A::B.
    // Unfortunately, there is no A::B::f. So, the
    // compiler will report an error. The presence
    // of A::f in the parent namespace A does not
    // contribute to the list of alternatives
    // considered.
}

