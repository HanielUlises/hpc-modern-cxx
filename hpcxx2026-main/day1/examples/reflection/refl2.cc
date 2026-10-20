#include <meta>
#include <print>
#include <type_traits>

template <class T>
requires std::is_class_v<T>
void print_members(const T& t)
{
    using namespace std::meta;
    template for (constexpr auto m: std::define_static_array(nonstatic_data_members_of(^^T, access_context::unprivileged()))) {
        std::println("{} = {}", identifier_of(m), t.[:m:]);
    }
    // After building and running this, change the access_context::unprivileged()
    // to access_context::unchecked() above and recompile and run again.
    // Note the difference in the output.
}

struct Point {
    private:
    int x = 3;
    public:
    double y = 3.44;
};

struct Vec3 {
    double x{}, y{}, z{};
};

auto main() -> int
{
    Point p{};
    Vec3 v{0.1, 0.2, 0.3};
    print_members(p);
    print_members(v);
}

