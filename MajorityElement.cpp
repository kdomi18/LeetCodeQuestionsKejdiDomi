#include <iostream>
#include <vector>

class Solution
{
  public:
    int majorityElement(std::vector<int> &nums)
    {
        int limit{static_cast<int>(nums.size()) / 2};
        std::sort(nums.begin(), nums.end());
        int cnt{0};
        int prevElem{nums.at(0)};
        for (auto &&i : nums)
        {
            if (i == prevElem)
            {
                cnt++;
            }
            else
            {
                prevElem = i;
                cnt = 1;
            }
            if (cnt > limit)
            {
                return i;
            }
        }

        return 0;
    }
};

int main()
{
    Solution sol;
    std::vector<int> vec{-1, 1, 1, 1, 2, 1};
    std::cout << sol.majorityElement(vec) << '\n';

    return 0;
}
