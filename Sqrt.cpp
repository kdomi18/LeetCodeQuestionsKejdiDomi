#include <cstdint>
#include <iostream>

class Solution
{
  public:
    int mySqrt(int x)
    {
        long int test{0};
        while (test * test <= x)
        {
            test++;
        }

        return test - 1;
    }
};

int main([[maybe_unused]] int argc, [[maybe_unused]] char const *argv[])
{
    Solution sol;
    int x{INT32_MAX};
    std::cout << "Sqrt of " << x << " is " << sol.mySqrt(x) << '\n';
    return 0;
}
