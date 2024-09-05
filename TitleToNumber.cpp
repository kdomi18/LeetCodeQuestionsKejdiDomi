#include <cassert>
#include <cstddef>
#include <iostream>
#include <string>

class Solution
{
  public:
    int titleToNumber([[maybe_unused]] std::string columnTitle)
    {
        int ret{0};
        int cnt{0};

        while (cnt < static_cast<int>(columnTitle.size()))
        {
            ret += p(cnt) * (columnTitle[columnTitle.size() - static_cast<size_t>(cnt) - 1] - 'A' + 1);
            cnt++;
        }

        return ret;
    }

  private:
    int p(int exp)
    {
        int ret{1};
        while (exp > 0)
        {
            ret *= 26;
            exp--;
        }
        return ret;
    }
};

int main()
{
    Solution sol;

    std::cout << sol.titleToNumber("A") << '\n';  // 1
    std::cout << sol.titleToNumber("AA") << '\n'; // 27
    std::cout << sol.titleToNumber("AB") << '\n'; // 28
    std::cout << sol.titleToNumber("ZY") << '\n'; // 701
    std::cout << sol.titleToNumber("AZ") << '\n'; //

    // std::vector<std::string> testVec{"A", "AB", "ZY"};
    // std::vector<int> testVecAns{1, 28, 701};

    // for (size_t i = 0; i < testVec.size(); i++)
    // {
    //     assert((sol.titleToNumber(testVec.at(i)) == testVecAns.at(i)));
    // }

    return 0;
}
