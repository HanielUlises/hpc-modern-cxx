#include <print>
#include <meta>
#include <ranges>
namespace sr = std::ranges;
namespace sv = sr::views;
namespace sm = std::meta;

#define str  sm::display_string_of

consteval auto categorize(sm::info r) -> std::string_view
{
    if (is_namespace(r))
        return "namespace";
    else if (is_function(r))
        return "function";
    else if (is_variable(r))
        return "variable";
    else if (is_class_type(r))
        return "class";
    else if (is_enum_type(r))
        return "enum";
    else if (is_union_type(r))
        return "union";
    else if (is_scalar_type(r))
        return "scalar";
    else
        return "uncategorized";

}


auto f(double x) -> double
{
    return x * x;
}

auto main(int argc, char* argv[]) -> int
{
    std::println("{} -> {}", str(^^::), categorize(^^::));
    std::println("{} -> {}", str(^^f), categorize(^^f));
    std::println("{} -> {}", str(^^main), categorize(^^main));
    constexpr auto rv = ^^argc;
    constexpr auto rt = ^^decltype(argc);
    std::println("{} (type = {}) = {}", str(rv), str(rt), argc);
    std::println("{} -> {}", str(rv), categorize(rv));
    std::println("{} -> {}", str(rt), categorize(rt));
}
