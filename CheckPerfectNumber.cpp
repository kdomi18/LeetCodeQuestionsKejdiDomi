#include <iostream>
#include <cmath>

class Solution
{
  public:
    bool checkPerfectNumber(int num)
    {
        if (num < 9)
        {
            if (num == 6)
            {
                return true;
            }
            
            return false;
        }
        
        int sum{};
        for (int i{2}; i < static_cast<int>(std::sqrt(num)); i++)
        {
            if (num % i == 0)
            {
                sum += (i + (num / i));
            }
        }
        return (sum+1) == num;
    }
};

int main()
{
    Solution sol{};
    std::cout << std::boolalpha;

    std::cout << sol.checkPerfectNumber(28); // true
    std::cout << sol.checkPerfectNumber(15); // false

    return 0;
}