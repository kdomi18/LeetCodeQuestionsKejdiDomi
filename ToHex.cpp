#include <cassert>
#include <iostream>
#include <string>

class Solution
{
  private:
    char digitToHex(int n)
    {
        assert(n < 16 && n >= 0 && "Invalid digit to convert to hex!");
        switch (n)
        {
        case 10:
            return 'a';
        case 11:
            return 'b';
        case 12:
            return 'c';
        case 13:
            return 'd';
        case 14:
            return 'e';
        case 15:
            return 'f';

        default:
            return n + '0';
            break;
        }
    }

  public:
    std::string toHex(int n)
    {
        unsigned int num{static_cast<unsigned int>(n)};
        if (num == 0)
        {
            return "0";
        }

        std::string retStr{};
        while (num != 0)
        {
            retStr.insert(retStr.begin(), digitToHex(num % 16));
            num /= 16;
        }

        return retStr;
    }
};

int main()
{
    Solution sol{};
    std::cout << sol.toHex(26) << '\n';
    std::cout << sol.toHex(-1) << '\n';

    return 0;
}