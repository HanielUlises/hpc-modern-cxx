#include <algorithm>
#include <iterator>
#include <print>
#include <ranges>
#include <vector>

int main()
{
    using namespace std;
    namespace sr = std::ranges;
    vector v { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    print("Vector v = (after initialization): {}\n", v);
    if (sr::is_sorted(v))
        print("The sequence is sorted in the increasing order.\n");
    else
        print("The sequence is not sorted in the increasing order.\n");

    sr::reverse(v);
    print("After std::ranges::reverse: {}.\n", v);

    sr::rotate(v, v.begin() + 3);
    print("After std::rotate by 3{}.\n", v);

    sr::sort(v);
    print("After std::ranges::sort{}.\n", v);

    vector<int> w { 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 }, x, y, z;
    print("Vector w = {}.\n", w);

    vector<int> m;
    sr::merge(v, w, std::back_inserter(m));
    print("ranges::merge of v and w gives ... : {}.\n", m);

    sr::set_union(v, w, back_inserter(x));
    print("Union of v and w : {}.\n", x);

    sr::set_intersection(w, v, back_inserter(y));
    print("Intersection of w and v : {}.\n", y);

    sr::set_symmetric_difference(v, w, back_inserter(z));
    print("Symmetric difference of v and w : {}.\n", z);

    if (sr::is_permutation(z, v)) {
        print("The above sequence is a permutation of the first sequence printed.\n");
    } else {
        print("The above sequence is not a permutation of the first sequence printed.\n");
    }
}
