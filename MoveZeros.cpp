#include <iostream>
#include <vector>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        auto erased = std::erase(nums, 0);
        nums.insert(nums.end(), erased, 0);
    }
};


[[maybe_unused]] auto print = [](std::vector<int> vec) {
    for (auto &&i : vec)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
};

int main()
{
    Solution sol{};
    std::vector<int> myVec{0,1,0,3,12};
    print(myVec);
    sol.moveZeroes(myVec);
    print(myVec);

    return 0;
}