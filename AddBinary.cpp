#include <iostream>
#include <string>
#include <algorithm>

class Solution
{
  public:
    std::string addBinary(std::string a, std::string b)
    {
        bool carry{false};
        bool A{}, B{};
        std::string c{};

        int a_index{static_cast<int>(a.size() - 1)};
        int b_index{static_cast<int>(b.size() - 1)};
        int c_index{5 - 1};

        while (a_index >= 0 or b_index >= 0)
        {
            if (a_index >= 0)
            {
                A = (a[a_index] == '1');
            }
            else
            {
                A = false;
            }

            if (b_index >= 0)
            {
                B = (b[b_index] == '1');
            }
            else
            {
                B = false;
            }

            c.push_back((A xor B xor carry) ? '1' : '0');
            carry = (A and B) or (B and carry) or (A and carry) or (A and B and carry);

            // 000 = 0(0);
            // 001 = 1(0);
            // 010 = 1(0);
            // 011 = 0(1); A and C
            // 100 = 1(0);
            // 101 = 0(1); B and C
            // 110 = 0(1); A and B
            // 111 = 1(1); A and B and C
            a_index--;
            b_index--;
        }
        if (carry)
        {
            c.push_back('1');
        }

        std::ranges::reverse(c);
        return c;
    }
};

int main([[maybe_unused]] int argc, [[maybe_unused]] char const *argv[])
{
    Solution sol;
    std::string a{"1"};
    std::string b{"1"};

    auto r = sol.addBinary(a, b);

    std::cout << r << '\n';

    return 0;
}
