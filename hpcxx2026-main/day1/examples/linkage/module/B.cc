export module B;
import std;

namespace app {
export int variable {};
}
export void B()
{
    std::print("{}\n", app::variable++);
}
