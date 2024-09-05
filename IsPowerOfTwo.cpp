#include <bitset>

class Solution
{
  public:
    bool isPowerOfTwo(int n)
    {
        if (n < 0)
        {
            n = -n;
        }
        return std::bitset<32>{static_cast<unsigned long long>(n)}.count() == 1;
    }
};
