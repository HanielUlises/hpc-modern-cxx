#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

template <class T>
using value_type_of = std::remove_cvref_t<T>::value_type;
auto main() -> int
{
    const std::vector inp1 { 1., 2., 3., 4., 5. };
    const std::vector inp2 { 9., 8., 7., 6., 5. };
    std::vector outp(inp1.size(), 0.);
    auto saxpy = []<class T_in, class T_out>(value_type_of<T_in> a,
                     T_in&& x, T_in&& y, T_out& z) {
        using in_element_type = value_type_of<T_in>;
        using out_element_type = value_type_of<T_out>;
        static_assert(std::is_same_v<in_element_type, out_element_type>, "Input and output element types must match!");
        std::transform(x.begin(), x.end(), y.begin(), z.begin(),
            [a](in_element_type X, in_element_type Y) { return a * X + Y; });
    };

    std::ostream_iterator<double> cout { std::cout, "\n" };
    saxpy(10., inp1, inp2, outp);
    copy(outp.begin(), outp.end(), cout);
    std::cout << ":::::::::::::::::::::\n";
}
