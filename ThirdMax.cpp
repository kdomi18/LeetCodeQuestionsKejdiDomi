#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

class Solution
{
  public:
    int thirdMax(const std::vector<int> &nums)
    {
        if (nums.size() < 3)
        {
            return *std::ranges::max_element(nums);
        }

        std::array<int, 3> maxes{INT_MIN, INT_MIN, INT_MIN};
        for (auto &&i : nums)
        {
            if (maxes.at(0) < i)
            {
                maxes.at(0) = i;
            }
            std::sort(maxes.begin(), maxes.end());
        }

        if (maxes.at(0) == maxes.at(1))
        {
            return maxes.at(2);
        }

        return maxes.at(0);
    }
};

int main()
{
    Solution sol{};
    std::cout << sol.thirdMax({1, 1, 2}) << '\n';
    std::cout << sol.thirdMax({3, 2}) << '\n';
    std::cout << sol.thirdMax({3, 2, 2}) << '\n';
    std::cout << sol.thirdMax({3, 2, INT_MIN}) << '\n';
    std::cout << sol.thirdMax({3, INT_MIN, INT_MIN}) << '\n';
    std::cout << sol.thirdMax({3, INT_MIN + 1, INT_MIN}) << '\n';

    return 0;
}