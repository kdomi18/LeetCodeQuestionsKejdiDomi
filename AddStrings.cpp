#include <iostream>
#include <string>

class Solution
{
  private:
    char addDigitStr(char d1, char d2, int &c)
    {
        int sum{(d1 - 48) + (d2 - 48) + c};
        c = sum / 10;
        return (sum % 10) + 48;
    }

  public:
    std::string addStrings(std::string num1, std::string num2)
    {
        if (num1.size() < num2.size())
        {
            std::swap(num1, num2);
        }
        auto d1p{num1.end()};
        auto d2p{num2.end()};
        int carry{};
        std::string retStr{};
        do
        {
            d1p = std::next(d1p, -1);
            d2p = std::next(d2p, -1);
            std::cout << *d1p << '\n';

            retStr.insert(retStr.begin(), addDigitStr(*d1p, *d2p, carry));

        } while (d2p != num2.begin());

        while (d1p != num1.begin())
        {
            d1p = std::next(d1p, -1);
            retStr.insert(retStr.begin(), addDigitStr(*d1p, '0', carry));
        }
        if (carry != 0)
        {
            retStr.insert(retStr.begin(), carry + 48);
        }

        return retStr;
    }
};

int main()
{
    Solution sol{};
    std::cout << sol.addStrings("9899", "1") << '\n';

    return 0;
}