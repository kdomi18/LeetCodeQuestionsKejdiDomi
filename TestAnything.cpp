#include <bitset>
#include <cstddef>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>

// speed up
// #include <fstream>
// #include <iostream>
// #include <string>
//
// auto init = []() {
//     std::cin.sync_with_stdio(false);
//     std::fstream out("user.out");
//     for (std::string s; std::getline(std::cin, s);)
//     {
//         std::getline(std::cin, s);
//         s[0] != '-' ? out << "true\n" : out << "false\n";
//     }
//     out.flush();
//     exit(0);
//     return 0;
// }();
// // end speedup

template <typename T>
[[maybe_unused]] auto print = [](std::vector<T> vec) {
    for (auto &&i : vec)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
};

// testing the behavior of unordered map
int main()
{
    int n{-4};
    unsigned long long input{static_cast<unsigned long long>(n)};
    std::bitset<32> bs{input};
    std::cout << bs;
    return 0;
}
