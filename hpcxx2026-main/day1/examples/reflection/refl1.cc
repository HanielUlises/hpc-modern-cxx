#include <meta>
#include <string_view>
#include <print>

template <class E>
requires std::is_enum_v<E>
constexpr auto enum_to_string(E value) -> std::string_view
{
    namespace sm = std::meta;
    template for (constexpr auto e: std::define_static_array(sm::enumerators_of(^^E))) {
        if (value == [: e :]) {
            return sm::display_string_of(e);
        }
    }
    return "<unknown>";
}

enum class Colour { red, green, blue };

auto main() -> int
{
    std::println("{}", enum_to_string(Colour::red));
}
