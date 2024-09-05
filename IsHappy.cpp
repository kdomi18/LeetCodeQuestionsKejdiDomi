#include <algorithm>
#include <iostream>
#include <vector>

class Solution
{
  public:
    std::vector<int> seen{2};
    bool isHappy(int n)
    {

        if (n == 1)
        {
            return true;
        }

        n = process(n);
        if (std::binary_search(seen.begin(), seen.end(), n))
        {
            return false;
        }
        else
        {
            seen.push_back(n);
            std::sort(seen.begin(), seen.end());
            return isHappy(n);
        }

        return false;
    }

  private:
    int process(int n)
    {
        int sum{0};
        while (n > 0)
        {
            sum += (n % 10) * (n % 10);
            n /= 10;
        }
        // std::cout << sum << ' ';
        return sum;
    }
};

int main()
{
    Solution sol;
    std::cout << std::boolalpha << sol.isHappy(2) << '\n';  // false
    std::cout << std::boolalpha << sol.isHappy(19) << '\n'; // true
    std::cout << std::boolalpha << sol.isHappy(20) << '\n'; //??

    return 0;
}
