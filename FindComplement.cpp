#include <iostream>
#include <cmath>

class Solution
{
private: 
    int bitWidth(int num)
    {
        return static_cast<int>(std::log2(num)) + 1;
    }

  public:
    int findComplement(int num)
    {
        return static_cast<int>(std::pow(2, bitWidth(num)) - 1) - num;
    }
};

int main()
{
    Solution sol{};

    std::cout << sol.findComplement(13) << '\n';
    std::cout << sol.findComplement(1) << '\n';

    return 0;
}

// 101 > 010
// 1101 = 13 (0010 = 2)

// 13/2 = 6(1)
// 6/2 = 3(0)
// 3/2 = 1(1)
// 1%2 = 0(1)