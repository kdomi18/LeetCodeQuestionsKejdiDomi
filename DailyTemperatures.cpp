#include <cstddef>
#include <iostream>
#include <vector>

class Solution
{
  public:
    std::vector<int> dailyTemperatures(std::vector<int> &temperatures)
    {
        std::vector<int> ret(temperatures.size(), 0);

        for (size_t i{0}; i < temperatures.size(); i++)
        {
            size_t j{i};
            for (; j < temperatures.size(); j++)
            {
                if (temperatures.at(i) < temperatures.at(j))
                {
                    break;
                }
            }
            if (j < temperatures.size())
            {
                ret.at(i) = j - i;
            }
            else
            {
                ret.at(i) = 0;
            }
        }
        return ret;
    }
};

[[maybe_unused]] auto print = [](std::vector<int> vec) {
    for (auto &&i : vec)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
};

int main()
{
    Solution sol;
    std::vector<int> temperatures{73, 74, 75, 71, 69, 72, 76, 73};
    print(sol.dailyTemperatures(temperatures));

    return 0;
}
