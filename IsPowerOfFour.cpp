#include <algorithm>
#include <bitset>
#include <iostream>
#include <string>

class Solution
{
  public:
    bool isPowerOfFour(int n)
    {
        std::string numInBinary{std::bitset<32>{static_cast<unsigned long long>(n)}.to_string()};
        auto countOfOnes{std::ranges::count(numInBinary, '1')};
        auto countOfZeros{std::count(std::find(numInBinary.begin(), numInBinary.end(), '1'), numInBinary.end(), '0')};
        return (n > 0) && (countOfOnes == 1) && (countOfZeros % 2 == 0);
    }
};

int main()
{
    Solution sol{};
    std::cout << std::boolalpha;

    std::cout << sol.isPowerOfFour(0) << '\n';
    std::cout << sol.isPowerOfFour(1) << '\n';
    std::cout << sol.isPowerOfFour(12) << '\n';
    std::cout << sol.isPowerOfFour(16) << '\n';
    std::cout << sol.isPowerOfFour(8) << '\n';
}