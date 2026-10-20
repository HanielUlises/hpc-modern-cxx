import std;
import NullSim;

auto main() -> int
{
    using namespace cxx_course;
    try {
        NullSimulator sim;
        sim.configure("Modules demo");
        sim.run();
        std::print("{}\n", sim.summary());
        return 0;
    } catch (std::exception& err) {
        std::print("{}\n", err.what());
        return 1;
    };
}
