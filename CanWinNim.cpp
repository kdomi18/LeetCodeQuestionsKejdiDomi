#include <iostream>


class Solution {
public:
    bool canWinNim(int n) {
        return n%4 != 0;
    }
};

int main()
{
    Solution sol{};

    std::cout << std::boolalpha;
    std::cout << sol.canWinNim(1) << '\n'; // true
    std::cout << sol.canWinNim(2) << '\n'; // true
    std::cout << sol.canWinNim(4) << '\n'; // false
    std::cout << sol.canWinNim(10) << '\n'; // true
}