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
    std::vector<int> intersect(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        if (nums1.empty() || nums2.empty())
        {
            return {};
        }

        std::vector<int> retVec{};

        for (std::size_t i{0}; i < nums1.size(); i++)
        {
            auto elem{std::find(nums2.begin(), nums2.end(), nums1.at(i))};
            if (elem != nums2.end())
            {
                retVec.push_back(*elem);
                nums2.erase(elem);
            }
            else
            {
                continue;
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

    print(sol.intersect(v1, v2));
    print(sol.intersect(v3, v4));
}