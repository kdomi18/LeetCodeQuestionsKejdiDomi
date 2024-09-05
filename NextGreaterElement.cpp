#include <iostream>
#include <unordered_map>
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
    std::vector<int> nextGreaterElement(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        std::unordered_map<int, int> mp{};
        for (std::size_t index{0}; index < nums2.size(); index++)
        {
            for (std::size_t i{index + 1}; i < nums2.size(); i++)
            {
                if (nums2.at(i) > nums2.at(index))
                {
                    mp[nums2.at(index)] = nums2.at(i);
                    break;
                }
                else
                {
                    mp[nums2.at(index)] = -1;
                    continue;
                }
            }
            if (index == nums2.size() - 1)
            {
                mp[nums2.at(index)] = -1;
            }
        }
        for (std::size_t i{0}; i < nums1.size(); i++)
        {
            nums1.at(i) = mp[nums1.at(i)];
        }
        return nums1;
    }
};

int main()
{
    Solution sol{};
    std::vector<int> n1{4, 1, 2}, n2{1, 3, 4, 2};
    print(sol.nextGreaterElement(n1, n2)); // [-1,3,-1]
}

// 1 3 2 4 5 -> 1->3 3->4 2->4 4->5 5->-1
// 5 4 2 3 1 -> -1 -1 3 -1 -1