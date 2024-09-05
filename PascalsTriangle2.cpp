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
    std::vector<int> getRow(int rowIndex)
    {
        std::vector<int> prev{1, 1};
        std::vector<int> curr;

        if (rowIndex == 0)
            return {1};
        if (rowIndex == 1)
            return prev;

        for (int cnt{0}; cnt < rowIndex - 1; cnt++)
        {
            // for (size_t i{0}; i < prev.size() - 1; i++)
            // {
            //     curr.insert(curr.begin() + static_cast<int>(i) + 1, prev.at(i) + prev.at(i + 1));
            // }

            curr = updateRow(prev);
            prev = curr;
        }

        return curr;
    }

  private:
    std::vector<int> updateRow(std::vector<int> prev)
    {
        std::vector<int> ret(prev.size() + 1);
        ret[0] = 1, ret[prev.size()] = 1;

        for (size_t i = 1; i < prev.size(); i++)
        {
            ret[i] = prev[i] + prev[i - 1];
        }
        return ret;
    }
};

int main()
{
    Solution sol;
    print(sol.getRow(0));
    print(sol.getRow(1));
    print(sol.getRow(2));
    print(sol.getRow(3));
    print(sol.getRow(4));
    print(sol.getRow(5));
    print(sol.getRow(33));

    return 0;
}

// 0 1 : 1
// 1 2 : 1  1
// 2 4 : 1  2   1
// 3 8 : 1  3   3   1
// 4 16: 1  4   6   4  1
// 5 32: 1  5  10  10  5  1
// 6 64: 1  6  15  20 15  6  1
// 7 128:1  7  21  35 35 21  7  1

// 1 1
// 1 2 1
// 1 2