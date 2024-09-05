#include <functional>
#include <iostream>
#include <string>
#include <vector>

template <typename T>
[[maybe_unused]] auto print = [](std::vector<T> vec) {
    for (auto &&i : vec)
    {
        std::cout << i << ' ';
    }
    std::cout << '\n';
};

class Solution
{
  public:
    std::vector<std::string> findRelativeRanks(std::vector<int> &score)
    {
        std::vector<std::string> ret{};
        std::vector<int> cpScore{score};
        std::ranges::sort(cpScore, std::greater{});
        std::unordered_map<int, std::string> mp{};

        for (std::size_t i{}; i < cpScore.size(); i++)
        {
            if (i > 2)
            {
                mp[cpScore.at(i)] = std::to_string(i+1);
            }
            else
            {
                if (i == 0)
                {
                    mp[cpScore.at(i)] = "Gold Medal";
                }
                if (i == 1)
                {
                    mp[cpScore.at(i)] = "Silver Medal";
                }
                if (i == 2)
                {
                    mp[cpScore.at(i)] = "Bronze Medal";
                }
            }
        }

        for (auto &&s : score)
        {
            ret.push_back(mp[s]);
        }
        return ret;
    }
};

int main()
{
    Solution sol{};
    std::vector<int> s{10, 3, 8, 9, 4};
    print<std::string>(sol.findRelativeRanks(s));

    return 0;
}