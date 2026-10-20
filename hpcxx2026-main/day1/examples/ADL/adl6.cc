namespace MyClassContext {
	class MyClass {
        public:
		// Only the minimal set of essential
		// member functions without which the class
		// can not be sensibly used, e.g., constructors
		// destructor, copy/move assignment, semantically
		// sensible setters and a minimal set of getters,
		// and operators which can not be non-members.
	private:
		// Functions belonging to implementation details.
		// Data members.
	};
	// All other class related functions, e.g., arithmetic
	// operators, properties calculable using those
	// available through getters.
	// ADL helps the compiler to find all functions here
	// which have at least one argument of the type MyClass
	// as easily as when they are member functions. Only
	// the notation changes from obj.someproperty() to
	// someproperty(obj). So, if someproperty can be
	// implemented in terms of the public accessor functions
	// in MyClass, it should be here, not in the class, to
	// increase data encapsulation, and reduce the maintenance
	// overhead on the long run.
}

