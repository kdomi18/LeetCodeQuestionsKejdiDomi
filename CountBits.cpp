#include <iostream>
#include <vector>

[[maybe_unused]] auto print = [](std::vector<int> vec) {
    for (auto &&i : vec)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
};

class Solution
{
  private:
    std::vector<int> temp{0, 1};

  public:
    std::vector<int> countBits(int n)
    {
        int prevN = n;
        std::vector<int> myVec{};
        myVec.emplace_back(0);
        myVec.emplace_back(1);
        while (n / 2 != 0)
        {
            n /= 2;
            increment(temp);
            myVec.insert(myVec.end(), temp.begin(), temp.end());
            temp = myVec;
        }
        myVec.resize(static_cast<size_t>(prevN+1));
        return myVec;
    }

    void increment(std::vector<int> &t)
    {
        for (size_t i = 0; i < t.size(); i++)
        {
            t.at(i)++;
        }
    }
};

int main()
{
    Solution sol{};

    print(sol.countBits(4));
}

// 000, 001, 010, 011, 100, 101, 110, 111, 1000, 1001, 1010, 1011, 1100, 1101, 1110, 1111, 10000
// 0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2,   3,  2,  3,  3,  4
// 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
