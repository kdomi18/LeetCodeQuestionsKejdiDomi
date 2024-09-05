#include <array>
#include <iostream>

class Solution
{
  public:
    bool isUgly(int n)
    {
        if (n <= 0)
        {
            return false;
        }
        if (n == 1)
        {
            return true;
        }

        constexpr std::array<int, 3> primeFactors{2, 3, 5};
        int currFactor{};
        for (size_t i = 0; i < primeFactors.size(); i++)
        {
            currFactor = primeFactors.at(i);
            while (n % currFactor == 0)
            {
                n /= currFactor;
                if (n == 1)
                {
                    return true;
                }
            }
        }

        return false;
    }
};

int main()
{
    Solution sol{};
    std::cout << std::boolalpha << sol.isUgly(12) << '\n';
    std::cout << sol.isUgly(120) << '\n';
    std::cout << sol.isUgly(14) << '\n';

    std::cout << typeid(6 / 3.0).name() << '\n';
}