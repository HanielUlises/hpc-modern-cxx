export module NullSim;

import std;
namespace cxx_course {
export class NullSimulator {
	bool config_ok{false}, run_ok{false};
public:
    void configure(std::string_view pars);
    void run();
    auto summary() const -> std::string;
};
export void check_results() {
    std::print("Function check_results()\n");
}
}
