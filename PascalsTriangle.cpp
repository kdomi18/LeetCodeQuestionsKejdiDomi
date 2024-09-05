#include <iostream>
#include <vector>

auto print = [](std::vector<int> vec) {
    for (auto &&i : vec)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
};

class Solution
{
  public:
    std::vector<std::vector<int>> generate([[maybe_unused]] int numRows)
    {

        std::vector<std::vector<int>> ret{};
        for (size_t i{0}; static_cast<int>(i) < numRows; i++)
        {
            std::vector<int> toBeAppended(i + 1, 1);
            for (size_t j{0}; j <= i; j++)
            {
                if (j == 0 or j == i)
                {
                    continue;
                }
                else
                {
                    toBeAppended[j] = ret[i - 1][j - 1] + ret[i - 1][j];
                }
            }
            ret.push_back(toBeAppended);
        }

        return ret;
    }
};

int main()
{
    Solution sol;
    std::vector<std::vector<int>> ans{sol.generate(4)};
    for (auto &&i : ans)
    {
        print(i);
    }
    return 0;
}