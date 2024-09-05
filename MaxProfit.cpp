#include <algorithm>
#include <iostream>
#include <vector>

[[maybe_unused]] auto print = [](std::vector<int> vec) {
    for (auto &&i : vec)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
};

// class Solution
// {
//   public:
//     int maxProfit(std::vector<int> &prices)
//     {
//         int max{0};

//         for (size_t i = 0; i < prices.size() - 1; i++)
//         {
//             for (size_t j{i + 1}; j < prices.size(); j++)
//             {
//                 if (prices.at(j) - prices.at(1) > max)
//                 {
//                     max = prices.at(j) - prices.at(i);
//                 }
//             }
//         }

//         return max;
//     }
// };

class Solution
{
  public:
    int MIN{0};
    long indexMIN{};
    int maxProfit(std::vector<int> &prices)
    {
        int max{0};
        int min{0};
        std::vector<int>::iterator result = std::min_element(prices.begin(), prices.end());
        MIN = *result;
        indexMIN = std::distance(prices.begin(), result);

        for (size_t i = prices.size() - 1; i >= 1; i--)
        {
            min = minimum(prices, i);
            if (max < prices.at(i) - min)
            {
                max = prices.at(i) - min;
            }
        }

        return max;
    }

  private:
    int minimum(std::vector<int> &prices, size_t last)
    {
        if (static_cast<long>(last) > indexMIN)
        {
            return MIN;
        }
        else
        {
            MIN = *std::min_element(prices.begin(), prices.begin() + static_cast<long>(last));
        }

        return MIN;
    }
};

int main()
{
    Solution sol;
    std::vector<int> v1{3, 2, 6, 5, 0, 3};
    // std::vector<int> v2{7, 6, 4, 3, 1};
    std::cout << sol.maxProfit(v1) << '\n';
    // std::cout << sol.maxProfit(v2) << '\n';

    return 0;
}