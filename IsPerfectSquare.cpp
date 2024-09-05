#include <iostream>

class Solution
{
  public:
    bool isPerfectSquare(int num)
    {
        if (num == 0 || num == 1 || num == 4)
        {
            return true;
        }
        if (num == 2 || num == 3)
        {
            return false;
        }

        long int l = 0;
        long int r = num / 2;
        long int mid{0};

        while (l < r)
        {
            if (r * r == num)
                return true;
            if (l * l == num)
                return true;

            // std::cout << "l = " << l << '\n';
            // std::cout << "mid = " << mid << '\n';
            // std::cout << "r = " << r << '\n';

            mid = (l + r) / 2;
            if (mid * mid == num)
                return true;
            if (mid * mid > num)
                r = mid - 1;
            if (mid * mid < num)
                l = mid + 1;
        }
        return false;
    }
};

int main()
{
    Solution sol{};
    std::cout << std::boolalpha;

    // std::cout << sol.isPerfectSquare(0) << '\n';      // true
    // std::cout << sol.isPerfectSquare(4) << '\n';      // true
    // std::cout << sol.isPerfectSquare(11) << '\n';     // false
    std::cout << sol.isPerfectSquare(8836) << '\n'; // true

    return 0;
}