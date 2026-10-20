module NullSim;

import std;
#define FMT std::format
namespace cxx_course {
    void NullSimulator::configure(std::string_view pars)
    {
	if (pars.empty()) throw std::runtime_error{"Empty configuration!"};
        std::println("configure called with parameters {}", pars);
	config_ok = true;
    }
    void NullSimulator::run()
    {
	if (not config_ok) 
		throw std::runtime_error{"Can't run without a valid configuration!"};
        std::println("running NullSimulator!");
        run_ok = true;
    }
    auto NullSimulator::summary() const -> std::string
    {
	if (not run_ok)
		throw std::runtime_error{"No run to summarize!"};
        return { "And here are the results of running the NullSimulator:" };
    }
}
