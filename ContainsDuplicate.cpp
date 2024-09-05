#include <iostream>
#include <unordered_map>
#include <vector>

class Solution
{
  public:
    bool containsDuplicate(std::vector<int> &nums)
    {
        std::unordered_map<int, int> mp;
        bool d{false};
        for (auto &&i : nums)
        {
            d = mp.insert({i, 1}).second;
            if (!d)
            {
                return true;
            }
        }
        return false;
    }
};

int main([[maybe_unused]] int argc, [[maybe_unused]] char *argv[])
{
    Solution sol;
    std::vector<int> n{1, 1};
    std::cout << std::boolalpha << sol.containsDuplicate(n) << '\n';

    return 0;
}

// 0000
// 0001
// 0010
// 0011
// 0100
// 0101
// 0110
// 0111
// 1000
// 1001
// 1010
// 1011
// 1100
// 1101
// 1110
// 1111
