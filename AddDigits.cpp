#include <iostream>
class Solution
{
  public:
    int addDigits(int num)
    {
        if (num >= 10)
        {
            num = recAdd(0, num);
            return addDigits(num);
        }
        else
        {
            return num;
        }
        
        
    }

    int recAdd(int sum, int num)
    {
        if (num == 0)
        {
            return sum;
        }
        else
        {
            sum += num % 10;
            return recAdd(sum, num / 10);
        }
    }
};

int main()
{
    Solution sol;
    std::cout << sol.addDigits(2147483647);
}