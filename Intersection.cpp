#include <algorithm>
#include <iostream>
#include <vector>

[[maybe_unused]] auto print = [](std::vector<int> vec) {
    for (auto &&i : vec)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
};

class Solution
{
  public:
    std::vector<int> intersection(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        if (nums1.empty() || nums2.empty())
        {
            return {};
        }

        std::vector<int> retVec{};
        for (auto &&i : nums1)
        {
            for (auto &&j : nums2)
            {
                if (i == j)
                {
                    if (std::ranges::find(retVec, i) == retVec.end())
                    {
                        retVec.push_back(i);
                    }
                }
            }
        }
        return retVec;
    }
};

int main()
{
    Solution sol{};
    std::vector<int> v1{1, 2, 2, 1};
    std::vector<int> v2{2, 2};
    std::vector<int> v3{4, 9, 5};
    std::vector<int> v4{9, 4, 9, 8, 4};

    print(sol.intersection(v1, v2));
    print(sol.intersection(v3, v4));
}