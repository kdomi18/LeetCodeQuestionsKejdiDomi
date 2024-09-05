#include <algorithm>
#include <cstddef>
#include <iostream>
#include <unordered_map>

class Solution
{
  public:
    bool containsNearbyDuplicate(std::vector<int> &nums, int K)
    {
        size_t size{nums.size()};
        if (size == 1)
        {
            return false;
        }
        size_t k = static_cast<size_t>(K);
        size_t left{0};
        size_t right{((left + k) > (size - 1)) ? size - 1 : (left + k)};
        while (right < size)
        {
            if (containsDuplicate(nums, left, right))
            {
                return true;
            }
            left++;
            right++;
        }

        return false;
    }

  private:
    bool containsDuplicate(std::vector<int> &nums, size_t left, size_t right)
    {
        for (size_t i{left}; i <= right; i++)
        {
            for (size_t j{i + 1}; j <= right; j++)
            {
                if (nums.at(i) == nums.at(j))
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main()
{
    Solution sol;
    std::vector<int> vec{1, 3, 4, 1};
    std::cout << std::boolalpha << sol.containsNearbyDuplicate(vec, 3);

    return 0;
}
