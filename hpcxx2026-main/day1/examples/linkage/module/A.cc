export module A;
import std;

namespace app {
export int variable {};
}
void other_func();

export void A()
{
    std::print("{}\n", app::variable++);
    other_func();
}
