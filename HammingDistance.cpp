#include <bitset>
#include <iostream>

class Solution
{
  public:
    int hammingDistance(int x, int y)
    {
        std::bitset<32> bx{static_cast<unsigned long long>(x)};
        std::bitset<32> by{static_cast<unsigned long long>(y)};

        return (bx ^ by).count();
    }
};

int main()
{
    Solution sol{};

    std::cout << sol.hammingDistance(3, 1);
}