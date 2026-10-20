export module NullSim;

import std;
namespace cxx_course {
export class NullSimulator {
	bool config_ok{false}, run_ok{false};
public:
    void configure(std::string_view pars);
    void run();
    inline auto summary() const -> std::string
    {
        return {"Summary of results:"};
    }
};
}
