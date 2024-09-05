#include <chrono>
#include <climits>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

class Solution
{
  public:
    std::vector<std::string> summaryRanges(std::vector<int> &nums)
    {
        if (nums.size() == 0)
        {
            return {};
        }
        if (nums.size() == 1)
        {
            return {std::to_string(nums[0])};
        }

        std::vector<std::string> ret{};
        std::string buf{};
        size_t firstIndex{};
        size_t lastIndex{};

        while (lastIndex < nums.size())
        {
            if (firstIndex == lastIndex)
            {
                buf += std::to_string(nums.at(firstIndex));
                lastIndex++;
                continue;
            }

            if (nums.at(lastIndex - 1) == nums.at(lastIndex) - 1)
            {
                lastIndex++;
            }
            else
            {
                if (lastIndex - firstIndex != 1)
                {
                    buf += "->" + std::to_string(nums.at(lastIndex - 1));
                    ret.push_back(buf);
                }
                else
                {
                    ret.push_back(buf);
                }
                buf = "";
                firstIndex = lastIndex;
            }
            if (lastIndex == nums.size() && nums.at(lastIndex - 1) - 1 == nums.at(lastIndex - 2))
            {
                buf += "->" + std::to_string(nums.at(lastIndex - 1));
            }
        }

        ret.push_back(buf);

        return ret;
    }
};

int main()
{
    Solution sol;
    // std::vector<int> nums{1, 2, 4, 6, 7, 9};
    std::vector<int> nums{-2147483648, -2147483647, 2147483647};

    // 1,2,3,4,6,7 : 6

    std::vector<std::string> ranges{sol.summaryRanges(nums)};

    for (auto &i : ranges)
    {
        std::cout << i << ' ';
    }

    return 0;
}
