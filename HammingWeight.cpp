#include <iostream>

class Solution
{
  public:
    int hammingWeight(uint32_t n)
    {
        int ret{0};
        while (n > 0)
        {
            if (n % 2 == 0)
            {
                ;
            }
            else
            {
                ret += 1;
            }
            n >>= 1;
        }
        return ret;
    }
};
