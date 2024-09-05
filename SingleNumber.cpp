#include <algorithm>
#include <iostream>
#include <vector>

class Solution
{
  public:
    int singleNumber(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        for (size_t i = 0; i < nums.size() - 1; i += 2)
        {
            if (nums.at(i) != nums.at(i + 1))
            {
                return nums.at(i);
            }
        }

        return nums.at(nums.size() - 1);
    }
};

int main()
{
    Solution sol;
    std::vector<int> v{4, 1, 2, 1, 2};
    // 1 1 2 2 4
    std::cout << sol.singleNumber(v) << '\n';
}