#include <iostream>
#include <vector>

class Solution
{
  public:
    int searchInsert(std::vector<int> &nums, int val)
    {
        size_t index{0};
        while (index < nums.size())
        {

            if (nums[index] > val)
            {
                nums.insert(nums.begin() + static_cast<int>(index), val);
                return index;
            }
            else if (nums[index] == val)
            {
                return index;
            }

            index++;
        }

        nums.insert(nums.end(), val);
        return nums.size() - 1;
    }
};

int main()
{

    return 0;
}
