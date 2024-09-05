#include <iostream>
#include <vector>

class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        int sum{static_cast<int>(((nums.size()) * (nums.size()+1))/2)};
        for (auto &&number : nums)
        {
            sum -= number;
        }

        return sum;
    }
};

int main()
{
    Solution sol{};
    std::vector<int> myVec{9,6,4,2,3,5,7,0,1};
    std::cout << sol.missingNumber(myVec);
}