#include <iostream>
#include <vector>

class Solution
{
  public:
    int findMaxConsecutiveOnes(std::vector<int> &nums)
    {
        int prevMax{};
        int cMax{};
        for (auto &&i : nums)
        {
            if (i == 1)
            {
                prevMax++;
            }
            if (i == 0)
            {
                if (cMax < prevMax)
                {
                    cMax = prevMax;
                }
                prevMax = 0;
            }
        }
        if (cMax < prevMax)
        {
            cMax = prevMax;
        }
        return cMax;
    }
};

int main()
{
    Solution sol{};
    std::vector<int> nums{0,0,0};
    std::cout << sol.findMaxConsecutiveOnes(nums) << '\n';

    return 0;
}