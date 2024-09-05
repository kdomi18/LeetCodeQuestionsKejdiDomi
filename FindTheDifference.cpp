#include <iostream>
#include <string>

class Solution
{
  public:
    char findTheDifference(std::string s, std::string t)
    {
        for (auto &&i : s)
        {
            auto it {t.begin()};
            t.erase(it + static_cast<long>(t.find(i)));
        }
        return t.at(0);
    }
};

int main()
{
    Solution sol{};

    std::cout << sol.findTheDifference("abcd", "abcde") << '\n';        // e
    std::cout << sol.findTheDifference("", "y") << '\n';                // y
    std::cout << sol.findTheDifference("leetcode", "tleeeorcd") << '\n'; // r

    return 0;
}