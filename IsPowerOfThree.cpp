#include <iostream>
#include <cmath>

class Solution
{
  public:
    bool isPowerOfThree(int n)
    {
        return isInt(std::log(n)/std::log(3));
    }

    bool isInt(double value)
    {
        return std::abs(std::round(value) - value) < 1e-6;
    }
};

int main()
{
    Solution sol{};
    std::cout << std::boolalpha;

    std::cout << sol.isPowerOfThree(0) << '\n';  // false
    std::cout << sol.isPowerOfThree(1) << '\n';  // true
    std::cout << sol.isPowerOfThree(3) << '\n';  // true
    std::cout << sol.isPowerOfThree(4) << '\n';  // false
    std::cout << sol.isPowerOfThree(27) << '\n'; // true
}