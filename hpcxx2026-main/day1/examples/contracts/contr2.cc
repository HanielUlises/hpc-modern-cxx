#include <iostream>
#include <contracts>
#include <print>
namespace con = std::contracts;
void handle_contract_violation(const con::contract_violation& v)
{
    auto&& loc = v.location();
    std::print(stderr, R"(Contract violation!
kind: {}
semantic: {}
comment: {}
location: {}:line={}
)",
            static_cast<int>(v.kind()),
            static_cast<int>(v.semantic()),
            v.comment(),
            loc.file_name(), loc.line());
    con::invoke_default_contract_violation_handler(v);
}

[[gnu::noinline]] auto divide(int a, int b)
    pre (b != 0)
{
    return a / b;
}

auto main() -> int
{
    int divider{1};
    std::cout << "Divider: ";
    std::cin >> divider;
    divide(10, divider);
}

