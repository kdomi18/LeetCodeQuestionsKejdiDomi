#include <cstddef>
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

class Solution
{
  public:
    std::string convertToTitle(int n)
    {

        std::string ret{};
        while (n)
        {
            char c = 'A' + (n - 1) % 26;
            ret = c + ret;
            n = (n - 1) / 26;
        }

        return ret;
    }
};

int main()
{
    Solution sol;

    std::cout << sol.convertToTitle(1) << '\n';
    std::cout << sol.convertToTitle(26) << '\n';
    std::cout << sol.convertToTitle(27) << '\n';
    std::cout << sol.convertToTitle(701) << '\n';

    return 0;
}
