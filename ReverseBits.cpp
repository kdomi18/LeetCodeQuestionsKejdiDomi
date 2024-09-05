#include <iostream>

class Solution
{
  public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t ret{0};
        for (int i{0}; i < 32; i++)
        {
            ret |= ((n >> i) << i) << (32 - (i + 1)) >> i;
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    std::cout << std::hex << sol.reverseBits(2) << '\n'; // 00000000'00000000'00000000'00000010 -> 0100''0000

    return 0;
}

// 1010 -> 0101
// 1101 -> 1011
// 111111x000 -> 000x000000 ->
