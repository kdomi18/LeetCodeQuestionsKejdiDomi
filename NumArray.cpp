#include <iostream>
#include <vector>

class NumArray
{
  private:
    std::vector<int> m_nums{};

  public:
    NumArray(std::vector<int> &nums) : m_nums(nums)
    {
    }

    int sumRange(int left, int right)
    {
        auto sum = 0;
        for (auto it = m_nums.begin() + left; it <= m_nums.begin() + right; it++)
        {
            sum += *it;
        }
        return sum;
    }
};

int main()
{
    std::vector<int> nums{1, 2, 3, 4};
    NumArray *obj = new NumArray(nums);

    std::cout << obj->sumRange(0, 2) << '\n';
        std::cout << obj->sumRange(0, 0) << '\n';
    //     std::cout << obj->sumRange(1, 3) << '\n';

    return 0;
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */